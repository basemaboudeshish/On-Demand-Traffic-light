/*
 * Timer.c
 *
 * Created: 9/29/2022 1:39:07 PM
 *  Author: Family
 */ 

#include "Timer.h"
#include <stdint.h>

// Timer for 1 second
void TIMER_1s(void)
{
	uint64_t overflowCounter_1sec = 0;
	uint64_t Num_overflows = 0;
	
	// Choose timer 2 mode to be normal mode
	TCCR2 = 0x00;
	
	// Timer/Counter2, Overflow Interrupt Enable
	TIMSK |= (1<<6);

	// Time is 2 second and no prescaler with 1MHZ
	Num_overflows = (1000/(0.000256))+1;
	
	// Timer set initial value
	TCNT2 = (256 - ((1000 * 1000000) / Num_overflows));

	// Timer start -> setting the clock source
	TCCR2 |= (1<<0);
	while(overflowCounter_1sec < Num_overflows)
	{
		// it will be repeated N times then it will stop
		// wait till the overflow flag is set
		while((TIFR & (1<<2)) == 0);
		
		// Clear the overflow flag
		TIFR |= (1<<6);
		overflowCounter_1sec++;
	}
	overflowCounter_1sec  = 0;
		
}

void TIMER_1s_stop(void)
{
	// Timer stop
	TCCR2 = 0X00;
}

void TIMER_delay(uint64_t time_ms)
{

uint64_t overflowCounter_=0;
uint64_t Num_overflows_ = 0;
	
// Choose timer 0 mode to be normal mode
TCCR0 = 0x00;

// Time in Milliseconds and no prescaler with 1MHZ
Num_overflows_ = (time_ms/(0.000256))+1;

// Timer set initial value
TCNT0 = (256 - ((time_ms * 1000000) / Num_overflows_));


// Timer start -> setting the clock source
TCCR0 |= (1<<0); 
   while(overflowCounter_ < Num_overflows_)
   {
	// it will be repeated N times then it will stop 
	// wait till the overflow flag is set
	while((TIFR & (1<<0)) == 0);
	
	// Clear the overflow flag
	TIFR |= (1<<0) | (1<<1);
	overflowCounter_++;
    }
    overflowCounter_  = 0;
	
	// Timer stop
	TCCR0 = 0X00;
	

}
