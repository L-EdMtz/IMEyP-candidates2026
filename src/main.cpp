#include <Arduino.h>
#include <Wire.h>
#include "./components/MotorShield/MotorShield.h"
#include "./components/Ultrasonic/Ultrasonic.h"
#include "./components/SensorColor/SensorColor.h"
#include "./components/LED/LED.h"
#include "./components/GiroscopioConfiguracion/giroscopio.h"

GIROSCOPIO giroscopio;
SensorColor tcs;
LED rgbL;
MotorShield motores;
Ultrasonic sensorFrente(31, 32); // Trigger pin 31, Echo pin 32
Ultrasonic sensorIzquierdo(33, 34); // Trigger pin 33, Echo pin 34
Ultrasonic sensorDerecho(35, 36); // Trigger pin 35, Echo pin 36

const float DISTANCIA_PARADA = 10.0; // Se detiene a 10 cm de la pared frontal
const float UMBRAL_LIBRE = 20.0;      // Distancia mínima para considerar que un camino está libre

void setup() {
    Serial.begin(9600);
    Wire.begin();
    sensorFrente.begin();
    sensorIzquierdo.begin();
    sensorDerecho.begin();
    giroscopio.inicializar();
    Serial.println("Calibrando giroscopio... Mantén el coche quieto.");
    float offset = giroscopio.calibrarGiroscopio();
    Serial.println("Calibración completada");
    Serial.println("Offset del giroscopio:");
    Serial.println(offset);
    rgbL.begin();
    if (!tcs.begin()) {
        Serial.println("Error initializing TCS34725");
        while (1);
    }
}

void loop() {

    float rumboDeseado = giroscopio.anguloActual; // Obtén el rumbo deseado desde el giroscopio
    
    giroscopio.avanzarHastaPared(rumboDeseado, 255, 15.0, motores, sensorFrente);
    Serial.println(rumboDeseado);
    Serial.println("Paredo detectado. Deteniendo el coche.");
    delay(300);
    long distanciaIzquierda = sensorIzquierdo.length();
    long distanciaDerecha = sensorDerecho.length();
    Serial.print("Distancia izquierda: "); Serial.print(distanciaIzquierda); Serial.print(" cm, ");
    Serial.print("Distancia derecha: "); Serial.print(distanciaDerecha); Serial.println(" cm");
    if (distanciaIzquierda > UMBRAL_LIBRE) {
        Serial.println("Girando a la izquierda");
        giroscopio.girar(90, motores); // Gira 90 grados a la izquierda
    } else if (distanciaDerecha > UMBRAL_LIBRE) {
        Serial.println("Girando a la derecha");
        giroscopio.girar(-90, motores); // Gira 90 grados a la derecha
    } else {
        Serial.println("No hay espacio libre. Girando 180 grados.");
        giroscopio.girar(180, motores); // Gira 180 grados
    }
    Serial.print("Rumbo deseado: ");
    Serial.println(rumboDeseado);


    delay(300);
    colorRGB rgb = tcs.readColor();
    colorHSV hsv = tcs.rgbToHsv(rgb.red, rgb.green, rgb.blue);
    String colorName = tcs.colorID(hsv.h, hsv.s, hsv.v);

    Serial.print("Color: ");
    Serial.println(colorName);

    rgbL.turnOnColor(colorName);


}
