/*
 * Interrupt.h
 *
 * Created: 9/30/2022 4:49:30 PM
 *  Author: Family
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

// Vector Macros

#define EXT_INT_0    __vector_1
#define TIMER2_OVF_vect   __vector_6

#include "../Utilities/registers.h"

//External interrupt 0 initialization
void ext_int0_setup(void);

//External interrupt 0 disable
void ext_int0_disable(void);



#endif /* INTERRUPT_H_ */