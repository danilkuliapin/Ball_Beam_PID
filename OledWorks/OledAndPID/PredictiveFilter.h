#include "Arduino.h"

class PredictiveFilter 
{
private:
  unsigned long _prevTime = 0;
  unsigned long _currentTime = 0;

  double _prevVal = 0.0;
  double _intg = 0.;
  double res = 0.0;

public:
  double Predict(double currentAngle, double distance)
  {
    _currentTime = millis();
     double dt = (_currentTime - _prevTime) / 1000.0;

    if(abs(current - _prevVal) > 10)
        res = (_intErr += 3 * current * dt + 2 * (current - _prevVal));
    else
        res = current;

    _prevVal = res;
    _prevTime = _currentTime;
    return res;
  }
};
