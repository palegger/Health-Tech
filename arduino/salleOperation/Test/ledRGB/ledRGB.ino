void setup(){
pinMode(40,OUTPUT); //règle la borne numérique numéro 0 de la carte Arduino en mode sortie
pinMode(41,OUTPUT); //règle la borne numérique numéro 1 de la carte Arduino en mode sortie
pinMode(42,OUTPUT); //règle la borne numérique numéro 1 de la carte Arduino en mode sortie
}

void loop(){
//le module LED s’allume en rouge et vert
digitalWrite(40,HIGH);
digitalWrite(41,LOW);
digitalWrite(42,HIGH);
}
