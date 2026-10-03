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

    long duration = pulseIn(pinEcho,HIGH);
    long distance = (duration * 0.034) / 2;

    return distance;
}

