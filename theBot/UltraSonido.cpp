

#include "UltraSonido.h"

/*ESQUEMA DE CONEXION ULTRASONIDO
http://4.bp.blogspot.com/-h2JVFwl3RVA/Uv99mU7yfHI/AAAAAAAAAIM/R7vpR8OPUx8/s1600/ultrasonido+hc.jpg
*/

 
UltraSonido::UltraSonido(){
  TriggerPin  = 5 ;
  EchoPin     = 4 ;

}



boolean UltraSonido::AlertaProximidad(){

  /*Activacion de pines Trigger Salida, y Echo entrada*/
  pinMode( TriggerPin , OUTPUT ); /*El pulso ultrasónico              */
  pinMode(EchoPin    , INPUT  ); /*Tiempo del rebote del ultrasonido */
  
  
 
  digitalWrite(TriggerPin,LOW);   /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(TriggerPin, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  Tiempo=pulseIn(EchoPin, HIGH);  /* Función para medir la longitud del pulso entrante. Mide el Tiempo que transcurrido entre el envío
   del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza a recibir el rebote, HIGH, hasta que
   deja de hacerlo, LOW, la longitud del pulso entrante*/
  Distancia= int(0.017*Tiempo); /*fórmula para calcular la Distancia obteniendo un valor entero*/
  /*Monitorización en centímetros por el monitor serial*/

   Serial.println("Distancia ");
   Serial.println(Distancia);
   Serial.println(" cm");
   
  


  if(Distancia>10){
    //Serial.println("estas Bien");
    ParaMovimiento=0;
  }
  else{
    //Serial.println("Error : Estas Mal!");
    ParaMovimiento=1;
  }

  delay(100);

  return ParaMovimiento;

}



