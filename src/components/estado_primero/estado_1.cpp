#include <Arduino.h>
#include "./../components/giroscopioConfiguracion/giroscopio.h"
#include "./../components/SensorColor/SensorColor.h"
#include "./../components/MotorShield/MotorShield.h"
#include "main.cpp"
#include "./../components/estado_primero/estados_general.cpp"


void ejecutarRetoCubiculo1() {
  motores.forward(255);
  delay(1000);
  giroscopio.girar(-90, motores);
  while (sensorFrente.length() > limite) {
    motores.forward(255);
  }
  giroscopio.girar(90,motores);
  motores.forward(255);
  delay(1000);
  giroscopio.girar(-90,motores);
  motores.forward(255);
  colorRGB rgb1 = tcs.readColor();
  colorHSV hsv1 = tcs.rgbToHsv(rgb1.red, rgb1.green, rgb1.blue);
  String colorName1 = tcs.colorID(hsv1.h, hsv1.s, hsv1.v);
  if (colorName1 == "red") {
    EstadoRobot estadoActual = NAVEGACION_IR;
}
}