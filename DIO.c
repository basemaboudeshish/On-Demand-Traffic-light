/*
 * DIO.c
 *
 * Created: 9/29/2022 1:37:41 PM
 *  Author: Family
 */ 

#include "DIO.h"


uint64_t time_ms;

void DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction)
{
	switch(portNumber)
	{
		case PORT_A:
		if(direction == IN)
		{
		DDRA &= ~(1<<pinNumber); //Input
		}
		else
		{
		DDRA |= (1<<pinNumber); //Output
		}
		break;
			
		case PORT_B:
		if(direction == IN)
		{
			DDRA &= ~(1<<pinNumber); //Input
		}
		else
		{
			DDRA |= (1<<pinNumber); //Output
		}
		break;
		
		case PORT_C:
		if(direction == IN)
		{
			DDRA &= ~(1<<pinNumber); //Input
		}
		else
		{
			DDRA |= (1<<pinNumber); //Output
		}
		break;
		
		case PORT_D:
		if(direction == IN)
		{
			DDRA &= ~(1<<pinNumber); //Input
		}
		else
		{
			DDRA |= (1<<pinNumber); //Output
		}
		break;		
			
		default:
		/* Do Nothing */
		break;
	}
}

void DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value)
{
	switch(portNumber)
	{
		case PORT_A:
		if(value == LOW)
		{
			PORTA &= ~(1<<pinNumber); //write 0
		}
		else
		{
			PORTA |= (1<<pinNumber); //write 1
		}
		break;
		
		case PORT_B:
		if(value == LOW)
		{
			PORTB &= ~(1<<pinNumber); //write 0
		}
		else
		{
			PORTB |= (1<<pinNumber); //write 1
		}
		break;
		
		case PORT_C:
		if(value == LOW)
		{
			PORTC &= ~(1<<pinNumber); //write 0
		}
		else
		{
			PORTC |= (1<<pinNumber); //write 1
		}
		break;
		
		case PORT_D:
		if(value == LOW)
		{
			PORTD &= ~(1<<pinNumber); //write 0
		}
		else
		{
			PORTD |= (1<<pinNumber); //write 1
		}
		break;
		
		default:
		/* Do Nothing */
		break;
	}
}


void DIO_toggle(uint8_t pinNumber, uint8_t portNumber)
{
		switch(portNumber)
		{
			case PORT_A:
			{
				unsigned int toggle_number = 0;
				// will toggle 5 times every 1 second
				while(toggle_number <5)
				{
				PORTA ^= (1<<pinNumber); // toggle
				// External Interrupt 0 disable during timer execution
				void ext_int0_disable(void);
				TIMER_delay(1000);
				toggle_number++;
				}
				// Reinitialize external interrupt 0 after timer execution
				void ext_int0_setup(void);
			}
			break;
			
			case PORT_B:
			{
				unsigned int toggle_number = 0;
				// will toggle 5 times every 1 second
				while(toggle_number <5)
				{
				PORTB ^= (1<<pinNumber); // toggle
				// External Interrupt 0 disable during timer execution
				void ext_int0_disable(void);				TIMER_delay(1000);
				toggle_number++;
				}
				// Reinitialize external interrupt 0 after timer execution
				void ext_int0_setup(void);
			}
			break;
			
			case PORT_C:
			{
				unsigned int toggle_number = 0;
				// will toggle 5 times every 1 second
				while(toggle_number <5)
				{
				PORTC ^= (1<<pinNumber); // toggle
				// External Interrupt 0 disable during timer execution
				void ext_int0_disable(void);
				TIMER_delay(1000);
				toggle_number++;
				}
				// Reinitialize external interrupt 0 after timer execution
				void ext_int0_setup(void);
			}
			break;
			
			case PORT_D:
			{
				unsigned int toggle_number = 0;
				// will toggle 5 times every 1 second
				while(toggle_number <5)
				{
				PORTD ^= (1<<pinNumber); // toggle
				// External Interrupt 0 disable during timer execution
				void ext_int0_disable(void);
				TIMER_delay(1000);
				toggle_number++;
				}
				// Reinitialize external interrupt 0 after timer execution
				void ext_int0_setup(void);
			}
			break;
			
			default:
			{
				/* Do Nothing */
				break;
			}
		}
			
}

void DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value)
{
		switch(portNumber)
	{
		case PORT_A:
		   *value = (PORTA & (1<<pinNumber))>>pinNumber; // read bit
		break;
		
		case PORT_B:
		   *value = (PORTB & (1<<pinNumber))>>pinNumber; // read bit
		break;
		
		case PORT_C:
		   *value = (PORTC & (1<<pinNumber))>>pinNumber; // read bit
		break;
		
		case PORT_D:
		   *value = (PORTD & (1<<pinNumber))>>pinNumber; // read bit
		break;
		
		default:
		/* Do Nothing */
		break;
	}
}

