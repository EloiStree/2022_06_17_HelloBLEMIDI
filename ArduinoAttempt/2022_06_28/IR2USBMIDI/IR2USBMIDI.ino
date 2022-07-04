/*
   SimpleReceiver.cpp

   Demonstrates receiving NEC IR codes with IRrecv

    This file is part of Arduino-IRremote https://github.com/Arduino-IRremote/Arduino-IRremote.

 ************************************************************************************
   MIT License

   Copyright (c) 2020-2022 Armin Joachimsmeyer

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is furnished
   to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
   INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
   PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
   HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
   CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
   OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

 ************************************************************************************
*/

/*
   Specify which protocol(s) should be used for decoding.
   If no protocol is defined, all protocols are active.
*/
//#define DECODE_DENON        // Includes Sharp
//#define DECODE_JVC
//#define DECODE_KASEIKYO
//#define DECODE_PANASONIC    // the same as DECODE_KASEIKYO
//#define DECODE_LG
#define DECODE_NEC          // Includes Apple and Onkyo
//#define DECODE_SAMSUNG
//#define DECODE_SONY
//#define DECODE_RC5
//#define DECODE_RC6

//#define DECODE_BOSEWAVE
//#define DECODE_LEGO_PF
//#define DECODE_MAGIQUEST
//#define DECODE_WHYNTER

//#define DECODE_DISTANCE     // universal decoder for pulse width or pulse distance protocols
//#define DECODE_HASH         // special decoder for all protocols

//#define DEBUG // Activate this for lots of lovely debug output from the decoders.
//#define INFO                // To see valuable informations from universal decoder for pulse width or pulse distance protocols
#include <USB-MIDI.h>
#include <Arduino.h>

#include "PinDefinitionsAndMore.h" //Define macros for input and output pin etc.
#include <IRremote.hpp>
USBMIDI_CREATE_DEFAULT_INSTANCE();
void setup() {
  ////https://github.com/Arduino-IRremote/Arduino-IRremote
  Serial.begin(115200);
  // Just to know which program is running on my Arduino
  Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));

  // Start the receiver and if not 3. parameter specified, take LED_BUILTIN pin from the internal boards definition as default feedback LED
  IrReceiver.begin(A0, ENABLE_LED_FEEDBACK);

  Serial.print(F("Ready to receive IR signals of protocols: "));
  printActiveIRProtocols(&Serial);
  Serial.println(F("at pin " STR(A0)));
  MIDI.begin(1);
}

  bool found =false;
void loop() {
  /*
     Check if received data is available and if yes, try to decode it.
     Decoded result is in the IrReceiver.decodedIRData structure.

     E.g. command is in IrReceiver.decodedIRData.command
     address is in command is in IrReceiver.decodedIRData.address
     and up to 32 bit raw data in IrReceiver.decodedIRData.decodedRawData
  */
  found =false;
  if (IrReceiver.decode()) {

    // Print a short summary of received data
    IrReceiver.printIRResultShort(&Serial);
    if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
      Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
      // We have an unknown protocol here, print more info
      IrReceiver.printIRResultRawFormatted(&Serial, true);
    }
    else  if (IrReceiver.decodedIRData.protocol != UNKNOWN) {
      

        int midiNote = IrReceiver.decodedIRData.command;
        int midiVelocity = IrReceiver.decodedIRData.address * 2;
        int channel = 1;

        if (midiNote > 127) {
          midiVelocity +=1;
          midiNote = midiNote % 127;
        }
        
        if (midiVelocity > 127) {
          midiVelocity = 127;
        }if (midiNote > 127) {
          midiNote = 127;
        }

        MIDI.sendNoteOn(midiNote, midiVelocity, channel);
        MIDI.sendNoteOff(midiNote, midiVelocity, channel);
        Serial.println();
        Serial.print(" Note:");
        Serial.print(midiNote);
        Serial.print(" Velocity:");
        Serial.print(midiVelocity);
        Serial.print( "Channel: ");
        Serial.println(channel);
      

    }  
    IrReceiver.resume(); // Enable receiving of the next value
    Serial.println();

if(found){
  
  
  }
    /*
       !!!Important!!! Enable receiving of the next value,
       since receiving has stopped after the end of the current received data packet.
    */

  }
}
