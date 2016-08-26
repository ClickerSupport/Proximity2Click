/* Proximity 2 Click Demo
 *  
 * Displays the ambient light in Lux and the percentage proximity detected.
 * 
 * For different light levels you may want to change the gain. Gain can be one of:
 * 
 * * PROXIMITY2_GAIN_1 (bright sunlight)
 * * PROXIMITY2_GAIN_4 (normal daylight)
 * * PROXIMITY2_GAIN_16 (indoor, dull)
 * * PROXIMITY2_GAIN_64 (very low light levels)
 * 
 * Ambient will read -1 if the light is too bright for the current gain setting.
 * 
 * Proximity sensing starts about 15-20cm away from the board (0%) and finishes
 * about 3cm from the board (100%). Any closer than 3cm reads 100%.
 * 
 * Actual values depend on colour and reflectivity of the item being sensed.
 */

#include <Wire.h>
#include <Proximity2Click.h>

Proximity2Click prox;

void setup() {
    Serial.begin(115200);
    prox.begin();
    prox.setGain(PROXIMITY2_GAIN_16);
}

void loop() {
    Serial.printf("Ambient: %6.2f lux. Proximity: %6.2f %%\r\n", 
        prox.readAmbient(), prox.readProximity());
    delay(1000);
}
