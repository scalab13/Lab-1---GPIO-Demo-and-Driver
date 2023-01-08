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

## Modifying the Blinking Speed
Ok, so what can we do to start changing things? Luckily, TI has done an astounding job of documenting the code! So much so, you should be able to quickly see what is controlling the blink speed.
```
__delay_cycles(100000);
```
The name of the function gives away what is does, but if you don't know, you can either look it up on Google and probably end up finding the answer, or, right click and open the declaration. But I will save you the search...
### __delay_cycles()
You should notice that this function is actually **BOLDED** in the editor. This means typically that this is a pre-compiler command or function, or it is something built in to the IDE, an Intrinsic. How this works is it is asking the compiler to generate junk code which will take exactly the amount of clock cycles as put in the parenthesis.

Now you might be thinking this is good, but we will learn quickly in the class that using something like __delay_cycles() can get something done, it is an extreme waste of clock cycles, energy, and processing time. It is ok for basic testing, but really as we go through the course, we should be phasing out the usage of it in your final code.

> **TASK:** Change the value inside of the __delay_cycles() function and see if you can make it double in speed and half its speed.

# GPIO and Registers
Ok, so this might seem a little challenging at first, but to get started with this, we need to have a quick discussion on what this code is actually doing, and how the hardware within the microcontroller is being impacted by the registers you are accessing.

## Register Access, aka, 90% of the code you are going to write in this class.
Taking a look at the majority of the LED Blinking Code, what are we doing?
```c
WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
P1DIR |= BIT0;                          // Set P1.0 to output direction

PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                        // to activate previously configured port settings
```

> This is the learning curve in programming in this course. These **ARE NOT** variables, these are register addresses...

One of the first questions that every... single... person... has looking at this code is "Where is WDTCTL, P1OUT, P1DIR, BIT0 defined, and what the hell does this have to do with an LED?" This is a very fair question.

### The C Operations
Just for a second, let's say that we all knew what all of these Macros and things were. Take a look at the operations being done:
| Operation        | Syntax           | Result  |
| ------------- |-------------| -----|
| Assignment      | = | Take whatever is on the left, and assign its value to the argument on the right |
| Bitwise OR      | \|      |   Takes two numbers, and ORs each individual bit together. Result is a number/bit array |
| Bitwise AND | `&`      | Takes two numbers and ANDs each bit together. Result is a number or bit array |
| Bitwise Invert/NOT | `~` | Inverts each bit in the number. For example `~(0101)` becomes `(1010)` |
| Bitwise XOR | `^` | Takes two numbers an XORs each bit together. Result is a number or bit array |

One other little C syntax you will see all the time is an operator and assignment together, such as `P1DIR |= BIT0`. Remember that this is the equivalent as writing: `P1DIR = P1DIR | BIT0`. This syntax is used to save space, as well as you will get used to seeing `P1DIR |= BIT0` as "I am OR'ing the Zeroth Bit of P1DIR with a 1".

### About those Macros...
**WDTCTL WDTPW WDTHOLD P1OUT P1DIR BIT0**
These all seem like variables, but there are a few issues here. First, where are they defined? And second, what are they doing? Well first off, these *are not* variables... these have been defined as a **MACRO**. Macros are ways to let you rename certain data types, functions, and more for easier integration and development.

If you wanted to see an example (and that means to do this) in the code, go ahead and hover over P1OUT. In a few seconds, you should see a tooltip pop up and with it, a definition.

![Hovering over P1OUT](https://i.gyazo.com/19923ff5945f1db65140a1a05a9a5bc1.gif)

You should see that P1OUT is actually really defined as `SFR_8BIT(P1OUT)`.

**SFR** stands for Special Function Register, and it is 8-bits wide. Register, as in the Registers you know from Computer Architecture.

What about **BIT0**:

![BIT0 is just 0x0001](https://i.gyazo.com/e75192a7e2b1d019a53ebdf96e2f997c.gif)

BIT0 is just a number... 1. Specifically in binary it is `BIT0 = 0b0000000000000001`.

You can also Right Click on a Macro and open its declaration in its original header file.

![All of the Macro Definitions](https://i.gyazo.com/e5069e01e39b99d0d8f3f6fc7056721f.gif)

The file that opens is the **header file** for your microcontroller, and contains all of the specific macros and addresses for your specific chip. _This is where all of these macros are defined_

### What is this code actually doing
So taking a look at `P1OUT |= BIT0` let's assume that our 8-Bit Register is initially set as 0x00 (you can confirm this in the microcontroller datasheet).
> Note: When doing bitwise operators, Code Composer will automatically assume you mean the lowest bits in a larger number.


| Step | Output |
| ---- | -----|
| P1OUT (initially) | 0b00000000 |
| BIT0 | 0b00000001 |
| P1OUT \| BIT0 | 0b00000001 |

Just off this one example, we can see that all we are doing in pretty much every line of code here is **Manipulating Specfic Bits within registers of our microcontroller**. But how is this causing an LED to blink?

## GPIO Peripheral and Registers
Since your processor (the actual CPU) can only really do basic math and set values into registers, there are many subcircuits within your Microcontroller, called perihperals, which their behavior can be modified and controlled through a set of Special Function Registers.

How do we know what these registers are and how they impact the hardware? **We Read the Datasheet**

### MSP430FR2355 Documentation
You should already have these open, but there are 3 documents which you should have open immediately as soon as you want to touch your microcontroller:
* [Processor Family User Guide](https://www.ti.com/lit/ug/slau445i/slau445i.pdf?ts=1673210382968&ref_url=https%253A%252F%252Fwww.google.com%252F)
* [Processor Datasheet](https://www.ti.com/lit/ds/symlink/msp430fr2355.pdf?ts=1673210426796&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FMSP430FR2355)
* [Launchpad Datasheet](https://www.ti.com/lit/ug/slau680/slau680.pdf?ts=1673210462032&ref_url=https%253A%252F%252Fwww.google.com%252F)

**Family User Guide:** The internals for each microcontroller within the family of devices. Many things are similar across these processors, and this has the internal workings for many peripherals and registers.

**Datasheet:** This is specific to the Microcontroller itself and will detail specific pins, features, and other things which make it unique compared to other devices in the family.

**Launchpad Datasheet:** Contains useful information, schematics, and resources for using the Launchpad and its features.

### GPIO Peripheral and Pin Diagram
Looking at the **MSP430FR2355 Datasheet**, what we need to do is go to the section where they talk about the "Input/Output Diagrams", Section 6.11.

![Port 1 Pin diagram](https://i.gyazo.com/600f02922f88146d479f46bb710cfc67.png)

While there is a lot going on here, let's focus on what is in our code, and how it deals with this diagram.

#### Watchdog Timer
We are going to handwaive this a little bit, as what you need to really know about it, is it is an internal timer which is meant to pull the processor out of a stall or a glitch if something happens. This is great in practice, but we do not need it, so the first line: `WDTCTL = WDTPW | WDTHOLD;`, is telling the watchdog timer to turn off. That's all you need to know right now...

#### P1OUT - Output Register
![P1OUT Path](https://i.gyazo.com/526bead592ec8d30dc8ed64bedd9622c.png)
P1OUT can be selected through a MUX, and once it goes through a Tri-State Buffer, is actually **the register which controls the pin state**. A few things should immediately come into question:
* What is controlling the select of the MUX?
* What is enabling the Tri-State Buffer?

#### P1SEL0 and P1SEL1 (and why they are not set in the code)
![P1SEL0 and P1SEL1](https://i.gyazo.com/776ff874c4fa352dcc14789b1e3a431a.png)
The MUX is controlled by two other Registers: P1SEL0 and P1SEL1. But why are they not in the code? Well, if you look in the Family User Guide, you can find that P1SEL0 and P1SEL1 default to 0x00 upon a reset. What this means is that when the microcontroller is Reset, the MUX will be pointing to the 00 input, which is already P1OUT. Therefore, you do not need to explicitly set these values.

>**A word of caution:** I would get into the habbit of still setting these, as when your code gets more complex, there might be times where you assume PXSEL is set to a value, but it actually isnt.


#### P1DIR - Pin Direction Registers
![P1DIR](https://i.gyazo.com/771ec67e0d166629941ca02254992898.png)
The Tristate Buffer is controlled by the output of the above MUX. It is a little tricky to see in the diagram, but P1SEL0 and P1SEL1 both also control this MUX. This means that by default, this MUX is selecting the 00 input, which is P1DIR.

| P1DIR Value | Tristate Buffer Behaviour | Pin Behaviour |
| ------------- |-------------| -----|
| 0 | High-Z, Non-conducting | Input |
| 1 | Low-Z, Buffer | Output |


## Using the Other LED on Pin 6.6
So how do we make this code work for the LED on Pin 6.6? Well, let's take a look at the Port 6 Input/Output Diagram.

![Port 6 Diagram](https://i.gyazo.com/7211727b134f76d1eeb8092b574e0c86.png)

So interesting, it has the same configuration... which should really be expected. The GPIO peripheral should be something that is standardized, to make it as easy as possible to move between pins, and even from different microcontrollers within the same family. If we wanted to control the other LED instead, it looks like we just need to make a few quick substitutions:
* P1OUT --> P6OUT
* P1DIR --> P6DIR
* BIT0 --> BIT6 (Remember, this is specifically which pin we would like to control)

> **TASK:** Implement the changes in your code to make the LED on Pin 6.6 Blink instead of Pin 1.0

# Section Task: Blinking Both LEDS Alternately
To wrap up working with the basic output functions, you will need to combine what you have done to blink the Red and Green LED alternatively at a constant rate. The expected behavior is:
* Initialize to RED on, Green Off
* After 500ms, RED off, Green On
* After 500ms, RED On, Green Off
* Repeat endlessly

The deliverable for this section task is to upload a commented C file containing your work, an appropriate author block, and appropriate comments and variable names such that it is easy to see what you have done.

Some advice:
* Use __delay_cycles(), do not panic about precision timing yet.
* You can use a variety of methods, such as XOR to Toggle, explicitly setting the bits in PXOUT, etc.
* You may (however, it isnt necessary) need to use some variable to track the state you are in or different things.
* It is up to you how you want to do this, but I recommend not just compiling on a prayer. Take a minute, a piece of paper, and actually pseudocode the behavior you want.
