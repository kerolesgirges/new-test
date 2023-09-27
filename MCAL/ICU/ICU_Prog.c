/*
 * ICU_Prog.c
 *
 *  Created on: Jun 17, 2023
 *      Author: koko_girgis
 */
#include "ICU_interface.h"

#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "ICU_Private.h"
#include <avr/io.h>

void Icu_init(void ){

	M_GIE_Void_GlobalInterruptEnable();
	TIMSK_REG = (1 << 2); /* Enable Timer1 overflow interrupts */
	/* Set all bit to zero Normal operation */
	M_DIO_Void_SetPinDirection(PA1_PIN, OUTPUT);
	M_DIO_Void_SetPinDirection(PD6_PIN, INPUT);
	TCCR1A_REG = 0;
	PORTD_REG = 0xFF;

}

/*
 * Description: Function to set the Call Back function address.
 */
void UtralSonic_trig(void){
	M_DIO_Void_SetPinValue(PA1_PIN, HIGH);
	_delay_us(10);
	M_DIO_Void_SetPinValue(PA1_PIN, LOW);

}
void UtralSonic_RISING_edge(u32 *flag_count_rising){

	TCNT1_REG = 0x00;
	TCCR1B_REG = 0x41;
	TIFR_REG = 1 << 5;
	TIFR_REG = 1 << 2;
	//SET_BIT(TIFR_REG,5);
	//SET_BIT(TIFR_REG,2);
	while ((GET_BIT(TIFR_REG,5) == 0)&&(flag_count_rising<=200000000)){
		flag_count_rising++;
	}

}
void UtralSonic_FAILING_edge(u32 *flag_count_falling){

	TCNT1 = 0; /* Clear Timer counter */
	TCCR1B = 0x01; /* Capture on falling edge, No prescaler */
	TIFR = 1 << ICF1; /* Clear ICP flag (Input Capture flag) */
	TIFR = 1 << TOV1; /* Clear Timer Overflow flag */

	while ( ( (TIFR & (1 << ICF1) ) == 0)&& (flag_count_falling<=200000000)){
		flag_count_falling++;
	}

}
/*
void Ultra_ALL(void)
{
	M_DIO_Void_SetPinValue(PA0_PIN ,HIGH);
	_delay_us(10);
	M_DIO_Void_SetPinValue(PA0_PIN ,LOW);

	TCNT1_REG=0x00;
	TCCR1B_REG=0x41;
	TIFR_REG = 1<<5;
	TIFR_REG = 1<<2;
	//SET_BIT(TIFR_REG,5);
	//SET_BIT(TIFR_REG,2);
	while(GET_BIT(TIFR_REG,5)==0);

	TCNT1_REG=0x00;
	TCCR1B_REG=0x01;

	TIFR_REG = 1<<5;
	TIFR_REG = 1<<2;
	TimerOverflow = 0;

	while(GET_BIT(TIFR_REG,5)==0);

	local_count=ICR1_REG+(65535*TimerOverflow);
	local_dis=(((double)local_count)/933.0);

	dtostrf(local_dis, 2, 2, string);
	H_Lcd_Void_LCDGoTo(2,0);
	H_Lcd_Void_LCDWriteString(string);
	_delay_ms(200);


}*/


double Ultra_get_dis(u32 over){
long local_count;
double local_dis;
local_count = ICR1_REG + (65535 * over);
local_dis = (((double) local_count) / 933.0);
return local_dis;
}
/*
 * Description: Function to set the required edge detection.
 */


