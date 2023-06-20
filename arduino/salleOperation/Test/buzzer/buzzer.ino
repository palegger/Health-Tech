void setup() {
  Serial.begin(9600);
  pinMode(31, OUTPUT);
}

void loop() {
    tone(buzzer, 1000); // Send 1KHz sound signal...
    delay(1000);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
    delay(1000);
}
