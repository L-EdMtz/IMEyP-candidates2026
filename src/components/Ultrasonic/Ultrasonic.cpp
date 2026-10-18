#
#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(uint8_t trigger, uint8_t echo) {
    pinTrigger = trigger;
    pinEcho = echo;

}

void Ultrasonic::begin() {
    pinMode(pinTrigger,OUTPUT);
    pinMode(pinEcho,INPUT);
    digitalWrite(pinTrigger,LOW);

}

long Ultrasonic::length() {
    digitalWrite(pinTrigger,HIGH);
    delayMicroseconds(10);
    digitalWrite(pinTrigger,LOW);

    long duration = pulseIn(pinEcho,HIGH,30000UL);
    if (duration == 0) {
        return 400; // Retorna 400 si no se detecta un pulso
    }
    
    long distance = (duration * 0.0343) / 2;

    return distance;
}

