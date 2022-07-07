#ifndef StringStructUtility_CPP
#define StringStructUtility_CPP

#include "Arduino.h"
#include "String.h"
#include "StructUtility.h"


static const void ConvertToCommandLine(String text, CommandLineKeyValue* command) {
  command->Flush();
  command->rawOrigine = text.substring(0);
  int slength = text.length();

  while (slength > 0 && text[slength - 1] == ' ') {
    text.remove(slength - 1);
    slength = text.length();
  }
  while (slength > 0 && (text[slength - 1] == '\n' || text[slength - 1] == '\r')) {
    text.remove(slength - 1);
    slength = text.length();
  }
  while (slength > 0 && text[0] == ' ') {
    text.remove(0, 1);
    slength = text.length();
  }

  command->rawOrigineTrimmed = text.substring(0);

  int lineIndex = text.indexOf(':');
  if (lineIndex < 0) {
    command->key = text.substring(0);
    command->keyLength = command->key.length();
    command->value = "";
    command->valueLength = 0;
  } else {
    command->key = text.substring(0, lineIndex);
    command->keyLength = command->key.length();
    if (lineIndex + 1 < text.length()) {
      command->value = text.substring(lineIndex + 1);
      command->valueLength = command->value.length();

    } else {
      command->value = "";
      command->valueLength = 0;
    }
  }
}

static const void GetPressionFromCharKey(CommandLineKeyValue* cmd, PressionRequest* action) {

  int i = cmd->keyLength - 1;
  action->press = (cmd->keyLength > 1 && (cmd->key[i] == 'p' || cmd->key[i] == 'P'));
  action->release = (cmd->keyLength > 1 && (cmd->key[i] == 'r' || cmd->key[i] == 'R'));
  if (!action->press && !action->release) {
    action->press = true;
    action->release = true;
  }
}
static const bool StartWith(String text, CommandLineKeyValue* cmd) {
  text.toLowerCase();
  if (cmd->key.startsWith(text)) return true;
  text.toUpperCase();
  if (cmd->key.startsWith(text)) return true;
  return false;
}
static const bool StartWith(char* groupOfChar[], int lenghtArray, CommandLineKeyValue* cmd) {
  for (int i = 0; i < lenghtArray; i++) {
    if (cmd->key[0] == groupOfChar[i]) return true;
  }
  return false;
}
static const bool StartWith(char c, CommandLineKeyValue* cmd) {
  return cmd->key.length() > 0 && cmd->key[0] == c;
}

static const bool TryConvert_CharToDigit(char c, int* index) {
  *index = 0;
  if (c == '0') {
    *index = 0;
    return true;
  }
  if (c == '1') {
    *index = 1;
    return true;
  }
  if (c == '2') {
    *index = 2;
    return true;
  }
  if (c == '3') {
    *index = 3;
    return true;
  }
  if (c == '4') {
    *index = 4;
    return true;
  }
  if (c == '5') {
    *index = 5;
    return true;
  }
  if (c == '6') {
    *index = 6;
    return true;
  }
  if (c == '7') {
    *index = 7;
    return true;
  }
  if (c == '8') {
    *index = 8;
    return true;
  }
  if (c == '9') {
    *index = 9;
    return true;
  }
  return false;
}
static const String RemoveAllButDigit(String text) {

  int l = text.length();
  for (int i = l - 1; i > -1; i--) {
    if (text[i] == '0' || text[i] == '1' || text[i] == '2' || text[i] == '3' || text[i] == '4' || text[i] == '5' || text[i] == '6' || text[i] == '7' || text[i] == '8' || text[i] == '9') {
    } else {
      text.remove(i, 1);
    }
  }
  return text;
}
static const bool TryConvert_CharToF24Max(String text, int* index) {

  *index = 50;
  text.trim();
  if (text.equals("0")) {
    *index = 0;
    return true;
  }
  if (text.equals("1")) {
    *index = 1;
    return true;
  }
  if (text.equals("2")) {
    *index = 2;
    return true;
  }
  if (text.equals("3")) {
    *index = 3;
    return true;
  }
  if (text.equals("4")) {
    *index = 4;
    return true;
  }
  if (text.equals("5")) {
    *index = 5;
    return true;
  }
  if (text.equals("6")) {
    *index = 6;
    return true;
  }
  if (text.equals("7")) {
    *index = 7;
    return true;
  }
  if (text.equals("8")) {
    *index = 8;
    return true;
  }
  if (text.equals("9")) {
    *index = 9;
    return true;
  }
  if (text.equals("10")) {
    *index = 10;
    return true;
  }
  if (text.equals("11")) {
    *index = 11;
    return true;
  }
  if (text.equals("12")) {
    *index = 12;
    return true;
  }
  if (text.equals("13")) {
    *index = 13;
    return true;
  }
  if (text.equals("14")) {
    *index = 14;
    return true;
  }
  if (text.equals("15")) {
    *index = 15;
    return true;
  }
  if (text.equals("16")) {
    *index = 16;
    return true;
  }
  if (text.equals("17")) {
    *index = 17;
    return true;
  }
  if (text.equals("18")) {
    *index = 18;
    return true;
  }
  if (text.equals("19")) {
    *index = 19;
    return true;
  }
  if (text.equals("20")) {
    *index = 20;
    return true;
  }
  if (text.equals("21")) {
    *index = 21;
    return true;
  }
  if (text.equals("22")) {
    *index = 22;
    return true;
  }
  if (text.equals("23")) {
    *index = 23;
    return true;
  }
  if (text.equals("24")) {
    *index = 24;
    return true;
  }
  return false;
}








//////////////////////////////////// Transmit to all
// The code here just transit information for the origine to destination(s) devices

// PrintToAllSerialText{
//   String textToPrint;
static const bool IsTransitionCommand(CommandLineKeyValue* cmd) {
  char* start[] = { 'T', 't' };
  return StartWith(start, 2, cmd);
}
static const bool TryConvertTo(CommandLineKeyValue* cmd, TransitToAllSerialText* actionOut) {

  if (!IsTransitionCommand(cmd)) return false;
  actionOut->textToPrint = cmd->value;
  return true;
}
/////////////////////////////////// TRANSMIT TO ALL END



static const bool IsKeyCommand(CommandLineKeyValue* cmd) {
  char* start[] = { 'K', 'k' };
  return StartWith(start, 2, cmd);
}

//KeyboardAlphaStroke  KeyboardNumpadStroke
static const bool TryConvertTo(CommandLineKeyValue* cmd, KeyboardNumpadStroke* actionOut) {

if (!IsKeyCommand(cmd))
    return false;
  if (cmd->valueLength > 0 && (cmd->value[0] == 'N' || cmd->value[0] == 'n')) {
    String s = cmd->value.substring(0);
    s = RemoveAllButDigit(s);
    int value = 0; 
    if (s.length()>0 && TryConvert_CharToDigit(s[0], &value)) {
      actionOut->numberToStroke0To9 = value;
      return true;
    }
  }
  return false;
}




//KeyboardAlphaStroke  KeyboardNumpadStroke
static const bool TryConvertTo(CommandLineKeyValue* cmd, KeyboardAlphaStroke* actionOut) {

  if (!IsKeyCommand(cmd))
    return false;
  if (cmd->valueLength > 0 && (cmd->value[0] == 'A' || cmd->value[0] == 'a')) {
    String s = cmd->value.substring(0);
    s = RemoveAllButDigit(s);
     int value = 0; 
    if (s.length()>0 && TryConvert_CharToDigit(s[0], &value)) {
      actionOut->numberToStroke0To9 = value;
      return true;
    }
  }
  return false;
}




static const bool TryConvertTo(CommandLineKeyValue* cmd, KeyboardFunctionStroke* actionOut) {

  if (!IsKeyCommand(cmd))
    return false;

  if (cmd->valueLength > 0 && (cmd->value[0] == 'F' || cmd->value[0] == 'f')) {
    String s = cmd->value.substring(0);
    s = RemoveAllButDigit(s);
    int value = 0;
    if (TryConvert_CharToF24Max(s, &value)) {
      actionOut->f1To24 = value;
      return true;
    }
  }
  return false;
}




////////////////////////////////////////// MIDI START


static const bool IsKeyMidi(CommandLineKeyValue* cmd) {
  char* m_midiStart[] = { 'M', 'm' };
  return StartWith(m_midiStart, 2, cmd);
}


static const bool TryConvertToMidi(CommandLineKeyValue* cmd, PressionRequest* actionOut, MidiAction* midiOut) {


  if (!IsKeyMidi(cmd))
    return false;

  GetPressionFromCharKey(cmd, actionOut);
  String values = cmd->value;
  int startIndex = values.indexOf(',');
  int endIndex = values.lastIndexOf(',');
  byte note = 0;
  byte channel = 0;
  byte velocity = 127;

  if (startIndex < 0 && endIndex < 0) {  // ONE VALUE
    note = values.toInt();
  } else if (startIndex > -1 && startIndex == endIndex) {  // TWO VALUE
    note = values.substring(0, startIndex).toInt();
    velocity = values.substring(startIndex + 1).toInt();
  } else if (startIndex > -1 && startIndex != endIndex) {  // THREE VALUE
    note = values.substring(0, startIndex).toInt();
    velocity = values.substring(startIndex + 1, endIndex).toInt();
    channel = values.substring(endIndex + 1).toInt();
  }

  midiOut->note = note;
  midiOut->velocity = velocity;
  midiOut->channel = channel;

  return true;
}





///////////////////////////MIDI STOP















#endif