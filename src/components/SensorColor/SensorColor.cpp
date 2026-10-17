#include "SensorColor.h"

SensorColor::SensorColor() {
    // Integracion (cantidad de tiempo que captura color) movimiento -, quieto +
    // (2.4, 24, 50, 101, 154, 700)
    // Ganancia (amplificacion de la señal) oscuro +, mucha luz - 
    // (1, 4, 16, 60)
    tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_24MS, TCS34725_GAIN_60X);
}

bool SensorColor::begin() {
    if (tcs.begin()) {
        return true;
    }

    return false;
}

colorRGB SensorColor::readColor() {
    colorRGB color;

    tcs.getRawData(&r_raw, &g_raw, &b_raw, &c_raw);

    color.red = (float)r_raw / c_raw * 225.0;
    color.green = (float)g_raw / c_raw * 225.0;
    color.blue = (float)b_raw / c_raw * 225.0;

    return color;
}

colorHSV SensorColor::rgbToHsv(float r, float g, float b) {
    colorHSV color;


    float maxVal = max(max(r, g), b);
    float minVal = min(min(r, g), b);
    float delta = maxVal - minVal;


    color.v = maxVal;
    color.s = (maxVal > 0.0) ? (delta / maxVal) : 0.0;
    
    if (delta < 0.00001) {
        color.h = 0;
    }

    else {    
        if (r >= maxVal) {
            color.h = ((g - b) / delta);
        } 
        else if (g >= maxVal) {
            color.h = 2.0 + ((b - r) / delta);
        } 
        else {
            color.h = 4.0 + ((r - g) / delta);
        }

        color.h *= 60.0;

        if (color.h < 0) color.h += 360.0;
    }
    
    return color;
}

String SensorColor:: colorID(float h, float s, float v) {
    // Si la saturación o el valor son muy bajos, no hay color claro
    if (s < 0.20 || v < 15.0) {
        return "Desconocido / Indeterminado";
    }

    if (h >= 353 || h < 8) {
        return "red";
    } 
    else if (h >= 8 && h < 40) {
        return "orange";
    } 
    else if (h >= 40 && h < 68) {
        return "yellow";
    } 
    else if (h >= 58 && h < 150) {
        return "green";
    } 
    else if (h >= 150 && h < 260) {
        return "cyan";
    } 
    else if (h >= 260 && h < 359) {
        return "magenta";
    }

    return "Desconocido";
}
