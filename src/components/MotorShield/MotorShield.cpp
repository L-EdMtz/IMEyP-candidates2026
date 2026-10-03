#include "MotorShield.h"

MotorShield::MotorShield() 
    : motorLF(1), motorLB(2), motorRF(4), motorRB(3) {
    // Código de inicialización adicional si lo necesitas
}

uint8_t speedMotorsF = 200;
uint8_t speedMotorsB = 150;
uint8_t speedMotorsT = 100;

void MotorShield::forward() {

    motorLF.setSpeed(speedMotorsF);
    motorLB.setSpeed(speedMotorsF);
    motorRF.setSpeed(speedMotorsF);
    motorRB.setSpeed(speedMotorsF);

    motorLF.run(FORWARD);
    motorLB.run(FORWARD);
    motorRF.run(FORWARD);
    motorRB.run(FORWARD);

}

void MotorShield::backward() {
    motorLF.setSpeed(speedMotorsB);
    motorLB.setSpeed(speedMotorsB);
    motorRF.setSpeed(speedMotorsB);
    motorRB.setSpeed(speedMotorsB);

    motorLF.run(BACKWARD);
    motorLB.run(BACKWARD);
    motorRF.run(BACKWARD);
    motorRB.run(BACKWARD);

}

void MotorShield::turnRight() {
    motorLF.setSpeed(speedMotorsT);
    motorLB.setSpeed(speedMotorsT);
    motorRF.setSpeed(speedMotorsT);
    motorRB.setSpeed(speedMotorsT);

    motorLF.run(FORWARD);
    motorLB.run(FORWARD);
    motorRF.run(BACKWARD);
    motorRB.run(BACKWARD);

}

void MotorShield::turnLeft() {
    motorLF.setSpeed(speedMotorsT);
    motorLB.setSpeed(speedMotorsT);
    motorRF.setSpeed(speedMotorsT);
    motorRB.setSpeed(speedMotorsT);

    motorLF.run(BACKWARD);
    motorLB.run(BACKWARD);
    motorRF.run(FORWARD);
    motorRB.run(FORWARD);

}