#include "./../components/sensorIR/sensorIR.h"
#include <Arduino.h>
#include "./../components/GiroscopioConfiguracion/giroscopio.h"
#include "./../components/SensorColor/SensorColor.h"
#include "./../components/MotorShield/MotorShield.h"
#include "main.cpp"

SensorIR::SensorIR(){

}

float SensorIR::tomarMedidaIR(int sensor) {
  float sensorIRmedida = analogRead(sensor);
  return sensorIRmedida;
}


void SensorIR::evaluarNavegacionIR() {
  motores.forward(255);
  float sensorIRmedidaIzq = tomarMedidaIR(pinIR_IZQ);
  float sensorIRmedidaDer = tomarMedidaIR(pinIR_DER);
  if (sensorIRmedidaIzq > UMBRAL_BLANCO && sensorIRmedidaDer > UMBRAL_BLANCO) {
    motores.stop();
  }
  if (sensorIRmedidaIzq > sensorIRmedidaDer){
    giroscopio.girar(90,motores);
    while (sensorFrente.length() > 6) {
      motores.forward(255);
    giroscopio.girar(-90,motores);
    }}
  else{
    giroscopio.girar(-90,motores);
    while (sensorFrente.length() > 6) {
      motores.forward(255);
    giroscopio.girar(90,motores);
  }
    }
  }
