#ifndef DigitAndAnalogAsBoolean_H
#define DigitAndAnalogAsBoolean_H

#include "Arduino.h"
#include <string.h>



class AnalogPinBoolean {
public:
  int m_pinId=0;
  bool m_lastValue ;
  bool m_currentValue;
  bool m_inverse;
  int m_range_0_1023;
  int m_currentvalue_0_1023;

  AnalogPinBoolean(int pinId=0,int range_0_1023=200, bool defaultValueIsOn=false, bool inverse=false);
  bool IsCurrentOn();
  bool IsPinOn();
  void UpdatePinInfo();
  bool HasChangedThisFrame();
  void SetupPin();
  bool IsPinZero();
};

class DigitPinBoolean {
public:
  int m_pinId=0;
  bool m_lastValue ;
  bool m_currentValue;
  bool m_inverse;
  DigitPinBoolean(int pinId=0, bool defaultValueIsOn=false, bool inverse=false);
  bool IsCurrentOn();
  bool IsPinOn();
  void UpdatePinInfo();
  bool HasChangedThisFrame();
  void SetupPin();
  bool IsPinZero();
};


class ListenPinsAsBoolean{

public:
int digitalBoolCount = 20; 
DigitPinBoolean digitalBool[20] ;
int analogBoolCount = 10;
AnalogPinBoolean analogBool[10] ;

ListenPinsAsBoolean();
void InitDefault();
void RemoveAllPins();
void SetDigitalPin(int index, int pin);
void SetAnalogPin(int index, int pin);
void RefreshPinMode();
void UpdatePinInfoIfNotZero();
void DisplayOnSerialChangedInput(bool updateFirst);

};

#endif