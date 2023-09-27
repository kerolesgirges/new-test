/*
 * ICU_Private.h
 *
 *  Created on: Jun 17, 2023
 *      Author: koko_girgis
 */

#ifndef MCAL_ICU_ICU_PRIVATE_H_
#define MCAL_ICU_ICU_PRIVATE_H_


/*   REGISTERS   */

#define TCCR1A_REG    *(volatile u8*)0x4F
#define TCCR1B_REG    *(volatile u8*)0x4E
#define TIMSK_REG     *(volatile u8*)0x59
#define TCNT1_REG     *(volatile u8*)0x4C
#define OCR1A_REG     *(volatile u16*)0x4A
#define OCR1B_REG     *(volatile u16*)0x48
#define ICR1_REG      *(volatile u16*)0x46
#define TIFR_REG      *(volatile u8*)0x58


/*   TCCR1A BITS   */
#define COM1A1_BIT                 7
#define COM1A0_BIT                 6
#define WGM11_BIT                  1
#define WGM10_BIT                  0

/*   TCCR1B BITS   */
#define WGM13_BIT                  4
#define WGM12_BIT                  3
#define CS12_BIT                   2
#define CS11_BIT                   1
#define CS10_BIT                   0
#define ICES1_BIT                   6
/*   TIMSK BITS   */
#define OCIE0_BIT                  1
#define TOIE0_BIT                  0




#endif /* MCAL_ICU_ICU_PRIVATE_H_ */
