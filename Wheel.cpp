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

#include "Wheel.h"

Wheel::Wheel()
: _pwmPin(0)
, _dirPin(0)
, _bRightWheel(true)
, _iWheelStateIdx(3)
{
    memset(_arrPwm, 0x00, sizeof(int32_t)*5);
    _arrPwm[0] = _arrPwm[6] = _MAX_PWM_;
    _arrPwm[1] = _arrPwm[5] = _MIN_PWM_ + _STEP_PWM_;
    _arrPwm[2] = _arrPwm[4] = _MIN_PWM_;
    _arrPwm[3] = 0;
    _nGain = 0;
}

void Wheel::Init(int pwmPin, int dirPin, bool bRightWheel) 
{
    _pwmPin = pwmPin;
    _dirPin = dirPin;
    _bRightWheel = bRightWheel;
    pinMode(_pwmPin, OUTPUT);
    pinMode(_dirPin, OUTPUT);
    
    Stop();
}

int32_t Wheel::GetPwm() 
{
  return _arrPwm[_iWheelStateIdx];
}

int32_t Wheel::GetDirection()
{   
    if (_bRightWheel) {
        if (_iWheelStateIdx >= 3 ) // forward
            return LOW;
        else 
            return HIGH;
    }
    else {
        if (_iWheelStateIdx >= 3 ) // forward
            return HIGH;
        else
            return LOW;
    }
}

void Wheel::Apply() 
{
    digitalWrite(_dirPin, GetDirection());
    analogWrite( _pwmPin, GetPwm() + _nGain);
}

void Wheel::Stop()
{
    _nGain = 0;
    _iWheelStateIdx = 3;
    Apply();
}

void Wheel::Up()
{
    _nGain = 0;
    if ( (_iWheelStateIdx + 1) < STATE_MAX ) {
      _iWheelStateIdx++;
    }
    Apply();
}

void Wheel::Down()
{
    _nGain = 0;
    if ( _iWheelStateIdx > 0 ) {
      _iWheelStateIdx--;
    }
    Apply();
}

void Wheel::GainUp() 
{
    _nGain += _GAIN_STEP_;
    if (_nGain > _MAX_GAIN_) {
      _nGain = _MAX_GAIN_;
    }
    
    Apply();
}

void Wheel::GainDown()
{
    if (_nGain > _MIN_GAIN_) {
      _nGain -= _GAIN_STEP_;
    }
    
    Apply();
}
