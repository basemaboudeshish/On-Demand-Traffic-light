/*
 * LEDs.h
 *
 * Created: 9/29/2022 1:33:33 PM
 *  Author: Family
 */ 


#ifndef LEDS_H_
#define LEDS_H_

#include "../MCAL/DIO/DIO.h"
#include "../MCAL/Timer/Timer.h"
#include "../Utilities/registers.h"
#include <stdint.h>

// 1- LED initialization
void LED_init(uint8_t led_pin, uint8_t led_port);

// 2- LED ON
void LED_ON(uint8_t led_pin, uint8_t led_port);

// 3- LED OFF
void LED_OFF(uint8_t led_pin, uint8_t led_port);

// 4- LED toggle
void LED_toggle(uint8_t led_pin, uint8_t led_port);

#endif /* LEDS_H_ */