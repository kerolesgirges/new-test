/*
 * ADC_NEW_config.h
 *
 *  Created on: Jun 12, 2023
 *      Author: koko_girgis
 */

#ifndef MCAL_ADC_NEW_CONFIG_ADC_NEW_CONFIG_H_
#define MCAL_ADC_NEW_CONFIG_ADC_NEW_CONFIG_H_

#define AREF 0
#define AVCC 1
#define INTERNAL 2

/*
0--->AREF,internal_Vref_turned_off
1--->AVCC_with_external_capacitor,AT_vref_pin
2--->internal(2.56V)_with_external_capacitor,AT_vref_pin
*/
#define Vol_Ref  AREF
/************************************************/
/*
0--->left_addjustment
1--->right_addjustment
*/

#define left_addjustment 0
#define right_addjustment 1

#define ADC_adjust  right_addjustment
/***********************************************/
/*
2
4
8
16
32
64
128
*/
#define ADC_PRE_2	0
#define ADC_PRE_4	1
#define ADC_PRE_8	2
#define ADC_PRE_16	3
#define ADC_PRE_32	4
#define ADC_PRE_64	5
#define ADC_PRE_128	6

#define ADC_Prescaler ADC_PRE_64
/***********************************************/



#endif /* MCAL_ADC_NEW_CONFIG_ADC_NEW_CONFIG_H_ */
