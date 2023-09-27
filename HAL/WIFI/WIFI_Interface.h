/*
 * WIFI_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_WIFI_WIFI_INTERFACE_H_
#define HAL_WIFI_WIFI_INTERFACE_H_

/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "UART_Interface.h"

/*--------------------------------------------------------------------------------------------*/
/*   PROTOTYPES   */
/*--------------------------------------------------------------------------------------------*/
void H_WIFI_Void_WIFIInit(void);
void H_WIFI_Void_WIFIWriteCharacter(u8);
void H_WIFI_Void_WIFIWriteString(u8*);
u8   H_WIFI_U8_WIFIRead(void);

#endif /* HAL_WIFI_WIFI_INTERFACE_H_ */
