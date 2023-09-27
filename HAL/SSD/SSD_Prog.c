/*
 * SSD_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

/*============================================================================================*/
/*   INCLUDES   */
/*============================================================================================*/
#include "SSD_Config.h"
#include "SSD_Interface.h"

/*============================================================================================*/
/*   FUNCTION BODY   */
/*============================================================================================*/
void H_SSD_Void_SSDInit(void)
{
	M_DIO_Void_SetPinDirection(SSD_A_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(SSD_B_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(SSD_C_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(SSD_D_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(SSD1_EN_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(SSD2_EN_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(SSD3_EN_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(SSD4_EN_PIN,OUTPUT);
	M_DIO_Void_SetPinValue(SSD1_EN_PIN,HIGH);
	M_DIO_Void_SetPinValue(SSD2_EN_PIN,HIGH);
	M_DIO_Void_SetPinValue(SSD3_EN_PIN,HIGH);
	M_DIO_Void_SetPinValue(SSD4_EN_PIN,HIGH);

}

/*============================================================================================*/
/*   FUNCTION BODY   */
/*============================================================================================*/
void H_SSD_Void_SSDDisplay(u32 Copy_U32_Num)
{
	u8 Local_U8_1    =  Copy_U32_Num % 10;
	u8 Local_U8_10   = (Copy_U32_Num / 10) % 10;
	u8 Local_U8_100  = (Copy_U32_Num / 100) % 10;
	u8 Local_U8_1000 =  Copy_U32_Num / 1000;
	u32 Local_U16_Counter = 0;
	for(Local_U16_Counter = 0 ; Local_U16_Counter < SSD_DISPLAY_TIME ; Local_U16_Counter++)
	{
		M_DIO_Void_SetPinValue(SSD_A_PIN,GET_BIT(Local_U8_1,0));
		M_DIO_Void_SetPinValue(SSD_B_PIN,GET_BIT(Local_U8_1,1));
		M_DIO_Void_SetPinValue(SSD_C_PIN,GET_BIT(Local_U8_1,2));
		M_DIO_Void_SetPinValue(SSD_D_PIN,GET_BIT(Local_U8_1,3));
		M_DIO_Void_SetPinValue(SSD1_EN_PIN,LOW);
		_delay_ms(1);
		M_DIO_Void_SetPinValue(SSD1_EN_PIN,HIGH);

		M_DIO_Void_SetPinValue(SSD_A_PIN,GET_BIT(Local_U8_10,0));
		M_DIO_Void_SetPinValue(SSD_B_PIN,GET_BIT(Local_U8_10,1));
		M_DIO_Void_SetPinValue(SSD_C_PIN,GET_BIT(Local_U8_10,2));
		M_DIO_Void_SetPinValue(SSD_D_PIN,GET_BIT(Local_U8_10,3));
		M_DIO_Void_SetPinValue(SSD2_EN_PIN,LOW);
		_delay_ms(1);
		M_DIO_Void_SetPinValue(SSD2_EN_PIN,HIGH);

		M_DIO_Void_SetPinValue(SSD_A_PIN,GET_BIT(Local_U8_100,0));
		M_DIO_Void_SetPinValue(SSD_B_PIN,GET_BIT(Local_U8_100,1));
		M_DIO_Void_SetPinValue(SSD_C_PIN,GET_BIT(Local_U8_100,2));
		M_DIO_Void_SetPinValue(SSD_D_PIN,GET_BIT(Local_U8_100,3));
		M_DIO_Void_SetPinValue(SSD3_EN_PIN,LOW);
		_delay_ms(1);
		M_DIO_Void_SetPinValue(SSD3_EN_PIN,HIGH);


		M_DIO_Void_SetPinValue(SSD_A_PIN,GET_BIT(Local_U8_1000,0));
		M_DIO_Void_SetPinValue(SSD_B_PIN,GET_BIT(Local_U8_1000,1));
		M_DIO_Void_SetPinValue(SSD_C_PIN,GET_BIT(Local_U8_1000,2));
		M_DIO_Void_SetPinValue(SSD_D_PIN,GET_BIT(Local_U8_1000,3));
		M_DIO_Void_SetPinValue(SSD4_EN_PIN,LOW);
		_delay_ms(1);
		M_DIO_Void_SetPinValue(SSD4_EN_PIN,HIGH);
	}
}
