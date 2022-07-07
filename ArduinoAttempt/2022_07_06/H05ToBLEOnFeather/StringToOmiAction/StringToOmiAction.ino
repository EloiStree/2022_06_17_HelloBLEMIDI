
#include "Arduino.h"
#include "String.h"
#include "USBSerialToStringLine.h"
#include "StructUtility.h"
#include "StructUtility.cpp"
#include "LogStruct.cpp"
#include "ExecuteStruct.cpp"

void setup() {

  Serial.begin(115200);
  Serial.print("Hello Boys !!!");
  // for debug
  while (!Serial); 
}


bool wasConverted;
bool * converted = &wasConverted;
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

  Serial.print(".");
}
bool useDelay=false;
PressionRequest* pressRequest = new PressionRequest();
CommandLineKeyValue* cmd = new CommandLineKeyValue();
MidiAction* midiAction = new MidiAction();
PrintToAllSerialText* transitionToAll = new PrintToAllSerialText();
void PushLine(String line) {
  cmd->Flush();
ConvertToCommandLine(line, cmd );
Log_Command(cmd);

  line.trim();
  Serial.print("Found Line:");
  Serial.println(line);
  int lineLenght = line.length();
  if (lineLenght > 2 && line[0] == 'N' && line[1] == 'P') {
    Serial.print("Keyboard Numpad parse:");
    Serial.println(line);
    if(useDelay)    delay(3000);
    //blePush.PushNumpad(line);
  }  
  else if (lineLenght > 1 && line[0] == 'K') {
    Serial.print("Keyboard parse:");
    Serial.println(line);
    if(useDelay)    delay(3000);
    //blePush.PushKey(0x80, true, true);

  } 
  else if (lineLenght > 1 && line[0] == 'M') {
    Serial.print("Midi parse:");
    Serial.println(line);
    if(useDelay)    delay(3000);
    TryConvertToMidi(converted, cmd, pressRequest, midiAction) ;
    if(*converted)
      Log(pressRequest, midiAction);
    else 
      Serial.println("Fail to convert Midi");
    //blePush.PushMidi(50,127,5);

  }  else if (lineLenght > 1 && line[0] == 'T') {

    TryConvertTo(converted, cmd,  transitionToAll);
    if(*converted)
      Log(transitionToAll);
    else 
      Serial.println("Fail to convert  Transit All");
  }  else if (lineLenght > 1 && line[0] == 'S') {

      Serial.println("Fail to convert  Transit All");
  }else if (lineLenght > 1 && line[0] == 'P') {

    Serial.println(cmd->value);
    // TryConvertToPinAction(converted, cmd,  );
    // if(*converted)
    //   Log(transitionToAll);
    // else 
    //   Serial.println("Fail to convert  Transit All");
  }
  else {
    Serial.print("Unmanaged line:");
    Serial.println(line);
  }
}

void PushAsTest(String line){

  PushLine(line);
  delay(1000);
}

void TDDInput(){

  PushLine("T:Some Message:io:lk");
  PushLine("M:50");
  PushLine("M:50,100,3");
  PushLine("KP:A");
  PushLine("KR:A");

  PushLine("K:A1"); //Stroke 1 on alpha bar up the keyboard
  PushLine("K:NP1");// Stroke 1 on the numpad
  PushLine("K:N1"); // stroke 1 on the numpad
  PushLine("K:F1"); // Stroke the F1 key
  PushLine("K:Ctrl"); // Stroke the ctrl key
  PushLine("K:Control"); // Stroke the Control key
  PushLine("K:Left"); // Stroke the Control key
  PushLine("K:Up"); // Stroke the Control key



}void TryToMakeItCrash(){

  PushLine("T:Some T: Message:io:lk");
  PushLine("M:50:10:10:10");
  PushLine("M:50,10,10,10");
  PushLine("M:50,100,3");

}


void CouldBeCoolToHaveButHard(){
  // Press the key A depending of the layer given to arduino EN to BE-FR from example
  PushLine("KLP:A");
  PushLine("KLR:A");
}

