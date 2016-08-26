#include <Arduino.h>
#include <Wire.h>

#define MAX44000_ADDRESS 0x4A

#define MAX44000_INT_STAT       0x00
#define MAX44000_CFG_MAIN       0x01
#define MAX44000_CFG_RX         0x02
#define MAX44000_CFG_TX         0x03
#define MAX44000_ALS_H          0x04
#define MAX44000_ALS_L          0x05
#define MAX44000_PROX           0x16
#define MAX44000_THR_U_ALS_H    0x06
#define MAX44000_THR_U_ALS_L    0x07
#define MAX44000_THR_L_ALS_H    0x08
#define MAX44000_THR_L_ALS_L    0x09
#define MAX44000_THR_PERSIST    0x0A
#define MAX44000_THR_PROX_IND   0x0B
#define MAX44000_THR_PROX       0x0C
#define MAX44000_GAIN_GREEN     0x0F
#define MAX44000_GAIN_IR        0x10

#define PROXIMITY2_GAIN_64      0b00
#define PROXIMITY2_GAIN_16      0b01
#define PROXIMITY2_GAIN_4       0b10
#define PROXIMITY2_GAIN_1       0b11

class Proximity2Click {
    private:
        float gain;

        void writeRegister(uint8_t reg, uint8_t val);
        uint8_t readRegister(uint8_t reg);

    public:
        Proximity2Click() {}
        void begin();
        void setGain(uint8_t g);
        float readAmbient();
        float readProximity();
};
