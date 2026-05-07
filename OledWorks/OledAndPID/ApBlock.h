#ifndef APBLOCK_H
#define APBLOCK_H

#include "Arduino.h"

class ApBlock 
{
private:
  double _prev = 0.0;
  double _prevPrev = 0.0;
  long long _prevTime = 0.0;
public:
  double T;
  double Filter(double current)
  {
    if(_prev == 0)
    {
      _prevPrev = _prev;
      _prevTime = millis();
      return _prev = current;
    }
    long long currTime = millis();
    double dt = (currTime - _prevTime) / 1000.0;
    // if(current > 50)
    // current = 50;
    
    // if(abs(current - _prev) > 10.0)
    // { //TODO: Check this
    //   // double predictRes = _prev + ((_prev - _prevPrev > 0) ? 1 : -1);
    //   // _prevPrev = _prev;
    //   // return _prev = predictRes;  
    //   current = _prev;
    // }
    double res = (dt * current + T *_prev) / (T + dt);
    _prevPrev = _prev;
    _prev = res;
    _prevTime = currTime;
    return res;
  }
};

#endif