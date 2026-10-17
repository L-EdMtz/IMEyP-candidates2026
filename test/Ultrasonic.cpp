#include <Arduino.h>

const int TRIG_PINF = 31;
const int ECHO_PINF = 32;

const int TRIG_PINI = 33;
const int ECHO_PINI = 34;

const int TRIG_PIND = 35;
const int ECHO_PIND = 36;

void setup() {
  Serial.begin(9600); // Inicia la comunicación serie
  pinMode(TRIG_PINF, OUTPUT);
  pinMode(ECHO_PINF, INPUT);
  pinMode(TRIG_PINI, OUTPUT);
  pinMode(ECHO_PINI, INPUT);
  pinMode(TRIG_PIND, OUTPUT);
  pinMode(ECHO_PIND, INPUT);

}

void loop() {
  // Limpia el pin del trigger
  digitalWrite(TRIG_PINF, LOW);
  delayMicroseconds(2);
  // Envía un pulso de 10 microsegundos al Trigger
  digitalWrite(TRIG_PINF, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PINF, LOW);

  // Lee el tiempo que tarda el eco en regresar (en microsegundos)
  long duration = pulseIn(ECHO_PINF, HIGH);

  // Calcula la distancia en centímetros (velocidad del sonido / 2)
  long distance = duration * 0.034 / 2;

  // Imprime los resultados en el monitor serie
  Serial.print("Distancia F: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Repite el proceso para el sensor izquierdo
  digitalWrite(TRIG_PINI, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PINI, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PINI, LOW);

  duration = pulseIn(ECHO_PINI, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distancia I: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(100); // Espera 100 ms antes de la siguiente lectura

    // Repite el proceso para el sensor derecho
    digitalWrite(TRIG_PIND, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIND, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIND, LOW);
    delayMicroseconds(2);

    duration = pulseIn(ECHO_PIND, HIGH);

    distance = duration * 0.034 / 2;

    Serial.print("Distancia D: ");
    Serial.print(distance);
    Serial.println(" cm");

}
