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

    delay(1000);

    motorRF.setSpeed(speedMotorsF-30);
    motorRB.setSpeed(speedMotorsF-30);
    motorLB.setSpeed(speedMotorsF-30);
    motorLF.setSpeed(speedMotorsF-30);
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

    delay(1000);

    motorLF.setSpeed(speedMotorsB-30);
    motorLB.setSpeed(speedMotorsB-30);
    motorRF.setSpeed(speedMotorsB-30);
    motorRB.setSpeed(speedMotorsB-30);
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

// MotorShield::MotorShield() 
//     : motorLF(1), motorLB(2), motorRF(4), motorRB(3) {

// }

// void MotorShield::forward(uint8_t speedMotorsF) {
//     // Dirección hacia adelante
//     motorLF.run(FORWARD);
//     motorLB.run(FORWARD);
//     motorRF.run(FORWARD);
//     motorRB.run(FORWARD);

//     // Rampa hardcodeada de aceleración
//     const uint8_t velocidadInicio = 80;
//     const uint8_t paso = 80;
//     const unsigned long tiempoPasoMs = 200;

//     for (uint8_t v = velocidadInicio; v < speedMotorsF; v += paso) {
//         motorLF.setSpeed(v);
//         motorLB.setSpeed(v);
//         motorRF.setSpeed(v);
//         motorRB.setSpeed(v);
//         delay(tiempoPasoMs);
//     }

//     // Velocidad final solicitada
//     motorLF.setSpeed(speedMotorsF);
//     motorLB.setSpeed(speedMotorsF);
//     motorRF.setSpeed(speedMotorsF);
//     motorRB.setSpeed(speedMotorsF);
// }

// void MotorShield::backward(uint8_t speedMotorsB) {
//     motorLF.run(BACKWARD);
//     motorLB.run(BACKWARD);
//     motorRF.run(BACKWARD);
//     motorRB.run(BACKWARD);

//     const uint8_t velocidadInicio = 80;
//     const uint8_t paso = 80;
//     const unsigned long tiempoPasoMs = 200;

//     if (speedMotorsB <= velocidadInicio) {
//         motorLF.setSpeed(speedMotorsB);
//         motorLB.setSpeed(speedMotorsB);
//         motorRF.setSpeed(speedMotorsB);
//         motorRB.setSpeed(speedMotorsB);
//         return;
//     }

//     for (uint8_t v = velocidadInicio; v < speedMotorsB; v += paso) {
//         motorLF.setSpeed(v);
//         motorLB.setSpeed(v);
//         motorRF.setSpeed(v);
//         motorRB.setSpeed(v);
//         delay(tiempoPasoMs);
//     }

//     motorLF.setSpeed(speedMotorsB);
//     motorLB.setSpeed(speedMotorsB);
//     motorRF.setSpeed(speedMotorsB);
//     motorRB.setSpeed(speedMotorsB);
// }

// void MotorShield::turnRight(uint8_t speedMotorsT) {
//     // Izquierda adelante, derecha atrás
//     motorLF.run(FORWARD);
//     motorLB.run(FORWARD);
//     motorRF.run(BACKWARD);
//     motorRB.run(BACKWARD);

//     const uint8_t velocidadInicio = 80;
//     const uint8_t paso = 80;
//     const unsigned long tiempoPasoMs = 200;

//     if (speedMotorsT <= velocidadInicio) {
//         motorLF.setSpeed(speedMotorsT);
//         motorLB.setSpeed(speedMotorsT);
//         motorRF.setSpeed(speedMotorsT);
//         motorRB.setSpeed(speedMotorsT);
//         return;
//     }

//     for (uint8_t v = velocidadInicio; v < speedMotorsT; v += paso) {
//         motorLF.setSpeed(v);
//         motorLB.setSpeed(v);
//         motorRF.setSpeed(v);
//         motorRB.setSpeed(v);
//         delay(tiempoPasoMs);
//     }

//     motorLF.setSpeed(speedMotorsT);
//     motorLB.setSpeed(speedMotorsT);
//     motorRF.setSpeed(speedMotorsT);
//     motorRB.setSpeed(speedMotorsT);
// }

// void MotorShield::turnLeft(uint8_t speedMotorsT) {
//     // Izquierda atrás, derecha adelante
//     motorLF.run(BACKWARD);
//     motorLB.run(BACKWARD);
//     motorRF.run(FORWARD);
//     motorRB.run(FORWARD);

//     const uint8_t velocidadInicio = 80;
//     const uint8_t paso = 80;
//     const unsigned long tiempoPasoMs = 200;

//     if (speedMotorsT <= velocidadInicio) {
//         motorLF.setSpeed(speedMotorsT);
//         motorLB.setSpeed(speedMotorsT);
//         motorRF.setSpeed(speedMotorsT);
//         motorRB.setSpeed(speedMotorsT);
//         return;
//     }

//     for (uint8_t v = velocidadInicio; v < speedMotorsT; v += paso) {
//         motorLF.setSpeed(v);
//         motorLB.setSpeed(v);
//         motorRF.setSpeed(v);
//         motorRB.setSpeed(v);
//         delay(tiempoPasoMs);
//     }

//     motorLF.setSpeed(speedMotorsT);
//     motorLB.setSpeed(speedMotorsT);
//     motorRF.setSpeed(speedMotorsT);
//     motorRB.setSpeed(speedMotorsT);
// }

// void MotorShield::moveLeft(uint8_t speedMotorsT) {
//     motorLF.run(BACKWARD);
//     motorLB.run(FORWARD);
//     motorRF.run(FORWARD);
//     motorRB.run(BACKWARD);

//     const uint8_t velocidadInicio = 80;
//     const uint8_t paso = 80;
//     const unsigned long tiempoPasoMs = 200;

//     if (speedMotorsT <= velocidadInicio) {
//         motorLF.setSpeed(speedMotorsT);
//         motorLB.setSpeed(speedMotorsT);
//         motorRF.setSpeed(speedMotorsT);
//         motorRB.setSpeed(speedMotorsT);
//         return;
//     }

//     for (uint8_t v = velocidadInicio; v < speedMotorsT; v += paso) {
//         motorLF.setSpeed(v);
//         motorLB.setSpeed(v);
//         motorRF.setSpeed(v);
//         motorRB.setSpeed(v);
//         delay(tiempoPasoMs);
//     }

//     motorLF.setSpeed(speedMotorsT);
//     motorLB.setSpeed(speedMotorsT);
//     motorRF.setSpeed(speedMotorsT);
//     motorRB.setSpeed(speedMotorsT);
// }

// void MotorShield::moveRight(uint8_t speedMotorsT) {
//     motorLF.run(FORWARD);
//     motorLB.run(BACKWARD);
//     motorRF.run(BACKWARD);
//     motorRB.run(FORWARD);

//     const uint8_t velocidadInicio = 80;
//     const uint8_t paso = 80;
//     const unsigned long tiempoPasoMs = 200;

//     if (speedMotorsT <= velocidadInicio) {
//         motorLF.setSpeed(speedMotorsT);
//         motorLB.setSpeed(speedMotorsT);
//         motorRF.setSpeed(speedMotorsT);
//         motorRB.setSpeed(speedMotorsT);
//         return;
//     }

//     for (uint8_t v = velocidadInicio; v < speedMotorsT; v += paso) {
//         motorLF.setSpeed(v);
//         motorLB.setSpeed(v);
//         motorRF.setSpeed(v);
//         motorRB.setSpeed(v);
//         delay(tiempoPasoMs);
//     }

//     motorLF.setSpeed(speedMotorsT);
//     motorLB.setSpeed(speedMotorsT);
//     motorRF.setSpeed(speedMotorsT);
//     motorRB.setSpeed(speedMotorsT);
// }

// void MotorShield::stop() {
//     motorLF.run(RELEASE);
//     motorLB.run(RELEASE);
//     motorRF.run(RELEASE);
//     motorRB.run(RELEASE);
// }