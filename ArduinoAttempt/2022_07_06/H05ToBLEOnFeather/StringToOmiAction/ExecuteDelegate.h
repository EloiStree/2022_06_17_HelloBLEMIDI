#ifndef EXECUTEDEF_HH
#define EXECUTEDEF_HH
#include "Arduino.h"
#include "String.h"
#include "StructUtility.h"

typedef void (*ExecuteNoReturnFunction) ();
typedef void (*Execute_NP_CharPression)                    ExecuteNumpadDigit(PressionRequest* pression ,char c);
typedef void (*Execute_NP_Char)                            ExecuteNumpadDigit(char c);
typedef void (*Execute_NP_IntPression)                     ExecuteNumpadDigit(PressionRequest* pression ,int index);
typedef void (*Execute_NP_Int)                             ExecuteNumpadDigit(int index);
typedef void (*Execute_ParseStringToNumpadStrokeAction)    Execute(ParseStringToNumpadStrokeAction* toExecute);
typedef void (*Execute_UnicodeFromText)                    ExecuteAsWindowUnicodeFromText(String unicodeAsText);
typedef void (*Execute_WindowUnicodeIntPrintAction)        Execute(WindowUnicodeIntPrintAction* toExecute);
typedef void (*Execute_WindowUnicodeStringPrintAction)     Execute(WindowUnicodeStringPrintAction* toExecute);
typedef void (*Execute_KeyboardStringPrintAction)          Execute(KeyboardStringPrintAction* toExecute);
typedef void (*Execute_KeyboardControlString)              Execute(KeyboardControlString* toExecute);
typedef void (*Execute_P_MidiAction)                       Execute(PressionRequest* pression , MidiAction* toExecute);
typedef void (*Execute_P_HidUsbId                 )        Execute(PressionRequest* pression , int hidUsbId);
typedef void (*Execute_P_KeyboardUSBIDAction          )    Execute(PressionRequest* pression , KeyboardUSBIDAction*             toExecute);
typedef void (*Execute_P_KeyboardCharTryToStrokeAction )   Execute(PressionRequest* pression , KeyboardCharTryToStrokeAction*   toExecute);
typedef void (*Execute_P_KeyboardCharPrintAction       )   Execute(PressionRequest* pression , KeyboardCharPrintAction*         toExecute);
typedef void (*Execute_P_KeyboardAlphaStroke           )   Execute(PressionRequest* pression , KeyboardAlphaStroke*             toExecute);
typedef void (*Execute_P_KeyboardNumpadStroke          )   Execute(PressionRequest* pression , KeyboardNumpadStroke*            toExecute);
typedef void (*Execute_P_KeyboardFunctionStroke        )   Execute(PressionRequest* pression , KeyboardFunctionStroke*          toExecute) ;
typedef void (*Execute_P_KeyboardArrowType             )   Execute(PressionRequest* pression , KeyboardArrowType*               toExecute);
typedef void (*Execute_P_KeyboardNumpadType            )   Execute(PressionRequest* pression , KeyboardNumpadType*              toExecute);
typedef void (*Execute_P_KeyboardClassicKeyType        )   Execute(PressionRequest* pression , KeyboardClassicKeyType*          toExecute);
typedef void (*Execute_P_SwitchPinIntMode              )   Execute(PressionRequest* pression , SwitchPinIntMode*                toExecute);
typedef void (*Execute_P_SwitchPinAsStringMode         )   Execute(PressionRequest* pression , SwitchPinAsStringMode*           toExecute);
typedef void (*Execute_PrintDefaultSerialText           )  Execute(PrintDefaultSerialText* toExecute);
typedef void (*Execute_TransitToAllSerialText           )  Execute(TransitToAllSerialText* toExecute);
typedef void (*Execute_TransitOnHCXXSerialText          )  Execute(TransitOnHCXXSerialText* toExecute);
typedef void (*Execute_TransitOnBLESerialText         )    Execute(TransitOnBLESerialText* toExecute);
typedef void (*Execute_CallFunctionInArduino          )    Execute(CallFunctionInArduino* toExecute);





 class KeyboardExecutorDef {

public:
KeyboardExecutorDef();
ExecuteNoReturnFunction ExecuteKeyPressionAlt;
ExecuteNoReturnFunction ExecuteKeyReleaseAlt;
ExecuteNoReturnFunction ExecuteKeyPressionCtrl;
ExecuteNoReturnFunction ExecuteKeyReleaseCtrl;
ExecuteNoReturnFunction ExecuteKeyPressionShift;
ExecuteNoReturnFunction ExecuteKeyReleaseShift;
ExecuteNoReturnFunction ExecuteKeyPressionEnter;
ExecuteNoReturnFunction ExecuteKeyReleaseEnter;
ExecuteNoReturnFunction ExecuteKeyStrokeEnter;
ExecuteNoReturnFunction ExecuteKeyStrokeTab;
ExecuteNoReturnFunction ExecuteKeyStrokeBackspace;



Execute_NP_CharPression                   execute_NP_CharPression                   ;// ExecuteNumpadDigit(PressionRequest* pression ,char c);        
Execute_NP_Char                           execute_NP_Char                           ;// ExecuteNumpadDigit(char c);
Execute_NP_IntPression                    execute_NP_IntPression                    ;// ExecuteNumpadDigit(PressionRequest* pression ,int index);
Execute_NP_Int                            execute_NP_Int                            ;// ExecuteNumpadDigit(int index);
Execute_ParseStringToNumpadStrokeAction   execute_ParseStringToNumpadStrokeAction   ;// Execute(ParseStringToNumpadStrokeAction* toExecute);
Execute_UnicodeFromText                   execute_UnicodeFromText                   ;// ExecuteAsWindowUnicodeFromText(String unicodeAsText);
Execute_WindowUnicodeIntPrintAction       execute_WindowUnicodeIntPrintAction       ;// Execute(WindowUnicodeIntPrintAction* toExecute);
Execute_WindowUnicodeStringPrintAction    execute_WindowUnicodeStringPrintAction    ;// Execute(WindowUnicodeStringPrintAction* toExecute);
Execute_KeyboardStringPrintAction         execute_KeyboardStringPrintAction         ;// Execute(KeyboardStringPrintAction* toExecute);
Execute_KeyboardControlString             execute_KeyboardControlString             ;// Execute(KeyboardControlString* toExecute);
Execute_P_MidiAction                      execute_P_MidiAction                      ;// Execute(PressionRequest* pression , MidiAction* toExecute);
Execute_P_HidUsbId                        execute_P_HidUsbId                        ;// Execute(PressionRequest* pression , int hidUsbId);
Execute_P_KeyboardUSBIDAction             execute_P_KeyboardUSBIDAction             ;// Execute(PressionRequest* pression , KeyboardUSBIDAction*             toExecute);
Execute_P_KeyboardCharTryToStrokeAction   execute_P_KeyboardCharTryToStrokeAction   ;// Execute(PressionRequest* pression , KeyboardCharTryToStrokeAction*   toExecute);
Execute_P_KeyboardCharPrintAction         execute_P_KeyboardCharPrintAction         ;// Execute(PressionRequest* pression , KeyboardCharPrintAction*         toExecute);
Execute_P_KeyboardAlphaStroke             execute_P_KeyboardAlphaStroke             ;// Execute(PressionRequest* pression , KeyboardAlphaStroke*             toExecute);
Execute_P_KeyboardNumpadStroke            execute_P_KeyboardNumpadStroke            ;// Execute(PressionRequest* pression , KeyboardNumpadStroke*            toExecute);
Execute_P_KeyboardFunctionStroke          execute_P_KeyboardFunctionStroke          ;// Execute(PressionRequest* pression , KeyboardFunctionStroke*          toExecute) ;
Execute_P_KeyboardArrowType               execute_P_KeyboardArrowType               ;// Execute(PressionRequest* pression , KeyboardArrowType*               toExecute);
Execute_P_KeyboardNumpadType              execute_P_KeyboardNumpadType              ;// Execute(PressionRequest* pression , KeyboardNumpadType*              toExecute);
Execute_P_KeyboardClassicKeyType          execute_P_KeyboardClassicKeyType          ;// Execute(PressionRequest* pression , KeyboardClassicKeyType*          toExecute);
Execute_P_SwitchPinIntMode                execute_P_SwitchPinIntMode                ;// Execute(PressionRequest* pression , SwitchPinIntMode*                toExecute);
Execute_P_SwitchPinAsStringMode           execute_P_SwitchPinAsStringMode           ;// Execute(PressionRequest* pression , SwitchPinAsStringMode*           toExecute);
Execute_PrintDefaultSerialText            execute_PrintDefaultSerialText            ;// Execute(PrintDefaultSerialText* toExecute);
Execute_TransitToAllSerialText            execute_TransitToAllSerialText            ;// Execute(TransitToAllSerialText* toExecute);
Execute_TransitOnHCXXSerialText           execute_TransitOnHCXXSerialText           ;// Execute(TransitOnHCXXSerialText* toExecute);
Execute_TransitOnBLESerialText            execute_TransitOnBLESerialText            ;// Execute(TransitOnBLESerialText* toExecute);
Execute_CallFunctionInArduino             execute_CallFunctionInArduino             ;// Execute(CallFunctionInArduino* toExecute);

);















};


#endif

