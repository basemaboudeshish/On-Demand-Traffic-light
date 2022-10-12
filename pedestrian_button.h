/*
 * pedestrian_button.h
 *
 * Created: 9/29/2022 1:31:34 PM
 *  Author: Family
 */ 


#ifndef PEDESTRIAN_BUTTON_H_
#define PEDESTRIAN_BUTTON_H_


#include "../MCAL/DIO/DIO.h"
#include "../MCAL/Interrupt/Interrupt.h"
#include "../Utilities/registers.h"
#include <stdint.h>

void pedbutton_init(uint8_t button_pin, uint8_t button_port);
void pedbutton_read(uint8_t button_pin, uint8_t button_port, uint8_t *value);


#endif /* PEDESTRIAN_BUTTON_H_ */