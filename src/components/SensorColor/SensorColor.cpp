#include "SensorColor.h"

SensorColor::SensorColor() {
    
    tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X);
}

bool SensorColor::begin() {
    if (tcs.begin()) {
        return true;
    }

    return false;
}

colors SensorColor::readColor() {
    colors color;

    tcs.getRGB(&r_raw, &g_raw, &b_raw);

    color.red = (uint8_t)constrain((int)(r_raw + 0.5f),0,255);
    color.green = (uint8_t)constrain((int)(g_raw + 0.5f),0,255);
    color.blue = (uint8_t)constrain((int)(b_raw + 0.5f),0,255);

    // tcs.getRawData(&r_raw, &g_raw, &b_raw, &c_raw);


    // if (c_raw > 0) {
    //     color.red = (uint8_t)(((float)r_raw / c_raw) * 255);
    //     color.green = (uint8_t)(((float)g_raw / c_raw) * 255);
    //     color.blue = (uint8_t)(((float)b_raw / c_raw) * 255);
    // }

    return color;
}