# Part 3: Buttons and Inputs
_Tasks_
- [ ] Import a new example for using an Input
- [ ] SUBMISSION: Creating code which will blink one LED (Red or Green), then based on Button/Input, change which LED is Blinking.

# Input Example - msp430fr235x_P1_01.c
The next example to import is the P1_01 example which can be found in the resource explorer.

![Port 1 Input Example](https://i.gyazo.com/3acad3ccfc135c434fa2406adff36ad0.png)

Here are some of the registers being manipulated in the code:

```c
P1DIR |= BIT0;                          // Set P1.0 to output direction
P1DIR &= ~BIT3;                         // Set P1.3 as input
...
if (P1IN & BIT3)
```

## New Registers, same Input/Output Diagrams
So while this code may look very different, it is still referring to the same Port diagram that we have seen before.

![Port 1 Pin Diagram](https://i.gyazo.com/3b76760bf6708eba2ef282fec1a17566.png)

### Software Explanation
It seems a little strange at first to see two separate lines of code setting a register to a value; however, note that we are _strictly_ assigning a constant. Instead, we are changing specific bits, a method known as **Non-Destructive Assignment**. This is where we are changing only specific bits at a time, instead of the entire register's value.

#### P1DIR \|= BITO
Let's assume on a Reset, P1DIR is set to all 0's. This line of code will provide us with.
```
P1DIR        0b00000000
BIT0         0b00000001
BITWISE OR   0b00000001
```
In this case, **only the bits OR'd with a 1 are affected**. This is a non-destructive assignment, where you are not completely re-writing all of the bits in the register.

#### P1DIR &= ~BIT3
Now that `P1DIR = 0b00000001`, let's real fast cover what that means. Pins 1.7-1.1 are still set as an Input, and now Pin 1.0 is set as an output. You might say "Why are we going to do anything else, if Pin 1.3 is already an input?". It is a good practice since once you get to more complex software designs, you may not know at any given point what the P1DIR register could be set as.

> As a general rule to follow, **always explicitly** declare your control registers.

So let's break down that this line of code.
```
P1DIR        0b00000001
~BIT3        0b11110111
BITWISE AND  0b00000001
```
In this case, **only the bits AND'd with a 0 are affected**. This is a non-destructive assignment to get a specific bit to a 0, while all other bits are unchanged.

#### P1IN & BIT3
So this is a Bitwise AND, and in this usage, this is called a **MASKING** operation. Assume that `P1IN = 0b01111011`.
```
P1IN         0b01111011
BIT3         0b00001000
BITWISE AND  0b00001000
```
This is called a Mask because we are only attempting to look at what a specific bit or bits within a register or value are equal to. But notably, this results in a *number or value* **not** a logical True or False, so how does this interact with an if statement?

#### if(P1IN & BIT3)
In C, if statements are conditional statements, which typically are evaluated on a True or False condition. But we have to ask ourselves, in a binary world, what is actually considered True and False? Answer...

* **False:** 0
* **True:** Anything other than a 0

So looking at this if statement, here are the possible results:
```
if(0b00000000)
  the if statement will not run, as it interprets a False

if(0b00001000)
  the if statement will run, as it interprets a True
```

One way that we could write this behavior, but it would use more variables, memory, processing time, etc.
```c
int ButtonState = 0;
if ((P1IN & BIT3) == 0b00001000)
  ButtonState = 1;
else if ((P1IN & BIT3) == 0b00000000)
  ButtonState = 0;
```

You can see how yes, this does the same thing, but using just the mask as the condition in the if statement can be much more efficient, and can leverage the ways the registers themselves are configured.

### Port Input/Output Diagram
![Input Portion of Port Schematic](https://i.gyazo.com/93b6ccdf3c20f0c492e559b3191fdee9.png)

The pin is connected through a schmitt trigger directly to the P1IN Register. So once we actually set the port direction, through the tristate buffer, then really, all that is left if just reading the P1IN Register.



# Section Task: Changing which LED Blinks Based on Button Input
Once you run the example, getting the LEDs to blink and to chose which LEDs should blink is actually not to terrible of a task. You need to create a piece of code which will:
* Initialize and start blinking the RED LED with a 1 second period.
* Whenever the Button is off, or the Pin is driven to a 0, then the RED LED should be blinking, and the GREEN LED should stop blinking.
* Whenever the Button is on, or the Pin is driven to a 1, then the RED LED should stop blinking, and the GREEN LED should start blinking.
* Note: You do not need to completely turn off the other LED when it changes, however, it is a good challenge to try.

The deliverable for this section task is to upload a commented C file containing your work, an appropriate author block, and appropriate comments and variable names such that it is easy to see what you have done.

Some advice:
* Use __delay_cycles(), do not panic about precision timing yet.
* You can use any methods you wish, ranging from the masking to using dummy or placeholder variables.
* It is up to you how you want to do this, but I recommend not just compiling on a prayer. Take a minute, a piece of paper, and actually pseudocode the behavior you want.
