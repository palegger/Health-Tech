#include "DHT.h"

  DHT dht(30, DHT11);
void setup() {
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  Serial.print(h);
}
