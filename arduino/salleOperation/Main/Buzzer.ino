void buzzerSetup(int buzzer) {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void buzzerLoop() {
    tone(buzzer, 1000); // Send 1KHz sound signal...
    delay(1000);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
    delay(1000);
}
