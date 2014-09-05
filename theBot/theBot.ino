// Clase BOT:

#include "Bot.h"

Bot bot;



//------Librerias Internas------

#include <Wire.h>

int HMC6352Address = 0x42;
// This is calculated in the setup() function
int slaveAddress;
int ledPin = 13;
boolean ledState = false;
byte headingData[2];
int i, headingValue;

//------------------------------

//---------Librerias Externas------------

#include <WiFly.h>         // Libreria del shield WiFly, Proporciona comunicacion WiFi
//#include "Credentials.h"   // Libreria externa proporciona atributos de conexion, Nombre de conexion y contraseña

//---------------------------------------


//----Atributos De Conexion-------

byte server[] = {
  192,168,43,29}; // Direccion IP del servidor al que se conecta en formato de arreglo de bytes.

Client client(server, 1234);     // Objeto cliente, que define el cliente que se conecta al servidor(server) en el puerto (1234).


// Variable donde se leen los datos seriales enviados por teclado.
int valorTecla = 0;


void setup() {

  
  bot.setupSerial();
  bot.setupBrujula();



  /*Serial.println("\n\r\n\rWiFly Shield Terminal Routine");

  WiFly.begin();

  if (!WiFly.join(ssid, passphrase)) {
    Serial.println("Association failed.");
    while (1) {
      // Hang on failure.
    }
  }

  Serial.println("connecting...");

  if (client.connect()) {
    Serial.println("connected");
    client.println("Hello World!\n");
    //client.println();
  } 
  else {
    Serial.println("connection failed");
  }
  */

  // Serial.println("Associated!");
}


void loop() {
  
  bot.readSerial(&valorTecla);
  
  boolean Detente= bot.DetectaObstaculo();
  
  if (valorTecla == 119){
  bot.avanza();
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
  
  



  //ultrasonido (EchoUltra,TriggerUltra, speed);


 



}


