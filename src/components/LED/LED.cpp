#include "LED.h"

LED::LED() {

}

void LED::begin() {
    pinMode(pinR,OUTPUT);
    pinMode(pinG,OUTPUT);
    pinMode(pinB,OUTPUT);

}
void LED::turnOn(uint8_t r, uint8_t g, uint8_t b) {

    analogWrite(pinR, 255 - r);
    analogWrite(pinG, 255 - g);
    analogWrite(pinB, 255 - b);
    
}

void LED::turnOnColor(String color) {
    if (color == "red") {
        turnOn(255, 0, 0);
    } 
    else if (color == "green") {
        turnOn(0, 255, 0);
    } 
    else if (color == "blue") {
        turnOn(0, 0, 255);
    } 
    else if (color == "white") {
        turnOn(255, 255, 255);
    } 
    else if (color == "orange") {
        turnOn(255, 128, 0);
    } 
    else if (color == "yellow") {
        turnOn(255, 255, 0);
    } 
    else if (color == "cyan") {
        turnOn(0, 255, 255);
    } 
    else if (color == "magenta") {
        turnOn(255, 0, 255);
    }
}