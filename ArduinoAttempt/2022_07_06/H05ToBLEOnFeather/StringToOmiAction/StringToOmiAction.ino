
#include "Arduino.h"
#include "String.h"
#include "USBSerialToStringLine.h"
#include "StructUtility.h"
#include "StructUtility.cpp"
#include "LogStruct.cpp"
#include "ExecuteStruct.h"
#include "ConvertStringToStruct.cpp"

void setup() {

  Serial.begin(115200);
  Serial.print("Hello Boys !!!");
  // for debug
  while (!Serial); 

  TDDInput();
}


String sString = "";
void loop() {
  //Current standar attempt
  //https://github.com/EloiStree/2022_06_17_HelloBLEMIDI/edit/main/Note/2022_07_03_WhatCanWePushWithLeonardo.md

  while (Serial.available()) {
    char c = Serial.read();
    sString += c;
    if (c == '\n') {
      PushLine(sString);
      sString = "";
    }
  }

    bool found =false;
  // MidiAction action =  MidiAction();
  // TryConvertToMidi(&found, &action);
  
  // Serial.print("Midi:");
  // Serial.print(found);
  // Serial.print(",");
  // Serial.print(action.note);
  // Serial.print(",");
  // Serial.print(action.velocity);
  // Serial.print(",");
  // Serial.print(action.channel);
  // Serial.println("");

  delay(50);
 // Serial.print(".");
}
bool useDelay=true;

void PushLine(String line) {
 TryConvertAndExecute(line);
}

void PushAsTest(String line){

  PushLine(line);
    if(useDelay)    
      delay(1000);
}

void TDDInput(){

  PushAsTest("T:Some Message:io:lk");
  PushAsTest("K:F12");
  PushAsTest("K:F1");
  PushAsTest("KP:F5");
  PushAsTest("KR:F2");
  PushAsTest("M:50");
  PushAsTest("M:50,100,3");
  PushAsTest("KP:A");
  PushAsTest("KR:A");
  PushAsTest("K:A7"); //Stroke 1 on alpha bar up the keyboard
  PushAsTest("K:NP9");// Stroke 1 on the numpad
  PushAsTest("K:N6"); // stroke 1 on the numpad
  PushAsTest("K:F24"); // Stroke the F1 key
  PushAsTest("K:Ctrl"); // Stroke the ctrl key
  PushAsTest("K:Control"); // Stroke the Control key
  PushAsTest("K:Left"); // Stroke the Control key
  PushAsTest("K:Up"); // Stroke the Control key



}void TryToMakeItCrash(){

  PushAsTest("T:Some T: Message:io:lk");
  PushAsTest("M:50:10:10:10");
  PushAsTest("M:50,10,10,10");
  PushAsTest("M:50,100,3");

}


void CouldBeCoolToHaveButHard(){
  // Press the key A depending of the layer given to arduino EN to BE-FR from example
  PushAsTest("KLP:A");
  PushAsTest("KLR:A");
}

