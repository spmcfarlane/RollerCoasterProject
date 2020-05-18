////////////////////////////////////////////////////////////
// Arduino firmware for use with FreeSixCube processing example
////////////////////////////////////////////////////////////


//#include <FIMU_ADXL345.h>
//#include <FIMU_ITG3200.h>

#define DEBUG
#ifdef DEBUG
#include "DebugUtils.h"
#endif

#include "CommunicationUtils.h"
#include "FreeSixIMU.h"
#include <Wire.h>
#include <SoftwareSerial.h>

SoftwareSerial XBee(2,3);


float q[9]; //hold q values
int rawq[8];
float mag_readings[3];
int magx;
int magy;
int magz;
IST8310 magn = IST8310();

// Set the FreeIMU object
FreeSixIMU my3IMU = FreeSixIMU();

void setup() {
 Serial.begin(115200);
 Wire.begin();

 delay(5);
 
 my3IMU.init();

 Serial.println("Starting Data");
 
}


void loop() { 
  my3IMU.getRawValues(rawq);
  magn.getRaw(&magx,&magy,&magz);

 //serialPrintFloatArr(q, 4);
 Serial.println(magx);
 Serial.println(magy);
 Serial.println(magz);
 delay(100); //line break

}
