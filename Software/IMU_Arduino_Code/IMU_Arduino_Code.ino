////////////////////////////////////////////////////////////
// FreeSixIMU with datalogger
//
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
#include <SPI.h>
#include <SD.h>


float q[9]; //hold q values
int rawq[9];
int chipSelect = 10; //Set chip select for SD card to 10
// Set the FreeIMU object
FreeSixIMU my3IMU = FreeSixIMU();

void setup() {
 Serial.begin(115200);
 Serial.print("Initializing SD card...");

 // see if the card is present and can be initialized:
 if (!SD.begin(chipSelect)) {
  Serial.println("Card failed, or not present");
  // don't do anything more:
  while (1);
 }
 Serial.println("card initialized.");
 Wire.begin();

 delay(5);
 
 my3IMU.init();

 // delete file from the SD card if it already exists
 if (SD.exists("datalog.txt"))
 {
    SD.remove("datalog.txt");
    Serial.println("Old data log file deleted");
 }
  

 Serial.println("Starting Data");

}


void loop() { 
  my3IMU.getRawValues(rawq);
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  String dataString = "";
  
  if (dataFile)
  {
    dataString = String(rawq[0]) + "," + String(rawq[1]) + "," + String(rawq[2]) + "," + 
    String(rawq[3]) + ","  + String(rawq[4]) + "," + String(rawq[5]) + "," + 
    String(rawq[6]) + "," + String(rawq[7]) + "," + String(rawq[8]);
    dataFile.println(dataString);
    dataFile.close();
  }else
  {
    Serial.println(rawq[0]);
    Serial.println(rawq[1]);
    Serial.println(rawq[2]);
    Serial.println(rawq[3]);
    Serial.println(rawq[4]);
    Serial.println(rawq[5]);
    Serial.println(rawq[6]);
    Serial.println(rawq[7]);
    Serial.println(rawq[8]);
  }

}
