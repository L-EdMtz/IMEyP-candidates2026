#ifndef MOTORSHIELD_H
#define MOTORSHIELD_H

#include <Arduino.h>
#include <AFMotor.h>

class MotorShield {
    private:
        AF_DCMotor motorLF;
        AF_DCMotor motorLB;
        AF_DCMotor motorRF;
        AF_DCMotor motorRB;
    
    public:
        MotorShield();
        void forward(uint8_t speedMotorsF = 200);
        void backward(uint8_t speedMotorsB = 150);
        void turnRight(uint8_t speedMotorsT = 100);
        void turnLeft(uint8_t speedMotorsT = 100);


};

#endif

