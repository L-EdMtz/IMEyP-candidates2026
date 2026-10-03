#ifndef LED_H
#define LED_H

#include <Arduino.h>

class LED {
    private:
        const uint8_t pinR = 44;
        const uint8_t pinG = 45;
        const uint8_t pinB = 46;

    public:
        LED();
        void begin();
        void turnOn(uint8_t r, uint8_t g, uint8_t b);
};


#endif