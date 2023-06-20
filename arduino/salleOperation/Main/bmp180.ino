#include <Wire.h>
#include <Adafruit_BMP085.h>
#define seaLevelPressure_hPa 1013.25

Adafruit_BMP085 bmp;
  
void bmp180Setup() {
  bmp.begin();
}

//Fonction qui va retourner la pression
int bmp180Loop() {
    return bmp.readSealevelPressure();
}
