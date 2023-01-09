/**
 * GPIO Driver
 *
 * This project is meant to develop a simple GPIO driver library which you will be able to use throughout the semester. It will pull from several
 * examples from the TI Resource Explorer and you will need to complete the functions listed in the GPIO_Driver.C and GPIO_Driver.h files.
 *
 * Author: Your Name Here
 * Version: 0.0 Change this to match your version
 *
 * Last Updated: 06 JAN 2023
 *
 * Change Log:
 */


#include <msp430.h> 

#include "GPIO_Driver.h"

/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    gpioInit(1, 0, 1);          // Set Pin 1.0 to Output
    gpioInit(6, 6, 1);          // Set Pin 6.6 to Output
    gpioInit(2, 0, 0);          // Set Pin 2.3 to Input

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    gpioWrite(1, 0, 0);         // Set Pin 1.0 to 0 initially
    gpioWrite(6, 6, 0);         // Set Pin 6.6 to 0 initially

    char LEDState = 0x00;

    while(1){
        char Button = gpioRead(2, 0);
        if (Button)
            gpioWrite(1, 0, LEDState);
        else if (!Button)
            gpioWrite(6, 6, LEDState);
        LEDState ^= 0x01;   // Toggle LED State
        __delay_cycles(100000);             // Delay for 100000*(1/MCLK)=0.1s
    }


    return 0;
}
