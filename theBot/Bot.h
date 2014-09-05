/*
Clase Bot para Robot Jardinero. Clase computacion fisica.
Autores:
Kevin Rubio
David Gaviria
Sergio Bromberg.

Una guia para la programacion de clases en Arduino puede encontrarse aqui:

 http://arduino.cc/en/Hacking/LibraryTutorial

*/


#ifndef Bot_h
#define Bot_h


#include "Arduino.h"
#include "Brujula.h"
#include "UltraSonido.h"

class Bot{

  public:
  // Variables
    int baud;
    int frentePin;
    int reverPint;
    int enablePinTrack;
    int enablePinGiro;
    int IzquierdaPin;
    int DerechaPin;
    
    Brujula brujula;
    UltraSonido ultrasonido;
    
    
    //Funciones
    Bot();
    void setupSerial();
    void setupBrujula();
    void direccion();
    
    void readSerial(int *);
    void avanza();
    void retrocede();
    void parar();
    void girarDerecha();
    void girarIzquierda();
    void centrarDireccion();
    
    
  
  
  private:

};
#endif

