/*
 * M_USART_NEW_Prog.c
 *
 *  Created on: Jun 25, 2023
 *      Author: Mohamed
 */

#include "M_USART_NEW_Interface.h"
#define BAUD_PRESCALE (((F_CPU / (9600 * 16UL))) - 1)

#include "STD.h"
void UART_init(void)
{
	UCSRB |= (1 << RXEN) | (1 << TXEN);/* Turn on transmission and reception */
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);/* Use 8-bit character sizes */
	UBRRL = BAUD_PRESCALE;		/* Load lower 8-bits of the baud rate value */
	UBRRH = (BAUD_PRESCALE >> 8);	/* Load upper 8-bits*/


}

unsigned char UART_RxChar()
{
	int counter=0;
	while ( ((UCSRA & (1 << RXC)) == 0) && (counter<2000)){/* Wait till data is received */
		counter++;
	}
	return(UDR);			/* Return the byte*/
}
void UART_TxChar(char ch)
{
	while (! (UCSRA & (1<<UDRE)));	/* Wait for empty transmit buffer*/
	UDR = ch ;
}

void UART_SendString(char *str)
{
	unsigned char j=0;

	while (str[j]!=0)		/* Send string till null */
	{
		UART_TxChar(str[j]);
		j++;
	}
}
