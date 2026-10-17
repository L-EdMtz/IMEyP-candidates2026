//PINES//
//Vcc = 5V
//GND = GND
//SDA = pin 20 megarduino
//SCL = pin 21 megarduino
//AD0, SDA y XDA/XCL van desconectados

#ifndef GIROSCOPIO_H
#define GIROSCOPIO_H
#include "./../MotorShield/MotorShield.h"
#include "./../Ultrasonic/Ultrasonic.h"
#include <Arduino.h>

class GIROSCOPIO {
    private:
        static constexpr uint8_t MPU_ADDR = 0x68;
        float gyroZ_offset = 0;
        unsigned long tiempoAnterior = 0;
        uint8_t direccion;

    public:
        GIROSCOPIO(uint8_t addr = MPU_ADDR);
        float calibrarGiroscopio();
        float leerVelocidadGiroZ();
        void actualizarAngulo();
        float anguloActual = 0;
        bool girar(float gradosObjetivo, MotorShield &motores, unsigned long timeoutMs = 5000);
        void inicializar();
        void avanzarHastaPared(float anguloObjetivo, uint8_t velocidadBase, float distanciaLimite, MotorShield &motores, Ultrasonic &sensorFrente);

};

#endif