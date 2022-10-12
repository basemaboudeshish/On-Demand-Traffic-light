 /*
 * On-demand_Traffic_light_control.c
 *
 * Created: 9/29/2022 1:09:57 PM
 * Author : Family
 */ 

#include "../ECUAL/LEDs/LEDs.h"
#include "../ECUAL/Pedestrian Button/pedestrian_button.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/Interrupt/Interrupt.h"
#include "../MCAL/Timer/Timer.h"
#include "../Utilities/registers.h"
#include "../App/App.h"
#include <avr/interrupt.h>



 int counter;
 uint8_t *Status1, *Status2;


/* int main(void)
{
	
	APP_init ();
	while (1)
	{
		APP_start();
	}
	
}
	*/


	
//ISR for timer 2 overflow interrupt
ISR(TIMER2_OVF_vect)
{
	DIO_read(2, PORT_D, Status1);
	if(*Status1 == HIGH)
	{
		counter++;
	}
}



// External interrupt 0 to start pedestrian mode as soon as the pedestrian button pressed
ISR(EXT_INT_0)
{
	pedestrian_mode();
	//reset microcontroller to return to the beginning of the main function
	__asm__ __volatile__ ("jmp 0x00");
}


// Testing DIO initialization function //
int main(void)
{
	while(1)
	{
		// DIO function initialization as an input for the test
		DIO_init(0, PORT_B, IN);
		DIO_init(1, PORT_B, IN);
		DIO_init(2, PORT_B, IN);
		DIO_init(3, PORT_B, IN);
		DIO_init(4, PORT_B, IN);
		DIO_init(5, PORT_B, IN);
		DIO_init(6, PORT_B, IN);
		DIO_init(7, PORT_B, IN);
		
		DIO_toggle(0, PORT_B);
		DIO_toggle(1, PORT_B);
		DIO_toggle(2, PORT_B);
		DIO_toggle(3, PORT_B);
		DIO_toggle(4, PORT_B);
		DIO_toggle(5, PORT_B);
		DIO_toggle(6, PORT_B);
		DIO_toggle(7, PORT_B);	
		
		// DIO function initialization as an output for the test
		DIO_init(0, PORT_B, OUT);
		DIO_init(1, PORT_B, OUT);
		DIO_init(2, PORT_B, OUT);
		DIO_init(3, PORT_B, OUT);
		DIO_init(4, PORT_B, OUT);
		DIO_init(5, PORT_B, OUT);
		DIO_init(6, PORT_B, OUT);
		DIO_init(7, PORT_B, OUT);
		
		// DIO function 
		
		DIO_read(0, PORT_B);
		DIO_read(1, PORT_B);
		DIO_read(2, PORT_B);
		DIO_read(3, PORT_B);
		DIO_read(4, PORT_B);
		DIO_read(5, PORT_B);
		DIO_read(6, PORT_B);
		DIO_read(7, PORT_B);
		
		
		// DIO function to keep all the inputs High
		/*DIO_write(0, PORT_A, HIGH);
		DIO_write(1, PORT_A, HIGH);
		DIO_write(2, PORT_A, HIGH);
		DIO_write(3, PORT_A, HIGH);
		DIO_write(4, PORT_A, HIGH);
		DIO_write(5, PORT_A, HIGH);
		DIO_write(6, PORT_A, HIGH);
		DIO_write(7, PORT_A, HIGH);	*/
		
		// DIO function to keep all the inputs low
		/*DIO_write(0, PORT_A, LOW);
		DIO_write(1, PORT_A, LOW);
		DIO_write(2, PORT_A, LOW);
		DIO_write(3, PORT_A, LOW);
		DIO_write(4, PORT_A, LOW);
		DIO_write(5, PORT_A, LOW);
		DIO_write(6, PORT_A, LOW);
		DIO_write(7, PORT_A, LOW);  */
	}
}