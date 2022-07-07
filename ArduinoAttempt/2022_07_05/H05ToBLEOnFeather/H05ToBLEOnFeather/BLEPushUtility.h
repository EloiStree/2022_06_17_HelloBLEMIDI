#ifndef BLEPushUtility_H
#define BLEPushUtility_H
#include "Arduino.h"
#include <SPI.h>
#include <string.h>
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_SPI.h"
#include "Adafruit_BluefruitLE_UART.h"
#include "Adafruit_BLEMIDI.h"
#include "BluefruitConfig.h"
//#include <USB-MIDI.h>

#define FACTORYRESET_ENABLE 0
#define MINIMUM_FIRMWARE_VERSION "0.7.0"
//#define MODE_LED_BEHAVIOUR "MODE"



class BLEPushUtility{

  public:
  
  //bool isConnected = false;
  bool useDebugLogInit=true;
  bool useDebugLogPush=true;
  Adafruit_BluefruitLE_SPI* pBleCom ;
  Adafruit_BLEMIDI* pMidiBleCom;
  Adafruit_BluefruitLE_SPI* GetBleCom ();
  Adafruit_BLEMIDI* GetBleMidiCom();
  bool IsConnected();
  BLEPushUtility();
  void Init(Adafruit_BluefruitLE_SPI* bleCom , Adafruit_BLEMIDI* midiBleCom);
  void PushNumpad(String text);
  void PushKey(int key, bool press, bool release);
  void PushMidi(byte note, byte velocity, byte channel);
  void PushMidiWithDelayIfNeed(byte note, byte velocity, byte channel, bool press, bool release, int delayIfNeededMs ) ;
  void PushMidiOn(byte note, byte velocity, byte channel);
  void PushMidiOff(byte note, byte velocity, byte channel);
  void PushAsRawKeyboardText(String text);

};


#endif