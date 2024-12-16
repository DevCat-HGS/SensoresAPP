#include <Keypad.h>

const byte ROWS = 5; 
const byte COLS = 4; 
char hexaKeys[ROWS][COLS] = {
  {'A','B','#','*'},
  {'1','2','3','W'},
  {'4','5','6','Z'},
  {'7','8','9','Y'},
  {'M','0','=','X'}
};
byte rowPins[ROWS] =  {36, 34, 32, 30, 28};
byte colPins[COLS] =  {29, 31, 33, 35};
Keypad teclado = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
char tecla; 
void setup() {
Serial.begin(9600);
}

void loop() {
 tecla = teclado.getKey();
if(tecla) {
  Serial.print(tecla);
}


}
