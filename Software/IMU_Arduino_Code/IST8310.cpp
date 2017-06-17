/*********************************************************
*                                                        *
* Author     : Sean McFarlane                            *
* Date       : 5/25/17                                   *
* File       : IST8310.cpp                               *
* Description: Interface a IST8310 to an Arduino via I2C *
**********************************************************
*                                                        *
* This program is free software; you can redistribute	   *
* it under the terms of the GNU license.                 * 
* This program is distributed in the hope that it will   *
* be useful, but WITHOUT ANY WARRANTY; without even the  *
* implied warranty of MERCHANTABILITY or FITNESS FOR A   *
* PARTICULAR PURPOSE. See the GNU General Public License * 
* for more details.                                      *
*                                                        *
* You should have received a copy of the GNU General     *
* Public License along with this program.  If not, see   *
* <http://www.gnu.org/licenses/>.                        *
*                                                        *
* This library borrows heavily from the HMC5883 library  *
* written by Fabio Varesano Â© 2011                       *
**********************************************************
*                                                        *
**********************************************************
*                                                        *
* The IST8310 is a replacement for the popular           *
* Honeywell HMC5883 3-axis magnetometer distributed by   *
* ISentek. It is described as pin-to-pin compatible and  *
* has a very similar register map.                       *
*                                                        *
*********************************************************/

#include "IST8310.h"

IST8310::IST8310()
{
  
}
void IST8310::init()
{
   delay(5);
   
   writeReg(0x41, 0x24); //set averaging to 16 samples
   writeReg(0x42, 0xC0);  //set pulse duraction to normal (recommended)
}

void IST8310::setMode(unsigned char mode)
{
   if(mode > 2)
      return;
   
   writeReg(IST8310_R_CTRL1, mode);
   delay(100);
}

int IST8310::calibrate()
{
   // This calibrate function works with the self test function.
   // Take measurements before and after self test mode has been 
   // turned on. If the absolute values are the same, then the 
   // axis measurements are accurate
   
   float x1,y1,z1;
   float x2,y2,z2;
   float abs_x, abs_y, abs_z;
   
   getISTFloatValues(&x1,&y1,&z1);
   
   writeReg(0x0C, 0x40); //enable self test mode
   
   getISTFloatValues(&x2,&y2,&z2);
   
   abs_x = abs(x2-x1);
   abs_y = abs(y2-y1);
   abs_z = abs(z2-z1);
   
   //I figure +- 5% is good enough for my purposes
   if (abs_x > (abs_y - abs_y*0.05) && abs_x < (abs_y + abs_y*0.05))
   { 
      if (abs_x > (abs_z - abs_z*0.05) && abs_x < (abs_z + abs_z*0.05))
         return 1;
      else
         return 0;
   }   
   writeReg(0x0C, 0x00); //Disable self test mode;
   
}

void IST8310::writeReg(unsigned char reg, unsigned char val)
{
   Wire.beginTransmission(IST8310_ADDR);
   Wire.write(reg);
   Wire.write(val);
   Wire.endTransmission();
}

void IST8310::getISTIntValues(int *x, int *y, int *z)
{
   float fx, fy, fz;
   getISTFloatValues(&fx, &fy, &fz);
   *x = (int) (fx + 0.5);
   *y = (int) (fy + 0.5);
   *z = (int) (fz + 0.5);
   
}

void IST8310::getISTFloatValues(float *x, float *y, float *z)
{
   int xr, yr, zr;
   
   getRaw(&xr, &yr, &zr);
   *x = ((float) xr) / x_scale;
   *y = ((float) yr) / y_scale;
   *z = ((float) zr) / z_scale;
}

void IST8310::getRaw(int *x, int *y, int *z)
{
   writeReg(IST8310_R_CTRL1, 0x01);
   delay(6);
   Wire.beginTransmission(IST8310_ADDR);
   Wire.write(byte(0x03));
   Wire.endTransmission();
   Wire.requestFrom(IST8310_ADDR,6);
   Serial.print(Wire.available());
   *x = (Wire.read() << 8) || Wire.read();
   *y = (Wire.read() << 8) || Wire.read();
   *z = (Wire.read() << 8) || Wire.read();
   Wire.endTransmission();
}
   
void IST8310::getValues(float *xyz)
{
   getISTFloatValues(&xyz[0], &xyz[1], &xyz[2]);
}   

void IST8310::getID(char ID)
{
   Wire.beginTransmission(IST8310_ADDR);
   Wire.write(IST8310_R_ID);
   Wire.endTransmission();
   Wire.beginTransmission(IST8310_ADDR);
   Wire.requestFrom(IST8310_ADDR, 1);
   Serial.print(ID);
   Wire.endTransmission();
}


