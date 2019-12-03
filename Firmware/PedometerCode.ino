#include <Wire.h>
#include <Adafruit_GFX.h>  // Include core graphics library for the display
#include <Adafruit_SSD1306.h>  // Include Adafruit_SSD1306 library to drive the display
#include <Adafruit_SSD1306.h>
#include <splash.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>


Adafruit_SSD1306 display(128, 64);  // Create display


#include <Fonts/FreeMonoBold12pt7b.h>  // Add a custom font
#include <Fonts/FreeMono9pt7b.h>  // Add a custom font

union data {
  int16_t data16;
  byte  byteStr[2];//{*DATAL,*DATAH}
};
union data xData;
union data yData;
union data zData;

const int sendorDeviceAddress = 0x1F;//I2C7bitAddressMode
const int regAddressXOUTL = 0x06;
const int regAddressYOUTL = 0x08;
const int regAddressZOUTL = 0x0A;
const int regAddressODCNTL = 0x1B;
const int regAddressCNTL1 = 0x18;

int steps=0;


void setup() {
   
  Serial.begin(115200);

  //KX023debice initialize
  Wire.begin();
  //stunbymode fullPower GLange2g
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
  
  //set device standbyMode
  //readCNTL1reg
  byte CNTL1 = 0;
  Wire.beginTransmission(sendorDeviceAddress);
  Wire.write(regAddressCNTL1);
  Wire.endTransmission();
  Wire.requestFrom(sendorDeviceAddress, 1);
  CNTL1 = Wire.read();
  //setCNTL1reg
  CNTL1 = CNTL1 & 0b01111111;
  Wire.beginTransmission(sendorDeviceAddress);
  Wire.write(regAddressCNTL1);
  Wire.write(CNTL1);
  Wire.endTransmission();

  //set LPF parameters
  //readODCNTLreg
  byte ODCNTL = 0;
  Wire.beginTransmission(sendorDeviceAddress);
  Wire.write(regAddressODCNTL);
  Wire.endTransmission();
  Wire.requestFrom(sendorDeviceAddress, 1);
  ODCNTL = Wire.read();
  //setODCNTLreg
  ODCNTL = ODCNTL | 0b01000000;//set filter corner frequency set to ODR/2
  ODCNTL = ODCNTL & 0b11110000;//set OutputDataRate 12.5Hz
  Wire.beginTransmission(sendorDeviceAddress);
  Wire.write(regAddressODCNTL);
  Wire.write(ODCNTL);
  Wire.endTransmission();
  
  //set device operating mode
  //readCNTL1reg
  Wire.beginTransmission(sendorDeviceAddress);
  Wire.write(regAddressCNTL1);
  Wire.endTransmission();
  Wire.requestFrom(sendorDeviceAddress, 1);
  CNTL1 = Wire.read();
  //setCNTL1reg
  CNTL1 = CNTL1 | 0b10000000;
  Wire.beginTransmission(sendorDeviceAddress);
  Wire.write(regAddressCNTL1);
  Wire.write(CNTL1);
  Wire.endTransmission();

  //DISPLAY
  
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

  Serial.print(xData.data16, DEC);
  Serial.print(",");
  Serial.print(yData.data16, DEC);
  Serial.print(",");
  Serial.println(zData.data16, DEC);


//?
double Norm = sqrt(double(pow(xdata,2) + pow(ydata,2) + pow(zdata,2)))-(32767/2);
//Serial.print(Norm,DEC);
//Serial.print(',');

static double vector = vector+Norm;
Serial.println(vector,DEC);

  if(Norm > 4500)
  {
    steps+=1;  
  }
  Serial.print("Steps:");
  Serial.print(steps);
  Serial.println("");

  display.clearDisplay();  // Clear the display so we can refresh
  display.setFont(&FreeMonoBold12pt7b);  // Set a custom font
  display.setTextSize(0);  // Set text size. We are using a custom font so you should always use the text size of 0
  display.setCursor(85, 32);  // (x,y)
  display.println(steps);  // Text or value to print

  display.setCursor(0,32);
  display.setTextSize(0);  // Set text size. We are using a custom font so you should always use the text size of 0
  display.println("Steps");

  display.display();  // Print everything we set previously


  delay(100);

}
