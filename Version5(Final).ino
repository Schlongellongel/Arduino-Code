
#include <Servo.h>;
#include "SevSeg.h"
SevSeg sevseg; 


Servo motor1;
int sensor = 0;
int schalter = 0;
long dauer = 0;
unsigned long Start = 0;
int delai50 = 50;
int delai1000 = 1000;


void setup() {

motor1.attach(5);
Serial.begin(9600);
pinMode(13,INPUT);


  byte numDigits = 3;
  byte digitPins[] = {2, 3, 4};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12};
  bool resistorsOnSegments = false;
  byte hardwareConfig = COMMON_CATHODE;
  bool updateWithDelays = false;
  bool leadingZeros = false;
  bool disableDecPoint = true;
  
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
  updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90);
}

void loop() {


sensor = analogRead(A1);

schalter = digitalRead(13);

sevseg.setNumber(000);

if (sensor < 300) {
  sevseg.setNumber(dauer);
  sevseg.refreshDisplay();

  if (schalter == 1 ) {
    Serial.println(schalter);
    sevseg.refreshDisplay();
    sevseg.setNumber(dauer);

    while (schalter == 1){
      sevseg.refreshDisplay();
      schalter = digitalRead(13);
      dauer = dauer + 1;
      Serial.println(dauer);
      sevseg.setNumber(dauer);
      if (dauer > 100){
        schalter = 0;
      }
      Start = millis();
      while (millis() <= (Start + delai50)){
        sevseg.refreshDisplay();
      }
      //delay(50);

    }

    while(dauer > 0){
      motor1.write(110);
      Serial.println(dauer);
      dauer = dauer - 1;
      Serial.println(dauer);
      Start = millis();
      while(millis() <= (Start + delai1000)){
        sevseg.refreshDisplay();
        sevseg.setNumber(dauer);
      }
      //delay(1000);
    }

    motor1.write(30);
    Serial.println("Vertig");
    dauer = 0;

    }
  
}

else if (sensor >= 300){
  motor1.write(30);
  sevseg.setNumber(0);
  sevseg.refreshDisplay();

}



}
// final Version M.J. JuFo 2024
