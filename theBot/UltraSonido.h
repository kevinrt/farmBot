
#ifndef UltraSonido_h
#define UltraSonido_h


#include "Arduino.h"


class UltraSonido{

public:
  // Variables
  int     TriggerPin     ;
  int     EchoPin        ;
  long    Distancia      ;
  long    Tiempo         ;
  boolean ParaMovimiento ;


  // Funciones
  UltraSonido()             ;
  boolean AlertaProximidad();




};
#endif



