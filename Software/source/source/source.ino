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


float q[5]; //hold q values

// Set the FreeIMU object
FreeSixIMU my3IMU = FreeSixIMU();

void setup() {
 Serial.begin(115200);
 Wire.begin();

 delay(5);
 Serial.print("Initializing");
 
 my3IMU.init();
 
 Serial.print("Initialization Complete");
}


void loop() { 
 my3IMU.getValues(q);
 Serial.print(q[0], DEC);
 Serial.print(" ");
 Serial.print(q[1], DEC);
 Serial.print(" ");
 Serial.print(q[2], DEC);
 Serial.print(" ");
 Serial.print(q[3], DEC);
 Serial.print(" ");
 Serial.print(q[4], DEC);
 Serial.print(" ");
 Serial.print(q[5], DEC);
 Serial.println(""); //line break

 delay(10);
}
