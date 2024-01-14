 #include <Servo.h>;
Servo motor1;
int sensor = 0;
int schalter = 0;

void setup() {

motor1.attach(11);
Serial.begin(9600);
pinMode(2,INPUT);
}

void loop() {


sensor = analogRead(A1);
Serial.println(sensor);
schalter = digitalRead(12);
Serial.println(schalter);


if (sensor < 300) {

  if (schalter == 1 ) {
    motor1.write(110);
    delay(2000);
    motor1.write(30);
    Serial.println("Hallo");}
  
}

else if (sensor >= 300){
  motor1.write(30);
}


//if(sensor > 300); {

  //motor1.write(30);

//}

//sensor = analogRead(A1);
//Serial.println(sensor);
//delay(100);

//motor1.write(110);
//delay(500);
//motor1.write(30);
//delay(500);


}