# Part 1: Getting Started with Code Composer and Resource Explorer
Code Composer is the IDE we will be using for the semester with the TI MSP430 line of microcontrollers. Before this lab, you should have had it installed, but if you need to still get it, you can grab it from [TIs Website](https://www.ti.com/tool/CCSTUDIO). You _WILL_ need to install it and make a TI account to get this. The Cloud Agent is useful; however, there are several tools such as the register inspector and energy trace which will be extremely useful in the class. From this point, we are assuming you have installed Code Composer.

Tasks for this part of the lab:
- [ ] Open and import the basic LED P1.0 Example from Resource Explorer

## Importing an Example Project from the Resource Explorer
There are two main ways to make a project in Code Composer Studio: from scratch, or from an example in the Resource Explorer. We are going to start where you genuinely always should, the Resource Explorer. This is available online through the [TI Resource Explorer Website](https://dev.ti.com/tirex/), but more importantly, it is also accessible in Code Composer Studio directly.

### Accessing the Resource Explorer in Code Composer Studio
There are two ways to access the resource explorer in CCS.

First is the getting started page.
![Clicking Resource Explorer on the Getting Started Page](https://i.gyazo.com/ba61d25e61b59dde7713247cf84ee0f7.gif)

Second is clicking on `View --> Resource Explorer`.
![Going through the View Menu](https://i.gyazo.com/2cab5e4635726949df54476a5abb587b.gif)

I would recommend trying to get the Offline version of the Resource Explorer if possible to make it easier to work with, but the online version is also fine.

### Selecting your Processor
If you have your Launchpad plugged in, it might already choose the right board for you. But typically, you will need to search for it. You can type in "MSP430FR2355" into the search bar and it should bring you to that board.
![Searching for the microcontroller](https://i.gyazo.com/ed891a32b40c2e740b7fd72c72521aba.gif)

You should notice that the folders and resources on the left hand side have been narrowed down to those which apply to your board.

To get to the Register Level examples TI has provided you need to go through the following folders:
`MSP430 Microcontrollers / Embedded Software / MSP430Ware / Devices / MSP430FR2XX_4XX / Peripheral Examples / Register Level`
![Directory Tree to get to examples](https://i.gyazo.com/952ae279d465ddd81a289069c12f0598.png)

### Importing the LED Example
We aren't kidding when we say the first thing any embedded developer does is blink an LED, and TI knows this. The first example listed is the one we need: _msp430fr235x_1.c_

From here, the example should open in the window, and it will look like a lot. Most of this is a copyright statement and introductory comments to understand what the code is doing. You could just copy and paste the code, but instead, we are actually going to _Import_ it into our workspace as a whole project.

On the right, you should see a symbol that says "Import". Clicking this it will ask you for a specific processor. Make sure you pick the _MSP430FR2355_. If it is your first time importing, it might ask you to download the resource explorer, and you should let it. Once you do, a project is created in your workspace and it will open the main c file.
![Importing Project into Code Composer](https://i.gyazo.com/a6a28714f44edfe9aa6f38829f65a3f4.gif).

#### What is in a name
Breaking down that file name:
* msp430fr235x : This is the processor family. There are other processors which share similar features as this one, and this code can be used and was designed for those processors with the starting names given.
* _1.c: This is just example 1. Normally this would be an abbreviation for a peripheral to help figure out what the code is doing.

## Move on to Part 2 of the Lab
If you have successfully imported the project, you are ready to move on to the second part of the lab. Make sure in this README that you mark off in the list with an "[x]" that you have completed this. This specific part of the lab does not require a README or any submissions.
