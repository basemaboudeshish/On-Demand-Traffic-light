/*
 * Interrupt.c
 *
 * Created: 9/30/2022 4:49:11 PM
 *  Author: Family
 */ 

#include "Interrupt.h"


void ext_int0_setup(void)
{

	// 1- Enable global interrupts
	SREG |= (1<<7);
	
	// 2- External interrupt INT0 sense on rising edge
	MCUCR |= (1<<0) | (1<<1);
	
	// 3- Enable External interrupt 0 -INT0
	GICR |= (1<<6);
}

void ext_int0_disable(void)
{
	// Disable External interrupt 0 -INT0
	GICR |= (0<<6);
}

