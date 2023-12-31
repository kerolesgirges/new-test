/*
 * ADC_NEW_PROG.c

 *
 *  Created on: Jun 12, 2023
 *      Author: koko_girgis
 */

#include "ADC_NEW_interface.h"

void ADC_NEW_init(void) {
#if (Vol_Ref==AREF)
CLR_BIT	(ADMUX_NEW,ADMUX_REFS0);
CLR_BIT	(ADMUX_NEW,ADMUX_REFS1);
#elif (Vol_Ref==AVCC)
SET_BIT(ADMUX_NEW,ADMUX_REFS0);
CLR_BIT	(ADMUX_NEW,ADMUX_REFS1);
#elif (Vol_Ref==INTERNAL)
SET_BIT	(ADMUX_NEW,ADMUX_REFS0);
SET_BIT	(ADMUX_NEW,ADMUX_REFS1);
#endif


#if (ADC_Prescaler==ADC_PRE_2)
SET_BIT(ADCSRA_NEW,ADCSRA_ADPS0);
CLR_BIT	(ADCSRA_NEW,ADCSRA_ADPS1);
CLR_BIT	(ADCSRA_NEW,ADCSRA_ADPS2);

#elif(ADC_Prescaler==ADC_PRE_4)

CLR_BIT	(ADCSRA_NEW,ADCSRA_ADPS0);
SET_BIT(ADCSRA_NEW,ADCSRA_ADPS1);
CLR_BIT	(ADCSRA_NEW,ADCSRA_ADPS2);

#elif(ADC_Prescaler==ADC_PRE_8)
SET_BIT	(ADCSRA_NEW,ADCSRA_ADPS0);
SET_BIT(ADCSRA_NEW,ADCSRA_ADPS1);
CLR_BIT	(ADCSRA_NEW,ADCSRA_ADPS2);
#elif(ADC_Prescaler==ADC_PRE_16)
CLR_BIT	(ADCSRA_NEW,ADCSRA_ADPS0);
CLR_BIT(ADCSRA_NEW,ADCSRA_ADPS1);
SET_BIT	(ADCSRA_NEW,ADCSRA_ADPS2);

#elif(ADC_Prescaler==ADC_PRE_32)
SET_BIT	(ADCSRA_NEW,ADCSRA_ADPS0);
CLR_BIT(ADCSRA_NEW,ADCSRA_ADPS1);
SET_BIT	(ADCSRA_NEW,ADCSRA_ADPS2);
#elif(ADC_Prescaler==ADC_PRE_64)
CLR_BIT	(ADCSRA_NEW,ADCSRA_ADPS0);
SET_BIT(ADCSRA_NEW,ADCSRA_ADPS1);
SET_BIT	(ADCSRA_NEW,ADCSRA_ADPS2);
#elif(ADC_Prescaler==ADC_PRE_128)
SET_BIT	(ADCSRA_NEW,ADCSRA_ADPS0);
SET_BIT(ADCSRA_NEW,ADCSRA_ADPS1);
SET_BIT	(ADCSRA_NEW,ADCSRA_ADPS2);
#endif

#if (ADC_adjust == left_addjustment )
SET_BIT	(ADMUX_NEW,ADMUX_ADLAR);
#elif (ADC_adjust == right_addjustment )
CLR_BIT	(ADMUX_NEW,ADMUX_ADLAR);

#endif
SET_BIT(ADCSRA_NEW,ADCSRA_ADEN);
}
u8   ADC_NEW_read(u8 ADC_chanel_num){
	u16 ADC_res =0;

	ADC_chanel_num &=0x07;       //chancel from 0 to 7
	ADMUX_NEW &=0xE0;
	ADMUX_NEW |=ADC_chanel_num;

	SET_BIT(ADCSRA_NEW,ADCSRA_ADSC); // start convertion
	while ( GET_BIT(ADCSRA_NEW,ADCSRA_ADIF) );
	SET_BIT(ADCSRA_NEW,ADCSRA_ADIF);
#if (ADC_adjust==left_addjustment)
	ADC_res =	(ADC_NEW>>6);
#elif(ADC_adjust==right_addjustment)
	ADC_res = ADC_NEW;
#endif

return ADC_res;

}

