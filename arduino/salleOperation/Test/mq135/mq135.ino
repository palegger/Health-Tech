void setup() {
  Serial.begin(9600);
}

void loop() {
  int mesure = analogRead(A0);
  if (mesure < 80 ) {
    Serial.print(" AIR CORRECT");
  }
  else
  {
    if (mesure < 140 ) {
      Serial.print(" AIR MALSAIN");
    }
    else
    {
      Serial.print("ALERTE POLLUTION");
    }
  }
}
