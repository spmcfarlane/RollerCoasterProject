#define DEBUG
#ifdef DEBUG
#include "DebugUtils.h"
#endif

#include "CommunicationUtils.h"
#include "FreeSixIMU.h"
#include "IST8310.h"
#include <Wire.h>
#include <SD.h>
#include <SPI.h>

IST8310 mag = IST8310();
int magx;
int magy;
int magz;
int x1,x2,y1,y2,z1,z2;
char magID;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Am I alive?");
  Wire.begin();
  mag.init();
  magID = mag.getID();
  if (magID == 16) //ID register from the IST8310 Datasheet
  {
    Serial.println("ID verification success");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //mag.getISTIntValues(magx, magy, magz);

  /*
  mag.getRaw(&magx, &magy, &magz);
  Serial.println(magx, DEC);
  Serial.println(magy, DEC);
  Serial.println(magz, DEC);
  delay(10);
  */

  Wire.beginTransmission(IST8310_ADDR);
  Wire.write(IST8310_R_CTRL1);
  Wire.write(0x01);
  Wire.endTransmission();
  delay(6);
  Wire.beginTransmission(IST8310_ADDR);
  Wire.write(byte(0x03));
  Wire.endTransmission();
  Wire.beginTransmission(IST8310_ADDR);
  Wire.requestFrom(IST8310_ADDR,6);
  Serial.print(Wire.available());
  x1 = Wire.read();
  x2 = Wire.read();
  y1 = Wire.read();
  y2 = Wire.read();
  z1 = Wire.read();
  z2 = Wire.read();
  Wire.endTransmission();
  Serial.println(x1);
  Serial.println(x2);
  Serial.println(y1);
  Serial.println(y2);
  Serial.println(z1);
  Serial.println(z2);
  delay(100);

}
