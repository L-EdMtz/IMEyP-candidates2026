#include "LED.h"

LED::LED() {

}

void LED::begin() {
    pinMode(pinR,OUTPUT);
    pinMode(pinG,OUTPUT);
    pinMode(pinB,OUTPUT);

}
void LED::turnOn(uint8_t r, uint8_t g, uint8_t b) {
    analogWrite(pinR, r);
    analogWrite(pinG, g);
    analogWrite(pinB, b);
    
}