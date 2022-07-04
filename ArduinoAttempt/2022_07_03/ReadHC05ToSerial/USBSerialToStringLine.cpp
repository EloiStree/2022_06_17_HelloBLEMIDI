#include "Arduino.h"
#include <SoftwareSerial.h>
#include "USBSerialToStringLine.h"


USBSerialToStringLine::USBSerialToStringLine(){

}

void USBSerialToStringLine::Init(uint8_t tx, uint8_t rx, int baud = 9600) {
  RxD = rx;
  TxD = tx;
  TargetSerial = new SoftwareSerial(RxD, TxD, false);
  Serial.begin(baud);
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  TargetSerial->begin(baud);
}
bool USBSerialToStringLine::CheckForAvailable() {
  char recvChar;
  newCharFound = false;
  newLineFound = false;
  if (TargetSerial->available()) {
    newCharFound = true;
    recvChar = TargetSerial->read();
    received += recvChar;
    if (recvChar == '\n') {
      newLineFound = true;
      lineFound = received;
      received = "";

      // Serial.print("Line found:");
      // Serial.println(lineFound);
    } else {
      // Serial.print("Append:");
      // Serial.println(received);
    }
  }
  return newLineFound;
}
void USBSerialToStringLine::DisplayStateIfChanged() {
  if (newCharFound) {
    if (newLineFound){
      Serial.print("Line found:"); 
      Serial.println(lineFound);
    }
    else{
      Serial.print("Append:");
      Serial.println(received);
    }
  }
}

bool USBSerialToStringLine::HasNewLine() {
  return newLineFound;
}
String USBSerialToStringLine::GetPreviousLine() {
  return lineFound;
}
String USBSerialToStringLine::GetCurrentStack() {
  return received;
}