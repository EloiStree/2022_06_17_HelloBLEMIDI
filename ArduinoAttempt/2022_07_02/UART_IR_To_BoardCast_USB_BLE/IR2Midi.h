#ifndef IR2Midi_H
#define IR2Midi_H

#include "Arduino.h"
#include <string.h>

class IR2Midi {
public:
  bool m_irToMidiFound ;
  int m_peviousNote ;
  int m_peviousVelocity ;
  int m_peviousChannel ;
  int m_peviousIrAddress ;
  int m_peviousIrCommand ;

  IR2Midi();
  void InitIR();
  void ReadAndConvertToMidi();
  void DisplayPreviousIRToMidi();
  void DisplayPreviousIRToMidiIfFound();
  bool HasReceivedIR();
};


#endif