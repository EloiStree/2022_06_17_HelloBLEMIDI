

#include "Arduino.h"
#include "DigitAndAnalogAsBoolean.h"
#include <string.h>

  AnalogPinBoolean::AnalogPinBoolean(int pinId,int range_0_1023, bool defaultValueIsOn, bool inverse=false){ 
    m_pinId= pinId;
    m_lastValue=defaultValueIsOn;
    m_currentValue=defaultValueIsOn;
    m_inverse=inverse;
    m_range_0_1023=range_0_1023;
  }
  
  void AnalogPinBoolean::SetupPin(){ pinMode(m_pinId,INPUT_PULLUP);}
  bool AnalogPinBoolean::IsCurrentOn(){ return m_currentValue; }
  bool AnalogPinBoolean::IsPinOn(){
    m_currentvalue_0_1023 =analogRead(m_pinId);
    if(m_inverse) return m_currentvalue_0_1023 >= m_range_0_1023;
    else return m_currentvalue_0_1023 <= m_range_0_1023;
  }
  void AnalogPinBoolean::UpdatePinInfo(){m_lastValue= m_currentValue; m_currentValue=IsPinOn(); }
  bool AnalogPinBoolean::HasChangedThisFrame(){ return m_lastValue != m_currentValue ; }
  bool AnalogPinBoolean::IsPinZero(){ return m_pinId==0;}



////////////////////////

  DigitPinBoolean::DigitPinBoolean(int pinId, bool defaultValueIsOn, bool inverse=false){ 
    m_pinId= pinId;
    m_lastValue=defaultValueIsOn;
    m_currentValue=defaultValueIsOn;
    m_inverse=inverse;
  }

  void DigitPinBoolean::SetupPin(){ pinMode(m_pinId,INPUT_PULLUP);}
  bool DigitPinBoolean::IsCurrentOn(){ return m_currentValue; }
  bool DigitPinBoolean::IsPinOn(){
    if(m_inverse) return digitalRead(m_pinId)==HIGH;
    else return digitalRead(m_pinId)!=HIGH;
  }
  void DigitPinBoolean::UpdatePinInfo(){m_lastValue= m_currentValue; m_currentValue=IsPinOn(); }
  bool DigitPinBoolean::HasChangedThisFrame(){ return m_lastValue!= m_currentValue ;}
  bool DigitPinBoolean::IsPinZero(){ return m_pinId==0;}



  //////////////////////////////

 ListenPinsAsBoolean::ListenPinsAsBoolean(){
  InitDefault();
}
void ListenPinsAsBoolean::RefreshPinMode(){
 for (int i = 0; i < digitalBoolCount; i++) {
  if(!digitalBool[i].IsPinZero())
    digitalBool[i].SetupPin();
  }
  for (int i = 0; i < analogBoolCount; i++) {
  if(!analogBool[i].IsPinZero())
    analogBool[i].SetupPin();
  }
}

void ListenPinsAsBoolean::UpdatePinInfoIfNotZero(){

  for (int i = 0; i < digitalBoolCount; i++) {
    digitalBool[i].UpdatePinInfo();
  }
  for (int i = 0; i < analogBoolCount; i++) {
    analogBool[i].UpdatePinInfo();
  }
}

void ListenPinsAsBoolean::DisplayOnSerialChangedInput(bool updateFirst){

  if(updateFirst)
    UpdatePinInfoIfNotZero();

  bool hadChange=false;
  for (int i = 0; i < digitalBoolCount; i++) {
    if (!digitalBool[i].IsPinZero() && 
      digitalBool[i].HasChangedThisFrame()) {
      Serial.print(digitalBool[i].m_pinId);
      Serial.print(digitalBool[i].IsCurrentOn());
      Serial.print(" ");
      hadChange=true;
    }
  }
  for (int i = 0; i < analogBoolCount; i++) {
    if (!analogBool[i].IsPinZero()
     && analogBool[i].HasChangedThisFrame()) {
      Serial.print(analogBool[i].m_pinId);
      Serial.print(analogBool[i].IsCurrentOn());
      Serial.print(" ");
      hadChange=true;
    }
  }
  if(hadChange)
      Serial.println(" <- Had Pin Change");
}

void ListenPinsAsBoolean::InitDefault(){
  
  RemoveAllPins();
  SetAnalogPin(0,A1);
  SetAnalogPin(1,A2);
  SetAnalogPin(2,A3);
  SetAnalogPin(3,A4);
  SetAnalogPin(4,A5);
  SetDigitalPin(0,3);
  SetDigitalPin(1,4);
  SetDigitalPin(2,5);
  SetDigitalPin(3,6);
  SetDigitalPin(4,7);
  SetDigitalPin(5,8);
  SetDigitalPin(6,9);
}

void  ListenPinsAsBoolean::RemoveAllPins(){
 for (int i = 0; i < digitalBoolCount; i++) {
    digitalBool[i].m_pinId=0;
  }
  for (int i = 0; i < analogBoolCount; i++) {
    analogBool[i].m_pinId=0;
  }
}
void  ListenPinsAsBoolean::SetDigitalPin(int index, int pin){
 digitalBool[index].m_pinId=pin;
}
void  ListenPinsAsBoolean::SetAnalogPin(int index, int pin){
  analogBool[index].m_pinId=pin;
}