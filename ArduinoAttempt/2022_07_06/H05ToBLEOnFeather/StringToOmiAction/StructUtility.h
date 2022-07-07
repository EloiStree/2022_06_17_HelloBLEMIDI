#ifndef StringStructUtility_H
#define StringStructUtility_H
#include "Arduino.h"
#include "string.h"



struct PressionRequest{
  bool press;
  bool release;
PressionRequest(bool pressValue, bool releaseValue )
{pressValue=true; releaseValue=true;}
PressionRequest(){}

};


static const PressionRequest* pressAndRelease = new PressionRequest(true, true);
static const PressionRequest* press = new PressionRequest(true, false);
static const PressionRequest* release = new PressionRequest(false, true);
static const PressionRequest* doNothing = new PressionRequest(false, false);


struct MidiAction {
  byte note;
  byte velocity;
  byte channel;
};

struct KeyboardUSBIDAction{
  int id;
};
struct KeyboardCharTryToStrokeAction{
  char toStroke;
};
struct KeyboardCharPrintAction{
  char toPrint;
};
struct KeyboardStringPrintAction{
  String toPrint;
};
struct WindowUnicodeIntPrintAction{
  int unicodeIntId;
};
struct WindowUnicodeStringPrintAction{
  String unicodeStringId;
};
struct ParseStringToNumpadStrokeAction{
  String textToNumpad;
};
struct KeyboardAlphaStroke{
  byte numberToStroke0To9;
};
struct KeyboardNumpadStroke{
  byte numberToStroke0To9;
};
struct KeyboardFunctionStroke{
  byte f1To24;
};

struct TransitToAllSerialText{
  String textToPrint;
};
struct PrintDefaultSerialText{
  String textToPrint;
};
struct TransitOnHCXXSerialText{
  String textToPrint;
};
struct TransitOnBLESerialText{
  String textToPrint;
};
struct SwitchPinIntMode{
  int pinId;
};struct SwitchPinAsStringMode{
  String pinIdAsString;
};

struct CallFunctionInArduino{
  String functionKeyName;
};

struct CommandLineKeyValue{
  String rawOrigine;
  String rawOrigineTrimmed;
  String key;
  int    keyLength;
  String value;
  int    valueLength;

  void Flush(){
    rawOrigine="";
    rawOrigineTrimmed="";
    key="";
    keyLength=0;
    value="";
    valueLength=0;
  }
};


enum KeyboardClassicKeyType {Space, Ctrl, Shift, DesktopOption, Alt, ShiftLock, Tab, Esc, Backspace, Enter, Menu, AltGR, Insert, Home, Delete, End, PageUp,PageDown};
enum KeyboardNumpadType {NumLock, Div, Multi, Sub, Add,  Point, NP0, _1, _2, _3, _4, _5, _6, _7, _8, _9};
enum KeyboardArrowType {Left,Right,Up,Down};

struct KeyboardClassicKeyStrokeEnum{
  KeyboardClassicKeyType toPress;
};
struct KeyboardNumpadStrokeEnum{
  KeyboardNumpadType toPress;
};
struct KeyboardArrowStrokeEnum{
  KeyboardArrowType toPress;
};

#endif