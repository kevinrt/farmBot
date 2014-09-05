// Clase BOT:

#include "Bot.h"
Bot bot;

//------Librerias Internas------

#include <Wire.h>


//---------Librerias Externas------------

#include <WiFly.h>           // Libreria del shield WiFly, Proporciona comunicacion WiFi
//#include "Credentials.h"   // Libreria externa proporciona atributos de conexion, Nombre de conexion y contraseña


// Variable donde se leen los datos seriales enviados por teclado.
int valorTecla = 0;


void setup() {
  bot.setupSerial();
  bot.setupBrujula();
}


void loop() {
  
  bot.readSerial(&valorTecla);
  
  boolean Detente= bot.DetectaObstaculo();
  
   bot.avanza();
  
  if (valorTecla == 119){
  //bot.avanza();
  Serial.println("avanzando");
  
  }
  if(Detente){
  bot.parar();
  Serial.println("ME DETENGO");
  }
  
  if (valorTecla == 115){
  bot.retrocede();
  }
  
  if(valorTecla == 97){
    bot.girarIzquierda();
          Serial.println("izq");
  }
  
  if(valorTecla == 100){
    bot.girarDerecha();
      Serial.println("derehca");
  }
  
  if(valorTecla == 49){
    bot.centrarDireccion();

  }
  
    bot.direccion();
  
}


