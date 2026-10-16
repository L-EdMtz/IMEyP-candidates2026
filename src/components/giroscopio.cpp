#include <Wire.h>
#include <Arduino.h>
//PINES//
//Vcc = 5V
//GND = GND
//SDA = pin 20 megarduino
//SCL = pin 21 megarduino
//AD0, SDA y XDA/XCL van desconectados

// --- CONFIGURACIÓN MPU-6050 (GY-521) ---
const int MPU_ADDR = 0x68;
float gyroZ_offset = 0;
float anguloActual = 0;
unsigned long tiempoAnterior = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // 1. Despertar el sensor MPU-6050
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B); // Registro PWR_MGMT_1
  Wire.write(0);    // Quita el modo de reposo
  Wire.endTransmission(true);

  // 2. Calibración inicial en estado estático
  Serial.println("Calibrando giroscopio... NO MOVER EL CARRITO");
  calibrarGiroscopio();
  Serial.println("¡Calibración lista!");

  tiempoAnterior = millis();
}

void loop() {
  // EJEMPLO: Girar +90 grados a la DERECHA
  Serial.println("Girando 90 deg a la DERECHA...");
  girar(90);
  delay(2000);

  // EJEMPLO: Girar -90 grados a la IZQUIERDA
  Serial.println("Girando 90 deg a la IZQUIERDA...");
  girar(-90);
  delay(5000);
}

// ================================================================
// FUNCIONES DEL GIROSCOPIO Y NAVEGACIÓN
// ================================================================

void calibrarGiroscopio() {
  float suma = 0;
  int muestras = 5000;
  for (int i = 0; i < muestras; i++) {      //Realiza 500 lecturas estando quieto y saca el promedio para obtener el error.
    suma += leerVelocidadGiroZ();
    delay(3);
  }
  gyroZ_offset = suma / muestras;
}

float leerVelocidadGiroZ() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x47); // Registro GYRO_ZOUT_H           //lee la velocidad de giro y la obtiene en °/s
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 2, true);

  int16_t rawZ = (Wire.read() << 8) | Wire.read();
  return (float)rawZ / 131.0;
}

void actualizarAngulo() {
  unsigned long tiempoActual = millis();
  float dt = (tiempoActual - tiempoAnterior) / 1000.0;
  tiempoAnterior = tiempoActual;

  float velocidadZ = leerVelocidadGiroZ() - gyroZ_offset;     //Función que actualiza el ángulo, ignorando los insignficantes.

  if (abs(velocidadZ) > 0.5) {
    anguloActual += velocidadZ * dt;
  }
}

void girar(float gradosObjetivo) {
  float anguloMeta = anguloActual + gradosObjetivo;
  uint8_t potenciaGiro = 160; // Potencia de transmisión (0 a 255)

  if (gradosObjetivo > 0) { 
    // Giro DERECHA: Motores izquierdos avanzan, motores derechos retroceden
    while (anguloActual < anguloMeta) {
      actualizarAngulo();
      //MOTORES DE IZQUIERDA RETROCEDE
      //MOTORES DE DERECHA AVANZAN                          //Comandos para girar hasta alcanzar el ángulo objetivo
    }
  } else { 
    // Giro IZQUIERDA: Motores izquierdos retroceden, motores derechos avanzan
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