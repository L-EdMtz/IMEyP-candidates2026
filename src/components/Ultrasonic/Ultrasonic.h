#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

class Ultrasonic {
    private:
        uint8_t pinTrigger;
        uint8_t pinEcho;

    public:
        Ultrasonic(uint8_t trigger, uint8_t echo);
        void begin();
        long length();
};

#endif