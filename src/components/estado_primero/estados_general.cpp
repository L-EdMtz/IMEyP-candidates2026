#include <Wire.h>
#include <Arduino.h>
#include "./../components/giroscopioConfiguracion/giroscopio.h"
#include "./../components/SensorColor/SensorColor.h"
#include "./../components/MotorShield/MotorShield.h"
#include "main.cpp"
#include "./../components/sensorIR/sensorIR.h"
#include "./../components/estado_primero/estado_1.cpp"
#include "./../components/estado_primero/estado_segundo.cpp"





// ================================================================
// 1. DEFINICIÓN DE ESTADOS DEL ROBOT
// ================================================================
enum EstadoRobot {
  RETO_CUBICULO,          // Fase 1: Cubículo y pelota
  NAVEGACION_IR,          // Fase 2: Evitar líneas y paredes buscando paso libre
  NAVEGACION_COLORES,     // Fase 3: Navegación por colores
  CHECKPOINT_FINAL        // Meta: Checkpoint Rojo Final
};

EstadoRobot estadoActual = RETO_CUBICULO;

//
void estados() {
  switch (estadoActual) {
    case RETO_CUBICULO:
      ejecutarRetoCubiculo();
      break;

    case NAVEGACION_IR:
      evaluarNavegacionIR();
      break;

    case NAVEGACION_COLORES:
      evaluarNavegacionColores();
      break;

    case CHECKPOINT_FINAL:
      frenar();
      Serial.println("¡RECORRIDO FINALIZADO CON ÉXITO!");
      while (1); 
      break;
  }

  delay(30);
}

// ================================================================
// LÓGICA DE FASES Y NAVEGACIÓN
// ================================================================

void ejecutarRetoCubiculo() {
  ejecutarRetoCubiculo1();
}


// --- FASE 2: NAVEGACIÓN DINÁMICA HASTA ENCONTRAR CHECKPOINT ROJO ---
void evaluarNavegacionIR() {
  motores.forward(255);
  if (sensorIRmedidaIzq > valor_blanco && sensorIRmedidaIzq > valor_blanco) {
    motores(RELEASE);
  }
  if (sensorIzq > sensorDer){
    giroscopio.girar(90,255);
    while (sensorFrente > 5) {
      motores.forward(255);
    giroscopio.girar(-90,255);
    }
  }
  if (colorDetect == "Red") {
    motores.stop();
    estadoActual = NAVEGACION_COLORES;
    return;
  }
}