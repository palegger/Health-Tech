
String idCard = "";

//Appel des setup des fichiers
void setup() {
  NFCsetup();
  ESPsetup();
}

//Appel des loop des fichiers
void loop() {
  idCard = NFCloop();
}
