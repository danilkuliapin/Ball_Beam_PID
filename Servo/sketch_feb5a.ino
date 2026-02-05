#include <ESP32Servo.h>
#include <Adafruit_GFX.h>
#include <SH1106.h>
#include <Wire.h>

Servo myServo;
int servoPin = 10;

void setup() 
{
  Serial.begin(11520);
  delay(5000);
  //myServo.attach(servoPin);
}

int angle = 0;
int direction = 1;

void loop() 
{
  //angle = random(0, 180);
  //myServo.write(angle);
  //Serial.print(angle); Serial.println("*");
  //delay(500);


}
