// #include <Arduino.h>
// #include "./components/MotorShield/MotorShield.h"
// #include "./components/Ultrasonic/Ultrasonic.h"
// #include "./components/SensorColor/SensorColor.h"
// #include "./components/LED/LED.h"

// SensorColor tcs;
// LED rgbL;

// void setup() {
//     Serial.begin(9600);
//     rgbL.begin();
//     if (!tcs.begin()) {
//         Serial.println("Error initializing TCS34725");
//         while (1);
//     }
// }

// void loop() {
//     colorRGB rgb = tcs.readColor();
//     colorHSV hsv = tcs.rgbToHsv(rgb.red, rgb.green, rgb.blue);
//     String colorName = tcs.colorID(hsv.h, hsv.s, hsv.v);

//     Serial.print("Color: ");
//     Serial.println(colorName);

//     rgbL.turnOnColor(colorName);

// }

