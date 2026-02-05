#include <Arduino.h>

#define ENCODER_A 2 // Pin A
#define ENCODER_B 3 // Pin B

volatile long encoderPos = 0;
volatile bool aSet = false;
volatile bool bSet = false;

void IRAM_ATTR doEncoderA() {
  if (digitalRead(ENCODER_A) == digitalRead(ENCODER_B)) encoderPos++;
  else encoderPos--;
}

void IRAM_ATTR doEncoderB() {
  if (digitalRead(ENCODER_A) != digitalRead(ENCODER_B)) encoderPos++;
  else encoderPos--;
}

void setup() {
  Serial.begin(115200);
  pinMode(ENCODER_A, INPUT_PULLUP);
  pinMode(ENCODER_B, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ENCODER_A), doEncoderA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_B), doEncoderB, CHANGE);
}

void loop() {
  static long lastPos = 0;
  if (encoderPos != lastPos) {
    Serial.println(encoderPos);
    lastPos = encoderPos;
  }
}
