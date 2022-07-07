 #ifndef EXECUTE_CPP
 #define EXECUTE_CPP
 #include "Arduino.h"
 #include "String.h"
 #include "StructUtility.h"
 #include "ExecuteStruct.h"
 #include "LogStruct.cpp"


KeyboardExecutor::KeyboardExecutor(){}
void KeyboardExecutor::ExecuteKeyPressionAlt(){}
void KeyboardExecutor::ExecuteKeyReleaseAlt(){}
void KeyboardExecutor::ExecuteKeyPressionCtrl(){}
void KeyboardExecutor::ExecuteKeyReleaseCtrl(){}
void KeyboardExecutor::ExecuteKeyPressionShift(){}
void KeyboardExecutor::ExecuteKeyReleaseShift(){}
void KeyboardExecutor::ExecuteKeyPressionEnter(){}
void KeyboardExecutor::ExecuteKeyReleaseEnter(){}
void KeyboardExecutor::ExecuteKeyStrokeEnter(){}
void KeyboardExecutor::ExecuteKeyStrokeTab(){}
void KeyboardExecutor::ExecuteKeyStrokeBackspace(){}

void KeyboardExecutor::ExecuteNumpadDigit(PressionRequest* pression ,char c){}
void KeyboardExecutor::ExecuteNumpadDigit(char c){}
void KeyboardExecutor::ExecuteNumpadDigit(PressionRequest* pression ,int index){}
void KeyboardExecutor::ExecuteNumpadDigit(int index){}

void KeyboardExecutor::Execute(ParseStringToNumpadStrokeAction* toExecute){}
void KeyboardExecutor::ExecuteAsWindowUnicodeFromText(String unicodeAsText){}
void KeyboardExecutor::Execute(WindowUnicodeIntPrintAction* toExecute){}
void KeyboardExecutor::Execute(WindowUnicodeStringPrintAction* toExecute){}
void KeyboardExecutor::Execute(KeyboardStringPrintAction* toExecute){}

void KeyboardExecutor::Execute(PressionRequest* pression , MidiAction* toExecute){
  Log(pression,toExecute);
}
void KeyboardExecutor::Execute(PressionRequest* pression , int hidUsbId){}
void KeyboardExecutor::Execute(PressionRequest* pression , KeyboardUSBIDAction* toExecute){}
void KeyboardExecutor::Execute(PressionRequest* pression , KeyboardCharTryToStrokeAction* toExecute){}
void KeyboardExecutor::Execute(PressionRequest* pression , KeyboardCharPrintAction* toExecute){}
void KeyboardExecutor::Execute(PressionRequest* pression , KeyboardAlphaStroke* toExecute){
Serial.print("\nAlpa Key:");
Serial.println(toExecute->numberToStroke0To9);
}
void KeyboardExecutor::Execute(PressionRequest* pression , KeyboardNumpadStroke* toExecute){

Serial.print("\Num Pad Key:");
Serial.println(toExecute->numberToStroke0To9);
}
void KeyboardExecutor::Execute(PressionRequest* pression , KeyboardFunctionStroke* toExecute){

Serial.print("\Func Key:");
Serial.println(toExecute->f1To24);
}

void KeyboardExecutor::Execute(PressionRequest* pression , KeyboardArrowType* toExecute){}
void KeyboardExecutor::Execute(PressionRequest* pression , KeyboardNumpadType* toExecute){}
void KeyboardExecutor::Execute(PressionRequest* pression , KeyboardClassicKeyType* toExecute){}

void KeyboardExecutor::Execute(PressionRequest* pression , SwitchPinIntMode* toExecute){}
void KeyboardExecutor::Execute(PressionRequest* pression , SwitchPinAsStringMode* toExecute){}

void KeyboardExecutor::Execute(PrintDefaultSerialText* toExecute){
  Serial.println(toExecute->textToPrint); 
}
void KeyboardExecutor::Execute(TransitToAllSerialText* toExecute){
  PrintDefaultSerialText* pt =new PrintDefaultSerialText();
  pt->textToPrint =toExecute->textToPrint;
  Execute(pt);

  TransitOnHCXXSerialText* hct =new TransitOnHCXXSerialText();
  hct->textToPrint =toExecute->textToPrint;
  Execute(hct);

  TransitOnBLESerialText* blet =new TransitOnBLESerialText();
  blet->textToPrint =toExecute->textToPrint;
  Execute(blet);

}
void KeyboardExecutor::Execute(TransitOnHCXXSerialText* toExecute){

  Serial.println("ADD CODE HERE:"); 
  Serial.println(toExecute->textToPrint); 
}
void KeyboardExecutor::Execute(TransitOnBLESerialText* toExecute){

  Serial.println("ADD CODE HERE:"); 
  Serial.println(toExecute->textToPrint); 
}

static const void FA(){Serial.println("AAA");}
static const void FB(){Serial.println("BBB");}
static const void FC(){Serial.println("CCC");}
static const void FD(){Serial.println("DDD");}

void KeyboardExecutor::Execute(CallFunctionInArduino* toExecute){
  if(toExecute->functionKeyName == "A") FA();
  else if(toExecute->functionKeyName == "B") FB();
  else if(toExecute->functionKeyName == "C") FC();
  else if(toExecute->functionKeyName == "D") FD();

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

