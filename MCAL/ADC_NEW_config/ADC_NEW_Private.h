/*
 * ADC_NEW_Private.h
 *
 *  Created on: Jun 12, 2023
 *      Author: koko_girgis
 */

#ifndef MCAL_ADC_NEW_CONFIG_ADC_NEW_PRIVATE_H_
#define MCAL_ADC_NEW_CONFIG_ADC_NEW_PRIVATE_H_
//------------------------------------
#define	 ADCSRA_ADPS0		0
#define	 ADCSRA_ADPS1		1
#define	 ADCSRA_ADPS2		2
#define	 ADCSRA_ADIE		3
#define	 ADCSRA_ADIF		4
#define	 ADCSRA_ADATE		5
#define	 ADCSRA_ADSC	 	6
#define	 ADCSRA_ADEN		7

//------------------------------------
#define	 ADMUX_MUX0	0
#define	 ADMUX_MUX1	1
#define	 ADMUX_MUX2	2
#define	 ADMUX_MUX3	3
#define	 ADMUX_MUX4	4
#define	 ADMUX_ADLAR	5
#define	 ADMUX_REFS0 	6
#define	 ADMUX_REFS1	7

//------------------------------------

#define	 SFIOR_ADTS0	5
#define	 SFIOR_ADTS1 	6
#define	 SFIOR_ADTS2	7



//- ---------------Register def ------------------------------

#define ADMUX_NEW	(*(volatile u8*)0x27)
#define ADCSRA_NEW	(*(volatile u8*)0x26)
#define ADC_NEW		(*(volatile u16*)0x24)
#define SFIOR_NEW	(*(volatile u8*)0x50)






#endif /* MCAL_ADC_NEW_CONFIG_ADC_NEW_PRIVATE_H_ */
