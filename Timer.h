/*
 * Timer.h
 *
 * Created: 9/29/2022 1:41:39 PM
 *  Author: Family
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <math.h>
#include "../MCAL/Interrupt/Interrupt.h"
#include "../Utilities/registers.h"
#include <stdint.h>


void TIMER_delay(uint64_t Time);
void TIMER_1s(void);
void TIMER_1s_stop(void);


#endif /* TIMER_H_ */