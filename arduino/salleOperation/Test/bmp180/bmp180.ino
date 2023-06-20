#include <Wire.h>
#include <Adafruit_BMP085.h>
#define seaLevelPressure_hPa 1013.25

Adafruit_BMP085 bmp;
  
void setup() {
  bmp.begin();
}
  
void loop() {
    Serial.print(bmp.readSealevelPressure());
}
