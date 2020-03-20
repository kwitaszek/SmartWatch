//Author: TECHBOYS
//Project: Smart Watch

//General Wiring library
#include <Wire.h>

//Bluetooth Library
#include "BluetoothSerial.h" //Header File for Serial Bluetooth, will be added by default into Arduino

//OLED Screen libraries
#include <Adafruit_GFX.h>  // Include core graphics library for the display
#include <Adafruit_SSD1306.h>  // Include Adafruit_SSD1306 library to drive the display
#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <Fonts/FreeMonoBold12pt7b.h>  // Add a custom font
#include <Fonts/FreeMono9pt7b.h>  // Add a custom font


// HeartBeat Sensor Libraries
#include <heartRate.h>
#include <MAX30105.h>
#include <spo2_algorithm.h>

//Global Variables


//Union for Pedometer Sensor
union data {
  int16_t data16;
  byte  byteStr[2];//{*DATAL,*DATAH}
};
union data xData;
union data yData;
union data zData;


//Global variables
Adafruit_SSD1306 display(128, 64);  // Create display
MAX30105 particleSensor;
const int sendorDeviceAddress = 0x1F;//I2C7bitAddressMode
const int regAddressXOUTL = 0x06;
const int regAddressYOUTL = 0x08;
const int regAddressZOUTL = 0x0A;
const int regAddressODCNTL = 0x1B;
const int regAddressCNTL1 = 0x18;
int steps=0;
const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.
byte rates[RATE_SIZE]; //Array of heart rates
byte rateSpot = 0;
long lastBeat = 0; //Time at which the last beat occurred
float beatsPerMinute;
int beatAvg;

BluetoothSerial ESP_BT; //Object for Bluetooth



void setup() {
   
  Serial.begin(115200);

  //KX023 Sensor Setup
  Wire.begin();
  Wire.beginTransmission(sendorDeviceAddress);
  Wire.write(0x18);
  Wire.write(0x40);
  Wire.endTransmission();
  //outPutDataLate 50Hz
  Wire.beginTransmission(sendorDeviceAddress);
  Wire.write(0x1B);
  Wire.write(0x02);
  Wire.endTransmission();
  //sensor WakeUp
  Wire.beginTransmission(sendorDeviceAddress);
  Wire.write(0x18);
  Wire.write(0xC0);
  Wire.endTransmission();
  
  byte CNTL1 = 0;
  Wire.beginTransmission(sendorDeviceAddress);
  Wire.write(regAddressCNTL1);
  Wire.endTransmission();
  Wire.requestFrom(sendorDeviceAddress, 1);
  CNTL1 = Wire.read();
  CNTL1 = CNTL1 & 0b01111111;
  Wire.beginTransmission(sendorDeviceAddress);
  Wire.write(regAddressCNTL1);
  Wire.write(CNTL1);
  Wire.endTransmission();

  byte ODCNTL = 0;
  Wire.beginTransmission(sendorDeviceAddress);
  Wire.write(regAddressODCNTL);
  Wire.endTransmission();
  Wire.requestFrom(sendorDeviceAddress, 1);
  ODCNTL = Wire.read();
  ODCNTL = ODCNTL | 0b01000000;//set filter corner frequency set to ODR/2
  ODCNTL = ODCNTL & 0b11110000;//set OutputDataRate 12.5Hz
  Wire.beginTransmission(sendorDeviceAddress);
  Wire.write(regAddressODCNTL);
  Wire.write(ODCNTL);
  Wire.endTransmission();
  
  Wire.beginTransmission(sendorDeviceAddress);
  Wire.write(regAddressCNTL1);
  Wire.endTransmission();
  Wire.requestFrom(sendorDeviceAddress, 1);
  CNTL1 = Wire.read();
  CNTL1 = CNTL1 | 0b10000000;
  Wire.beginTransmission(sendorDeviceAddress);
  Wire.write(regAddressCNTL1);
  Wire.write(CNTL1);
  Wire.endTransmission();

  // Heart Beat Sensor Setup
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) //Use default I2C port, 400kHz speed
  {
    Serial.println("MAX30105 was not found. Please check wiring/power. ");
    while (1);
  }
  Serial.println("Place your index finger on the sensor with steady pressure.");
  
  particleSensor.setup(); //Configure sensor with default settings
  particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
  particleSensor.setPulseAmplitudeGreen(0); //Turn off Green LED

  //Display setup
  delay(100);  // This delay is needed to let the display to initialize
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize display with the I2C address of 0x3C
  display.clearDisplay();  // Clear the buffer
  display.setTextColor(WHITE);  // Set color of the text
  display.setRotation(0);  // Set orientation. Goes from 0, 1, 2 or 3
  display.setTextWrap(false);  // By default, long lines of text are set to automatically “wrap” back to the leftmost column.
                               // To override this behavior (so text will run off the right side of the display - useful for
                               // scrolling marquee effects), use setTextWrap(false). The normal wrapping behavior is restored
                               // with setTextWrap(true).
  display.dim(0);  //Set brightness (0 is maximun and 1 is a little dim)

  ESP_BT.begin("ESP32"); //Name of your Bluetooth Signal
  Serial.println("Bluetooth Device is Ready to Pair");
  
}

void loop() {

  //readXout
  Wire.beginTransmission(sendorDeviceAddress);
  Wire.write(regAddressXOUTL);
  Wire.endTransmission();
  Wire.requestFrom(sendorDeviceAddress, 2);
  xData.byteStr[0] = Wire.read();
  xData.byteStr[1] = Wire.read();

  //readYout
  Wire.beginTransmission(sendorDeviceAddress);
  Wire.write(regAddressYOUTL);
  Wire.endTransmission();
  Wire.requestFrom(sendorDeviceAddress, 2);
  yData.byteStr[0] = Wire.read();
  yData.byteStr[1] = Wire.read();

  //readZout
  Wire.beginTransmission(sendorDeviceAddress);
  Wire.write(regAddressZOUTL);
  Wire.endTransmission();
  Wire.requestFrom(sendorDeviceAddress, 2);
  zData.byteStr[0] = Wire.read();
  zData.byteStr[1] = Wire.read();

  //rawDataOutput
  Serial.print("x:");
  Serial.print(xData.data16, DEC);
  Serial.print(",");
  Serial.print("y:");
  Serial.print(yData.data16, DEC);
  Serial.print(",");
  Serial.print("z:");
  Serial.println(zData.data16, DEC);

  long xdata = xData.data16;
  long ydata = yData.data16;
  long zdata = zData.data16;

  //Serial.print(xData.data16, DEC);
  //Serial.print(",");
  //Serial.print(yData.data16, DEC);
  //Serial.print(",");
  //Serial.println(zData.data16, DEC);


//?
double Norm = sqrt(double(pow(xdata,2) + pow(ydata,2) + pow(zdata,2)))-(32767/2);
//Serial.print(Norm,DEC);
//Serial.print(',');

static double vector = vector+Norm;
//Serial.println(vector,DEC);

  if(Norm > 2000)
  {
    steps+=1;  
  }

long irValue = particleSensor.getIR();
  
  if (checkForBeat(irValue) == true)
  {
    //We sensed a beat!
    long delta = millis() - lastBeat;
    lastBeat = millis();
    
    beatsPerMinute = 60 / (delta / 1);
    
    if (beatsPerMinute < 255 && beatsPerMinute > 20)
    {
    rates[rateSpot++] = (byte)beatsPerMinute; //Store this reading in the array
    rateSpot %= RATE_SIZE; //Wrap variable
    
    //Take average of readings
    beatAvg = 0;
    for (byte x = 0 ; x < RATE_SIZE ; x++)
    beatAvg += rates[x];
    beatAvg /= RATE_SIZE;

    
    
    }
  }

  Serial.print("IR=");
  Serial.print(irValue);
  Serial.print(", BPM=");
  Serial.print(beatsPerMinute);
  Serial.print(", Avg BPM=");
  Serial.print(beatAvg);
  
  if (irValue < 50000)
    Serial.print(" No finger?");
  
  Serial.println();

  
  Serial.print("Steps:");
  Serial.print(steps);
  Serial.println("");
  
  display.clearDisplay();  // Clear the display so we can refresh
  
  display.setCursor(0,16);
  display.setTextSize(0.5);  // Set text size. We are using a custom font so you should always use the text size of 0
  display.println("Techboys Prototype");
  
  display.setTextSize(1);  // Set text size. We are using a custom font so you should always use the text size of 0
  display.setCursor(85, 32);  // (x,y)
  display.println(beatsPerMinute);  // Text or value to print

  
  display.setCursor(0,32);
  display.setTextSize(1);  // Set text size. We are using a custom font so you should always use the text size of 0
  display.println("HeartBeat");

  display.setCursor(85,48);
  display.setTextSize(1);  // Set text size. We are using a custom font so you should always use the text size of 0
  display.println(steps);

  display.setCursor(0,48);
  display.setTextSize(1);  // Set text size. We are using a custom font so you should always use the text size of 0
  display.println("Steps");

  display.display();  // Print everything we set previously

  ESP_BT.print(steps);    


  delay(500);

  }
