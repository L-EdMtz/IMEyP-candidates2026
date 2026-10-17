#include "giroscopio.h"
#include <Arduino.h>
#include <Wire.h>
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

void GIROSCOPIO::girar(float gradosObjetivo, MotorShield &motores) {
    float anguloMeta = anguloActual + gradosObjetivo;
    uint8_t potenciaGiro = 255; // Potencia de transmisión (0 a 255)
    const float TOLERANCIA = 4.0; // Rango de tolerancia de ±4 grados

    if (gradosObjetivo > 0) { 
        motores.turnLeft(potenciaGiro); // Gira a la izquierda/derecha según tu cableado
        
        // Corta el bucle 4 grados antes de anguloMeta
        while (anguloActual < (anguloMeta - TOLERANCIA)) {
            actualizarAngulo();
        }
    } else { 
        motores.turnRight(potenciaGiro);
        
        // Corta el bucle 4 grados antes de anguloMeta
        while (anguloActual > (anguloMeta + TOLERANCIA)) {
            actualizarAngulo();
        }
    }

    // FRENAR TODOS LOS MOTORES
    motores.stop(); // Apaga los motores al alcanzar el rango
    delay(500);
    actualizarAngulo();
    tiempoAnterior = millis();
}
void GIROSCOPIO::avanzarHastaPared(float anguloObjetivo, uint8_t velocidadBase, float distanciaLimite, MotorShield &motores, Ultrasonic &sensorFrente) {
  motores.forward(velocidadBase);
  while (sensorFrente.length() > distanciaLimite) {
    actualizarAngulo();
    float error = anguloActual - anguloObjetivo;
    int ajuste = static_cast<int>(error * 2); // Ajuste proporcional al error
    int velocidadIzquierda = velocidadBase - ajuste;
    int velocidadDerecha = velocidadBase + ajuste;

    // Limitar las velocidades para que estén dentro del rango permitido
    velocidadIzquierda = constrain(velocidadIzquierda, 0, 255);
    velocidadDerecha = constrain(velocidadDerecha, 0, 255);

    motores.motorLF.setSpeed(velocidadIzquierda);
    motores.motorLB.setSpeed(velocidadIzquierda);
    motores.motorRF.setSpeed(velocidadDerecha);
    motores.motorRB.setSpeed(velocidadDerecha);
  }
  motores.stop();
}