# Pedometer build instructions

#### Table of Contents

1.[Introduction](https://github.com/kwitaszek/SmartWatch#introduction)

2.[Items to purchase](https://github.com/kwitaszek/SmartWatch#items-to-purchase)

3.[Total time for project](https://github.com/kwitaszek/SmartWatch#total-time-for-project)

4.[Soldering the Arduino and the other parts](https://github.com/kwitaszek/SmartWatch#soldering-the-arduino-pcb-and-other-parts)

5.[Flashing the software on the Arduino](https://github.com/kwitaszek/SmartWatch#flashing-the-software-on-the-arduino)

6.[Breadboard assembly](https://github.com/kwitaszek/SmartWatch#breadboard-assembly)

7.[Power Up](https://github.com/kwitaszek/SmartWatch#power-up)

8.[Unit Testing](https://github.com/kwitaszek/SmartWatch#unit-testing)

9.[Production Testing](https://github.com/kwitaszek/SmartWatch#production-testing)

## Introduction

Hello. My name is Kevin Witaszek and I am the author for the KX-023 Pedometer Sensor module build instructions for the Smart Watch project. The idea behind this project is to intergrate the pedometer sensor with an Arduino Pro Mini board. This sensor will work alongside a heart rate sensor module to build a smart watch which will be developed in the next semester with my partner Antonio Zuleta. Following the instructions below, you will create your own pedometer project which you can use for your own purposes. Let's begin.

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

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)
![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)
![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)
![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

#### Step 1:

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

Get a soldering kit. If you are a student at Humber, you can rent a kit at the Humber Parts Crib and solder in areas where you have access to a fume extractor or if you have access to the Prototype Lab, you can do your work there.

#### Step 2: 

Prepare male header pins for the board. You will require 42 pins overall. For the Arduino, there are 12 on both sides, 6 on top and two in the middle. For the sensor and OLED screen, you will need 4 each and the USB charger will require 2 pins.

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

#### Step 3:

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

Take the sponge off the kit and soak it in water.

#### Step 4:

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

Turn on the soldering kit and wait for the soldering iron to heat up. The proper temperature for soldering should be roughly 660 F.

#### Step 5:

Check your tip of your soldering iron. If it has a melted solder on it, it is ready for soldering. If not, tin the tip with some iron on the tip, soak it in the spondge and put the iron in steel wool to get rid of the excess solder.

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

#### Step 6: 

Set the arduino and the pins on the breadboard so that the pins are stable for soldering.

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

#### Step 7 Soldering the Arduino:

Prepare your solder in one hand and soldering iron in the other. Place your iron next to the area you want to solder in. Place the solder onto the tinned area and let the solder sink into the soldered area. This process should be 2-3 seconds for every hole.After finishing this should be the finished work:

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

#### Step 8 Soldering the components:

Repeat step 7 for the OLED screen, the sensor and the USB charger. All the pins on each component will face downward.
After you done this is how the finsihed work should look like.

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)
![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)
![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

Congrats if this is your first time soldering. After you are done, make sure to turn off the the iron in case you forget.

## Flashing the software on the Arduino

Now that you have soldered the pins on the Ardunio you are now able to put software the on the board.

Carefully connect the cable between the adapter and the board(the top 6 pins).

Adapter     Arduino:

3.3V  -->   VCC

GND   -->   GND

TXD   -->   RSX

RSX   -->   TXD

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

Making sure the connections are correct, plug in the adapter into your PC. Once connected, your Arduino should be flashing blue meaning the connections are succesful.

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

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

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

Once the above steps are complete, compile and the code should flash onto theh board.Now there was an issue with uploading the code unto the board. To avoid this issue, as soon as the prompt says Uploading.... Please press the reset button on the board. This will make the board available for code.


## Breadboard assembly

As the first step in any hardware project, it is wise to start with setting up a prototype on a breadboard. This is required as we need to check if the parts work properly before we continue with the project. Please assemble the parts on the breadboard as shown below:

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

This is what it should look on an actual breadboard:

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

## Power-Up

At this stage, you should be able to power up the breadboard circuit. you are free to use the USB adapter or the USB charger as the power source. After the booting,the OLED screen should power up, displaying the screen as shown below:

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

## Unit testing

Reaching this step confirms you were successful with the previous steps. To check if board is working properly, try shaking a board a couple of times. This will increment the step counter thats being displayed on the board.

## Production testing






