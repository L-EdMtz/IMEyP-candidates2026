#ifndef LED_H
#define LED_H

#include <Arduino.h>

class LED {
    private:
        // const uint8_t pinR = 44;
        // const uint8_t pinG = 45;
        // const uint8_t pinB = 46;
        const uint8_t pinR = 3;
        const uint8_t pinG = 5;
        const uint8_t pinB = 6;

    public:
        LED();
        void begin();
        void turnOn(uint8_t r, uint8_t g, uint8_t b);
        void turnOnColor(String color = "white");
};


#endif