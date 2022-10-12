/*
 * LEDs.c
 *
 * Created: 9/29/2022 1:32:54 PM
 *  Author: Family
 */ 

#include "LEDs.h"

// 1- LED initialization
void LED_init(uint8_t led_pin, uint8_t led_port)
{
	DIO_init(led_pin, led_port, OUT);
}

// 2- LED ON
void LED_ON(uint8_t led_pin, uint8_t led_port)
{
	DIO_write(led_pin, led_port, HIGH);
}

// 3- LED OFF
void LED_OFF(uint8_t led_pin, uint8_t led_port)
{
	DIO_write(led_pin, led_port, LOW);
}


// 4- LED toggle
void LED_toggle(uint8_t led_pin, uint8_t led_port)
{
	DIO_toggle(led_pin, led_port);
}

