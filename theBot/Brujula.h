
#ifndef Brujula_h
#define Brujula_h


#include "Arduino.h"
#include "Wire.h"


class Brujula{

public:
  // Variables
  int HMC6352Address;

  int slaveAddress;
  int ledPin; 
  boolean ledState;
  byte headingData[2];
  int headingValue;


  // Funciones
  Brujula();
  void setup();
  void direccion();
  void calibrar();



};
#endif



