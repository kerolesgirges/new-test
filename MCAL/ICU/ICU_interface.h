/*
 * ICU_interface.h
 *
 *  Created on: Jun 17, 2023
 *      Author: koko_girgis
 */

#ifndef MCAL_ICU_ICU_INTERFACE_H_
#define MCAL_ICU_ICU_INTERFACE_H_

/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/

#include "BitMath.h"
#include "STD.h"
#include "GIE_Interface.h"
#include <util/delay.h>
/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}Icu_Clock;

typedef enum
{
	FALLING,RISING
}Icu_EdgeType;

typedef struct
{
	Icu_Clock clock;
	Icu_EdgeType edge;
}Icu_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


void Icu_init(void );

/*
 * Description: Function to set the Call Back function address.
 */
void UtralSonic_trig(void);
void UtralSonic_RISING_edge(u32 *flag_count_rising);
void UtralSonic_FAILING_edge(u32 *flag_count_falling);
double Ultra_get_dis(u32 over);
void Ultra_ALL(void);

/*
 * Description: Function to set the required edge detection.
 */


#endif /* MCAL_ICU_ICU_INTERFACE_H_ */
