#include <Arduino.h>
#include "./components/Ultrasonic/Ultrasonic.h"

Ultrasonic ultrasonic(5, 6);


void setup() {
    Serial.begin(9600);
    ultrasonic.begin();
}

void loop() {
    long distance = ultrasonic.length();
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(1000);
}