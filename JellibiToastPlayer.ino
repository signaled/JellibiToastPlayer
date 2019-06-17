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
#define HC06BAUDRATE 9600
#include <JellibiButton.h>
#include <JellibiPin.h>
#include "ServoAction.h"
#include "Drive.h"

// 젤리비 토스트 보드 간이 핀맵 
#define TOASTPINMAP_BLUELED   6
#define TOASTPINMAP_REDLED    5

#define TOASTPINMAP_RIGHTPWM  11
#define TOASTPINMAP_RIGHTDIR  4
#define TOASTPINMAP_LEFTPWM   10
#define TOASTPINMAP_LEFTDIR   2

#define EXTBOARD_SERVOPORT    0

ServoAction _grip;
Drive _drive;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(HC06BAUDRATE);
  _drive.Init(TOASTPINMAP_RIGHTPWM, TOASTPINMAP_RIGHTDIR, 
              TOASTPINMAP_LEFTPWM,  TOASTPINMAP_LEFTDIR);
  _grip.Init(EXTBOARD_SERVOPORT);
  
  pinMode(TOASTPINMAP_BLUELED, OUTPUT);
  pinMode(TOASTPINMAP_REDLED, OUTPUT);
  digitalWrite(TOASTPINMAP_BLUELED, HIGH);
  digitalWrite(TOASTPINMAP_REDLED, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long curSec = millis()/1000;

  if (curSec%2) {
    digitalWrite(TOASTPINMAP_BLUELED, HIGH);
    digitalWrite(TOASTPINMAP_REDLED, LOW);    
  } else {
    digitalWrite(TOASTPINMAP_BLUELED, LOW);
    digitalWrite(TOASTPINMAP_REDLED, HIGH);
  }
  uint8_t btCmd = 0;
  if (Serial.available()>0) {
    btCmd = Serial.read();
  }    
  
  switch(btCmd)
  {
    case 'U':
      Serial.print('U');
      _drive.Go();
      break;
    case 'R':
      Serial.print('R');
      _drive.Right();
      break;
    case 'D':
      Serial.print('D');
      _drive.Back();
      break;
    case 'L':
      Serial.print('L');
      _drive.Left();
      break;
    case 'S':
      Serial.print('S');
      _drive.Stop();
      break;
    case 'O':
      Serial.print('O');
      _grip.OpenGrip();
      break;
    case 'o':
      Serial.print('o');
      _grip.StepOpen();
      break;
    case 'G':
      Serial.print('G');
      _grip.Grip();
      break;
    case 'g':
      Serial.print('g');    
      _grip.StepGrip();
      break;
  }
}
