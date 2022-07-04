#ifndef IR2Midi_CPP
#define IR2Midi_CPP

#include "Arduino.h"
#include <string.h>
#include "IR2Midi.h"
#include <IRremote.hpp>


IR2Midi::IR2Midi() {
  m_irToMidiFound = false;
  m_peviousNote = 0;
  m_peviousVelocity = 0;
  m_peviousChannel = 0;
  m_peviousIrAddress = 0;
  m_peviousIrCommand = 0;
}

void IR2Midi::InitIR() {
  m_irToMidiFound = false;
  m_peviousNote = 0;
  m_peviousVelocity = 0;
  m_peviousChannel = 0;
  m_peviousIrAddress = 0;
  m_peviousIrCommand = 0;
  IrReceiver.begin(A0, ENABLE_LED_FEEDBACK);
  printActiveIRProtocols(&Serial);
}
void IR2Midi::ReadAndConvertToMidi() {

  m_irToMidiFound = false;
  if (IrReceiver.decode()) {

    // Print a short summary of received data
    IrReceiver.printIRResultShort(&Serial);
    if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
      Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
      IrReceiver.printIRResultRawFormatted(&Serial, true);
    } else if (IrReceiver.decodedIRData.protocol != UNKNOWN) {

      m_peviousIrAddress = IrReceiver.decodedIRData.address;
      m_peviousIrCommand = IrReceiver.decodedIRData.command;

      m_peviousNote = m_peviousIrCommand;
      m_peviousVelocity =126-( m_peviousIrAddress * 2);
      m_peviousChannel = 1;

      if (m_peviousNote > 127) {
        m_peviousVelocity = +1;
        m_peviousNote = m_peviousNote % 127;
      }

      if (m_peviousVelocity > 127) {
        m_peviousVelocity = 127;
      }
      if (m_peviousNote > 127) {
        m_peviousNote = 127;
      }
      m_irToMidiFound = true;
    }
    IrReceiver.resume();  // Enable receiving of the next value
  }
}

bool IR2Midi::HasReceivedIR(){
return m_irToMidiFound;

}

void IR2Midi::DisplayPreviousIRToMidiIfFound() {
  if (m_irToMidiFound) {
    DisplayPreviousIRToMidi();
  }
}

void IR2Midi::DisplayPreviousIRToMidi() {

  Serial.println("## Display IR 2 MIDI ##");
  
  Serial.print(" Address: ");
  Serial.print(m_peviousIrAddress);
  Serial.print(" Command: ");
  Serial.print(m_peviousIrCommand);
  Serial.println();

  Serial.print(" Note: ");
  Serial.print(m_peviousNote);
  Serial.print(" Velocity: ");
  Serial.print(m_peviousVelocity);
  Serial.print(" Channel: ");
  Serial.print(m_peviousChannel);
  Serial.println();
}

#endif