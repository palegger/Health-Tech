String Ip = "192.168.192.232";
String WifiSSID = "OnePlus Gaab";
String WifiPSW = "gabigaab1";

void setup(){
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
void loop()
{
 
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
