# GPIO Driver Assignment
Now that you have become familiar with the GPIO Peripheral, we can now begin working on a general driver, which will let you write higher level code, and abstract some specific things about the microcontroller away. This resulting code is something that you will be able to use in your projects and in future labs.

## Assignment
In this folder, there are the following files:
* **main.c:** A program which will control which LED is blinking based on the state of a button.
* **GPIO_Driver.h:** The header file containing the function definitions which you will be developing.
* **GPIO_Driver.c:** The c file containing the code for the functions defined in the GPIO_Driver.h.

You **only need to edit GPIO_Driver.c**, while in the other files, you need to update the author block.

You will need to upload your version of these files, updated with comments, author blocks, and any additions to the code you have made.

## Functions you need to implement

### gpioInit(char Port, char Pin, char Direction)
Used to configure a single GPIO pin as an input or output.

Arguments:
* char **Port**: takes values from 1-6
* char **Pin**: takes values from 0-7
* char **Direction**: 0 for Input, 1 for Output

Example: Setting pin 1.0 to an output
```c
gpioInit(1, 0, 1);
```


### gpioWrite(char Port, char Pin, char Value)
Used to write a 1 or 0 to a Pin which has already been declared as an output.

Arguments:
 * char **Port**: takes values from 1-6
 * char **Pin**: takes values from 0-7
 * char **Value**: 0 or 1

Example: Setting pin 1.0 to a 1
```c
gpioWrite(1, 0, 1);
```


### gpioRead(char Port, char Pin, char Value)
Used to Read from a pin which has been declared as an input.

Arguments:
 * char **Port**: takes values from 1-6
 * char **Pin**: takes values from 0-7
Returns:
 * 1 or 0 based on pin value.
Example: Reading Pin 1.1
```c
unsigned char PinState = gpioRead(1, 1);
```


## Advice and Getting Started
When you are trying to write a driver or a generalized piece of code, a great place to start is with the code you already have working. So for example, while there is a main.c file that you will need to test your final code with, I would recommend trying to replicate the examples you have already done with these functions.

### Encapsulating and Abstracting your Code
You can start by looking at what lines of code are doing which functions, and breaking them down into those groups. For example, looking at the LED Blinking example, can you break it down into:
* Which lines of code are **initializing** the pins and ports?
* Which lines of code are **writing** values to the pins?
* Which lines of code are **reading** values from the pins?

In general, most of your code in this class should end up looking something like:
```c
gpioInit();
timerInit();
adcInit();
while (1){
  readADC();
  setPWM();
  ...
}
```
This does several things:
* It *abstracts* away the specifics of the registers, allowing you to work on separate parts of the code without interfering with others.
* It *encapsulates* functionality, so that you can thinking about your code from a higher level, and determine what functionality you will need to develop.

### Switch Case Statements
These are very useful and can be one way you approach how the inputs are handled in your functions.
```c
switch(expression) {

   case constant-expression  :
      statement(s);
      break; /* optional */

   case constant-expression  :
      statement(s);
      break; /* optional */

   /* you can have any number of case statements */
   default : /* Optional */
   statement(s);
}
```
### Efficiency
As of right now, you are just getting something that works. If you can get something working, you can then begin thinking about efficiency after that. **DO NOT** worry about how efficient or elegant your code is. Those types of things come with practice and familiarity with the language. What matters is that your code works. We are not counting cycles and microwatts, so a little extra work to get something done isnt going to cause many issues.

### Commenting and Naming
Not only is this good practice, it is a major part of your grade in these assignments. Making code that is readable, easy to implement, and easy to augment is the name of the game. It is tempting just to use basic, 1 letter names for things, but use actual words for your variables. Does it take a little longer to write? Sure. Will it save you much more time later whe you are looking back at this and trying to figure out what you did? Absolutely.

Comments are not just for others, they are for you as well. Many of you might try to knock this out in one sitting, and when you do that, your brain is still in the same headspace and all the little things you were keeping track of and reasoning why you did things make sense now. But once you try to come back to it, all of those details are lost and are extremely hard to get back. Any time you make a decision to do something in your code, **comment why you did it**. This should read like a book almost, and anyone looking at it should not only understand what you have written, but why you approached it that way.
