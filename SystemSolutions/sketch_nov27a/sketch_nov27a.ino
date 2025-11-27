const int stepPin = 6;
const int dirPin  = 5;
const int potPin = A0;

class StepperMotor
{
public:
  StepperMotor(uint16_t stepPin, uint16_t dirPin, int minPosition, int maxPosition)
  {
    _dirPin = dirPin;
    _stepPin = stepPin;
    _minPosition = minPosition;
    _maxPosition = maxPosition;
    _currentPosition = 0;
  }

  void begin()
  {
    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
  }

  void SetAngle(int angle)
  {
    SetPosition((int)(angle / 0.9));
  }

  // Rotates to position that is the number of steps from _initialPosition 
  void SetPosition(int positionSteps)
  {
    int distance = positionSteps - _currentPosition;
    _currentPosition = positionSteps;

    if(distance < 0)
    {
      distance = -distance;
      digitalWrite(_dirPin, LOW);
    }
    else if(distance > 0)
      digitalWrite(_dirPin, HIGH);
    else
      return;

    _rotateByStepCount(distance);
  } 

private:
  int _currentPosition;
  uint16_t _stepPin;
  uint16_t _dirPin;
  int _minPosition;
  int _maxPosition;

  // Sends impulses, the count of which is equal to stepsCount
  void _rotateByStepCount(int stepsCount)
  {
    for(int i = 0; i < stepsCount; i++)
    {
      digitalWrite(_stepPin, HIGH);
      delayMicroseconds(500);
      digitalWrite(_stepPin, LOW);
      delayMicroseconds(500);
    }
  }
};

StepperMotor motor(stepPin, dirPin, 0, 200);

void setup() 
{  
  pinMode(potPin, OUTPUT);
  Serial.begin(115200);
  motor.begin();  
}

void loop() 
{
  Serial.print(analogRead(potPin));
  Serial.print("     ");
  int currAngle = map(analogRead(potPin), 0, 1023, 0, 90);
  Serial.println(currAngle);
  motor.SetAngle(currAngle);
  delay(10); 
}