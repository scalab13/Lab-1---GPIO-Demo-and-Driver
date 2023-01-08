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
When your code is done compiling and flashed to your board, your Code Composer environment will be ready for debugging. **BEFORE DOING ANYTHING**, let's take a look at the environment layout to see what it is trying to show you.

### Code Window
The Debugger is able to show you what line of code it is currently about to execute when it is Paused. When you first start the debugger, it pauses the code right before running the first line of code. In the example below, it is paused execution at line 71.
![Code Window](https://i.gyazo.com/1907b89fa67245c0fd13c7fbfa23a17c.png)

### Element Inspector
This is where, to me, the magic happens with a Debugger. This will allow you to track vairables, values, register contents, and even change them while code is paused. This let's you see an entire snapshot of your microcontroller at any point in your code. So if something is not working, you have the ability to check all the system settings.
![Element Inspector](https://i.gyazo.com/780e04b58cdf037f30c880539838f82a.png)

### Control Toolbar
This controls the execution of the debugger.
![Control toolbar](https://i.gyazo.com/b0de82170a4d83052ab2ed809e945390.png)
- ![Resume](https://i.gyazo.com/ccf8d0a8aad673d33f038522d907f05b.png): Resumes execution without stopping, pauses the execution, or stops and terminates the debug session.
- ![Step Controls](https://i.gyazo.com/cee0ced7064275fa6938de6c5d7be682.png): Step Controls allow you to step line by line, step over arguments, or step into arguments.
- ![Rewind](https://i.gyazo.com/30f2d05ee986c14a5e3d23ab76b17231.png): Rewind is essentially a restart to take you to the back of the beginning of the code. This also will reset the processor as well.

## Running and Breakpoints
Once you are ready, hit the Resume button (play button), and you should see your Red LED blinking on and off. Congrats! You blinked an LED! But what if we wanted to know what actually was going on? That is where we can use either the pause function or **breakpoints** to tell the debugger to pause when it gets to a paritcular line of code.

### Adding a breakpoint
Why don't we stop the code when it tries to turn the LED on. To do this, in the Code Window, either right click on the line number of the line of code you want to add a breakpoint to, or double click it to add a breakpoint.
![Adding Breakpoint](https://i.gyazo.com/d7942b0b36df10d95cdc4d8f4d2e501c.gif)

### Run until Breakpoint
Now hit the resume button, and the debugger will automatically pause once we reach that line of code.
![Running](https://i.gyazo.com/6dc4fefbe3110c72c7f6544652219e50.gif)
Ok, what just happened? The debugger went through the lines of code up to that point, meaning it did all the pin configurations and entered the loop. Once it did that, it paused, and you can even see on your lauchpad that the debugger is actively pausing the code execution.

### Let's see what that XOR Operation is actually doing
Now that we paused there, let's use the element inspector to see what exactly is going on _in the processor_. To do this, we are going to go to the Register Tab:

![Register Inspector](https://i.gyazo.com/acc60cc10edca1c6e1eefd7b0c4c25c4.gif)

This microcontroller has a lot of register, but they are organized based on peripheral. Since we are controlling Pin 1.0, that is on Port 1, or P1. So we are going to expand those registers and look for **P1OUT**.

![Port 1](https://i.gyazo.com/f36b5fa6e79880474a3c35e7943e3d7d.gif)

HEX is a very common way for us to see bytes of data, but if we wanted to see the individual bits, we can change the base or the way the data is represented by right clicking and changing the number format. We are going to change it to Binary.

![ChangeNumberFormat](https://i.gyazo.com/79bbe1e8b12ff8622f956e6b78899977.gif)

Now that we can see the individual bits, let's actually step into that line of code and see what the change in the P1OUT Register is.

![Changing P1OUT](https://i.gyazo.com/cfe72ab822f5c6dbdda479f14f6a4907.gif)

Code Composer will actually highlight registers which have changed values to make your life a little easier. But look at what happened with that line of code: The 0th bit of P1OUT Toggled from a 0 to a 1!. And if you noticed, the LED state on your board should have changed.

### Manually Changing Registers
Sometimes it is really useful to be able to change the value of a register. To do this, you need to make sure your code is paused. Then you can actually click on the register and begin custom typing in a value. In the gif below, I am changing the last bit back to a 0. When you finish and hit enter, the debugger with force the microcontroller to load that new register values, and you should be able to see the LED change again.

![Changing Bit 0](https://i.gyazo.com/48a900d4157a5a138e83ac145dc2541e.gif)


### Removing your breakpoint and continuing execution
If you want to keep your code running and remove the breakpoint, double clik the breakpoint, or right click it and remove it. Then when you hit the resume button, it will continue running the code like normal.
