// Test circuit for esp32cam
// and MCP23017 GPIO Expander
// Standard SDA is 21 and SCL is 22
// Use wire.h to change SDA SCL pins...
// When Flashing - put USB SDA SCL pins for esp32 on SDA 21 and SCL 22
// When Flashing - put USB on standard flashing pins...

#include <Wire.h> // set Wire.begin(SDA, SCL)
#include "Adafruit_MCP23017.h"

Adafruit_MCP23017 mcp; // Instantiate mcp object
int dly = 500; // 1/4 second delay

void setup(){
Serial.begin(115200);
Serial.println("Setup starting: Ready");

Wire.begin(12, 14); // NOTE '//' out Wire.begin in MCP23017.cpp library! Or will not map pins!!

mcp.begin(); // "Start" the mcp object

mcp.pinMode(0, OUTPUT); // relay 
mcp.pinMode(1, INPUT); // push button - green
mcp.pullUp(1, HIGH); // turn on a 100K pullup internally
mcp.pinMode(2, INPUT); // touch sensor - filzer custom
mcp.pullUp(2, HIGH); // turn on a 100K pullup internally 

}

void loop(){

// Digital write test - for Relay testing


Serial.print("Relay - Flashing GPIO: "); // Tell us what pin is flashing.

mcp.digitalWrite(0, HIGH); // Set pin HIGH (on)
delay(dly); // On for 1/4 second
mcp.digitalWrite(0, LOW); // Set pin LOW (off)
delay(dly); // Off for 1/4 Second



// digit read test - for push buttons x2

int val1 = mcp.digitalRead(1); // Read the value of pin P1 
int val2 = mcp.digitalRead(2); // Read the value of pin P2 


if (val1 == HIGH) Serial.print("Button: HIGH"); // If Button is Pressed
else 
Serial.print("Button: LOW"); // When Button is Released
delay(50);
Serial.print("\t");

if (val2 == HIGH) Serial.print("Touch Sensor: HIGH"); // If Button is Pressed
else 
Serial.print("Touch Sensor: LOW"); // When Button is Released
delay(50);
Serial.print("\t");

Serial.println();

}