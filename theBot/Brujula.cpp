

#include "Brujula.h"

/* ESQUEMA DE CONEXION DE BRUJULA

http://2.bp.blogspot.com/-spu31Kj1NQw/TwLCYj4MJFI/AAAAAAAAABM/Jot68BKVsFI/s1600/Arduino_ADXL335_HMC6352.png
*/


Brujula::Brujula(){


}

void Brujula::setup(){

  HMC6352Address = 0x42;
  slaveAddress = HMC6352Address >> 1;   // This results in 0x21 as the address to pass to TWI
  ledPin = 13;
  ledState = false;
  pinMode(ledPin, OUTPUT);      // Set the LED pin as output
  Wire.begin();

}

void Brujula::direccion(){


  Wire.beginTransmission(slaveAddress);
  Wire.write("A");              // The "Get Data" command
  Wire.endTransmission();
  delay(10);                   // The HMC6352 needs at least a 70us (microsecond) delay
  // after this command.  Using 10ms just makes it safe
  // Read the 2 heading bytes, MSB first
  // The resulting 16bit word is the compass heading in 10th's of a degree
  // For example: a heading of 1345 would be 134.5 degrees
  Wire.requestFrom(slaveAddress, 2);        // Request the 2 byte heading (MSB comes first)
  int i = 0;
  while(Wire.available() && i < 2)
  { 
    headingData[i] = Wire.read();
    i++;
  }
  headingValue = headingData[0]*256 + headingData[1];  // Put the MSB and LSB together
  Serial.print("Current heading: ");
  Serial.print(int (headingValue / 10));     // The whole number part of the heading
  Serial.print(".");
  Serial.print(int (headingValue % 10));     // The fractional part of the heading
  Serial.println(" degrees");

  delay(10);


}

void Brujula::calibrar(){

}



