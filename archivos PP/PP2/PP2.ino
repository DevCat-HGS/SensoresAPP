int alto = 37;
int medioalto = 38;
int medio = 39;
int bajoalto = 40;
int bajo = 41;
int ledRojo = 53;
int ledVerde = 51;
int ledAzul = 52;
int buzzer = 50;
#include <LiquidCrystal.h>
const int rs = 27, en = 22, d4 = 26, d5 = 25, d6 = 24, d7 = 23;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#include <Keypad.h>   //libreria
const byte ROWS = 5;  //four rows
const byte COLS = 4;  //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  { 'A', 'B', '#', '*' },
  { '1', '2', '3', 'W' },
  { '4', '5', '6', 'Z' },
  { '7', '8', '9', 'Y' },
  { 'M', '0', '=', 'X' }
};
byte rowPins[ROWS] = { 36, 34, 32, 30, 28 };
byte colPins[COLS] = { 29, 31, 33, 35 };

Keypad teclado = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
//---------------
#include <Wire.h>
#include <I2C_RTC.h>
static DS1307 RTC;
//---------------
char tecla;
String clave = "";
String password = "BABA55";
int sw = 0;
bool estado = false;
int c = 0;



void setup() {
  pinMode(alto, INPUT);
  pinMode(medioalto, INPUT);
  pinMode(medio, INPUT);
  pinMode(bajoalto,INPUT);
  pinMode(bajo, INPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  Serial.println("Test de sensores");
  delay(2000);
  Wire.begin();
  RTC.begin();
  RTC.setDateTime(__DATE__, __TIME__);
  Serial.begin(9600);
  inicio();
  reloj();
}

void loop() {

  tecla = teclado.getKey();
  if (estado == true && sw ==0 ) {
   sensores();
  }
  if (tecla && sw == 0) {
    Menu1();
  }
  if (sw == 10) {
    switch (tecla) {
      case '1':
        Serial.print(" Digite clave : ");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("clave: ");
        tecla = 0;
        sw = 20;
        break;
      case '*':
        sw = 0;
        tecla = 0;
        reloj();
        break;
    }
  }
  if (tecla && sw == 20) {
    if (tecla == 'X') {
      lcd.clear();
      Serial.println(" ");
      lcd.print("validando...");
      c=0;
      ver_password();
    } else {
      clave += tecla;
      c++;
      Serial.print("*");
      lcd.setCursor(6+c, 0);
      lcd.print(tecla);
      
    }
  }
}
//-------------------------
void reloj() {
  lcd.clear();
  lcd.print("Fecha: ");
  lcd.print(RTC.getDay());
  lcd.print("/");
  lcd.print(RTC.getMonth());
  lcd.print("/");
  lcd.print(RTC.getYear());
  lcd.setCursor(0,1);
  lcd.print("hora: ");
  lcd.print(RTC.getHours());
  lcd.print(":");
  lcd.print(RTC.getMinutes());

  
  Serial.println("            FECHA      ");
  switch (RTC.getWeek()) {
    case 1:
      Serial.print(" Lunes  ");
      break;
    case 2:
      Serial.print(" Martes  ");
      break;
    case 3:
      Serial.print(" Miercoles  ");
      break;
    case 4:
      Serial.print(" Jueves  ");
      break;
    case 5:
      Serial.print(" Viernes  ");
      break;
    case 6:
      Serial.print(" Sabado  ");
      break;
    case 0:
      Serial.print(" Domingo  ");
      break;
  }
  Serial.print(RTC.getDay());
  Serial.print(" de ");
  switch (RTC.getMonth()) {
    case 1:
      Serial.print("Enero");
      break;
    case 2:
      Serial.print("Febrero");
      break;
    case 3:
      Serial.print("Marzo");
      break;
    case 4:
      Serial.print("Abril");
      break;
    case 5:
      Serial.print("Mayo");
      break;
    case 6:
      Serial.print("Junio");
      break;
    case 7:
      Serial.print("Julio");
      break;
    case 8:
      Serial.print("Agosto");
      break;
    case 9:
      Serial.print("Septiembre");
      break;
    case 10:
      Serial.print("Octubre");
      break;
    case 11:
      Serial.print("Novienbre");
      break;
    case 12:
      Serial.print("Dicienbre");
      break;
  }
  Serial.print(" de ");
  Serial.println(RTC.getYear(), DEC);
  Serial.println("            HORA      ");
  Serial.print("          ");
  Serial.print(RTC.getHours());  //horas
  Serial.print(":");
  Serial.print(RTC.getMinutes());  //minutos
  Serial.print(":");
  Serial.print(RTC.getSeconds());  //segundos
  Serial.println("    ");
  //delay(10000); // La información se actualiza cada 1 minuto.
}

//---------------------
void inicio() {
  Serial.println("------------------------------------");
  Serial.println("MONITOREO DEL AGUA");
  lcd.setCursor(0,0);
  lcd.print("MONITOREO DEL");
  Serial.println("SENSORES DE NIVEL");
  lcd.setCursor(0,1);
  lcd.print("NIVEL DE AGUA");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("BIENVENIDOS");
  lcd.setCursor(0,1);
  lcd.print("CREADORES");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Harold G");
  lcd.setCursor(0,1);
  lcd.print("Smaikell A");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Juan Esteban D");
  lcd.setCursor(0,1);
  lcd.print("Manuel R");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Camilo T");
  delay(2000);
  lcd.clear();
  reloj();
  Serial.println(" ");
}

//---------------
void Menu1() {
  lcd.clear();
  if (estado == false && sw == 0) {
    Serial.println("1: Activar Sistema");
    lcd.setCursor(0, 0);
    lcd.print("1: Activar ");
    Serial.println("*: Salir");
    lcd.setCursor(0, 1);
    lcd.print("*: Salir");
  }
  if (estado == true && sw == 0) {
    Serial.println("1: Apagar Sistema");
    lcd.setCursor(0, 0);
    lcd.print("1: Apagar ");
    Serial.println("*: Salir");
    lcd.setCursor(0, 1);
    lcd.print("*: Salir");
  }
  sw = 10;
  tecla = 0;
}

//-------------
void ver_password() {
  if (clave == password) {
    if (estado == false) {
      estado = true;
      Serial.println(" Sistema Activado");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("ENCENDIDO");
    } else {
      estado = false;
      Serial.println("Sistema Apagado");
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("APAGADO");
    }
  } else {
    Serial.println("Clave incorrecta");
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("INCORRECTO");
  }
  delay(2000);
  sw = 0;
  reloj();
  clave = "";
}
//-------------------- lectura sensores
void sensores(){
  if (digitalRead(alto) == 0) {
      Serial.println("ALTO");
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("***PELIGRO***");
      lcd.setCursor(3, 1);
      lcd.print("inundacion");
      lcd.noDisplay();
      delay(5000);
      lcd.display();
      delay(5000);
      digitalWrite(53, HIGH);
      digitalWrite(52, LOW);
      digitalWrite(51, LOW);
      tone(buzzer,220,100);
      noTone(buzzer);
      digitalWrite(50, LOW);
    } else if (digitalRead(medioalto) == 0) {
      Serial.println("MEDIO-ALTO");
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("presipitacion");
      lcd.setCursor(4, 1);
      lcd.print("del agua ");
      lcd.noDisplay();
      delay(5000);
      lcd.display();
      delay(5000);
      digitalWrite(52, HIGH);
      digitalWrite(53, HIGH);
      digitalWrite(51, LOW);
    } else if (digitalRead(medio)== 0){
      Serial.println("MEDIO");
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("*** bajo ***");
      lcd.setCursor(4, 1);
      lcd.print("moderado");
      lcd.noDisplay();
      delay(5000);
      lcd.display();
      delay(5000);
      digitalWrite(51, LOW);
      digitalWrite(52, HIGH);
      digitalWrite(53, LOW);
    } if (digitalRead(bajoalto) == 0){
      Serial.println("BAJO-ALTO");
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("*** bajo ***");
      lcd.setCursor(4, 1);
      lcd.print("precipitado");
      lcd.noDisplay();
      delay(1000);
      lcd.display();
      delay(1000);
      digitalWrite(51, HIGH);
      digitalWrite(52, HIGH);
      digitalWrite(53, HIGH);
      
    } 
    else {
      Serial.println("BAJO");
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("*** bajo ***");
      lcd.setCursor(4, 1);
      lcd.print("moderado");
      lcd.noDisplay();
      delay(1000);
      lcd.display();
      delay(1000);
      digitalWrite(51, HIGH);
      digitalWrite(52, LOW);
      digitalWrite(53, LOW);
      
    }
}

