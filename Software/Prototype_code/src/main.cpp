#include <arduino.h>
#include <Servo.h>
#include "Inverse_kinematic.h"
#define Servo1_pin 16
#define Servo2_pin 17

Point Cel{0.0, -80.0};
Servo servo1;
Servo servo2;
float Servo1_angle, Servo2_angle;

void setup(){
  Serial.begin(115200);
 servo1.attach(Servo1_pin);
 servo2.attach(Servo2_pin);
}


void Servo_run(){
Return_all_angles(Servo1_angle, Servo2_angle, Cel);
Servo1_angle+=180.0f;
servo1.write(Servo1_angle);
servo2.write(Servo2_angle);
delay(10);


}

void showtime(){
      for (int i = -100; i >= -200; i--)
    {
        Cel = {0.0, (double)i};
        Servo_run();
    }

    for (int i = -200; i <= -100; i++)
    {
        Cel = {0.0, (double)i};
        Servo_run();
    }
}

void startup(){
servo1.write(90);
servo2.write(180);
delay(1000);
}

void loop()
{
  showtime();
}




