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



void setup() {
  Wire.begin();
  RTC.begin();
  RTC.setDateTime(__DATE__, __TIME__);
  Serial.begin(9600);
  inicio();
  reloj();
}

void loop() {
  tecla = teclado.getKey();
  if (estado == true )
  {
    
  }
  if (tecla && sw == 0)
  {
    Menu1();
  }
  if (sw == 10)
   {
     switch (tecla)
      {
        case '1' :   Serial.print (" Digite clave : "); tecla = 0; sw = 20;
          break;
        case '*' :   sw = 0; tecla = 0; reloj();
          break;
      }
   }
   if (tecla && sw == 20)
   {
     if (tecla == 'X')
     {
       Serial.println(" "); ver_password();
     }
     else{
      clave += tecla;
      Serial.print("*");
     }
   }
}
//-------------------------
void reloj() {

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
  Serial.println("  SENA CTPGA - Tecnico en Sistemas  ");
  Serial.println("     JOHN JADER ALEMAN MONTES       ");
  reloj();
  Serial.println(" ");
}

//---------------
void Menu1() {
  if (estado == false && sw == 0) {
    Serial.println("1: Activar Sistema");
    Serial.println("*: Salir");
  }
  if (estado == true && sw == 0) {
    Serial.println("1: Apagar Sistema");
    Serial.println("*: Salir");
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
    } 
    else {
      estado = false;
      Serial.println("Sistema Apagado");
    }
  } else {
    Serial.println("Clave incorrecta");
  }
  delay(2000);
  sw = 0;
  reloj();
  clave = "";
}