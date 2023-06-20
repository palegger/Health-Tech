void ledSetup(int lightR, int lightV, int lightB) {
  // initialize serial communication at 9600 bits per second:
  pinMode(lightR, OUTPUT);
  pinMode(lightV, OUTPUT);
  pinMode(lightB, OUTPUT);
  
  Serial.begin(9600);
}
//Fonction qui va activer la led en rouge ou vert en fonction de la valeur envoyer
void ledLoop(int color) {
  if(color == 1) {
    digitalWrite(lightR,LOW);
    digitalWrite(lightV,HIGH);
    digitalWrite(lightB,LOW);
  }
  else {
    digitalWrite(lightR,HIGH);
    digitalWrite(lightV,LOW);
    digitalWrite(lightB,LOW);
  }
}
