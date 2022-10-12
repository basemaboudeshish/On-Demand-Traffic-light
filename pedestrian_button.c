/*
 * pedestrian_.c
 *
 * Created: 9/29/2022 1:30:57 PM
 *  Author: Family
 */ 

#include "pedestrian_button.h"

// 1- Pedestrian button initialization
void pedbutton_init(uint8_t button_pin, uint8_t button_port)
{
	DIO_init(button_pin, button_port, IN);
}

// 2- Pedestrian button read
void pedbutton_read(uint8_t button_pin, uint8_t button_port, uint8_t *value)
{
	DIO_read(button_pin, button_port, value);
}