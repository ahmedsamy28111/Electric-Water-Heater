/*
 * TIMER_Program.c
 *
 *   
 *      Author: Ahmed Samy
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"TIMER_Private.h"
#include"TIMER_Config.h"

void TIMER0_voidInit(void)
{
	/*SET TIMER0 Mode*/
#if TIMER0_MODE==TIMER0_OVERFLOW_MODE
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
	/*OVERFLOW INTERRUPT ENABLE*/
	SET_BIT(TIMSK,0);

#elif TIMER0_MODE==TIMER0_CTC_MODE
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	/*CTC INTERRUPT ENABLE*/
	SET_BIT(TIMSK,1);
	#if TIMER0_CTC_MODE_OC0_MODE==TIMER0_CTC_MODE_OC0_OFF
		CLR_BIT(TCCR0,5);
		CLR_BIT(TCCR0,4);
	#elif TIMER0_CTC_MODE_OC0_MODE==TIMER0_CTC_MODE_OC0_TOGGLE
		CLR_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);
	#elif TIMER0_CTC_MODE_OC0_MODE==TIMER0_CTC_MODE_OC0_SET
		SET_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);
	#elif TIMER0_CTC_MODE_OC0_MODE==TIMER0_CTC_MODE_OC0_CLR
		SET_BIT(TCCR0,5);
		CLR_BIT(TCCR0,4);
	#else
		#error "TIMER0 CTC MODE OC0 PIN Options invalid....."
	#endif
#elif TIMER0_MODE==TIMER0_FAST_PWM
		SET_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);

	#if TIMER0_PWM_OC0_PIN_MODE == TIMER0_PWM_NON_INVERTING
		SET_BIT(TCCR0,5);
		CLR_BIT(TCCR0,4);
	#elif TIMER0_PWM_OC0_PIN_MODE == TIMER0_PWM_INVERTING
		SET_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);
	#else
		#error "TIMER0 PWM OC0 PIN MODE Options invalid....."
	#endif

#elif TIMER0_MODE==TIMER0_PHASE_CORRECT_PWM
		SET_BIT(TCCR0,6);
		CLR_BIT(TCCR0,3);
	#if TIMER0_PWM_OC0_PIN_MODE == TIMER0_PWM_NON_INVERTING
		SET_BIT(TCCR0,5);
		CLR_BIT(TCCR0,4);
	#elif TIMER0_PWM_OC0_PIN_MODE == TIMER0_PWM_INVERTING
		SET_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);
	#else
		#error "TIMER0 PWM OC0 PIN MODE Options invalid....."
	#endif

#else
#error"TIMER0 MODE Options invalid....."

#endif
/*SET suitable Prescaler*/
		TCCR0&=0xF8;
		TCCR0|=TIMER0_PRESCALER;
		OCR0=250;

}
void TIMER0_voidSetPreLoadValue(u8 Copy_u8Preload)
{
	TCNT0=Copy_u8Preload;
}
void TIMER0_voidSetCTCRegister(u8 Copy_u8CTC_Value)
{
	OCR0=Copy_u8CTC_Value;
}


/////timer1
void TIMER1_voidInit(void)
{
SET_BIT(TCCR1B,3);


	// PUT Value in OCR1A
	OCR1AH = 0b00000000;
	OCR1AL = 0b01100010;

	// Select Clock Prescaler 1024
	SET_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);
}
