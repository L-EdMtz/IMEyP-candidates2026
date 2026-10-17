#include <Wire.h>
#include "giroscopio.h"
#include <Arduino.h>
#include "./components/MotorShield/MotorShield.h"

GIROSCOPIO::GIROSCOPIO(uint8_t addr)
{
    direccion = addr;
}

// --- CONFIGURACIÓN MPU-6050 (GY-521) ---
//const int MPU_ADDR = 0x68;
//float gyroZ_offset = 0;
//float anguloActual = 0;
//unsigned long tiempoAnterior = 0;

//void setup() {
//  Serial.begin(9600);
//  Wire.begin();

  // 2. Calibración inicial en estado estático
//  Serial.println("Calibrando giroscopio... NO MOVER EL CARRITO");
//  calibrarGiroscopio();
//  Serial.println("¡Calibración lista!");

//  tiempoAnterior = millis();
//}


// ================================================================
// FUNCIONES DEL GIROSCOPIO Y NAVEGACIÓN
// ================================================================
void GIROSCOPIO::inicializar() {
    // Despertar el sensor MPU-6050
    Wire.beginTransmission(direccion);
    Wire.write(0x6B); // Registro PWR_MGMT_1
    Wire.write(0);    // Quita el modo de reposo (sleep mode)
    Wire.endTransmission(true);
}

float GIROSCOPIO::calibrarGiroscopio() {
  float suma = 0;
  int muestras = 5000;
  for (int i = 0; i < muestras; i++) {      //Realiza 500 lecturas estando quieto y saca el promedio para obtener el error.
    suma += leerVelocidadGiroZ();
    delay(3);
  }
  gyroZ_offset = suma / muestras;
  return gyroZ_offset;
}

float GIROSCOPIO::leerVelocidadGiroZ() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x47); // Registro GYRO_ZOUT_H           //lee la velocidad de giro y la obtiene en °/s
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 2, true);

  int16_t rawZ = (Wire.read() << 8) | Wire.read();
  return (float)rawZ / 131.0;
}

void GIROSCOPIO::actualizarAngulo() {
  unsigned long tiempoActual = millis();
  float dt = (tiempoActual - tiempoAnterior) / 1000.0;
  tiempoAnterior = tiempoActual;

  float velocidadZ = leerVelocidadGiroZ() - gyroZ_offset;     //Función que actualiza el ángulo, ignorando los insignficantes.

  if (abs(velocidadZ) > 0.5) {
    anguloActual += velocidadZ * dt;
  }
}

void GIROSCOPIO::girar(float gradosObjetivo) {
  float anguloMeta = anguloActual + gradosObjetivo;
  uint8_t potenciaGiro = 160; // Potencia de transmisión (0 a 255)

  if (gradosObjetivo > 0) { 
    
    while (anguloActual < anguloMeta) {
      actualizarAngulo();
      //MOTORES DE IZQUIERDA RETROCEDE

      //MOTORES DE DERECHA AVANZAN                          //Comandos para girar hasta alcanzar el ángulo objetivo
    }
  } else { 
    while (anguloActual > anguloMeta) {
      actualizarAngulo();
      //MOTORES DE IZQUIERDA AVANZAN
      //MOTORES DE DERECHA RETROCEDEN
    }
  }

  //FRENAR TODOS LOS MOTORES
  delay(500);
  actualizarAngulo();
  tiempoAnterior = millis();
}