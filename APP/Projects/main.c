/* + MOTOR
 * Projects_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */
#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "Timer_Private.h"

#include "Projects_Interface.h"
#include "DIO_Private.h"

#include <string.h>
#include <stdlib.h>

#include "Projects_Interface.h"
#include "DIO_Interface.h"
#include "ICU_interface.h"
#include "ICU_Private.h"
#include <string.h>
#include <stdlib.h>
#include "ADC_Interface.h"
#include"M_USART_NEW_Interface.h"

#define ICR1_REG      *(volatile u16*)0x46
#define  Trigger_pin	PA1
double distance;
char string[10];
long local_count;
double local_dis;
#define Sys_on_EEPROM 44
#define Sys_off_EEPROM 60
#define Sys_WaitingOn_EEPROM 20
#define Sys_WaitingOff_EEPROM 30

#define Sys_On 1
#define Sys_Off 0
u32 error_flag_falling=0;
u32 error_flag_rising=0;

u8 fail_flag = 0;


//#define TCNT0_REG     *(volatile u8*)0x52
#define PRESS_THRESHOLD  5000000
u8 CPS_SYS_STAT= 0;
int TimerOverflow = 0;
u16 LDR_read=0;
ISR(TIMER1_OVF_vect) {
	TimerOverflow++; /* Increment Timer Overflow count */
}
u8 GAS_STAT=0;
u8 flag = 0;
u8 volatile sys_state = Sys_Off;
u8 waiting_state = 0;
u8 i=0;
//u8 s=0;
u8 Pu_3_return_u8 = 1;                      //button is relesed (sys button)
u8 Pu_0_return_u8 = 1;                      //gas button
u8 Pu_2_return_u8 = 1;                      //green

u8 pressCounter = 0;
u8 buttonPressed = 0;
u8 LDRSHOW [7];
u8 LDR=0;
void test_timer(void) {
	H_LED_Void_LedTog(LED_RED);                      //toggle gas led state
	M_Timer_Void_TimerStop2();
	//M_Timer_Void_TimerStop(TIMER0_CHANNEL);
	flag = 0;
	if (sys_state == Sys_On) {

		sys_state = Sys_Off;                      //sys  off
		H_Lcd_Void_LCDGoTo(0, 12);
		H_Lcd_Void_LCDWriteString("  off   ");
		H_EEPROM_Void_EEPROMWrite(0, 1, Sys_off_EEPROM);

	} else if (sys_state == Sys_Off) {
		sys_state = Sys_On;
			H_Lcd_Void_LCDGoTo(0, 12);             //sys on
			H_Lcd_Void_LCDWriteString("   on   ");
		H_EEPROM_Void_EEPROMWrite(0, 1, Sys_on_EEPROM);

	}

}
u8 Uart_dataRead=0;
int main() {
	Icu_init();


//	M_Timer_Void_PWMInit(TIMER0_CHANNEL);
//	M_Timer_Void_PWMSetDutyCycle(TIMER0_CHANNEL,80);
//	M_Timer_Void_PWMStart(TIMER0_CHANNEL);
//	M_DIO_Void_SetPinDirection(PB6_PIN , OUTPUT);
//	M_DIO_Void_SetPinDirection(PB5_PIN , OUTPUT);
//	M_DIO_Void_SetPinValue(PB6_PIN , HIGH);
	//----------------------------
	H_Lcd_Void_LCDInit();
	M_Timer_Void_Timer2_Init();
//	M_Timer_Void_TimerInit();
	M_GIE_Void_GlobalInterruptEnable();
	//M_Timer_Void_TimerSetTime(120);
	M_Timer_Void_Timer2_SetTime(2000);

	//Sys_init_end--------------------------------

	 u8 EEPROM_Read_sysStat=0;
	 u8 EEPROM_Read_sysWaiting=0;
	 u16 EEPROM_Read_sysUltraSonic=0;
	 H_LED_Void_LedInit(LED_BLU);

		H_Lcd_Void_LCDGoTo(0, 1);
		H_Lcd_Void_LCDWriteString("  CCS : ");

	 //------------------------------------------------- at initalization check last state of the system activation
	 H_EEPROM_Void_EEPROMInit();
	 _delay_ms(300);
	 EEPROM_Read_sysStat=H_EEPROM_U8_EEPROMRead(0,1);     // read system status
	 if (EEPROM_Read_sysStat==Sys_on_EEPROM){
	 sys_state=Sys_On;
	 H_LED_Void_LedOn(LED_RED);
		H_Lcd_Void_LCDGoTo(0, 12);             //sys on
		H_Lcd_Void_LCDWriteString("   on   ");
	 }
	 else if (EEPROM_Read_sysStat==Sys_off_EEPROM)
	 {
	 sys_state=Sys_Off;
	 H_LED_Void_LedOff(LED_RED);
		H_Lcd_Void_LCDGoTo(0, 12);
		H_Lcd_Void_LCDWriteString("   off   ");
	 }
	 //------------------------------------------------- at initalization check last state of the system waiting status
	 EEPROM_Read_sysWaiting=H_EEPROM_U8_EEPROMRead(0,4);     // read waiting system status
if (EEPROM_Read_sysWaiting==Sys_WaitingOn_EEPROM){
	waiting_state=1;
}
else if (EEPROM_Read_sysWaiting==Sys_WaitingOff_EEPROM){
	waiting_state=0;
}
//----------------------------------------------------------------------------------------------------------------

_delay_ms(1000);
 EEPROM_Read_sysUltraSonic=H_EEPROM_U8_EEPROMRead(0,5);     // read ultrasonic value
 //EEPROM_Read_sysUltraSonic=( (EEPROM_Read_sysUltraSonic<<8 )|((u16)(H_EEPROM_U8_EEPROMRead(0,6) )));
H_Lcd_Void_LCDGoTo(3, 11);
H_Lcd_Void_LCDWriteNumber(EEPROM_Read_sysUltraSonic);
H_Lcd_Void_LCDGoTo(3, 0);
H_Lcd_Void_LCDWriteString("last ulra:");

M_ADC_Void_ADCInit();

M_DIO_Void_SetPinValue(PA0_PIN , HIGH);
UART_init();
	//Sys_init------------------------------------
	H_PushButton_Void_PushButtonInit(PUSH_BUTTON_3);	// sys_button
	H_LED_Void_LedInit(LED_RED);						//sys led
	//------------------------------
	H_PushButton_Void_PushButtonInit(PUSH_BUTTON_0);	// gas_button
	H_LED_Void_LedInit(LED_YEL);						//Gas led
	//------------------------------
	H_PushButton_Void_PushButtonInit(PUSH_BUTTON_2);	// waiting_button
	H_LED_Void_LedInit(LED_GRN);						//waiting led
	//----------------------------

	H_LED_Void_LedInit(LED_BLU);						//waiting led
	//----------------------------
	M_DIO_Void_SetPinDirection(PC7_PIN, OUTPUT);
	M_DIO_Void_SetPinDirection(PA7_PIN, OUTPUT);
u8 uart_counter=0;
u8 last_read=0;

	while (1)

	{
		//------------------UtralSonic_section---------------
		UtralSonic_trig();

		UtralSonic_RISING_edge(&error_flag_rising);
		/*		 Wait for rising edge */

		TimerOverflow = 0;/* Clear Timer overflow count */
//
		UtralSonic_FAILING_edge(&error_flag_falling);
		if ((error_flag_falling==200000000)||(error_flag_rising==200000000)){

			H_Lcd_Void_LCDGoTo(2, 10);
			H_Lcd_Void_LCDWriteString("fail");


		}

		//_delay_ms(100);

	 	Uart_dataRead = UART_RxChar();

		//_delay_ms(100);

		local_dis = Ultra_get_dis(TimerOverflow);

		H_EEPROM_Void_EEPROMWrite(0,5,(u16)local_dis);
		//_delay_ms(400);
		//H_EEPROM_Void_EEPROMWrite(0,6,((u16)local_dis)>>8);


		if (local_dis > 5 && sys_state == Sys_On) {
			H_LED_Void_LedOn(LED_YEL);
			//	M_DIO_Void_SetPinValue(PB6_PIN , HIGH);        		 //motor enable
		} else if (local_dis < 5 && sys_state == Sys_On) {
			H_LED_Void_LedOff(LED_YEL);
			//	M_DIO_Void_SetPinValue(PB6_PIN , LOW); 			  //motor disable
		}
		if ((sys_state == Sys_Off) && (GAS_STAT ==0)){
			H_LED_Void_LedOff(LED_YEL);
		}

		if ((u8)local_dis==last_read){
			uart_counter++;
			H_Lcd_Void_LCDGoTo(1, 0);
			H_Lcd_Void_LCDWriteNumber(uart_counter);
		}
		else
		{
			H_Lcd_Void_LCDGoTo(0, 0);
			H_Lcd_Void_LCDWriteString("  CCS :    ");
			fail_flag = 0;
			uart_counter=0;
		}

		if ((u8)uart_counter==40){
			uart_counter=0;
			H_Lcd_Void_LCDGoTo(1, 0);
			H_Lcd_Void_LCDWriteNumber(uart_counter);
			H_Lcd_Void_LCDClear();
			H_Lcd_Void_LCDGoTo(0, 8);
			H_Lcd_Void_LCDWriteString(" Ultra Fail");
			fail_flag = 1;
		}
		last_read=local_dis;


		//--------------------------LDR_section--------------------------


		LDR_read =M_ADC_Void_ADCRead(ADC_CHANNEL_0);


		//i=LDR_read/204.8;

		// Now since it’s a 10bit ADC for every Vref(5V)/1024=5mV(4.88mV) we get one digital increment or for every 1V increment in input we get 204.8 count increment. So for finding voltage at ADC pin.

		//LDR = (i*10/(5-i));

		//dtostrf(LDR, 4, 1, LDRSHOW);
		//H_Lcd_Void_LCDGoTo(3,0 );
		//H_Lcd_Void_LCDWriteNumber(LDR_read);
if(LDR_read == 1023)
{
	H_Lcd_Void_LCDClear();
	H_Lcd_Void_LCDGoTo(0, 8);
	H_Lcd_Void_LCDWriteString(" LDR Fail");
	fail_flag = 1;
}
else if (LDR_read>=500){
		H_Lcd_Void_LCDGoTo(1,9 );
		H_Lcd_Void_LCDWriteString( " Night  ");
		fail_flag = 0;
}
else if (LDR_read<500){
		H_Lcd_Void_LCDGoTo(1,9 );
		H_Lcd_Void_LCDWriteString(" Day  ");
		fail_flag = 0;
}


		//H_Lcd_Void_LCDGoTo(1,9 );
		//H_Lcd_Void_LCDWriteString(LDRSHOW);
		//H_Lcd_Void_LCDWriteNumber(LDR_read);
		_delay_ms(50);








		//------------------------------------------------------

/*--------------------------------------------------------------------------------------------------------------------------------------------*/
if(fail_flag == 0){
		dtostrf(local_dis, 2, 2, string);

		H_Lcd_Void_LCDGoTo(2, 0);
		strcat(string, " cm   ");
		H_Lcd_Void_LCDWriteString(string);
		_delay_ms(200);

		//------------------End-UtralSonic_section---------------



		//-------------------------Gas_button_check---------------------------------------

		Pu_0_return_u8 = H_PushButton_U8_PushButtonRead(PUSH_BUTTON_0);

		if (((Pu_0_return_u8 == PUSH_BUTTON_PRESSED) ||(Uart_dataRead=='a')) )// EDIT HERE FOR ULTRA SONIC
		{
			//GAS_STAT;
			GAS_STAT=(GAS_STAT==0)? 1:0 ;   // gas state toggile

		}
		//else if ((Pu_0_return_u8 == PUSH_BUTTON_RELEASED ) && sys_state == Sys_Off) {
		else if ((Pu_0_return_u8 == PUSH_BUTTON_RELEASED ) && sys_state == Sys_Off && (GAS_STAT==0)) {
		H_LED_Void_LedOff(LED_YEL);
			//	M_DIO_Void_SetPinValue(PB6_PIN , LOW);
		}
		if (GAS_STAT==1){
			flag = 1;
						sys_state = Sys_Off;
						H_LED_Void_LedOff(LED_RED);
						H_LED_Void_LedOn(LED_YEL);
						//M_DIO_Void_SetPinValue(PB6_PIN , HIGH);   //motor enable
						H_Lcd_Void_LCDGoTo(0, 12);             //sys on
								H_Lcd_Void_LCDWriteString("   off   ");
						H_EEPROM_Void_EEPROMWrite(0,1,Sys_off_EEPROM);
		}
if (GAS_STAT==0){
	H_LED_Void_LedOff(LED_YEL);
}
		if ((Pu_0_return_u8 == PUSH_BUTTON_PRESSED) &&( local_dis < 5) &&( sys_state == Sys_On)) {
			flag = 1;
			H_LED_Void_LedOff(LED_RED);
			H_LED_Void_LedOn(LED_YEL);
			M_DIO_Void_SetPinValue(PB6_PIN, HIGH);              //motor enable
			H_Lcd_Void_LCDGoTo(0, 12);             //sys on
					H_Lcd_Void_LCDWriteString("   off  ");
			H_EEPROM_Void_EEPROMWrite(0,1,Sys_off_EEPROM);
			sys_state = Sys_Off;
		}

		//-------------END-----Gas_button_check---------------------------------------

		//-----------------CPS_sys_start----------------------------------------------
		Pu_0_return_u8 = H_PushButton_U8_PushButtonRead(PUSH_BUTTON_0);

		if ((Pu_0_return_u8 == PUSH_BUTTON_PRESSED)||Uart_dataRead=='h')// EDIT HERE FOR ULTRA SONIC
		{
			CPS_SYS_STAT=(CPS_SYS_STAT==0)? 1:0 ;   //CPS sys is on

		}

		if ((CPS_SYS_STAT ==1) &&( local_dis < 5)) {
			H_LED_Void_LedOn(LED_BLU);
		}
		if ((CPS_SYS_STAT ==1) &&( local_dis > 5)) {
			H_LED_Void_LedOff(LED_BLU);
		}
		else if (CPS_SYS_STAT ==0){
			H_LED_Void_LedOff(LED_BLU);
		}







		//-----------------CPS_sys_END------------------------------------------------


		//------------sys_activation check--------------------------------------------

		Pu_3_return_u8 = H_PushButton_U8_PushButtonRead(PUSH_BUTTON_3);	//get sys button reading
	//	if ((Pu_3_return_u8 == PUSH_BUTTON_PRESSED) ||((Pu_3_return_u8 == PUSH_BUTTON_PRESSED) && (sys_state == Sys_On))||(Uart_dataRead=='b'))  //check if button is pressed
		if ((Pu_3_return_u8 == PUSH_BUTTON_PRESSED)||Uart_dataRead=='b')
		{
			sys_state=(sys_state==0)? 1:0 ;
		}

		if (sys_state==Sys_On){
			H_LED_Void_LedOn(LED_RED);                      //led on
				//M_Timer_Void_TimerStop2();
				//M_Timer_Void_TimerStop(TIMER0_CHANNEL);
				flag = 0;
				//sys_state = Sys_On;
				H_Lcd_Void_LCDGoTo(0, 12);
				H_Lcd_Void_LCDWriteString("   on ");
				H_EEPROM_Void_EEPROMWrite(0, 1, Sys_on_EEPROM);



				}
						if (sys_state == Sys_Off) {

						//	sys_state = Sys_Off;                      //sys  off
							H_LED_Void_LedOff(LED_RED);
							H_Lcd_Void_LCDGoTo(0, 12);
							H_Lcd_Void_LCDWriteString("   off  ");
							H_EEPROM_Void_EEPROMWrite(0, 1, Sys_off_EEPROM);

						}


		/*

		else if ((Pu_3_return_u8 == PUSH_BUTTON_RELEASED)||( (Pu_3_return_u8 == PUSH_BUTTON_RELEASED) && (sys_state == Sys_On) )||(Uart_dataRead=='c') )//check if button is release

		{
			flag = 0;
			pressCounter=0;
			M_Timer_Void_TimerStop2();
			TCNT2_REG = 0x00;
		}
*/
		//trying to check if button is continously pressed
		/*
		if ()

		{
			buttonPressed = 1;
			if (flag == 0) {
				TCNT2_REG = 0x00;
				M_Timer_Void_SetCallBack2(test_timer);
				M_Timer_Void_TimerStart2();

				flag = 1;
			}



		} else if () //check if button is release
				{
			flag = 0;
			TCNT2_REG = 0x00;
			M_Timer_Void_TimerStop2();

		}*/
//---------------END_section_sys activation check--------------------------------------------

//---------------waiting section-------------------------------------------------------------
		Pu_2_return_u8 = H_PushButton_U8_PushButtonRead(PUSH_BUTTON_2);

		if (waiting_state == 1 ) {
			_delay_ms(30);
			H_LED_Void_LedTog(LED_GRN);
			M_DIO_Void_TogPin(PC7_PIN);
			M_DIO_Void_TogPin(PA7_PIN);
			_delay_ms(30);

		}
		if (((Pu_2_return_u8 == PUSH_BUTTON_PRESSED)|| (Uart_dataRead=='c')) && (waiting_state == 0)) //check if button is pressed
				{
			waiting_state = 1;
			_delay_ms(50);
			H_EEPROM_Void_EEPROMWrite(0,4,Sys_WaitingOn_EEPROM);
			_delay_ms(50);

		}

		else if (((Pu_2_return_u8 == PUSH_BUTTON_PRESSED)|| (Uart_dataRead=='c'))&& (waiting_state == 1)) //check if button is pressed
				{
			_delay_ms(50);
			H_EEPROM_Void_EEPROMWrite(0,4,Sys_WaitingOff_EEPROM);
			_delay_ms(50);
			M_DIO_Void_SetPinValue(PC7_PIN, LOW);
			M_DIO_Void_SetPinValue(PA7_PIN, LOW);
			H_LED_Void_LedOff(LED_GRN);
			waiting_state = 0;
		}

		//---------END------waiting section-------------------------------------------------------------
		}
	}

	return 0;
}

