#include "MotorShield.h"

MotorShield::MotorShield() 
    : motorLF(1), motorLB(2), motorRF(4), motorRB(3) {

}

void MotorShield::forward(uint8_t speedMotorsF) {

    motorLF.run(FORWARD);
    motorLB.run(FORWARD);
    motorRF.run(FORWARD);
    motorRB.run(FORWARD);

    motorLF.setSpeed(speedMotorsF);
    motorLB.setSpeed(speedMotorsF);
    motorRF.setSpeed(speedMotorsF);
    motorRB.setSpeed(speedMotorsF);

    delay(500);

    motorLF.setSpeed(speedMotorsF-55);
    motorLB.setSpeed(speedMotorsF-55);
    motorRF.setSpeed(speedMotorsF-55);
    motorRB.setSpeed(speedMotorsF-55);
}

void MotorShield::backward(uint8_t speedMotorsB) {
    
    motorLF.run(BACKWARD);
    motorLB.run(BACKWARD);
    motorRF.run(BACKWARD);
    motorRB.run(BACKWARD);

    motorLF.setSpeed(speedMotorsB);
    motorLB.setSpeed(speedMotorsB);
    motorRF.setSpeed(speedMotorsB);
    motorRB.setSpeed(speedMotorsB);

    delay(500);

    motorLF.setSpeed(speedMotorsB-55);
    motorLB.setSpeed(speedMotorsB-55);
    motorRF.setSpeed(speedMotorsB-55);
    motorRB.setSpeed(speedMotorsB-55);
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

    // delay(1000);

    // motorLF.setSpeed(speedMotorsT-55);
    // motorLB.setSpeed(speedMotorsT-55);
    // motorRF.setSpeed(speedMotorsT-55);
    // motorRB.setSpeed(speedMotorsT-55);
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

    // delay(1000);

    // motorLF.setSpeed(speedMotorsT-55);
    // motorLB.setSpeed(speedMotorsT-55);
    // motorRF.setSpeed(speedMotorsT-55);
    // motorRB.setSpeed(speedMotorsT-55);
}


void MotorShield::moveLeft(uint8_t speedMotorsT) {
    motorLF.setSpeed(speedMotorsT);
    motorLB.setSpeed(speedMotorsT);
    motorRF.setSpeed(speedMotorsT);
    motorRB.setSpeed(speedMotorsT);

    motorLF.run(BACKWARD);
    motorLB.run(FORWARD);
    motorRF.run(FORWARD);
    motorRB.run(BACKWARD);

}

void MotorShield::moveRight(uint8_t speedMotorsT) {
    motorLF.setSpeed(speedMotorsT);
    motorLB.setSpeed(speedMotorsT);
    motorRF.setSpeed(speedMotorsT);
    motorRB.setSpeed(speedMotorsT);

    motorLF.run(FORWARD);
    motorLB.run(BACKWARD);
    motorRF.run(BACKWARD);
    motorRB.run(FORWARD);

}

void MotorShield::stop() {
    motorLF.run(RELEASE);
    motorLB.run(RELEASE);
    motorRF.run(RELEASE);
    motorRB.run(RELEASE);

}
