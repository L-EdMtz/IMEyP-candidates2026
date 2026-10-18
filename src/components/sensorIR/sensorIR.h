#ifndef SENSOR_IR_H
#define SENSOR_IR_H

#include <Arduino.h>

const int pinIR_IZQ = A0;
const int pinIR_DER = A1;
const int UMBRAL_BLANCO = 400; // Valores menores a 400 indican color BLANCO
class SensorIR {
    private:
        
        

    
    public:
        const int pinIR_IZQ = A0;
        const int pinIR_DER = A1;
        const int UMBRAL_BLANCO = 400;
        SensorIR();
        void evaluarNavegacionIR();
        float tomarMedidaIR(int sensor);
};


#endif