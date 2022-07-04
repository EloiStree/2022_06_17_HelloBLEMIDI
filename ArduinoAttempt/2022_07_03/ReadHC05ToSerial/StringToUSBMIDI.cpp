#include "Arduino.h"
#include "StringToUSBMIDI.h"
#include "MIDIUSB.h"


StringToUSBMIDI::StringToUSBMIDI() {}

void StringToUSBMIDI::Init() {
  //IF you don't you need to set the serial to 115200
  //Serial.begin(115200);
}

void StringToUSBMIDI::TryToParseTextToAction(String commandline) {

  if (commandline[0] != 'M')
    return;

  int removeIndex = commandline.indexOf('\n');
  if (removeIndex > -1)
    commandline.remove(removeIndex);
  removeIndex = commandline.indexOf('\r');
  if (removeIndex > -1)
    commandline.remove(removeIndex);

  int strLenght = commandline.length();
  if (strLenght < 2)
    return;
  Serial.print("Here MIDI A#");
  Serial.print(commandline);
  Serial.print("#");
  Serial.println();
  Serial.print("Lenght A:");
  Serial.println(strLenght);

  //IS it Stroke, press or release
  bool press = true;
  bool release = true;

  if (strLenght > 2 && commandline[1] == 'P') {
    press = true;
    release = false;
  } else if (commandline[1] == 'R') {
    release = true;
    press = false;
  } else {
    press = true;
    release = true;
  }

  int lineIndex = commandline.indexOf(':');
  if (lineIndex > -1) {
    String values = commandline.substring(lineIndex+1);
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
  // Serial.print("MIDI Sent:");
  // Serial.print(note);
  // Serial.print("-");
  // Serial.print(velocity);
  // Serial.print("-");
  // Serial.print(channel);
  // Serial.print("-");
  // Serial.print(startIndex);
  // Serial.print("-");
  // Serial.print(endIndex);
  // Serial.println();
    NoteStroke(note, velocity, channel, press,release, m_defaultDelayWhenNeeded);
    return;
  }
  Serial.println("Try to translate but key code not found");
}


void StringToUSBMIDI::NoteStroke(byte note, byte velocity, byte channel, bool press, bool release) {
  NoteStroke(note, velocity, channel, press, release, m_defaultDelayWhenNeeded);
}
void StringToUSBMIDI::NoteStroke(byte note, byte velocity, byte channel, bool press, bool release, int delayMS) {

  if (press)
    NoteOn( note, velocity ,channel );
  if (press && release)
    delay(delayMS);
  if (release)
    NoteOff( note, velocity ,channel);
}

void StringToUSBMIDI::NoteStroke( byte note, byte velocity, byte channel,int delayMS) {
 
 NoteOn(note,velocity,   channel);
 delay(delayMS);
 NoteOff(note, velocity,  channel );

}
void StringToUSBMIDI::NoteOn(byte note, byte velocity , byte channel) {
  midiEventPacket_t noteOn = { 0x09, 0x90 | channel , note  , velocity };
  MidiUSB.sendMIDI(noteOn);
  Flush();
  SetLastPushAs(note, velocity, channel);
}

void StringToUSBMIDI::NoteOff(byte note, byte velocity,  byte channel) {
  midiEventPacket_t noteOff = { 0x08, 0x80 | channel , note , velocity };
  MidiUSB.sendMIDI(noteOff);
  Flush();
  SetLastPushAs(note, velocity, channel);
}

void StringToUSBMIDI::SetLastPushAs(byte note, byte velocity, byte channel){
  m_lastPushVelocity = velocity;
  m_lastPushChannel = channel;
  m_lastPushNote = note;
}



// First parameter is the event type (0x0B = control change).
// Second parameter is the event type, combined with the channel.
// Third parameter is the control number number (0-119).
// Fourth parameter is the control value (0-127).

void StringToUSBMIDI::ControlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = { 0x0B, 0xB0 | channel, control, value };
  MidiUSB.sendMIDI(event);
}
void StringToUSBMIDI::Flush() {
  MidiUSB.flush();
}