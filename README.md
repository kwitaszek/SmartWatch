# Pedometer build instructions


Table of Contents

1.[Introduction](https://github.com/kwitaszek/SmartWatch#introduction)

2.[Items to purchase](https://github.com/kwitaszek/SmartWatch#introduction)

3.[Total time for project](https://github.com/kwitaszek/SmartWatch#total-time-for-project)

4.[Soldering the Arduino and the other parts](https://github.com/kwitaszek/SmartWatch#soldering-the-arduino-and-other-parts)

5.[Flashing the software on the Arduino](https://github.com/kwitaszek/SmartWatch#flashing-the-software-on-the-arduino)

6.[Breadboard assembly](https://github.com/kwitaszek/SmartWatch#breadboard-assembly)

7.[Soldering the PCB]()

8.[Power Up](https://github.com/kwitaszek/SmartWatch#power-up)

9.[Unit Testing]()

10.[Production Testing]()


### Introduction

Hello. My name is Kevin Witaszek and I am the author for the KX-023 Pedometer Sensor module build instructions for the Smart Watch project. The idea behind this project is to intergrate the pedometer sensor with an Arduino Pro Mini board. This sensor will work alongside a heart rate sensor module to build a smart watch which will be developed in the next semester with my partner Antonio Zuleta. Following the instructions below, you will create your own pedometer project which you can use for your own purposes. Let's begin.


### Items to purchase 


![](https://github.com/kwitaszek/SmartWatch/blob/master/Images/Budget.png)

The above list includes what you need to make this project possible. All of these parts(except the sensor) are available on Amazon and if you have Amazon Prime, you can save on shipping to make the price go down. The total for me was 112 CAD dollars. The sensor can be obtained from eletronic stores or websites from China. Please be aware that shipping from China can take long or short so please try to find the best deal possible.


### Total time for project


![](https://github.com/kwitaszek/SmartWatch/blob/master/Images/Schedule.png)

The above Gantt chart represents the schedule I used to schedule the steps i needed to work on the project.
Considering the user already pruchased and obtained all the items , the total time for making the project should be roughly around 10 hours .


### Soldering the Arduino and other parts

Prerequitsites:

Before we can start work on the project, we need to solder male header pins onto the arduino itself. It's cheap cost derives from the fact that the board comes without the pins soldered. The position of the pins will be position as shown below. the pins on the sides have to be pointed downwards whereas the top pins need to be pointed upwards so that we can attach the USB to TTL adapter to our board.

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)
![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

Step 1:

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

Get a soldering kit. If you are a student at Humber, you can rent a kit at the Humber Parts Crib and solder in areas where you have access to a fume extractor or if you have access to the Prototype Lab, you can do your work there.

Step 2: 

Prepare male header pins for the board. You will require 32 pins overall. 12 on both sides, 6 on top and two in the middle. For the sensor Oledn you will need 4 each and the usb hcarger will reuiqre 2 pins.

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

Step 3:

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

Take the sponge off the kit and soak it in water.

Step 4:

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

Turn on the soldering kit and wait for the soldering iron to heat up. The proper temperature for soldering should be 660 F.

Step 5:

Check your tip of your soldering iron. If it has a melted solder on it, it is ready for soldering. If not, melt some solder on the tip, soak it in the spondge and put the iron in steel wool to get rid of the excess solder.

Step 6: 

Set the arduino and the pins on the breadboard so that the pins are stable for soldering.

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

Step 7:

Prepare your solder in one hand and sodlering iron in another . Place your iron with the sodlered area near the scopper hole. Place the solcder and on the melted aread and let tahsodler sink inot the scopper hole. This process should be 2-3 seconds for every hole on the baord. after finishing this should be the fafinsihed work.

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

Step 8:

Repeat step 7 for the OLED screen, the sensor and the usb charger. All the pins on each component will face downwarsds.
After you done this is how the finsihed work should look like.

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)
![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)
![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

Congrats if this is yourr first time sodlering. After you are done, make sure to tunr off the the iron in case uyou forget.

### Flashing the software on the Arduino

Now that you ahve soldered the ardunio you are now able to put software the on the baord.

Carefully connect the cable between the adapter and the board.

Adapter:  Arduino:

3.3V   --> VCC

GND    --> GND

TXD    --> RSX

RSX    --> TXD

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

Making sure the connections are correct, plug in the adapter into your PC. Once connected, your adruino should be beeping bleu meaning the conenctionw as succesful.

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

Next, you will need an Arduino IDE. You can download the official IDE from the official Ardunio website.

Once installed you can use the code below and put it in the IDE

Download the code from the following link:
https://github.com/kwitaszek/SmartWatch/blob/master/Firmware/PedometerCode.ino
This code is made in C and is made specifally for the ardunio pro mini and the sensor attached.

This code will require the user to import libraires. The follwoing links will provide the user with the libraires. Download the zip files and in the IDE you can import them.

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

YOu will also need to set your tools. THe devie willbe the Arduni pro mini 3.3v 8 Mhz and tset the COM the one associated th the USB adapter.

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

Once the above steps are complete, compile and the code should flash onto theh baord.

### Breadboard assembly

As the first step in any hardware project, it is wise to start with setting up a prototype on a breadboard. This is required as we need to check if the parts work properly before we continue with the project. Please assemble the parts on the breadboard as shown below:


![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

### Power-Up

At this stage, you shoudl be able to pwoer up the breaboard curcuit. you are fre to use the adapter or the usb chager as the power source. After the booting,the oled screen shuld power up , disaplying the screen as shown below:

![](https://github.com/kwitaszek/SmartWatch/blob/master/Images)

### Soldering the PCB






