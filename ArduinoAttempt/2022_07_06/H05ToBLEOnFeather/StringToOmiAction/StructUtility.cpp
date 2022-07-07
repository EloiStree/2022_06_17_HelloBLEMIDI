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

  action->press = (cmd->keyLength > 1 && (cmd->key[1] == 'p' || cmd->key[1] == 'P'));
  action->release = (cmd->keyLength > 1 && (cmd->key[1] == 'r' || cmd->key[1] == 'R'));
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














static const void TryConvert_CharToDigit(bool* converted, char c, int* index) {
  *converted = true;
  if (c == '0'){ *index = 0;return;}
  if (c == '1'){ *index = 1;return;}
  if (c == '2'){ *index = 2;return;}
  if (c == '3'){ *index = 3;return;}
  if (c == '4'){ *index = 4;return;}
  if (c == '5'){ *index = 5;return;}
  if (c == '6'){ *index = 6;return;}
  if (c == '7'){ *index = 7;return;}
  if (c == '8'){ *index = 8;return;}
  if (c == '9'){ *index = 9;return;}
  *converted = false;
}



//////////////////////////////////// Transmit to all
// The code here just transit information for the origine to destination(s) devices

// PrintToAllSerialText{
//   String textToPrint;
static const bool IsTransitionCommand(CommandLineKeyValue* cmd) {
  char* start[] = { 'T', 't' };
  return StartWith(start, 2, cmd);
}


static const void TryConvertTo(bool* converted, CommandLineKeyValue* cmd,  PrintToAllSerialText* actionOut) {
  *converted = false;
  if (!IsTransitionCommand(cmd)) return;
  actionOut->textToPrint=cmd-> value;

    *converted = true;
}



/////////////////////////////////// TRANSMIT TO ALL END


static const bool IsNumpadCommand(CommandLineKeyValue* cmd) {
  return StartWith("NP", cmd);
}


////////////////////////////////////////// MIDI START


static const bool IsKeyMidi(CommandLineKeyValue* cmd) {
  char* m_midiStart[] = { 'M', 'm' };
  return StartWith(m_midiStart, 2, cmd);
}


static const void TryConvertToMidi(bool* converted, CommandLineKeyValue* cmd, PressionRequest* actionOut, MidiAction* midiOut) {
  *converted = false;
  if (!IsKeyMidi(cmd)) return;
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
  midiOut->velocity = velocity ;
  midiOut->channel = channel;
    *converted = true;
}





///////////////////////////MIDI STOP















#endif