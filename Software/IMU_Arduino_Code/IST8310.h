/*********************************************************
*                                                        *
* Author     : Sean McFarlane                            *
* Date       : 5/25/17                                   *
* File       : IST8310.h                                 *
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

#include "Arduino.h"
#include <Wire.h>

#ifndef IST8310_h
#define IST8310_h

//Define 7-Bit I2C address

#define IST8310_ADDR 0X0E

//Define regster map

#define IST8310_R_ID    0x00 //Device ID
#define IST8310_R_STAT1 0x02 //Data status 1
#define IST8310_R_XL    0x03 //Low Byte for X-Axis data
#define IST8310_R_XH    0x04 //High Byte for X-Axis data
#define IST8310_R_YL    0x05 //Low Byte for Y-Axis data
#define IST8310_R_YH    0x06 //High Byte for Y-Axis data
#define IST8310_R_ZL    0x07 //Low Byte for Z-Axis data
#define IST8310_R_ZH    0x08 //High Byte for Z-Axis data
#define IST8310_R_STAT2 0x09 //Data status 2
#define IST8310_R_CTRL1 0x0A //Chip control setting 1
#define IST8310_R_CTRL2 0x0B //Chip control setting 2
#define IST8310_R_TL    0x1C //Low Byte for Temp data
#define IST8310_R_TH    0x1D //High Byte for Temp data

class IST8310
{
   public:
      IST8310();
      void init();
      void init(int address, bool setmode);
      void getISTIntValues(int *x, int *y, int *z);
      void getISTFloatValues(float *x, float *y, float *z);
      void getValues(float *xyz);
      void getRaw(int *x, int *y, int *z);
      void getRaw(int *xyz);
      int  calibrate();
      void setMode(unsigned char mode);
      void setGain(unsigned char gain);
      void getID(char ID);
   private:
      void writeReg(unsigned char reg, unsigned char val);
      float x_scale,y_scale,z_scale,x_max,y_max,z_max;    
};

#endif




