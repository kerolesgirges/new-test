/*
 * ADC_NEW_interface.h
 *
 *  Created on: Jun 12, 2023
 *      Author: koko_girgis
 */
/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "STD.h"
#include "BitMath.h"
#include "ADC_NEW_config.h"
#include "ADC_NEW_Private.h"

#ifndef MCAL_ADC_NEW_CONFIG_ADC_NEW_INTERFACE_H_
#define MCAL_ADC_NEW_CONFIG_ADC_NEW_INTERFACE_H_

#define ADC_NEW_CH_1	0
#define ADC_NEW_CH_2	1
#define ADC_NEW_CH_3	2
#define ADC_NEW_CH_4	3
#define ADC_NEW_CH_5	4
#define ADC_NEW_CH_6	5
#define ADC_NEW_CH_7	6
#define ADC_NEW_CH_8	7


void ADC_NEW_init(void) ;
u8   ADC_NEW_read(u8 ADC_chanell);

#endif /* MCAL_ADC_NEW_CONFIG_ADC_NEW_INTERFACE_H_ */
