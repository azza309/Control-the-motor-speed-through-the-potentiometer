/*
 * adc.h
 *
 *  Created on: 3/6/2021
 *      Author: AZZA OMARA
 */

#ifndef ADC_H_
#define ADC_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"
extern volatile uint16 g_adcResult;
typedef enum
{
  ADC_0,ADC_1,ADC_2,ADC_3,ADC_4,ADC_5,ADC_6,ADC_7
}ADC_channel;

typedef enum
{
	AREF,AVCC,INTERNAL= 3
}ADC_reference;


typedef enum
{
	Polling,Interrupt
}ADC_mode;

typedef enum
{
	NO_prescaler,F_CPU_2,F_CPU_4,F_CPU_8_,F_CPU_16,F_CPU_32,F_CPU_64_,F_CPU_128
}ADC_prescaler;

typedef struct
{
	ADC_channel   channel;
	ADC_reference reference;
	ADC_mode      mode;
	ADC_prescaler Division;
}ADC_configType;


/* FUN for init ADC driver */

void ADC_init(const ADC_configType * config_Ptr);

/*FUN for read analog data from a certain ADC channel and convert to digital using ADC*/

uint16 ADC_readChannel(const ADC_configType * config_Ptr);

#endif
