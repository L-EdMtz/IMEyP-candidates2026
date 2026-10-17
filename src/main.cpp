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
int girosAbortadosConsecutivos = 0;

unsigned long ultimaLecturaColor = 0;
int contadorRojo = 0;
String colorActual = "";

void actualizarColor() {
    if (millis() - ultimaLecturaColor < 30) return;
    ultimaLecturaColor = millis();

    colorRGB c = tcs.readColor();
    colorHSV h = tcs.rgbToHsv(c.red, c.green, c.blue);
    String nombre = tcs.colorID(h.h, h.s, h.v);

    if (nombre != colorActual) {          // LED siempre refleja el color
        colorActual = nombre;
        rgbL.turnOnColor(colorActual);
    }
    Serial.println(colorActual);
    Serial.println(h.h);
    contadorRojo = (nombre == "red") ? contadorRojo + 1 : 0;

    if (contadorRojo >= 3) {              // rojo: se corta todo
        motores.stop();
        Serial.println("ROJO detectado. Programa detenido.");
        while (true) { }
    }
}

void esperar(unsigned long ms) {
    unsigned long inicio = millis();
    while (millis() - inicio < ms) {
        actualizarColor();
    }
}

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
    // Serial.println(offset);
    rgbL.begin();
    if (!tcs.begin()) {
        Serial.println("Error initializing TCS34725");
        while (1);
    }
}

void loop() {
    actualizarColor();
    
    float rumboDeseado = giroscopio.anguloActual;
    bool giroExitoso = true;
    giroscopio.avanzarHastaPared(rumboDeseado, 220, 15.0, motores, sensorFrente);

    
    Serial.println(rumboDeseado);
    Serial.println("Paredo detectado. Deteniendo el coche.");
    esperar(100);
    long distanciaIzquierda = sensorIzquierdo.length();
    long distanciaDerecha = sensorDerecho.length();
    Serial.print("Distancia izquierda: "); Serial.print(distanciaIzquierda); Serial.print(" cm, ");
    Serial.print("Distancia derecha: "); Serial.print(distanciaDerecha); Serial.println(" cm");


    if (distanciaIzquierda > UMBRAL_LIBRE && distanciaIzquierda > distanciaDerecha) {
       giroExitoso = giroscopio.girar(90, motores); // Gira 90 grados a la izquierda
    } else if (distanciaDerecha > UMBRAL_LIBRE && distanciaDerecha > distanciaIzquierda) {
        giroExitoso = giroscopio.girar(-90, motores);
    }

    // if (distanciaIzquierda > UMBRAL_LIBRE) {

    //     giroExitoso = giroscopio.girar(90, motores); // Gira 90 grados a la izquierda
    //     Serial.println("Girando a la izquierda");

    // } else if (distanciaDerecha > UMBRAL_LIBRE) {
        
    //     Serial.println("Girando a la derecha");
    //     giroExitoso = giroscopio.girar(-90, motores); // Gira 90 grados a la derecha

    // } 
    else {
        
        Serial.println("No hay espacio libre. Girando 180 grados.");
        giroscopio.girar(180, motores); // Gira 180 grados
    
    }
    if (!giroExitoso) {
        girosAbortadosConsecutivos++;
        Serial.print("Giros abortados seguidos: ");
        Serial.println(girosAbortadosConsecutivos);
    } else {
        girosAbortadosConsecutivos = 0; 
    }

    // Si se ha abortado el giro 2 veces seguidas:
    if (girosAbortadosConsecutivos >= 2) {
        Serial.println("Se abortó el giro 2 veces seguidas. Retrocediendo durante 2.5 segundos...");
        
        motores.backward(220); // O la función de retroceso que utilices
        esperar(1500);           
        motores.stop();
        
        girosAbortadosConsecutivos = 0; 
    }
    Serial.print("Rumbo deseado: ");
    Serial.println(rumboDeseado);

    


    esperar(100);
    


}
