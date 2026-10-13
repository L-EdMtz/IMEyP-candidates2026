#ifndef SENSOR_COLOR_H
#define SENSOR_COLOR_H

#include <Arduino.h>
#include <Adafruit_TCS34725.h>

struct colorHSV {
    float h;
    float s;
    float v;
};

struct colorRGB {
    // uint8_t red;
    // uint8_t green;
    // uint8_t blue;

    float red;
    float green;
    float blue;
};

class SensorColor {
    private:
        Adafruit_TCS34725 tcs;
        uint16_t r_raw, g_raw, b_raw, c_raw;

    
    public:
        SensorColor();
        bool begin();
        colorRGB readColor();
        colorHSV rgbToHsv(float r, float g, float b);
        String colorID(float h, float s, float v);
};


#endif