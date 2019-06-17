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

#ifndef __SERVO_ACTION_H__
#define __SERVO_ACTION_H__
#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>

#define SERVOMIN  150
#define SERVOMAX  600 

class ServoAction
{
private:
  const int32_t _STEP_ = 60;
  const int32_t _MAX_ = 290;
  const int32_t _MIN_ = 110;
  int32_t _nDuty;    
  Adafruit_PWMServoDriver _pwm;

  int32_t _iServoPort;
public:
  ServoAction();
  void Init(int32_t servoPortIndex = 0);
  void OpenGrip();
  void StepOpen();
  void Grip();
  void StepGrip();

};

#endif//__SERVO_ACTION_H__
