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
        void forward();
        void backward();
        void turnRight();
        void turnLeft();


};

#endif

