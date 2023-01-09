/*
 * GPIO_Driver.c
 *
 *  Created on: Jan 6, 2023
 *      Author:
 */



#include "GPIO_Driver.h"
#include <msp430.h>


/**
 * gpioInit(char Port, char Pin, char Direction)
 * Used to configure a single GPIO pin as an input or output.
 *
 * char Port: takes values from 1-6
 * char Pin: takes values from 0-7
 * char Direction: 0 for Input, 1 for Output
 *
 * Example: Setting pin 1.0 to an output
 * gpioInit(1, 0, 1);
 */

void gpioInit(char Port, char Pin, char Direction){

}



/**
 * gpioWrite(char Port, char Pin, char Value)
 * Used to write a 1 or 0 to a Pin which has already been declared as an output.
 *
 * char Port: takes values from 1-6
 * char Pin: takes values from 0-7
 * char Value: 0 or 1
 *
 * Example: Setting pin 1.0 to a 1
 * gpioWrite(1, 0, 1);
 */

void gpioWrite(char Port, char Pin, char Value){


}


/**
 * gpioRead(char Port, char Pin, char Value)
 * Used to Read from a pin which has been declared as an input.
 * Returns a 1 or 0 based on pin value.
 *
 * char Port: takes values from 1-6
 * char Pin: takes values from 0-7
 *
 * Example: Reading Pin 1.1
 * unsigned char PinState = gpioRead(1, 1);
 */

char gpioRead(char Port, char Pin){


}

