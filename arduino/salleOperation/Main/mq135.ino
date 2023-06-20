//Foncion qui va retouner la qualiter de l'air
String mq135Loop() {
  int mesure = analogRead(A0);
  if (mesure < 80 ) {
    return " AIR CORRECT";
  }
  else
  {
    if (mesure < 140 ) {
      return " AIR MALSAIN";
    }
    else
    {
      return ("ALERTE POLLUTION");
    }
  }
}
