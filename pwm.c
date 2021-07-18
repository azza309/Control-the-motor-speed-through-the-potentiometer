/*
 * pwm.c
 *
 *  Created on: 2/6/2021
 *      Author: AZZA OMARA
 */


#include "pwm.h"

uint8  F_initCount_T0 = 0;
uint16 F_initCount_T1 = 0;
uint8  F_initCount_T2 = 0;
uint8 F_OCR0;
uint8 F_OCR1;
uint8 F_OCR2;

void PWM_init(const PWM_ConfigerType * configer_Ptr)
{
	if((configer_Ptr->whichTimer) == TIMER_0)
	{
		SET_BIT(DDRB,PB3);
		TCNT0 = F_initCount_T0;
		OCR0  = F_OCR0;
		SET_BIT(TCCR0,WGM01);
		SET_BIT(TCCR0,WGM00);
		TCCR0 = (TCCR0 & 0xCF) | ((configer_Ptr->mode)<<4);
		TCCR0 = (TCCR0 & 0xF8) | (configer_Ptr->clock);
	}
	else if((configer_Ptr->whichTimer) == TIMER_1)
	{

	}
	else if((configer_Ptr->whichTimer) == TIMER_2)
	{
		SET_BIT(DDRD,PB7);
		TCNT2 = F_initCount_T2;
		OCR2  = F_OCR2;
		SET_BIT(TCCR2,WGM21);
		SET_BIT(TCCR2,WGM20);
		TCCR2 = (TCCR2 & 0xCF) | ((configer_Ptr->mode)<<4);
		TCCR2 = (TCCR2 & 0xF8) | (configer_Ptr->clock);
	}
}

void PWM_changeDuty(const PWM_ConfigerType * configer_Ptr,uint8 a_duty)
{
	if((configer_Ptr->whichTimer) ==TIMER_0)
	{
		OCR0 = a_duty;
	}
	else if((configer_Ptr->whichTimer) ==TIMER_1)
	{

	}
	else if((configer_Ptr->whichTimer) ==TIMER_2)
	{
		OCR2 = a_duty;
	}
}
