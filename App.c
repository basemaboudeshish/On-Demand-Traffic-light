/*
 * App.c
 *
 * Created: 9/29/2022 1:34:12 PM
 *  Author: Family
 */ 

#include "App.h"
#include "../MCAL/DIO/DIO.h"
#include "../ECUAL/LEDs/LEDs.h"
#include <stdint.h>

    // Declaring and initialize variables //
	int counter;
	uint8_t *Status1, *Status2;
    
    // write all instructions that will run only one time

void APP_init (void)
{
	// Initialization LEDs for cars traffic light 
	LED_init(0, PORT_A);
	LED_init(1, PORT_A);
	LED_init(2, PORT_A);
	
	// Initialization LEDs for pedestrians traffic light
	LED_init(0, PORT_B);
	LED_init(1, PORT_B);
	LED_init(2, PORT_B);
	
	// Initialization buttons for pedestrians traffic light 
	pedbutton_init(2, PORT_D);	
	
	// Initialization for external interrupt 0
	ext_int0_setup();
}

// Application start function
void APP_start(void)
{
	//stop timer
	TIMER_1s_stop();
	// counter reset
	counter == 0;
	//Clear PORT A pins
	LED_OFF(0, PORT_A);
	LED_OFF(1, PORT_A);
	LED_OFF(2, PORT_A);
	//Clear PORT B pins
	LED_OFF(0, PORT_B);
	LED_OFF(1, PORT_B);
	LED_OFF(2, PORT_B);
	// Normal mode
	normal_mode();
}


	
// Normal mode function for both Cars and pedestrian traffic lights
void normal_mode(void)
{
	while(1)
	{
		// red cars light on
		LED_ON(0, PORT_A);
		// green pedestrian light on
		LED_ON(2, PORT_B);
		// External Interrupt 0 disable during timer execution
		void ext_int0_disable(void);
		// Timer delay
		TIMER_delay(5000);
		// Reinitialize external interrupt 0 after timer execution
		void ext_int0_setup(void);
		// red cars light off
		LED_OFF(0, PORT_A);
		// green cars light off
		LED_OFF(2, PORT_B);
		// yellow cars light blinking
		LED_toggle(1, PORT_A);
		// yellow pedestrian light on
		LED_toggle(1, PORT_B);
		// green cars light on
		LED_ON(2, PORT_A);
		// red pedestrian light on
		LED_ON(0, PORT_B);
		// External Interrupt 0 disable during timer execution
		void ext_int0_disable(void);
		// Timer delay
		TIMER_delay(5000);
		// Reinitialize external interrupt 0 after timer execution
		void ext_int0_setup(void);
		// green cars light off
		LED_OFF(2, PORT_A);
		// red pedestrian light off
		LED_OFF(0, PORT_B);
	}
}


// 1 second timer start
    void presstime(void)
	{
		// start timer 1 that counts 1 second
		while (1)
		{
			TIMER_1s();
		}
	}

// Pedestrian mode function
void pedestrian_mode(void)
{
	// starting timer to calculate the time of button press
	presstime();
	
	// story 1,2 ,&3: when the pedestrian made a short press on pedestrian button assuming it is from 1 second to less than 10 seconds
	if ((counter > 3906251) && (counter < 39062510))
	{

		// story 1: when cars green light is ON
		DIO_read(2, PORT_A, Status1);
		if(*Status1 == HIGH)
		{
				// pedestrian red light is ON
				LED_ON(0, PORT_B);
				// cars yellow light is blinking for 5 seconds
				LED_toggle(1, PORT_A);
				// pedestrian yellow light is blinking for 5 seconds
				LED_toggle(1, PORT_B);
				// cars red light is ON
				LED_ON(0, PORT_A);
				// pedestrian green light is ON
				LED_ON(2, PORT_B);
				// External Interrupt 0 disable during timer execution
				void ext_int0_disable(void);
				TIMER_delay(5000);
				// Reinitialize external interrupt 0 after timer execution
				void ext_int0_setup(void);
				// cars red light is OFF
				LED_OFF(0, PORT_A);
				// cars yellow light is blinking for 5 seconds
				LED_toggle(1, PORT_A);
				// pedestrian yellow light is blinking for 5 seconds
				LED_toggle(1, PORT_B);
				// pedestrian green light is OFF
				LED_ON(2, PORT_B);
				// pedestrian red light is ON
				LED_ON(0, PORT_A);
				// cars green light is ON
				LED_ON(2, PORT_A);
				return;
				
		}
		// story 2: when cars yellow light is blinking
		DIO_read(1, PORT_A, Status1);
		if(*Status1 == HIGH)
		{
				// pedestrian red light is ON
				LED_ON(0, PORT_B);
				// cars yellow light is blinking for 5 seconds
				LED_toggle(1, PORT_A);
				// pedestrian yellow light is blinking for 5 seconds
				LED_toggle(1, PORT_B);
				// cars red light is ON
				LED_ON(0, PORT_A);
				// pedestrian green light is ON
				LED_ON(2, PORT_B);
				// External Interrupt 0 disable during timer execution
				void ext_int0_disable(void);
				TIMER_delay(5000);
				// Reinitialize external interrupt 0 after timer execution
				void ext_int0_setup(void);
				// cars red light is OFF
				LED_OFF(0, PORT_A);
				// cars yellow light is blinking for 5 seconds
				LED_toggle(1, PORT_A);
				// pedestrian yellow light is blinking for 5 seconds
				LED_toggle(1, PORT_B);
				// pedestrian green light is OFF
				LED_ON(2, PORT_B);
				// pedestrian red light is ON
				LED_ON(0, PORT_A);
				// cars green light is ON
				LED_ON(2, PORT_A);
				return;
			}
		// story 3: when cars red light is ON and pedestrian green light is ON
		DIO_read(0, PORT_A, Status1);
		DIO_read(2, PORT_B, Status2);
		if((*Status1 == HIGH) && (*Status2 == HIGH))
		{
				// External Interrupt 0 disable during timer execution
				void ext_int0_disable(void);
				// start 5 seconds delay
				TIMER_delay(5000);
				// Reinitialize external interrupt 0 after timer execution
				void ext_int0_setup(void);
				return;
		}
		else 
		{
			return;
		}
	}
	// story 4: when the pedestrian made a long press considering the long press is equal to or more than 10 seconds
	else if(counter > 39062510)
	{
		// Do nothing
		return;
	}
	// story 5: when the pedestrian made a double press while INTF0: External Interrupt Flag 0 is set, just ignore it
	else if(((GIFR & (1<<6))>>6)==1)
	{
		// 2 seconds delay
		TIMER_delay(2000);
		return;
	}
	
	else  
	{
		return;
	}
	return;
}
		
		
	
