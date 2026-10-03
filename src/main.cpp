#include <Arduino.h>
#include "./components/MotorShield/MotorShield.h"
#include "./components/Ultrasonic/Ultrasonic.h"

Ultrasonic ultrasonicF(48, 47);
Ultrasonic ultrasonicL(27, 26);
Ultrasonic ultrasonicR(28, 29);
MotorShield motors;

void setup() {

    ultrasonicF.begin();
    ultrasonicL.begin();
    ultrasonicR.begin();
}

void loop() {

    if (ultrasonicF.length() > ultrasonicL.length() && ultrasonicF.length() > ultrasonicR.length()) {
        motors.forward();
    }
    else if (ultrasonicL.length() > ultrasonicF.length() && ultrasonicL.length() > ultrasonicR.length()) {
        motors.turnLeft();
    }
    else if (ultrasonicR.length() > ultrasonicF.length() && ultrasonicR.length() > ultrasonicL.length()) {
        motors.turnRight();
    }
    else {
        motors.backward();
    }


}