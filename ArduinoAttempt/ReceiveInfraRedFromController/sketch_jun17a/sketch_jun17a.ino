
#include <IRremote.hpp>
#include <USB-MIDI.h>

USBMIDI_CREATE_DEFAULT_INSTANCE();

// Send note 42 with velocity 127 on channel 1
void setup()
{
	//https://github.com/Arduino-IRremote/Arduino-IRremote
    //__usbMIDI="Test1";
    MIDI.begin(1);
  //  IrReceiver.begin(7, ENABLE_LED_FEEDBACK); // Start the receiver
    IrReceiver.begin(3, ENABLE_LED_FEEDBACK); // Start the receiver
}

void loop() {
  if (IrReceiver.decode()) {

      //int hexHash = IrReceiver.decodedIRData.decodedRawData;
      //Serial.print("D:");
      //Serial.println(hexHash);
      if(IrReceiver.decodedIRData.address==0 && IrReceiver.decodedIRData.command==0){
        
        }
      else {
        
      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
      Serial.print("Address:");
      Serial.println(IrReceiver.decodedIRData.address);
      Serial.print("Command:");
      Serial.println(IrReceiver.decodedIRData.command);

      int midiNote=IrReceiver.decodedIRData.command;
      int midiVelocity=IrReceiver.decodedIRData.address*2;
      int channel=1;

      if(midiNote>127){
          midiVelocity=+1;
          midiNote = midiNote%127;
       }
       //if midi note >127 use channel

      
      Serial.println();
      Serial.print(" Note:");
      Serial.print(midiNote);
      Serial.print(" Velocity:");
      Serial.print(midiVelocity);
      Serial.print( "Channel: ");
      Serial.println(channel);
      
      
      IrReceiver.printIRResultShort(&Serial); // optional use new print version
      MIDI.sendNoteOn(midiNote, midiVelocity, channel);
      MIDI.sendNoteOff(midiNote, midiVelocity, channel);
      IrReceiver.resume(); // Enable receiving of the next value
      
      }
  }
 
}
