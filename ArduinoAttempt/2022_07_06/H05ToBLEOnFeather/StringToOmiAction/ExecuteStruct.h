#ifndef EXECUTE_HH
#define EXECUTE_HH
#include "Arduino.h"
#include "String.h"
#include "StructUtility.h"

 class KeyboardExecutor {

public:
KeyboardExecutor();

void ExecuteKeyPressionAlt();
void ExecuteKeyReleaseAlt();
void ExecuteKeyPressionCtrl();
void ExecuteKeyReleaseCtrl();
void ExecuteKeyPressionShift();
void ExecuteKeyReleaseShift();
void ExecuteKeyPressionEnter();
void ExecuteKeyReleaseEnter();
void ExecuteKeyStrokeEnter();
void ExecuteKeyStrokeTab();
void ExecuteKeyStrokeBackspace();

void ExecuteNumpadDigit(PressionRequest* pression ,char c);
void ExecuteNumpadDigit(char c);
void ExecuteNumpadDigit(PressionRequest* pression ,int index);
void ExecuteNumpadDigit(int index);

void Execute(ParseStringToNumpadStrokeAction* toExecute);
void ExecuteAsWindowUnicodeFromText(String unicodeAsText);
void Execute(WindowUnicodeIntPrintAction* toExecute);
void Execute(WindowUnicodeStringPrintAction* toExecute);
void Execute(KeyboardStringPrintAction* toExecute);
void Execute(KeyboardControlString* toExecute);
void Execute(PressionRequest* pression , MidiAction* toExecute);
void Execute(PressionRequest* pression , int hidUsbId);
void Execute(PressionRequest* pression , KeyboardUSBIDAction* toExecute);
void Execute(PressionRequest* pression , KeyboardCharTryToStrokeAction* toExecute);
void Execute(PressionRequest* pression , KeyboardCharPrintAction* toExecute);
void Execute(PressionRequest* pression , KeyboardAlphaStroke* toExecute);
void Execute(PressionRequest* pression , KeyboardNumpadStroke* toExecute);
void Execute(PressionRequest* pression, KeyboardFunctionStroke* toExecute) ;

void Execute(PressionRequest* pression , KeyboardArrowType* toExecute);
void Execute(PressionRequest* pression , KeyboardNumpadType* toExecute);
void Execute(PressionRequest* pression , KeyboardClassicKeyType* toExecute);

void Execute(PressionRequest* pression , SwitchPinIntMode* toExecute);
void Execute(PressionRequest* pression , SwitchPinAsStringMode* toExecute);


void Execute(PrintDefaultSerialText* toExecute);
void Execute(TransitToAllSerialText* toExecute);
void Execute(TransitOnHCXXSerialText* toExecute);
void Execute(TransitOnBLESerialText* toExecute);

void Execute(CallFunctionInArduino* toExecute);


};


#endif

