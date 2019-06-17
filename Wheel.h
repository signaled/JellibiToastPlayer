/* *********************************************************************************** 
MIT License

Copyright (c) 2019 jhlee@robotnmore.com (signaled@gmail.com)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*********************************************************************************** */

#ifndef __WHEEL_H__
#define __WHEEL_H__
#include <Arduino.h>


#define STATE_MAX   7
#define _STOP_PWM_  0
#define _MIN_PWM_   40
#define _STEP_PWM_  60
#define _MAX_PWM_   160

#define _MIN_GAIN_  (-30)
#define _GAIN_STEP_ (10)
#define _MAX_GAIN_  (30)

class Wheel
{
private:
  int _pwmPin;
  int _dirPin;
  bool _bRightWheel;
  int32_t _nGain;
    
  int32_t GetDirection();
  int32_t GetPwm(); 
  void Apply();
  
  int8_t _iWheelStateIdx;
  int32_t _arrPwm[STATE_MAX];
  
public:
  Wheel();
  void Init(int pwmPin, int dirPin, bool bRightWheel);
  void Stop();

  void Up();
  void Down();
  void GainUp();
  void GainDown();
};

#endif//__WHEEL_H__
