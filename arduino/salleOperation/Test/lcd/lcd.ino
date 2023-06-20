//library LCD SCREEN
#include <LiquidCrystal.h>
// initialize the library by providing the nuber of pins to it
LiquidCrystal lcd(8,9,4,5,6,7);

void setup(){
  //init LCD
  lcd.begin(16,2);
// set cursor position to start of first line on the LCD
lcd.setCursor(0,0);
//text to print
lcd.print("   POUBELLE");
// set cusor position to start of next line
lcd.setCursor(0,1);
lcd.print("    CONFIGURE");
}

void loop(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Test");
  lcd.setCursor(0,1);
  lcd.print("Test");
}
