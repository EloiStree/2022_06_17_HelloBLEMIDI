#ifndef BLEPushUtility_CPP
#define BLEPushUtility_CPP
#include "Arduino.h"
#include <SPI.h>
#include <string.h>
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_SPI.h"
#include "Adafruit_BluefruitLE_UART.h"
#include "Adafruit_BLEMIDI.h"
#if SOFTWARE_SERIAL_AVAILABLE
  #include <SoftwareSerial.h>
#endif
#include "BluefruitConfig.h"
//#include <USB-MIDI.h>
#include "BLEPushUtility.h"


//MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

bool isBleConnected = false;

BLEPushUtility::BLEPushUtility(){}

 void  SLog_Error(const __FlashStringHelper* err) {
  Serial.println(err);
  // while (1)
  //   ;
}

 void  SLog_Connected(void) {
  isBleConnected = true;
  Serial.println(F(" CONNECTED!"));
  delay(1000);
}

 void SLog_Disconnected(void) {
  Serial.println("disconnected");
  isBleConnected = false;
}

 void SLog_BleMidiRX(uint16_t timestamp, uint8_t status, uint8_t byte1, uint8_t byte2) {
  Serial.print("[MIDI ");
  Serial.print(timestamp);
  Serial.print(" ] ");
  Serial.print(status, HEX);
  Serial.print(" ");
  Serial.print(byte1, HEX);
  Serial.print(" ");
  Serial.print(byte2, HEX);
  Serial.print(" ");
  Serial.println();
}

 void  SLog_ReceivedNoteOnUSB(byte inChannel, byte inNumber, byte inVelocity) {
  Serial.print("NoteOn  ");
  Serial.print(inNumber);
  Serial.print("\tvelocity: ");
  Serial.println(inVelocity);
}

 void SLog_ReceivedNoteOffUSB(byte inChannel, byte inNumber, byte inVelocity) {
  Serial.print("NoteOff ");
  Serial.print(inNumber);
  Serial.print("\tvelocity: ");
  Serial.println(inVelocity);
}


bool BLEPushUtility::IsConnected(){return isBleConnected;}

void BLEPushUtility::Init(Adafruit_BluefruitLE_SPI* bleCom , Adafruit_BLEMIDI* midiBleCom) {

pBleCom = bleCom;
pMidiBleCom = midiBleCom;

//******************
Serial.println(F("Adafruit Bluefruit MIDI Example"));
  Serial.println(F("---------------------------------------"));

  // /* Initialise the module */
  // Serial.print(F("Initialising the Bluefruit LE module: "));

  // if ( !bleCom->begin(VERBOSE_MODE) )
  // {
  //   SLog_Error(F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));
  // }
  // Serial.println( F("OK!") );

  // if ( FACTORYRESET_ENABLE )
  // {
  //   /* Perform a factory reset to make sure everything is in a known state */
  //   Serial.println(F("Performing a factory reset: "));
  //   if ( ! bleCom->factoryReset() ) {
  //     SLog_Error(F("Couldn't factory reset"));
  //   }
  // }

  // //ble.sendCommandCheckOK(F("AT+uartflow=off"));
  // bleCom->echo(false);
  // if (useDebugLogInit){
  //   Serial.println(F("Setting device name to 'Bluefruit Keyboard': "));
  // }
  // if (!pBleCom->sendCommandCheckOK(F("AT+GAPDEVNAME=HC2BLE Keyboard A")) ) {
  //   if (useDebugLogInit) 
  //     SLog_Error(F("Could not set device name?"));
  // }

  // Serial.println("Requesting Bluefruit info:");
  // /* Print Bluefruit information */
  // bleCom->info();

  // /* Set BLE callbacks */
  // bleCom->setConnectCallback(SLog_Connected);
  // bleCom->setDisconnectCallback(SLog_Disconnected);

  // // Set MIDI RX callback
  // pMidiBleCom->setRxCallback(SLog_BleMidiRX);

  // Serial.println(F("Enable MIDI: "));
  // if ( ! pMidiBleCom->begin(true) )
  // {
  //   SLog_Error(F("Could not enable MIDI"));
  // }

  // bleCom->verbose(false);
  // Serial.print(F("Waiting for a connection..."));
//*****************
  // MIDI.begin(1);
  // MIDI.setHandleNoteOn(SLog_ReceivedNoteOnUSB);
  // MIDI.setHandleNoteOff(SLog_ReceivedNoteOffUSB);
  if (useDebugLogInit) Serial.println(F("Init Bluetooth"));
  if (useDebugLogInit) Serial.println(F("---------------------------------------"));


/* Change the device name to make it easier to find */
  
  // if (FACTORYRESET_ENABLE) {
  //   /* Perform a factory reset to make sure everything is in a known state */
  //   if (useDebugLogInit)
  //     Serial.println(F("Performing a factory reset: "));
  //   if (!pBleCom->factoryReset()) {
  //     if (useDebugLogInit)
  //       SLog_Error(F("Couldn't factory reset"));
  //   }
  // }

  // //ble.sendCommandCheckOK(F("AT+uartflow=off"));
  // pBleCom->echo(false);
  // if (useDebugLogInit)
  //   Serial.println("Requesting Bluefruit info:");
  // /* Print Bluefruit information */
  // pBleCom->info();

  // /* Set BLE callbacks */
  // pBleCom->setConnectCallback(SLog_Connected);
  // pBleCom->setDisconnectCallback(SLog_Disconnected);

  // // Set MIDI RX callback
  // pMidiBleCom->setRxCallback(SLog_BleMidiRX);
  // if (useDebugLogInit)
  //   Serial.println(F("Enable MIDI: "));
  // if (!pMidiBleCom->begin(true)) {
  //   if (useDebugLogInit)
  //     SLog_Error(F("Could not enable MIDI"));
  // }



  

  // /* Enable HID Service */
  // if (useDebugLogInit) Serial.println(F("Enable HID Service (including Keyboard): "));
  // if (pBleCom->isVersionAtLeast(MINIMUM_FIRMWARE_VERSION)) {
  //   if (!pBleCom->sendCommandCheckOK(F("AT+BLEHIDEN=1"))) {
  //     if (useDebugLogInit) SLog_Error(F("Could not enable Keyboard"));
  //   }
  // } else {
  //   if (!pBleCom->sendCommandCheckOK(F("AT+BLEKEYBOARDEN=1"))) {
  //     if (useDebugLogInit) SLog_Error(F("Could not enable Keyboard"));
  //   }
  // }


  // if (useDebugLogInit) Serial.println(F("Enable HID Service (including Mouse): "));
  // if (!pBleCom->sendCommandCheckOK(F("AT+BLEHIDEN=1"))) {
  //   if (useDebugLogInit) SLog_Error(F("Failed to enable HID (firmware >=0.6.6?)"));
  // }


  // //Not sure a good idea to have it but if I want fast data reading ?
  // // Serial.println( F("Switching to DATA mode!") );
  // //ble.setMode(BLUEFRUIT_MODE_DATA);

  // if (!pBleCom->sendCommandCheckOK(F("ATZ"))) {
  //   if (useDebugLogInit) SLog_Error(F("Failed to use ATZ"));
  // }
  // // /* Add or remove service requires a reset */
  // // Serial.println(F("Performing a SW reset (service changes require a reset): "));
  // // if (!ble.reset()) {
  // //   SLog_Error(F("Couldn't reset??"));
  // // }

  // pBleCom->verbose(false);
  // if (useDebugLogInit) Serial.print(F("Waiting for a connection..."));
}

Adafruit_BluefruitLE_SPI* BLEPushUtility::GetBleCom() {
  return pBleCom;
}
Adafruit_BLEMIDI* BLEPushUtility::GetBleMidiCom() {
  return pMidiBleCom;
}
void BLEPushUtility::PushNumpad(String text) {

  int l = text.length();
  Serial.print("Digit text:");
  for (int i = 0; i < l; i++) {
    char c = text[i];
    Serial.print(c);
  }
  Serial.println("");
}
void BLEPushUtility::PushKey(int key, bool press, bool release) {
  
  Serial.println("");
}
void BLEPushUtility::PushMidi(byte note, byte velocity, byte channel) {
  PushMidiWithDelayIfNeed(note, velocity, channel,true, true, 10 );
}
void BLEPushUtility::PushMidiOn(byte note, byte velocity, byte channel) {
  //MIDI.sendNoteOn(note, velocity, channel);
  if (isBleConnected) {
    pMidiBleCom->send(0x90, note, velocity);
    
  }
}
void BLEPushUtility::PushMidiOff(byte note, byte velocity, byte channel) {
  //MIDI.sendNoteOff(note, velocity, channel);
  if (isBleConnected) {
    pMidiBleCom->send(0x80, note, velocity);
  }
}

void BLEPushUtility::PushMidiWithDelayIfNeed(byte note, byte velocity, byte channel, bool press, bool release, int delayIfNeededMs) {
  if (press)
    PushMidiOn(note,  velocity,  channel);
  if (press && release)
    delay(delayIfNeededMs);
  if (release)
    PushMidiOff(note,  velocity,  channel);
}
void BLEPushUtility::PushAsRawKeyboardText(String text) {
  Serial.print("\nSending:");
  Serial.println(text);
  pBleCom->print("AT+BleKeyboard=");
  pBleCom->println(text);

  if (pBleCom->waitForOK()) {
    Serial.println(F("OK!"));
  } else {
    Serial.println(F("FAILED!"));
  }
}

#endif