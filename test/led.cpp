#include <Arduino.h>
#include "./components/LED/LED.h"

LED rgbL;

void setup() {
    rgbL.begin();

}

void loop() {
    
    //rojo
    rgbL.turnOn(255, 0, 0);
    delay(1000);
    // verde
    rgbL.turnOn(0, 255, 0);
    delay(1000);
    // azul
    rgbL.turnOn(0, 0, 255);
    delay(1000);
    //blanco
    rgbL.turnOn(255, 255, 255);
    delay(1000);
    // naranja
    rgbL.turnOn(255, 128, 0);
    delay(1000);
    // amarillo
    rgbL.turnOn(255, 255, 0);
    delay(1000);
    // cian
    rgbL.turnOn(0, 255, 255);
    delay(1000);
    // magenta
    rgbL.turnOn(255, 0, 255);
    delay(1000);

    rgbL.turnOnColor("red");
    delay(1000);
    rgbL.turnOnColor("green");
    delay(1000);
    rgbL.turnOnColor("blue");
    delay(1000);
    rgbL.turnOnColor("white");
    delay(1000);
    rgbL.turnOnColor("orange");
    delay(1000);
    rgbL.turnOnColor("yellow");
    delay(1000);
    rgbL.turnOnColor("cyan");
    delay(1000);
    rgbL.turnOnColor("magenta");
    delay(1000);

}