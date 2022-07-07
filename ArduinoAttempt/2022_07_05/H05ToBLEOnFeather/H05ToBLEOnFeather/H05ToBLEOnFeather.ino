
#include "Arduino.h"
#include "String.h"
#include "USBSerialToStringLine.h"
#include "BLEPushUtility.h"
#include "StructUtility.h"
#include "StructUtility.cpp"
//#include "BLEPushUtility.cpp"
Adafruit_BluefruitLE_SPI bleCom (BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);
Adafruit_BLEMIDI midiBleCom (bleCom);
//USBSerialToStringLine BT;
BLEPushUtility blePush;


void setup() {

  Serial.begin(115200);
  Serial.print("Hello Boys !!!");
  // for debug
  while (!Serial); 

  //BT.Init(A2, A1, 9600);
  blePush.Init( &bleCom , &midiBleCom);
  Serial.print("Ready ? ");
}

String sString = "";
void loop() {
  
  while (!Serial); 

  // if (BT.CheckForAvailable()) {
  //   // BT.DisplayStateIfChanged();
  //   String line = BT.GetPreviousLine();
  //   PushLine(line);
  // }
  while (Serial.available()) {
    char c = Serial.read();
    sString += c;
    if (c == '\n') {
      PushLine(sString);
      sString = "";
    }
  }

    bool found =false;
  MidiAction action =  MidiAction();
  TryConvertToMidi(&found, &action);
  
  Serial.print("Midi:");
  Serial.print(found);
  Serial.print(",");
  Serial.print(action.note);
  Serial.print(",");
  Serial.print(action.velocity);
  Serial.print(",");
  Serial.print(action.channel);
  Serial.println("");
  bleCom.update(500);
  delay(50);
  if (! blePush.IsConnected()){
    Serial.print("-");
    return;
  }
  else
  {

  Serial.print(".");



  }
}
bool useDelay=false;
void PushLine(String line) {
  line.trim();
  Serial.print("Found Line:");
  Serial.println(line);
  int lineLenght = line.length();
  if (lineLenght > 2 && line[0] == 'N' && line[1] == 'P') {
    Serial.print("Keyboard Numpad parse:");
    Serial.println(line);
    if(useDelay)    delay(3000);
    blePush.PushNumpad(line);
  }  
  else if (lineLenght > 1 && line[0] == 'K') {
    Serial.print("Keyboard parse:");
    Serial.println(line);
    if(useDelay)    delay(3000);
    blePush.PushKey(0x80, true, true);

  } 
  else if (lineLenght > 1 && line[0] == 'M') {
    Serial.print("Midi parse:");
    Serial.println(line);
    if(useDelay)    delay(3000);
    blePush.PushMidi(50,127,5);

  } 
  else {
    Serial.print("Unmanaged line:");
    Serial.println(line);
  }
}