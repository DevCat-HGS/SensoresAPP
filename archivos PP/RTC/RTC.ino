#include <RTClib.h>
#include <Wire.h>
RTC_DS1307 RTC;


void setup() 
{
 Wire.begin();
 RTC.begin(); 
Serial.begin(9600);
//RTC:adjust(DateTime(F(__DATE__),F(__TIME__)));


}

void loop() 
{
 DateTime now = RTC.now();
 Serial.print(now.year(),DEC);
 Serial.print(now.month(),DEC);
  Serial.print(now.day(),DEC);
}
