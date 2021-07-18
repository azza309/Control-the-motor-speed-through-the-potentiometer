/*
 * interrupt.h
 *
 *  Created on: 2/6/2021
 *      Author: AZZA OMARA
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"

typedef enum
{
	INTERRUPT_0,INTERRUPT_1,INTERRUPT_2
}INTERRUPT_numberType;

typedef enum
{
	LOW_LEVEL,ANY_CHANGE,FALLING_EDGE,RISING_EDGE
}INTERRUPT_mode;

typedef struct
{
	INTERRUPT_numberType INTERRUPT_number;
	INTERRUPT_mode       mode;
}INTERRUPT_configType;


void INTERRUPT_init(const INTERRUPT_configType * config_Ptr);
void INTERRUPT_callBack(void (*a_ptr)(void));

#endif
