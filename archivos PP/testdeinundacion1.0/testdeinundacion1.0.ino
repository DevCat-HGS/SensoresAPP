
int alto = 37;
int medio = 38;
int bajo = 39;
int ledRojo = 53;
int ledVerde = 51;
int ledAzul = 52;

#include <LiquidCrystal.h>
const int rs = 27, en = 22, d4 = 26, d5 = 25, d6 = 24, d7 = 23;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(alto, INPUT);
  pinMode(medio, INPUT);
  pinMode(bajo, INPUT);
pinMode(ledRojo, OUTPUT);
pinMode(ledVerde, OUTPUT);
pinMode(ledAzul, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  Serial.println("Test de sensores");
  lcd.print("Test de sensores");
  delay(2000);
}

void loop() {
  if (digitalRead(alto) == 0) {
    Serial.println("alerta de inundacion");
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("*** Alerta ***");
    lcd.setCursor(3, 1);
    lcd.print("inundacion");
    lcd.noDisplay();
    delay(500);
    lcd.display();
    delay(500);
  } else if (digitalRead(medio) == 0) {
    Serial.println("alerta,proximidad de desborde");
        lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("presipitacion");
    lcd.setCursor(4, 1);
    lcd.print("del agua ");
    lcd.noDisplay();
    delay(500);
    lcd.display();
    delay(500);
    
  } 
  else {
    Serial.println("nivel bajo");
        lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("*** bajo ***");
    lcd.setCursor(4, 1);
    lcd.print("moderado");
    lcd.noDisplay();
    delay(500);
    lcd.display();
    delay(500);
  }
  
}
