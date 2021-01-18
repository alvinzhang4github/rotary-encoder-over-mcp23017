#include "Wire.h"
 
void setup()
{
Wire.begin(); // wake up I2C bus
// set I/O pins to outputs
Wire.beginTransmission(0x20);
Wire.write(0x00); // IODIRA register
Wire.write(0x00); // set all of port A to outputs
Wire.endTransmission();
}
 
void loop()
{
Wire.beginTransmission(0x20);
Wire.write(0x12); // address bank A
Wire.write((byte)0xAA); // value to send - all HIGH
Wire.endTransmission();
delay(500);
Wire.beginTransmission(0x20);
Wire.write(0x12); // address bank A
Wire.write((byte)0x55); // value to send - all HIGH
Wire.endTransmission();
delay(500);
}