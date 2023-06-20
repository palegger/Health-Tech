#include "DHT.h"

  DHT dht(30, DHT11);
void dhtSetup() {
  dht.begin();
}
//Fonction pour retourner l'humidité
float dhLoop() {
  float h = dht.readHumidity();
  return h;
}
//Fonction pour retourner la température
float dhTemp() {
  float t = dht.readTemperature();
  return t;
}
