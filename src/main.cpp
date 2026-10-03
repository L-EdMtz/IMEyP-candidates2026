#include <Arduino.h>
#include "./components/MotorShield/MotorShield.h"
#include "./components/Ultrasonic/Ultrasonic.h"
#include "./components/SensorColor/SensorColor.h"


Ultrasonic ultrasonicF(48, 47);
Ultrasonic ultrasonicL(27, 26);
Ultrasonic ultrasonicR(28, 29);
MotorShield motors;
SensorColor tcs;

void setup() {
    Serial.begin(9600);

    ultrasonicF.begin();
    ultrasonicL.begin();
    ultrasonicR.begin();
    
    if (!tcs.begin()) {
        Serial.println("Error con sensor de color");
        while(1) delay(1000);
    }
}

void loop() {

    if (ultrasonicF.length() > ultrasonicL.length() && ultrasonicF.length() > ultrasonicR.length()) {
        motors.forward();
    }
    else if (ultrasonicL.length() > ultrasonicF.length() && ultrasonicL.length() > ultrasonicR.length()) {
        motors.turnLeft();
        delay(1000);
    }
    else if (ultrasonicR.length() > ultrasonicF.length() && ultrasonicR.length() > ultrasonicL.length()) {
        motors.turnRight();
        delay(1000);
    }
    else {
        motors.backward();
    }

    colors color = tcs.readColor();

    Serial.println(color.red);
    Serial.println(color.green);
    Serial.println(color.blue);
    delay(200);

}