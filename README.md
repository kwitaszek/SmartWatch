# Pedometer build instructions

#### Table of Contents

1.[Introduction](https://github.com/kwitaszek/SmartWatch#introduction)

2.[Items to purchase](https://github.com/kwitaszek/SmartWatch#items-to-purchase)

3.[Total time for project](https://github.com/kwitaszek/SmartWatch#total-time-for-project)

4.[Soldering the Arduino and the other parts](https://github.com/kwitaszek/SmartWatch#soldering-the-arduino-pcb-and-other-parts)

5.[Flashing the software on the Arduino](https://github.com/kwitaszek/SmartWatch#flashing-the-software-on-the-arduino)

6.[Breadboard assembly](https://github.com/kwitaszek/SmartWatch#breadboard-assembly)

7.[Power Up](https://github.com/kwitaszek/SmartWatch#power-up)

8.[Soldering the PCB and its components](https://github.com/kwitaszek/SmartWatch#soldering-the-pcb-and-its-components)

9.[Power Up PCB](https://github.com/kwitaszek/SmartWatch#power-up-pcb)

10.[Unit Testing](https://github.com/kwitaszek/SmartWatch#unit-testing)

11.[Enclosure](https://github.com/kwitaszek/SmartWatch#enclosure)

12.[Production Testing](https://github.com/kwitaszek/SmartWatch#production-testing)

13.[Reproducible?]

## Introduction

Hello. My name is Kevin Witaszek and I am the author for the KX-023 Pedometer Sensor module build instructions for the Smart Watch project. The idea behind this project is to intergrate the pedometer sensor with an Arduino Pro Mini board. This sensor will work alongside a heart rate sensor module to build a smart watch which will be developed in the next semester with my partner Antonio Zuleta. Following the instructions below, you will create your own pedometer project which you can use for your own purposes. Let's begin.

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

## Items to purchase 

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images/Budget.png)

The above list includes what you need to make this project possible. All of these parts(except the sensor) are available on Amazon and if you have Amazon Prime, you can save on shipping to make the price go down. The total for me was 112 CAD dollars. The sensor can be obtained from eletronic stores or websites from China. Please be aware that shipping from China can take long or short so please try to find the best deal possible. The prices for the PCB and laser cutting might differ based on where you get it done. If you are a Humber Student, you havee free access to the services in the Prototype Lab. 

## Total time for project

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images/Schedule.png)

The above Gantt chart represents the schedule I used to schedule the steps I needed to work on during the project.
Considering the user already purchased and obtained all the items, the total time for making the project should be roughly around 10 hours.

## Soldering the Arduino, PCB and other parts

#### Prerequitsites:

Before we can start work on the project, we need to solder male header pins onto the Arduino and the other componennts. The position of the pins on the Arduino will be positioned as shown below. The pins on the sides have to be pointed downwards whereas the top pins need to be pointed upwards so that we can attach the USB to TTL adapter to our board. For the sensor,OLED screen and USB charger, the pins will be pointed downwards.

#### Step 1:

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images/solder_kit.png)

Get a soldering kit. If you are a student at Humber, you can rent a kit at the Humber Parts Crib and solder in areas where you have access to a fume extractor or if you have access to the Prototype Lab, you can do your work there.

#### Step 2: 

Prepare male header pins for the board. You will require 42 pins overall. For the Arduino, there are 12 on both sides, 6 on top and two in the middle. For the sensor and OLED screen, you will need 4 each and the USB charger will require 2 pins.

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images/male_header_pins.png)

#### Step 3:

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images/sponge.png)

Take the sponge off the kit and soak it in water.

#### Step 4:

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images/preheat.png)

Turn on the soldering kit and wait for the soldering iron to heat up. The proper temperature for soldering should be roughly 660 F.

#### Step 5:

Check your tip of your soldering iron. If it has a melted solder on it, it is ready for soldering. If not, tin the tip with some iron on the tip, soak it in the spondge and put the iron in steel wool to get rid of the excess solder.

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images/tip.png)

#### Step 6: 

Set the arduino and the pins on the breadboard so that the pins are stable for soldering. I ran out of header pins but you should set more pins on the other side of the arduino so that board is stable for soldering.

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images/setting_pins.png)

#### Step 7 Soldering the Arduino:

Prepare your solder in one hand and soldering iron in the other. Place your iron next to the area you want to solder in. Place the solder onto the tinned area and let the solder sink into the soldered area. This process should be 2-3 seconds for every hole.After finishing this should be the finished work:

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images/arduino_soldered(read).png)

#### Step 8 Soldering the components:

Repeat step 7 for the OLED screen, the sensor and the USB charger. All the pins on each component will face downward.
After you done this is how the finsihed work should look like.

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images/USB_charger.png)
![](https://github.com/kwitaszek/SmartWatch/blob/master/Images/OLED_soldered.png)
![](https://github.com/kwitaszek/SmartWatch/blob/master/Images/sensor_soldered.png)

Congrats if this is your first time soldering. After you are done, make sure to turn off the the iron in case you forget.

## Flashing the software on the Arduino

Now that you have soldered the pins on the Ardunio you are now able to put software the on the board.

Carefully connect the cable between the adapter and the board(the top 6 pins).

Adapter     Arduino:

3.3V  -->   VCC

GND   -->   GND

TXD   -->   RSX

RSX   -->   TXD

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images/adapter_connections.png)

Making sure the connections are correct, plug in the adapter into your PC. Once connected, your Arduino should be flashing blue meaning the connections are succesful.

Next, you will need an Arduino IDE. You can download the official IDE from the official Arduino website.

Once installed, you can use the code below and put it in the IDE

Download the code from the following link:
https://github.com/kwitaszek/SmartWatch/blob/master/Firmware/PedometerCode.ino

This code was made in C and is made specifally for the Arduino Pro Mini and the components.

This code will require the user to import libraries. The follwoing links will provide the user with the libraires required. Download the zip files and in the IDE you can import them following the below instruction:

Sketch --> Include library --> Add .ZIP Library

You will also need to set your tools. The device will be set as Arduino Pro Mini 3.3V 8 MHz and the the COM port the one that is associated with the USB adapter.

Tools --> Board:Arduino Pro Mini.

Tools --> Processor:Atmega328P(3.3V 8Mhz).

Tools --> Port:(Windows)COM , (Mac)UsbtoUART.

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images/tools.png)

Once the above steps are complete, compile and the code should flash onto the board.Now there was an issue with uploading the code unto the board. To avoid this issue, as soon as the prompt says Uploading.... Please press the reset button on the board. This will make the board available for code.


## Breadboard assembly

As the first step in any hardware project, it is wise to start with setting up a prototype on a breadboard. This is required as we need to check if the parts work properly before we continue with the project. Please assemble the parts on the breadboard as shown below:

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

This is what it should look on an actual breadboard:

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

## Power-Up Breadboard

At this stage, you should be able to power up the breadboard circuit. you are free to use the USB adapter or the USB charger as the power source. After the booting,the OLED screen should power up, displaying the screen as shown below:

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

## Soldering the PCB

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images/PCB_Design(read).png)

The image above is the designed PCB for the project. Please download the .fzz file from the link below and export the project for production in gerber format in Fritzing. Here, you will need to send the files generated by the program to a production company of your choice. For Humber students, the best and quickest option would be to send the files to the prototype lab as it takes up to 24 hours for the employees to make your pcb. For anyone not in Humber, there are various companies online that accept PCB projects but for a fee. Only thing to notice is that shipping may vary on company so try to find the best deal possible.

https://github.com/kwitaszek/SmartWatch/blob/master/Documentation/Pedometer_PCB.fzz

To start, please prepare female socket pins that we will be soldering onto the PCB.

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images/female_header_pins.png)

You will need 36 units for one PCB. 2 x 14 sockets , 1 x 2 sockets, 2 x 4 sockets and 2 x 1 sockets. Please refer to the image below to see how to set up the sockets on the board.

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images/PCB_top.png).

For this soldering process, you will be soldering on the bottom. Keep the PCB in place by placing the fockets on the bottom and then cafefully turning the PCB upside down.Then start soldering. The image below represents the finished work.

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images/PCB_Bottom.png)

After you are done, it will be wise to do continuity checks between pins. This is important as sometimes PCB production produces defective units. Using the continuity option on a Digital Multimeter, you can check for any potential shorts.

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images/)

## Power up PCB

Place the components as shown in the image below. You can either power up the board by using the USB charger or the USB adapter used to put code into the board. Once plugged in,your OLED screen should boot up with the dsiplayed string: 
"Steps 0".

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images/steps.png)

## Unit testing

Reaching this step confirms you were successful with the previous steps. To check if board is working properly, try shaking a board a couple of times. This will increment the step counter thats being displayed on the board.

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images/steps_8.png)

## Enclosure

Below you will find the link to the enclosure file which was made in Corel Draw Graphics suite. If you are a Humber student or employee, you can send the file to the Prototype Lab at North Campus which would laser cut the project with clear acrylic. After obtanining the top and bottom layers, you can assemble the enclosure using standoff screws which can be obtained from the parts crib or from amazon. The finished project will be as shown below:

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images/)

## Production testing

If there were to be massive production done for the project, I would suggest making a circut tester that would check connections between the pins. It would enter into the the board through the female header pins using male header pins.
The board would have two LEDs: a green and red. If the green LED lights up, it means there are no shorts between the ground and power.

## Reproducible?

Following the steps above, I am certain that you will be able to to reproduce the project I was able to complete.






