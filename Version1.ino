#include <Servo.h>;
Servo motor1;
int sensor = 0;

void setup() {

motor1.attach(11);
Serial.begin(9600);

}

void loop() {


sensor = analogRead(A1);
Serial.println(sensor);

if (sensor < 300) {

  motor1.write(110);
}


if(sensor > 300) {

  motor1.write(30);

}

//sensor = analogRead(A1);
//Serial.println(sensor);
//delay(100);

//motor1.write(110);
//delay(500);
//motor1.write(30);
//delay(500);

}
