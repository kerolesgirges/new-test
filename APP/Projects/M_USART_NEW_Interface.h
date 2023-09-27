/*
 * M_USART_NEW_Interface.h
 *
 *  Created on: Jun 25, 2023
 *      Author: Mohamed
 */

#ifndef MCAL_NEW_USART_M_USART_NEW_INTERFACE_H_
#define MCAL_NEW_USART_M_USART_NEW_INTERFACE_H_

#include "avr/io.h"
#define F_CPU 16000000UL
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)


void UART_init(void);


unsigned char UART_RxChar();

void UART_TxChar(char ch);


void UART_SendString(char *str);

#endif /* MCAL_NEW_USART_M_USART_NEW_INTERFACE_H_ */
