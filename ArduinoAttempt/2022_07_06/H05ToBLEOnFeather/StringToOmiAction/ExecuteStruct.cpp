#ifndef EXECUTE_H
#define EXECUTE_H
#include "Arduino.h"
#include "String.h"
#include "StructUtility.h"


static const ExecuteKeyPressionAlt(){
  // Put your coder here
}
static const ExecuteKeyReleaseAlt(){
  // Put your coder here
}


static const ExecuteNumpadDigit(PressionRequest* pression ,int index) {
  if (index < 0 || index > 9) return;
  Serial.println("-- Put your code here: Execute numpad  ");
  Serial.println(index);
}




static const ExecuteNumpadDigit(PressionRequest* pression ,char c){

  int value =42;
  if(c=='1') value = 1;
  else if(c=='2') value= 2;
  else if(c=='3') value= 3;
  else if(c=='4') value= 4;
  else if(c=='5') value= 5;
  else if(c=='6') value= 6;
  else if(c=='7') value= 7;
  else if(c=='8') value= 8;
  else if(c=='9') value= 9;
  else if(c=='0') value= 0;
  ExecuteNumpadDigit(pression,value);
}
static const Execute(ParseStringToNumpadStrokeAction* toExecute){
  for(int i =0 ; i < toExecute->textToNumpad.length() ; i++) {
    char c =toExecute->textToNumpad[i];
    ExecuteNumpadDigit(pressAndRelease,c);
  }
}static const Execute(PressionRequest* pression ,ParseStringToNumpadStrokeAction* toExecute){
  for(int i =0 ; i < toExecute->textToNumpad.length() ; i++) {
    char c =toExecute->textToNumpad[i];
    ExecuteNumpadDigit(pressAndRelease,c);
  }
}



static const ExecuteAsWindowUnicodeFromText(String unicodeAsText){
  //
  ExecuteKeyPressionAlt();
  for(int i =0 ; i < unicodeAsText.length() ; i++) {
    char c =unicodeAsText[i];
    ExecuteNumpadDigit(pressAndRelease,c);
  }
  ExecuteKeyReleaseAlt();
}
static const Execute(WindowUnicodeIntPrintAction* toExecute){
  String s = String(toExecute->unicodeIntId);
  ExecuteAsWindowUnicodeFromText(s);
}

static const Execute(WindowUnicodeStringPrintAction* toExecute){
  ExecuteAsWindowUnicodeFromText(toExecute->unicodeStringId);
}
static const Execute(KeyboardStringPrintAction* toExecute){
 
  Serial.println("-- Put your code here: Let's execute the keyboard api for this string  ");
  Serial.println(toExecute->toPrint);
}



static const Execute(PressionRequest* pression , MidiAction* toExecute){
 
  Serial.println("-- Put your code here: Let's execute  midi   ");
  Serial.println(pression->press);
  Serial.println(pression->release);
  Serial.println(toExecute->note);
  Serial.println(toExecute->velocity);
  Serial.println(toExecute->channel);
}

static const Execute(PressionRequest* pression , KeyboardUSBIDAction* toExecute){
 
  Serial.println("-- Put your code here: Let's execute  midi   ");
  Serial.println(pression->press);
  Serial.println(pression->release);
  Serial.println(toExecute->id);
}
static const Execute(PressionRequest* pression , KeyboardCharTryToStrokeAction* toExecute){
 
  Serial.println("-- Put your code here: Try to stroke the key instead of the text if you can with your api");
  Serial.println(pression->press);
  Serial.println(pression->release);
  Serial.println(toExecute->toStroke);
}

static const Execute(PressionRequest* pression , KeyboardCharPrintAction* toExecute){
 
  Serial.println("-- Put your code here: Let the api try to type the given text");
  Serial.println(pression->press);
  Serial.println(pression->release);
  Serial.println(toExecute->toPrint);
}



static const Execute(PressionRequest* pression , KeyboardAlphaStroke* toExecute){
 
  Serial.println("-- Put your code here: Let the api try to type the given text");
  Serial.println(pression->press);
  Serial.println(pression->release);
  Serial.println(toExecute->numberToStroke0To9);
}

static const Execute(PressionRequest* pression , KeyboardNumpadStroke* toExecute){
 
  Serial.println("-- Put your code here: Let the api try to type the given text");
  Serial.println(pression->press);
  Serial.println(pression->release);
  Serial.println(toExecute->numberToStroke0To9);

}static const Execute(PressionRequest* pression , KeyboardFunctionStroke* toExecute){
 
  Serial.println("-- Put your code here: Let the api try to type the given text");
  Serial.println(pression->press);
  Serial.println(pression->release);
  Serial.println(toExecute->f1To24);
}

static const Execute(PressionRequest* pression , KeyboardArrowType* toExecute){
 
  Serial.println("-- Put your code here: enum of arraws");
  Serial.println(pression->press);
  Serial.println(pression->release);
  Serial.println(*toExecute);
}

static const Execute(PressionRequest* pression , KeyboardNumpadType* toExecute){
 
  Serial.println("-- Put your code here: enum of numpad type");
  Serial.println(pression->press);
  Serial.println(pression->release);
  Serial.println(*toExecute);
}

static const Execute(PressionRequest* pression , KeyboardClassicKeyType* toExecute){
 
  Serial.println("-- Put your code here: ");
  Serial.println(pression->press);
  Serial.println(pression->release);
  Serial.println(*toExecute);
}

static const Execute(CallFunctionInArduino* toExecute){
 
  Serial.println("-- Put your code here: call registered function in your arduino");
  Serial.println(toExecute->functionKeyName);
}





#endif

