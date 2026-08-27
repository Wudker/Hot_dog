#include <arduino.h>
#include <Servo.h>
#include "Inverse_kinematic.h"
#define Servo1_pin 9
#define Servo2_pin 10


Servo servo1;
Servo servo2;
Point Cel={10.0, -120.0};

void setup(){
 servo1.attach(Servo1_pin);
 servo2.attach(Servo2_pin);
}

void loop(){
C = Find_C(Cel);
  Serial.print(C.x);
  Serial.print(",");
  Serial.println(C.y);
  delay(5000);
}
/*
  servo1.write(0);
  servo2.write(0);
  delay(5000);
  servo1.write(90);
  servo2.write(90);
  delay(5000);

*/