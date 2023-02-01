/*
 * GPIO_Driver.c
 *
 *  Created on: Jan 6, 2023
 *      Author: Russell
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

    unsigned char PinNumber = 0x01 << Pin;   // Right Shifting a 1 to match the pin needed for the port
if(Direction) {
    switch(Port){


    case 1:                 // Port 1
                P1DIR |= PinNumber;  // Setting Input for Pin 1
                break;

    case 2:             // Port 2


                     P2DIR |= PinNumber; // Setting Input for Pin 2
                     break;

    case 3:  //Port 3



        P3DIR |= PinNumber; // Setting Input for Pin 3
        break;

    case 4: //Port 4
        P4DIR |= PinNumber; // Setting Input for Pin 4
        break;

    case 5:     //Port 5
        P5DIR |= PinNumber; // Setting Input for Pin 5
        break;

    case 6:     //Port 6;
        P6DIR |= PinNumber; // Setting Input for Pin 6
        break;

    }
}

else {
    switch(Port){


    case 1:                 // Port 1
                //Using Input to turn off Output
                P1DIR &= ~PinNumber;
                P1REN |= PinNumber;
                P1OUT |= PinNumber;
                break;

    case 2:             // Port 2

        //Using Input to turn off Output
        P2DIR &= ~PinNumber;
        P2REN |= PinNumber;
        P2OUT |= PinNumber;
                     break;

    case 3:  //Port 3
        //Using Input to turn off Output
        P3DIR &= ~PinNumber;
        P3REN |= PinNumber;
        P3OUT |= PinNumber;
        break;

   case 4: //Port 4
       //Using Input to turn off Output
       P4DIR &= ~PinNumber;
       P4REN |= PinNumber;
       P4OUT |= PinNumber;
        break;

    case 5:     //Port 5
        //Using Input to turn off Output
        P5DIR &= ~PinNumber;
        P5REN |= PinNumber;
        P5OUT |= PinNumber;
        break;

    case 6:     //Port 6;
        //Using Input to turn off Output
        P6DIR &= ~PinNumber;
        P6REN |= PinNumber;
        P6OUT |= PinNumber;
        break;

    }
}
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

void gpioWrite(char Port, char PinNumber, char Value){
    unsigned char Pin = 0x01 << PinNumber; //Right shift bit
  if (Value){ // Assigning Port to Output
      switch(Port){


      case 1:                 // Port 1
                  P1OUT |= Pin;  // Clearing output of Pin 1
                  break;

      case 2:             // Port 2


          P2OUT |= Pin;  // Clearing output of Pin 2
                       break;

      case 3:  //Port 3



          P3OUT |= Pin;  // Clearing output of Pin 3
          break;

     case 4: //Port 4

          P4OUT |= Pin; // Clearing output of Pin 4
          break;

      case 5:     //Port 5
          P5OUT |= Pin; // Clearing output of Pin 5
          break;

      case 6:     //Port 6;
          P6OUT |= Pin; // Clearing output of Pin 6
          break;

      }
  }
  else { // Assigning Port to Input
      switch(Port) {
      case 1:
          P1OUT &= ~Pin; //Makes Pin an Input
          break;
      case 2:
          P2OUT &= ~Pin; //Makes Pin an Input
          break;
      case 3:
          P3OUT &= ~Pin; //Makes Pin an Input
          break;
      case 4:
          P4OUT &= ~Pin; //Makes Pin an Input
          break;
      case 5:
          P5OUT &= ~Pin; //Makes Pin an Input
          break;
      case 6:
          P6OUT &= ~Pin; //Makes Pin an Input
          break;
      }
  }
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

char gpioRead(char Port, char PinNumber){
  unsigned char Pin = 0x01 << PinNumber; // Bit Shift
  char x; // Temp variable to hold the returned va;ue

    switch(Port){


    case 1:                 // Port 1
                x = P1IN & Pin; // Outputs 1 or 0 based on Pin directory
                break;

    case 2:             // Port 2


        x = P2IN & Pin; // Outputs 1 or 0 based on Pin directory
                     break;

    case 3:  //Port 3
        x = P3IN & Pin; // Outputs 1 or 0 based on Pin directory
        break;

   case 4: //Port 4
       x = P4IN & Pin; // Outputs 1 or 0 based on Pin directory
        break;

    case 5:     //Port 5
        x = P5IN & Pin; // Outputs 1 or 0 based on Pin directory
        break;

    case 6:     //Port 6;
        x = P6IN & Pin; // Outputs 1 or 0 based on Pin directory
        break;

    }
  return x; //Return Value

}


