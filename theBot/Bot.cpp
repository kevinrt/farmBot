#include "Bot.h"

Bot::Bot(){
  // Constructor... nada por ahora.
  baud = 10;
  // pines del motor
  frentePin      =  8; //Variables que definen el numero ID de los pines digitales de la Arduino -
  reverPint      =  7; //que se conectaran a los pines controladores del integrado que diferencian la direccion del motor de traccion, frente o reversa.
  enablePinTrack = 12;
  enablePinGiro  = 11;
  DerechaPin     = 10;
  IzquierdaPin   =  9;


}

void Bot::setupSerial(){

  Serial.begin(9600);

}

void Bot::setupBrujula(){

  brujula.setup();

}

void Bot::readSerial(int   * valorTecla){


  if (Serial.available() > 0) {
    *valorTecla = Serial.read(); 
      // say what you got:

    Serial.println(*valorTecla, DEC);

  }


}

void Bot::avanza(){


  analogWrite(  enablePinTrack    , 255    );

  digitalWrite( frentePin   ,HIGH );// avanza arranca en alto
  digitalWrite( reverPint   ,LOW );// reversa arranca en bajo

  Serial.println(frentePin + " " +reverPint);

}

void Bot::retrocede(){

  analogWrite(  enablePinTrack    , 255    );

  digitalWrite( frentePin   ,LOW  );// avanza arranca en alto
  digitalWrite( reverPint   ,HIGH );// reversa arranca en bajo


}

void Bot::parar (){
  analogWrite( enablePinGiro, 255  );// tal vez no sea necesario

  digitalWrite( frentePin   , HIGH );
  digitalWrite( reverPint   , HIGH );
}

void Bot:: girarDerecha(){


  analogWrite(  enablePinGiro    , 255    );

  digitalWrite( IzquierdaPin ,LOW  );// avanza arranca en alto
  digitalWrite( DerechaPin   ,HIGH );// reversa arranca en bajo



}

void Bot:: girarIzquierda(){
  analogWrite( enablePinGiro, 255  );

  digitalWrite( IzquierdaPin ,HIGH );// avanza arranca en alto
  digitalWrite( DerechaPin   ,LOW  );// reversa arranca en bajo

}

void Bot::centrarDireccion(){

  analogWrite( enablePinGiro, 255  );


  digitalWrite( IzquierdaPin ,HIGH  );
  digitalWrite( DerechaPin   ,HIGH  );

}

void Bot::direccion(){
  brujula.direccion();
}



