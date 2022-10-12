/*
 * DIO.h
 *
 * Created: 9/29/2022 1:38:02 PM
 *  Author: Family
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../MCAL/Timer/Timer.h"
#include "../Utilities/registers.h"
#include <math.h>
#include <stdint.h>

// Driver macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'


// Direction defines
#define IN 0
#define OUT 1

// Value defines
#define LOW 0
#define HIGH 1




void DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction);
void DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value);
void DIO_toggle(uint8_t pinNumber, uint8_t portNumber);
void DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);


#endif /* DIO_H_ */