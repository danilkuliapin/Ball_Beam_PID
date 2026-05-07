#ifndef PID_H
#define PID_H

#include "Arduino.h"

class PID 
{
private:
  unsigned long _prevTime = 0;
  unsigned long _currentTime = 0;
  double _intErr = 0.;
  double _prevErr = 0.;
  double _derErr = 0.;
  double _err = 0.; 

public:
  double Kp;
  double Ki;
  double Kd; 
  double Setpoint;

  PID(double setpoint, double Kp, double Ki, double Kd)
  {
    Setpoint = setpoint;
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
  }


  double GetControlOutput(double input)
  {
    _currentTime = millis();
    double dt = _currentTime - _prevTime;
    dt /= 1000.0;
    _err = input - Setpoint;
    _intErr += _err * dt;
    _derErr = (_err - _prevErr) / dt;

    _prevErr = _err;
    _prevTime = _currentTime;

    return Kp * _err + Ki * _intErr + Kd * _derErr; 
  }
};


#endif