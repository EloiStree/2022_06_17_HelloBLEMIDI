#include <BLEMIDI_Transport.h>

#include <BLEUtils.h>
//#include <hardware/BLEMIDI_ESP32_NimBLE.h>
#include <hardware/BLEMIDI_ESP32.h>
//#include <hardware/BLEMIDI_nRF52.h>
//#include <hardware/BLEMIDI_ArduinoBLE.h>

BLEMIDI_CREATE_DEFAULT_INSTANCE()

unsigned long t0 = millis();
bool isConnected = false;

// -----------------------------------------------------------------------------
// When BLE connected, LED will turn on (indication that connection was successful)
// When receiving a NoteOn, LED will go out, on NoteOff, light comes back on.
// This is an easy and conveniant way to show that the connection is alive and working. 
// -----------------------------------------------------------------------------
uint8_t pinLed=13;
void setup()
{
  MIDI.begin();

  pinMode(pinLed, OUTPUT);
  digitalWrite(pinLed, LOW);

  BLEMIDI.setHandleConnected([]() {
    isConnected = true;
    digitalWrite(pinLed, HIGH);
  });

  BLEMIDI.setHandleDisconnected([]() {
    isConnected = false;
    digitalWrite(pinLed, LOW);
  });

  MIDI.setHandleNoteOn([](byte channel, byte note, byte velocity) {
    digitalWrite(pinLed, LOW);
  });
  MIDI.setHandleNoteOff([](byte channel, byte note, byte velocity) {
    digitalWrite(pinLed, HIGH);
  });
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void loop()
{
  MIDI.read();

  if (isConnected && (millis() - t0) > 1000)
  {
    t0 = millis();

    MIDI.sendNoteOn (60, 100, 1); // note 60, velocity 100 on channel 1
  }
}
