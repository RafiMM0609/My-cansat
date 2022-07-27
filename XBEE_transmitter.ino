#include "SoftwareSerial.h"

SoftwareSerial zigbee(1,3);//Define rx & tx pin
void setup(){
  Serial.begin(9600);
  zigbee.begin(9600);//zigbee Baudrate
}
void loop(){
    Serial.println("success");
    delay(500);
}
