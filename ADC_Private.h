/*
 * ADC_Private.h
 *
 *  
 *      Author: Ahmed Samy
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADC_AVCC        0
#define ADC_INTERNAL_2  1

#define ADC_LEFT_ADJUST   1
#define ADC_RIGHT_ADJUST  0

#define ADMUX    *((volatile u8*)0x27)
#define ADCSRA   *((volatile u8*)0x26)
#define ADC      *((volatile u16*)0x24)

#endif /* ADC_PRIVATE_H_ */
