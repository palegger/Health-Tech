#include <SPI.h> // SPI
#include <MFRC522.h> // RFID

#define SS_PIN 9
#define RST_PIN 8
    
// Déclaration 
MFRC522 rfid(SS_PIN, RST_PIN); 

// Tableau contentent l'ID
byte nuidPICC[4];

int nfcId = 1;

String nfcName = "";
String nfcLocation = "couloir_1";
String tagId = "";
String nfcInfos[2] = {nfcLocation, tagId};


void NFCsetup() 
{ 
  //ESPsetup();
  // Init RS232
  Serial.begin(9600);

  // Init SPI bus
  SPI.begin(); 

  // Init MFRC522 
  rfid.PCD_Init(); 
}
 
String NFCloop() 
{
  tagId = "";
  // Initialisé la boucle si aucun badge n'est présent 
  if ( !rfid.PICC_IsNewCardPresent())
    return "";

  // Vérifier la présence d'un nouveau badge 
  if ( !rfid.PICC_ReadCardSerial())
    return tagId;

  // Enregistrer l'ID du badge (4 octets) 
  for (byte i = 0; i < 4; i++) 
  {
    nuidPICC[i] = rfid.uid.uidByte[i];
  }
  
  // Affichage de l'ID 
  Serial.println("Un badge est détecté");
  Serial.println(" L'UID du tag est:");
  for (byte i = 0; i < 4; i++) 
  {
    Serial.print(nuidPICC[i], HEX);
    Serial.print(" ");
    tagId.concat(String(nuidPICC[i], HEX));
  }
  tagId.toUpperCase();
  Serial.println(tagId);
  Serial.println(nfcInfos[0]);
  Serial.println();
  delay(1000);

  if (tagId != ""){
    if (tagId == "FCF9C716"){
      nfcName = "chariot_1";
    }else if(tagId == "837C733"){
      nfcName = "defibrilateur_8";
    }else if(tagId == "5C5F7217"){
      nfcName = "lit_17";
    }
    APISensor(nfcLocation, tagId, nfcName);
    delay(5000);
  }

  // Re-Init RFID
  rfid.PICC_HaltA(); // Halt PICC
  rfid.PCD_StopCrypto1(); // Stop encryption on PCD
}
