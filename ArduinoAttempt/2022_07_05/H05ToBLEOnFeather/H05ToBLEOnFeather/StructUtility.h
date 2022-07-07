#ifndef StringStructUtility_H
#define StringStructUtility_H
#include "Arduino.h"
#include "string.h"
#include "StructUtility.h"

struct MidiAction {
  byte note;
  byte velocity;
  byte channel;
  bool press;
  bool release;
};




#endif