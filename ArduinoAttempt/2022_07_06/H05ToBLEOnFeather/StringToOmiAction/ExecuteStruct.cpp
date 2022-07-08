#ifndef EXECUTE_CPP
#define EXECUTE_CPP
#include "Arduino.h"
#include "String.h"
#include "StructUtility.h"
#include "ExecuteStruct.h"
#include "LogStruct.cpp"


KeyboardExecutor::KeyboardExecutor() {}
void KeyboardExecutor::ExecuteKeyPressionAlt() {Serial.print(" ??  ");}
void KeyboardExecutor::ExecuteKeyReleaseAlt() {Serial.print(" ??  ");}
void KeyboardExecutor::ExecuteKeyPressionCtrl() {Serial.print(" ??  ");}
void KeyboardExecutor::ExecuteKeyReleaseCtrl() {Serial.print(" ??  ");}
void KeyboardExecutor::ExecuteKeyPressionShift() {Serial.print(" ??  ");}
void KeyboardExecutor::ExecuteKeyReleaseShift() {Serial.print(" ??  ");}
void KeyboardExecutor::ExecuteKeyPressionEnter() {Serial.print(" ??  ");}
void KeyboardExecutor::ExecuteKeyReleaseEnter() {Serial.print(" ??  ");}
void KeyboardExecutor::ExecuteKeyStrokeEnter() {Serial.print(" ??  ");}
void KeyboardExecutor::ExecuteKeyStrokeTab() {Serial.print(" ??  ");}
void KeyboardExecutor::ExecuteKeyStrokeBackspace() {Serial.print(" ??  ");}

void KeyboardExecutor::ExecuteNumpadDigit(PressionRequest* pression, char c) {Serial.print(" ??  ");}
void KeyboardExecutor::ExecuteNumpadDigit(char c) {Serial.print(" ??  ");}
void KeyboardExecutor::ExecuteNumpadDigit(PressionRequest* pression, int index) {Serial.print(" ??  ");}
void KeyboardExecutor::ExecuteNumpadDigit(int index) {Serial.print(" ??  ");}

void KeyboardExecutor::Execute(ParseStringToNumpadStrokeAction* toExecute) {Serial.print(" ??  ");}
void KeyboardExecutor::ExecuteAsWindowUnicodeFromText(String unicodeAsText) {Serial.print(" ??  ");}
void KeyboardExecutor::Execute(WindowUnicodeIntPrintAction* toExecute) {Serial.print(" ??  ");}
void KeyboardExecutor::Execute(WindowUnicodeStringPrintAction* toExecute) {Serial.print(" ??  ");}

void KeyboardExecutor::Execute(KeyboardStringPrintAction* toExecute) {
  Serial.print("Keyboard:");
  Serial.println(toExecute->toWrite);
}

void KeyboardExecutor::Execute(PressionRequest* pression, MidiAction* toExecute) {
  Log(pression, toExecute);
}
void KeyboardExecutor::Execute(PressionRequest* pression, int hidUsbId) {}
void KeyboardExecutor::Execute(PressionRequest* pression, KeyboardUSBIDAction* toExecute) {}
void KeyboardExecutor::Execute(PressionRequest* pression, KeyboardCharPrintAction* toExecute) {

  Serial.print("CHAR Print:");
  Serial.print(pression->press);
  Serial.print(pression->release);
  Serial.println(toExecute->toWrite);
}


void KeyboardExecutor::Execute(PressionRequest* pression, KeyboardCharTryToStrokeAction* toExecute) {

  Serial.print("CHAR Stroke:");
  Serial.print(pression->press);
  Serial.print(pression->release);
  Serial.println(toExecute->toStroke);

}

void KeyboardExecutor::Execute(PressionRequest* pression, KeyboardAlphaStroke* toExecute) {
  Serial.print("\nAlpa Key:");
  Serial.println(toExecute->numberToStroke0To9);
}
void KeyboardExecutor::Execute(PressionRequest* pression, KeyboardNumpadStroke* toExecute) {

  Serial.print("\Num Pad Key:");
  Serial.println(toExecute->numberToStroke0To9);
}
void KeyboardExecutor::Execute(PressionRequest* pression, KeyboardFunctionStroke* toExecute) {
  Serial.print("\Func Key:");
  Serial.println(toExecute->f1To24);
}

void KeyboardExecutor::Execute(PressionRequest* pression, KeyboardArrowType* toExecute) {}
void KeyboardExecutor::Execute(PressionRequest* pression, KeyboardNumpadType* toExecute) {}
void KeyboardExecutor::Execute(PressionRequest* pression, KeyboardClassicKeyType* toExecute) {}

void KeyboardExecutor::Execute(PressionRequest* pression, SwitchPinIntMode* toExecute) {
  pinMode(toExecute->pinId, OUTPUT);

  digitalWrite(toExecute->pinId, pression->press ? LOW : HIGH);
  if (pression->press && pression->release) {
    delay(10);
  }
  digitalWrite(toExecute->pinId, pression->release ? LOW : HIGH);

  Serial.print("Pin:");
  Serial.println(toExecute->pinId);
}
void KeyboardExecutor::Execute(PressionRequest* pression, SwitchPinAsStringMode* toExecute) {
  String s = toExecute->pinIdAsString;
  s.toUpperCase();
  s.trim();
  int pinId = 0;
  if (s.equals("A0") || s.equals("0A")) pinId = A0;
  else if (s.equals("A1") || s.equals("1A"))
    pinId = A1;
  else if (s.equals("A2") || s.equals("2A"))
    pinId = A2;
  else if (s.equals("A3") || s.equals("3A"))
    pinId = A3;
  else if (s.equals("A4") || s.equals("4A"))
    pinId = A4;
  else if (s.equals("A5") || s.equals("5A"))
    pinId = A5;
  else if (s.equals("A6") || s.equals("6A"))
    pinId = A6;
  else if (s.equals("A7") || s.equals("7A"))
    pinId = A7;
  else
    pinId = s.toInt();
  pinMode(pinId, OUTPUT);
  digitalWrite(pinId, pression->press ? LOW : HIGH);
  if (pression->press && pression->release) {
    delay(10);
  }
  digitalWrite(pinId, pression->release ? LOW : HIGH);


  Serial.print("Pin:");
  Serial.println(pinId);
}




void KeyboardExecutor::Execute(PrintDefaultSerialText* toExecute) {
  Serial.println(toExecute->textToPrint);
}
void KeyboardExecutor::Execute(TransitToAllSerialText* toExecute) {
  PrintDefaultSerialText* pt = new PrintDefaultSerialText();
  pt->textToPrint = toExecute->textToPrint;
  Execute(pt);

  TransitOnHCXXSerialText* hct = new TransitOnHCXXSerialText();
  hct->textToPrint = toExecute->textToPrint;
  Execute(hct);

  TransitOnBLESerialText* blet = new TransitOnBLESerialText();
  blet->textToPrint = toExecute->textToPrint;
  Execute(blet);
}
void KeyboardExecutor::Execute(TransitOnHCXXSerialText* toExecute) {

  Serial.println("ADD CODE HERE:");
  Serial.println(toExecute->textToPrint);
}
void KeyboardExecutor::Execute(TransitOnBLESerialText* toExecute) {

  Serial.println("ADD CODE HERE:");
  Serial.println(toExecute->textToPrint);
}
void KeyboardExecutor::Execute(KeyboardControlString* toExecute) {

  Serial.println("ADD CODE HERE:");
  Serial.print("Key Control:");
  Serial.println(toExecute->stringKey);
}



static const void FA() {
  Serial.println("AAA");
}
static const void FB() {
  Serial.println("BBB");
}
static const void FC() {
  Serial.println("CCC");
}
static const void FD() {
  Serial.println("DDD");
}

void KeyboardExecutor::Execute(CallFunctionInArduino* toExecute) {
  if (toExecute->functionKeyName.equals("A")) FA();
  else if (toExecute->functionKeyName.equals("B"))
    FB();
  else if (toExecute->functionKeyName.equals("C"))
    FC();
  else if (toExecute->functionKeyName.equals("D"))
    FD();
}










// static const ExecuteKeyPressionAlt(){
//   // Put your coder here
// }
// static const ExecuteKeyReleaseAlt(){
//   // Put your coder here
// }


// static const ExecuteNumpadDigit(PressionRequest* pression ,int index) {
//   if (index < 0 || index > 9) return;
//   Serial.println("-- Put your code here: Execute numpad  ");
//   Serial.println(index);
// }




// static const ExecuteNumpadDigit(PressionRequest* pression ,char c){

//   int value =42;
//   if(c=='1') value = 1;
//   else if(c=='2') value= 2;
//   else if(c=='3') value= 3;
//   else if(c=='4') value= 4;
//   else if(c=='5') value= 5;
//   else if(c=='6') value= 6;
//   else if(c=='7') value= 7;
//   else if(c=='8') value= 8;
//   else if(c=='9') value= 9;
//   else if(c=='0') value= 0;
//   ExecuteNumpadDigit(pression,value);
// }
// static const Execute(ParseStringToNumpadStrokeAction* toExecute){
//   for(int i =0 ; i < toExecute->textToNumpad.length() ; i++) {
//     char c =toExecute->textToNumpad[i];
//     ExecuteNumpadDigit(pressAndRelease,c);
//   }
// }static const Execute(PressionRequest* pression ,ParseStringToNumpadStrokeAction* toExecute){
//   for(int i =0 ; i < toExecute->textToNumpad.length() ; i++) {
//     char c =toExecute->textToNumpad[i];
//     ExecuteNumpadDigit(pressAndRelease,c);
//   }
// }



// static const ExecuteAsWindowUnicodeFromText(String unicodeAsText){
//   //
//   ExecuteKeyPressionAlt();
//   for(int i =0 ; i < unicodeAsText.length() ; i++) {
//     char c =unicodeAsText[i];
//     ExecuteNumpadDigit(pressAndRelease,c);
//   }
//   ExecuteKeyReleaseAlt();
// }
// static const Execute(WindowUnicodeIntPrintAction* toExecute){
//   String s = String(toExecute->unicodeIntId);
//   ExecuteAsWindowUnicodeFromText(s);
// }

// static const Execute(WindowUnicodeStringPrintAction* toExecute){
//   ExecuteAsWindowUnicodeFromText(toExecute->unicodeStringId);
// }
// static const Execute(KeyboardStringPrintAction* toExecute){

//   Serial.println("-- Put your code here: Let's execute the keyboard api for this string  ");
//   Serial.println(toExecute->toPrint);
// }



// static const Execute(PressionRequest* pression , MidiAction* toExecute){

//   Serial.println("-- Put your code here: Let's execute  midi   ");
//   Serial.println(pression->press);
//   Serial.println(pression->release);
//   Serial.println(toExecute->note);
//   Serial.println(toExecute->velocity);
//   Serial.println(toExecute->channel);
// }

// static const Execute(PressionRequest* pression , KeyboardUSBIDAction* toExecute){

//   Serial.println("-- Put your code here: Let's execute  midi   ");
//   Serial.println(pression->press);
//   Serial.println(pression->release);
//   Serial.println(toExecute->id);
// }
// static const Execute(PressionRequest* pression , KeyboardCharTryToStrokeAction* toExecute){

//   Serial.println("-- Put your code here: Try to stroke the key instead of the text if you can with your api");
//   Serial.println(pression->press);
//   Serial.println(pression->release);
//   Serial.println(toExecute->toStroke);
// }

// static const Execute(PressionRequest* pression , KeyboardCharPrintAction* toExecute){

//   Serial.println("-- Put your code here: Let the api try to type the given text");
//   Serial.println(pression->press);
//   Serial.println(pression->release);
//   Serial.println(toExecute->toPrint);
// }



// static const Execute(PressionRequest* pression , KeyboardAlphaStroke* toExecute){

//   Serial.println("-- Put your code here: Let the api try to type the given text");
//   Serial.println(pression->press);
//   Serial.println(pression->release);
//   Serial.println(toExecute->numberToStroke0To9);
// }

// static const Execute(PressionRequest* pression , KeyboardNumpadStroke* toExecute){

//   Serial.println("-- Put your code here: Let the api try to type the given text");
//   Serial.println(pression->press);
//   Serial.println(pression->release);
//   Serial.println(toExecute->numberToStroke0To9);

// }static const Execute(PressionRequest* pression , KeyboardFunctionStroke* toExecute){

//   Serial.println("-- Put your code here: Let the api try to type the given text");
//   Serial.println(pression->press);
//   Serial.println(pression->release);
//   Serial.println(toExecute->f1To24);
// }

// static const Execute(PressionRequest* pression , KeyboardArrowType* toExecute){

//   Serial.println("-- Put your code here: enum of arraws");
//   Serial.println(pression->press);
//   Serial.println(pression->release);
//   Serial.println(*toExecute);
// }

// static const Execute(PressionRequest* pression , KeyboardNumpadType* toExecute){

//   Serial.println("-- Put your code here: enum of numpad type");
//   Serial.println(pression->press);
//   Serial.println(pression->release);
//   Serial.println(*toExecute);
// }

// static const Execute(PressionRequest* pression , KeyboardClassicKeyType* toExecute){

//   Serial.println("-- Put your code here: ");
//   Serial.println(pression->press);
//   Serial.println(pression->release);
//   Serial.println(*toExecute);
// }

// static const Execute(CallFunctionInArduino* toExecute){

//   Serial.println("-- Put your code here: call registered function in your arduino");
//   Serial.println(toExecute->functionKeyName);
// }






#endif