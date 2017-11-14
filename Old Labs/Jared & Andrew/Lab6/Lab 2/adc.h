/*
 * adc.h
 *
 *  Created on: Oct 5, 2017
 *      Author: jdanner
 */

#ifndef ADC_H_
#define ADC_H_

#include <inc/tm4c123gh6pm.h>
#include "lcd.h"

void adc_Start();

void adc_Stop();

int adc_Read();



#endif /* ADC_H_ */