#ifndef StringStructUtility_CPP
#define StringStructUtility_CPP

#include "Arduino.h"
#include "string.h"
#include "StructUtility.h"



static const void TryConvertToMidi(bool* converted, MidiAction* midi) {
  int t= random(50);
  midi->note = 50 + t % 50;
  midi->velocity = 100 + t % 126;
  midi->channel = t % 10;
  midi->press = true;
  midi->release = true;
}


#endif