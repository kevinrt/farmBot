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
#include "Credentials.h"   // Libreria externa proporciona atributos de conexion, Nombre de conexion y contraseña

//---------------------------------------


//----Atributos De Conexion-------

byte server[] = {
  192,168,43,29}; // Direccion IP del servidor al que se conecta en formato de arreglo de bytes.

Client client(server, 1234);     // Objeto cliente, que define el cliente que se conecta al servidor(server) en el puerto (1234).


//-------Atributos de SensorUltraSonido-------

int TriggerUltra    = 6 ;  //Pin del trigger del ultra
int EchoUltra       = 5 ;  //Pin del Echo del ultra
long distancia          ;
long tiempo             ; 


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
  
  if (valorTecla == 119){
  bot.avanza();
  Serial.println("avanzando");
  
  }
  if(valorTecla == 32){
  bot.parar();
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

boolean ultrasonido (int pin1 ,int  pin2,int speed){



  //ultra sonido 
  pinMode(pin2, OUTPUT); /*activación del pin 6 como salida: para el pulso ultrasónico*/
  pinMode(pin1, INPUT); /*activación del pin 5 como entrada: tiempo del rebote del ultrasonido*/
  //pin2 = TriggerUltra y pin1 = EchoUltra

  digitalWrite(pin2,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(pin2, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo=pulseIn(pin1, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío
   del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza a recibir el rebote, HIGH, hasta que
   deja de hacerlo, LOW, la longitud del pulso entrante*/
  distancia= int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
  /*Monitorización en centímetros por el monitor serial*/

  /* Serial.println("Distancia ");
   Serial.println(distancia);
   Serial.println(" cm");
   */
  boolean semueve= 0;


  if(distancia>10){
    //Serial.println("estas Bien");




    // setMotor(speed     , !reverse      ,1 ); //Funcion que controla  motor de direccion: setMotor(velocidad,verificadorReversaDireccion,verificadorPresionTecla)
    // setTrac(TrackSpeed , reverseTrack ,1 ); //Funcion que controla  motor de traccion: setTrac(velocidad,verificadorReversaTraccion,verificadorPresionTecla)
    semueve=1;
  }
  else{
    //Serial.println("Error : Estas Mal!");

    semueve=0;

    // setMotor(speed     , reverse      ,1); //Funcion que controla  motor de direccion: setMotor(velocidad,verificadorReversaDireccion,verificadorPresionTecla)
    //setTrac(TrackSpeed , reverseTrack ,1 ); //Funcion que controla  motor de traccion: setTrac(velocidad,verificadorReversaTraccion,verificadorPresionTecla)
  }

  delay(100);

  return semueve;

}

