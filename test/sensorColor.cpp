#include <Arduino.h> 
#include "./components/SensorColor/SensorColor.h"

SensorColor tcs;


void setup() {
  Serial.begin(9600);
  tcs.begin();
}

void loop() {
  colorRGB rgb = tcs.readColor();
  colorHSV hsv = tcs.rgbToHsv(rgb.red, rgb.green, rgb.blue);
  String current_color = tcs.colorID(hsv.h, hsv.s, hsv.v);
  
  Serial.print(hsv.h);
  Serial.println(current_color);
  delay(1000);

}

