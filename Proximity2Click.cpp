#include <Proximity2Click.h>

void Proximity2Click::writeRegister(uint8_t reg, uint8_t val) {
    Wire.beginTransmission(MAX44000_ADDRESS);
    Wire.write(reg);
    Wire.write(val);
    Wire.endTransmission();
}

uint8_t Proximity2Click::readRegister(uint8_t reg) {
    Wire.beginTransmission(MAX44000_ADDRESS);
    Wire.write(reg);
    Wire.endTransmission(false);
    Wire.requestFrom((uint8_t)MAX44000_ADDRESS, (uint8_t)1);
    return Wire.read();
}

void Proximity2Click::begin() {
    Wire.begin();
    writeRegister(MAX44000_CFG_MAIN, 0x30); // Constant ALS and PROX measurements
    writeRegister(MAX44000_CFG_RX, 0xF0);
    writeRegister(MAX44000_CFG_TX, 0x0F);
    gain = 0.03125;
}

void Proximity2Click::setGain(uint8_t g) {
    g &= 0x03;
    writeRegister(MAX44000_CFG_RX, 0xF0 | g);
    switch(g) {
        case PROXIMITY2_GAIN_64: gain = 0.03125; break;
        case PROXIMITY2_GAIN_16: gain = 0.125; break;
        case PROXIMITY2_GAIN_4: gain = 0.5; break;
        case PROXIMITY2_GAIN_1: gain = 4; break;
    }
}

float Proximity2Click::readAmbient() {
    uint8_t h = readRegister(MAX44000_ALS_H);
    uint8_t l = readRegister(MAX44000_ALS_H);
    uint16_t v = (h << 8) | l;
    if (v & 0x4000) return -1; // Overflow.
    return v * gain;
}

float Proximity2Click::readProximity() {
    uint8_t prox = readRegister(MAX44000_PROX);
    return prox / 253.0 * 100.0;
}
