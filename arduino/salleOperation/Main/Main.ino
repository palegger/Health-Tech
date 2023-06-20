int lightR = 40;
int lightV = 41;
int lightB = 42;

int buzzer = 31;

//Fonction qui va toute les initialisations
void setup() {
  Serial.begin(115200);
  ESPsetup();
  LCDSetup();
  ledSetup(lightR, lightV, lightB);
  dhtSetup();
  buzzerSetup(buzzer);
  bmp180Setup();
}
//Fonction principale qui va tourner en boucle
void loop() {
  float dh = dhLoop();
  String airQuality = mq135Loop();
  int bmp = bmp180Loop();
  float temp = dhTemp();
  lcdLoop(dh, airQuality, bmp, temp);

  if(dh > 20 || airQuality != "ALERTE POLLUTION" || bmp > -300000) {
    ledLoop(0);
    buzzerLoop();
  }
  else{
    ledLoop(1);
  }
  Serial.print("Sensor");
  APISensor(airQuality, bmp, dh, temp);
}
