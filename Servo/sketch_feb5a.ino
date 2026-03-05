#include <ESP32Servo.h>
#include <Wire.h>

Servo myServo;
int servoPin = 21;

void setup() 
{
  Serial.begin(115200);
  delay(5000);
  myServo.attach(servoPin);
  myServo.write(90);
  //while(1);
}

int angle = 0;
int direction = 1;

int center = 85;
int max_angle = 5;
int d_l = 50;

void loop()
{
  // 0 → -25
  for(int i = 0; i >= -max_angle*2; i--)
  {
    myServo.write(center + i);
    Serial.println(center + i);
    delay(d_l);
  }

  // -25 → 0
  for(int i = -max_angle*2; i <= 0; i++)
  {
    myServo.write(center + i);
    Serial.println(center + i);
    delay(d_l);
  }

  // 0 → +25
  for(int i = 0; i <= max_angle; i++)
  {
    myServo.write(center + i);
    Serial.println(center + i);
    delay(d_l);
  }

  // +25 → 0
  for(int i = max_angle; i >= 0; i--)
  {
    myServo.write(center + i);
    Serial.println(center + i);
    delay(d_l);
  }
}
  
