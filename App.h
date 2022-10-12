/*
 * App.h
 *
 * Created: 9/29/2022 1:34:30 PM
 *  Author: Family
 */ 


#ifndef APP_H_
#define APP_H_

#include "../ECUAL/LEDs/LEDs.h"
#include "../ECUAL/Pedestrian Button/pedestrian_button.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/Interrupt/Interrupt.h"
#include "../MCAL/Timer/Timer.h"
#include "../Utilities/registers.h"
#include <stdint.h>



	void APP_start(void);
	void APP_init (void);
	void normal_mode(void);
	void presstime(void);
	void pedestrian_mode(void);
	
	
	

#endif /* APP_H_ */