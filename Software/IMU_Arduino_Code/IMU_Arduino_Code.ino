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

// Set the FreeIMU object
FreeSixIMU my3IMU = FreeSixIMU();

void setup() {
 Serial.begin(115200);
 Wire.begin();

 delay(5);
 
 my3IMU.init();

 
}


void loop() { 
 //my3IMU.getRawValues(rawq);
  //magn.getRaw(&magx,&magy,&magz);
  my3IMU.getQ(q);

 serialPrintFloatArr(q, 4);
 Serial.println(""); //line break

 delay(10);
}
