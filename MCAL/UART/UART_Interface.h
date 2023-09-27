/*
 * UART_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "BitMath.h"
#include "DIO_Interface.h"
#include "STD.h"

/*--------------------------------------------------------------------------------------------*/
/*   PROTOTYPES   */
/*--------------------------------------------------------------------------------------------*/
void M_UART_Void_UARTInit(void);
void M_UART_Void_UARTWriteCharacter(u8);
void M_UART_Void_UARTWriteString(u8*);
u8   M_UART_U8_UARTReadCharacter(void);

#endif /* MCAL_UART_UART_INTERFACE_H_ */
