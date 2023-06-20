//library LCD SCREEN
#include <LiquidCrystal.h>
// initialize the library by providing the nuber of pins to it
LiquidCrystal lcd(8,9,4,5,6,7);

void LCDSetup(){
  //init LCD
  lcd.begin(16,2);
// set cursor position to start of first line on the LCD
lcd.setCursor(0,0);
}
//Fonction that will rotate the information
void lcdLoop(float dh, String airQuality, int bmp, float temp){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Humidity ");
  lcd.print(dh);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print(airQuality);
  delay(1500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pres :");
  lcd.print(bmp);
  lcd.print("Pa");
  lcd.setCursor(0,1);
  lcd.print("Temp ");
  lcd.print(temp);
  delay(1500);
}
