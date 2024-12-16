int alto= 37;
int medio= 38;
int bajo= 39;


void setup() 
{
  pinMode(alto,INPUT);
  pinMode(medio,INPUT);
  pinMode(bajo,INPUT);
 Serial.begin(9600);
Serial.println("Test de sensores");

}

void loop() 
{
 if(digitalRead(alto)==0){
Serial.println("alerta de inundacion");
 }
 else if(digitalRead(medio)==0){
Serial.println("alerta,proximidad de desborde");
 }
 else{
Serial.println("nivel bajo");
 }
}
