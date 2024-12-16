#include <LiquidCrystal.h>
const int rs = 27, en = 22, d4 = 26, d5 = 25, d6 = 24, d7 = 23;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);



void setup() {
 lcd.begin(16, 2);
lcd.setCursor(6,0);
lcd.print ("Hora");
lcd.setCursor(4,1);
lcd.print ("del weed");



}

void loop() {
  

}
