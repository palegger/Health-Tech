String Ip = "192.168.192.232";
String WifiSSID = "OnePlus Gaab";
String WifiPSW = "gabigaab1";

//Fonction pour se connecter au wifi
void ESPsetup(){
  Serial3.begin(115200);
    Serial.println("**********************************************************");
    Serial.println("**************** DEBUT DE L'INITIALISATION ***************");
    Serial.println("**********************************************************");
    envoieAuESP8266("AT+RST");
    recoitDuESP8266(2000);
    Serial.println("**********************************************************");
    envoieAuESP8266("AT+CWMODE=3");
    recoitDuESP8266(5000);
    Serial.println("**********************************************************");
    Serial.println("**********************************************************");
    envoieAuESP8266("AT+CWJAP=\""+WifiSSID+"\",\""+WifiPSW+"\"");
    recoitDuESP8266(5000);
    Serial.println("**********************************************************");
    Serial.println("***************** INITIALISATION TERMINEE ****************");
    Serial.println("**********************************************************");
}

//Fonction ESP
void APISensor(String airQuality,int pression,float dh, float temp)
{
  String cmd = "GET /newStatus/"+ String(airQuality) +"&"+String(pression)+"&"+String(dh)+"&"+String(temp)+"&Chirurgie HTTP/1.0";
  Serial.print(cmd);
  Serial.println("**************** INIT ENVOIE ***************");
  envoieAuESP8266("AT+CIPSTART=\"TCP\",\"" + Ip + "\",8001");
  recoitDuESP8266(500);
  Serial.println("**************** NB DATA ***************");
  envoieAuESP8266("AT+CIPSEND=250");
  recoitDuESP8266(500);
  Serial.println("**************** GET ROUTE ***************");
  envoieAuESP8266(cmd);
  recoitDuESP8266(500);
  Serial.println("**************** HOST ROUTE ***************");
  envoieAuESP8266("Host: "+Ip);
  envoieAuESP8266("\r\n");
  envoieAuESP8266("\r\n");

  recoitDuESP8266(5000);
}

void envoieAuESP8266(String commande)
{
    Serial3.println(commande);
}

void recoitDuESP8266(const int timeout)
{
    String reponse = "";
    long int time = millis();
    while ((time + timeout) > millis())
    {
        while (Serial3.available())
        {
            char c = Serial3.read();
            reponse += c;
        }
    }
    Serial.print(reponse);
}
