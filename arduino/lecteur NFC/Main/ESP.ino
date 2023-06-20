String Ip = "192.168.192.232";
String WifiSSID = "OnePlus Gaab";
String WifiPSW = "gabigaab1";

//connection de l'ESP
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
    envoieAuESP8266("AT+CWJAP=\""+WifiSSID+"\",\""+WifiPSW+"\"");
    recoitDuESP8266(5000);
    Serial.println("**********************************************************");
    Serial.println("***************** INITIALISATION TERMINEE ****************");
    Serial.println("**********************************************************");
}

//Fonction ESP, envoie de la donnée en methode GET sur notre API
void APISensor(String nfcLocation,String nfcId,String nfcName)
{
  String cmd = "GET /newPosition/"+String(nfcLocation)+"&"+String(nfcName)+"&"+String(nfcId)+" HTTP/1.0";
  Serial.println("**************** INIT ENVOIE ***************");
  envoieAuESP8266("AT+CIPSTART=\"TCP\",\"" + Ip + "\",8001");
  recoitDuESP8266(1000);
  Serial.println("**************** NB DATA ***************");
  envoieAuESP8266("AT+CIPSEND=120");
  recoitDuESP8266(1000);
  Serial.println("**************** GET ROUTE ***************");
  envoieAuESP8266(cmd);
  recoitDuESP8266(1000);
  Serial.println("**************** HOST ROUTE ***************");
  envoieAuESP8266("Host: "+Ip);
  envoieAuESP8266("\r\n");
  Serial.println("**************** FORCE ENVOIE ***************");
  envoieAuESP8266("AT+CIPSTART=\"TCP\",\"" + Ip + "\",8001");

  recoitDuESP8266(3000);
  envoieAuESP8266("\r\n");
}

//envoie de données
void envoieAuESP8266(String commande)
{
    Serial3.println(commande);
}

//attente de réponses
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
