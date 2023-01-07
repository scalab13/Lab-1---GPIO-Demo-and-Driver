# Part 2: Blinking LEDS
_Tasks_
- [ ] Compile and run the example you imported from the previous part of the lab.
- [ ] Change the rate of blinking by changing one line of code
- [ ] Modify the code to blink the other on board LED
- [ ] SUBMISSION: Creating code which will blink the LEDS alternatively at a common rate (Red, Green, Red, Green...)

## Compiling and Running your Code in Code Composer
Once you have imported your project, this has everything you need for your project to be built and compiled. We will be living in the _Debug_ view when we are investigating the code running, so we should start a Debug session.

You can either click the little green bug in the toolbar, or go to `Run --> Debug`.
![Debug Symbol in the Toolbar](https://i.gyazo.com/a7bdc75abc350ced25ca294ca7a2f129.png)

This does a few things:
* Runs the compiler
* Runs the build tool
* Programs the microcontroller
* Setups the microcontroller and the IDE into a Debug state for system inspection.

### Compiler
The first step in this is the compiler. This is the syntax checker and it is checking to see if the code you wrote can be synthesized and compiled into a set of machine code instructions. Think of this as a _Spell and Grammar Check_ for your code: it can tell how things are spelled and that you wrote legal code arguments; __HOWEVER__, it cannot check the behavior of your code. This is critical.

> Just because your code can compile **DOES NOT** mean it will actually function.

### Build Tool
Once the compiler has determined the instructions needed to run your code, it will invoke several tools to actually get the correct addresses and specifics of your target microcontroller. This is managed through the `msp430.h` header file and linker files. These are already included in your projects when you start them.

### Programming the Microcontroller
This is honestly something that takes a second to realize. The code you wrote _is not_ running on your computer, it is running on the microcontroller itself. To get the code over to the Microcontroller, Code Composer uses the USB connection to load instructions into the Flash/FRAM memory on the MSP430FR2355. Sometimes this is called "Burning the code in". While the code itself is going into Non-Volatile Memory, this memory can be re-written through this same process.

### Setting up the Debug Session
Two things need to happen for the Debug Session to be active. First, your IDE needs to be in the Debug Environment, which is done automatically when you click "Debug". Second and more importantly, the management circuit on the top of your launchpad (the really really compilacted and densely packed part of the launchpad with the USB on it) goes into a Debug Mode. What this means for your microcontroller is that essentially, this management circuit can tell your microcontroller to step one instruction at a time, to inpect ANY register and read its contents, track the values of vairable, and let you change register contents on the fly. In short, you will have __TOTAL__ control over the microcontroller as it runs through your code. This could be the best tool in your software arsenal to debug what you system is doing.

## Running and Stepping through your code.
