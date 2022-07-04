 #ifndef StringToUSBMIDI_H
#define StringToUSBMIDI_H
#include "Arduino.h"

class StringToUSBMIDI{
  public:
    int m_defaultDelayWhenNeeded=10;
    byte m_lastPushNote;
    byte m_lastPushVelocity;
    byte m_lastPushChannel;
    StringToUSBMIDI();
    void Init() ;
    void TryToParseTextToAction(String commandline);
    void NoteStroke(byte note, byte velocity, byte channel, bool press, bool release);
    void NoteStroke(byte note, byte velocity, byte channel, bool press, bool release, int delayMS) ;
    void NoteStroke(byte channel, byte pitch, byte velocity, int delayMS);
    void NoteOn(byte channel, byte pitch, byte velocity) ;
    void NoteOff(byte channel, byte pitch, byte velocity) ;
    void ControlChange(byte channel, byte control, byte value);
    void SetLastPushAs(byte note, byte velocity, byte channel);
    void Flush() ;
};
#endif