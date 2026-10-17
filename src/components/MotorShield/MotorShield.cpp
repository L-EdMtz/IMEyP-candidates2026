#include "MotorShield.h"

MotorShield::MotorShield() 
    : motorLF(1), motorLB(2), motorRF(4), motorRB(3) {

}

void MotorShield::forward(uint8_t speedMotorsF) {

    motorLF.setSpeed(speedMotorsF);
    motorLB.setSpeed(speedMotorsF);
    motorRF.setSpeed(speedMotorsF);
    motorRB.setSpeed(speedMotorsF);

    motorLF.run(FORWARD);
    motorLB.run(FORWARD);
    motorRF.run(FORWARD);
    motorRB.run(FORWARD);

}

void MotorShield::backward(uint8_t speedMotorsB) {
    motorLF.setSpeed(speedMotorsB);
    motorLB.setSpeed(speedMotorsB);
    motorRF.setSpeed(speedMotorsB);
    motorRB.setSpeed(speedMotorsB);

    motorLF.run(BACKWARD);
    motorLB.run(BACKWARD);
    motorRF.run(BACKWARD);
    motorRB.run(BACKWARD);

}

void MotorShield::turnRight(uint8_t speedMotorsT) {
    motorLF.setSpeed(speedMotorsT);
    motorLB.setSpeed(speedMotorsT);
    motorRF.setSpeed(speedMotorsT);
    motorRB.setSpeed(speedMotorsT);

    motorLF.run(FORWARD);
    motorLB.run(FORWARD);
    motorRF.run(BACKWARD);
    motorRB.run(BACKWARD);

}

void MotorShield::turnLeft(uint8_t speedMotorsT) {
    motorLF.setSpeed(speedMotorsT);
    motorLB.setSpeed(speedMotorsT);
    motorRF.setSpeed(speedMotorsT);
    motorRB.setSpeed(speedMotorsT);

    motorLF.run(BACKWARD);
    motorLB.run(BACKWARD);
    motorRF.run(FORWARD);
    motorRB.run(FORWARD);
}

void MotorShield::stop() {
    motorLF.run(RELEASE);
    motorLB.run(RELEASE);
    motorRF.run(RELEASE);
    motorRB.run(RELEASE);

}