#ifndef SENSOR_COLOR_H
#define SENSOR_COLOR_H

#include <Arduino.h>
#include <Adafruit_TCS34725.h>

struct colors {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

class SensorColor {
    private:
        Adafruit_TCS34725 tcs;
        float r_raw, g_raw, b_raw; 
    
    public:
        SensorColor();
        bool begin();
        colors readColor();

};


#endif