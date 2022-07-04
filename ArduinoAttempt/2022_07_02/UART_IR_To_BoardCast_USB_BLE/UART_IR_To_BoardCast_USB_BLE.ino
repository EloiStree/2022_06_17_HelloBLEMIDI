#include <Arduino.h>
#include <SPI.h>
#include <string.h>
#include <USB-MIDI.h>
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_SPI.h"
#include "Adafruit_BluefruitLE_UART.h"
#include "Adafruit_BLEMIDI.h"
#include "BluefruitConfig.h"
#include "ConstVariable.h"
#include "PinDefinitionsAndMore.h"  //Define macros for input and output pin etc.
#include "IR2Midi.h"
#if SOFTWARE_SERIAL_AVAILABLE
#include <SoftwareSerial.h>
#endif

#define FACTORYRESET_ENABLE 0
#define MINIMUM_FIRMWARE_VERSION "0.6.6"
#define MODE_LED_BEHAVIOUR "MODE"

Adafruit_BluefruitLE_SPI ble(BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);
Adafruit_BLEMIDI midiBLE(ble);


USBMIDI_CREATE_DEFAULT_INSTANCE();


bool isConnected = false;
int current_note = 60;
IR2Midi irToMidi;


void error(const __FlashStringHelper* err) {
  Serial.println(err);
  while (1)
    ;
}
// callback
void connected(void) {
  isConnected = true;
  Serial.println(F("Connected"));
  delay(1000);
}

void disconnected(void) {
  Serial.println(F("disocnnect"));
  isConnected = false;
}

void setup(void) {
  Serial.begin(115200);
  Serial.print(F("Ready to receive IR signals of protocols: "));
  irToMidi.InitIR();
  Serial.println(F("at pin " STR(A0)));

  MIDI.begin(1);
  Serial.println(F("Adafruit Bluefruit Inject from UART and IR"));
  Serial.println(F("---------------------------------------"));

  /* Initialise the module */
  Serial.print(F("Initialising the Bluefruit LE module: "));
  if (!ble.begin(VERBOSE_MODE)) {
    error(F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));
  }
  Serial.println(F("OK!"));

  if (FACTORYRESET_ENABLE) {
    /* Perform a factory reset to make sure everything is in a known state */
    Serial.println(F("Performing a factory reset: "));
    if (!ble.factoryReset()) {
      error(F("Couldn't factory reset"));
    }
  }

  ble.sendCommandCheckOK(F("AT+uartflow=on"));
  ble.echo(false);

  Serial.println("Requesting Bluefruit info:");
  /* Print Bluefruit information */
  ble.info();

  /* Set BLE callbacks */
  ble.setConnectCallback(connected);
  ble.setDisconnectCallback(disconnected);

  // Set MIDI RX callback
  //midiBLE.setRxCallback(BleMidiRX);

  Serial.println(F("Enable MIDI: "));
  if (!midiBLE.begin(true)) {
    error(F("Could not enable MIDI"));
  }



  /* Change the device name to make it easier to find */
  Serial.println(F("Setting device name to 'Bluefruit Keyboard': "));
  if (!ble.sendCommandCheckOK(F("AT+GAPDEVNAME=IR 2 MIDI Bluefruit"))) {
    error(F("Could not set device name?"));
  }

  /* Enable HID Service */
  Serial.println(F("Enable HID Service (including Keyboard): "));
  if (ble.isVersionAtLeast(MINIMUM_FIRMWARE_VERSION)) {
    if (!ble.sendCommandCheckOK(F("AT+BLEHIDEN=1"))) {
      error(F("Could not enable Keyboard"));
    }
  } else {
    if (!ble.sendCommandCheckOK(F("AT+BLEKEYBOARDEN=1"))) {
      error(F("Could not enable Keyboard"));
    }
  }


  Serial.println(F("Enable HID Service (including Mouse): "));
  if (!ble.sendCommandCheckOK(F("AT+BLEHIDEN=1"))) {
    error(F("Failed to enable HID (firmware >=0.6.6?)"));
  }


  //Not sure a good idea to have it but if I want fast data reading ?
  // Serial.println( F("Switching to DATA mode!") );
  //ble.setMode(BLUEFRUIT_MODE_DATA);

  if (!ble.sendCommandCheckOK(F("ATZ"))) {
    error(F("Failed to use ATZ"));
  }
   /* Add or remove service requires a reset */
   Serial.println(F("Performing a SW reset (service changes require a reset): "));
   if (!ble.reset()) {
     error(F("Couldn't reset??"));
   }

  ble.verbose(false);
  Serial.print(F("Waiting for a connection..."));
}
void loop(void) {
  // interval for each scanning ~ 500ms (non blocking)
  ble.update(500);
  delay(100);

  {  //IR DEMO
    irToMidi.ReadAndConvertToMidi();
    if (irToMidi.HasReceivedIR()) {

      irToMidi.DisplayPreviousIRToMidiIfFound();
      if (isConnected) {
      }


      {  //PUSH MIDI
        if (isConnected) {
          //PUSH IN TX UART
          ble.print("AT+BLEUARTTX=IR2MIDI,");
          ble.print(irToMidi.m_peviousNote);
          ble.print(",");
          ble.print(irToMidi.m_peviousVelocity);
          ble.print(",");
          ble.print(irToMidi.m_peviousChannel);
          ble.println();
        }
        /// PUSH AS NOTE
        MIDI.sendNoteOn(irToMidi.m_peviousNote, irToMidi.m_peviousVelocity, 1);
        if (isConnected) {
          midiBLE.send(0x90, irToMidi.m_peviousNote, irToMidi.m_peviousVelocity);
        }
        delay(TIMEBETWEENPRESSRELEASE);
        MIDI.sendNoteOff(irToMidi.m_peviousNote, irToMidi.m_peviousVelocity, 1);
        if (isConnected) {
          midiBLE.send(0x80, irToMidi.m_peviousNote, irToMidi.m_peviousVelocity);
        }
        // check response stastus
        if (!ble.waitForOK()) {
          Serial.println(F("Failed to send Midi?"));
        }

      //Experiment 
      bool forFunKeyboardMorse=true;
        if (forFunKeyboardMorse) {
          ble.print("AT+BleKeyboard=00");
          ble.print(irToMidi.m_peviousNote);
          ble.print("|");
          ble.print(irToMidi.m_peviousVelocity);
          ble.print("|");
          ble.print(irToMidi.m_peviousChannel);
          ble.print("00");
          ble.println();
          if (ble.waitForOK()) {
            Serial.println(F("OK!"));
          } else {
            Serial.println(F("FAILED!"));
          }
        }
      }
    }
  }  //PUSH MIDI


  if (false) {

    // Check for user input and echo it back if anything was found
    char keys[BUFSIZE + 1];
    getUserInput(keys, BUFSIZE);


    {  // CONTROL

      if (keys[0] == '?') {
        printDefinedControlKey();
      } else {
        ble.print("AT+BleHidControlKey=");
        ble.println(keys);

        if (ble.waitForOK()) {
          Serial.println(F("OK!"));
        } else {
          Serial.println(F("FAILED!"));
          // Failed, probably pairing is not complete yet
          Serial.println(F("Please make sure Bluefruit is paired and try again"));
        }
      }


    }  // CONTROL



    {  //UART


      {
        // Send characters to Bluefruit
        Serial.print("[Send] ");
        Serial.println(keys);

        ble.print("AT+BLEUARTTX=");
        ble.println(keys);

        // check response stastus
        if (!ble.waitForOK()) {
          Serial.println(F("Failed to send?"));
        }
      }

      // Check for incoming characters from Bluefruit
      ble.println("AT+BLEUARTRX");
      ble.readline();
      if (strcmp(ble.buffer, "OK") == 0) {
        // no data
        return;
      }
      // Some data was found, its in the buffer
      Serial.print(F("[Recv] "));
      Serial.println(ble.buffer);
      ble.waitForOK();


    }  ///UART





    if (true) {  //KEYBOARD REGION



      Serial.print("\nSending:");
      Serial.println(keys);
      ble.print("AT+BleKeyboard=");
      ble.println(keys);

      if (ble.waitForOK()) {
        Serial.println(F("OK!"));
      } else {
        Serial.println(F("FAILED!"));
      }

    }  //KEYBOARD REGION







    {  //PRESS LEFT MOUSE

      if (ble.sendCommandCheckOK(F("AT+BleHidMouseButton=L,press"))) {
        // delay a bit
        delay(150);
        // Mouse moves according to the user's input
        ble.println(F("AT+BLEHIDMOUSEMOVE=100,100"));
        if (ble.waitForOK()) {
          Serial.println(F("OK!"));
        } else {
          Serial.println(F("FAILED1!"));
        }
        delay(150);
        ble.println(F("AT+BLEHIDMOUSEMOVE=,,20,"));
        if (ble.waitForOK()) {
          Serial.println(F("OK!"));
        } else {
          Serial.println(F("FAILED2!"));
        }
        delay(150);
        ble.println(F("AT+BLEHIDMOUSEMOVE=0,0,0,100"));
        if (ble.waitForOK()) {
          Serial.println(F("OK!"));
        } else {
          Serial.println(F("FAILED3!"));
        }



        // Release the Left mouse's button
        ble.sendCommandCheckOK(F("AT+BleHidMouseButton=0"));
      } else {
        // Failed, probably pairing is not complete yet
        Serial.println(F("Please make sure Bluefruit is paired and try again"));
      }
    }  //PRESS LEFT MOUSE


    bool sent = false;

    int note = current_note;
    int velocity = current_note + 1;
    {  //MIDI REGION


      //If connected to USB
      MIDI.sendNoteOn(note, velocity, 1);
      if (isConnected) {
        midiBLE.send(0x90, note, velocity);
        sent = true;
      }
      delay(TIMEBETWEENPRESSRELEASE);
      MIDI.sendNoteOff(note, velocity, 1);
      if (isConnected) {

        midiBLE.send(0x80, note, velocity);
      }
      sent = true;



      if (sent) {
        current_note++;
        if (current_note > 72)
          current_note = 60;
      }
    }  //MIDI REGION
  }
}





void getUserInput(char buffer[], uint8_t maxSize) {
  memset(buffer, 0, maxSize);
  while (Serial.available() == 0) {
    delay(1);
  }

  uint8_t count = 0;

  do {
    count += Serial.readBytes(buffer + count, maxSize);
    delay(2);
  } while ((count < maxSize) && !(Serial.available() == 0));
}




void printDefinedControlKey(void) {
  Serial.println();
  Serial.println(F("You can send a raw 16-bit (e.g 0x1234) usage key from the USB"
                   "\n"
                   "HID Consumer Control Page or use one of the the following keys:"));

  Serial.println(F("List of pre-defined control keys:"));
  Serial.print(F(
    "- BRIGHTNESS+"
    "\n"
    "- BRIGHTNESS-"
    "\n"
    "- PLAYPAUSE"
    "\n"
    "- MEDIANEXT"
    "\n"
    "- MEDIAPREVIOUS"
    "\n"
    "- MEDIASTOP"
    "\n"
    "- VOLUME"
    "\n"
    "- MUTE"
    "\n"
    "- BASS"
    "\n"
    "- TREBLE"
    "\n"
    "- BASS_BOOST"
    "\n"
    "- VOLUME+"
    "\n"
    "- VOLUME-"
    "\n"
    "- BASS+"
    "\n"
    "- BASS-"
    "\n"
    "- TREBLE+"
    "\n"
    "- TREBLE-"
    "\n"
    "- EMAILREADER"
    "\n"
    "- CALCULATOR"
    "\n"
    "- FILEBROWSER"
    "\n"
    "- SEARCH"
    "\n"
    "- HOME"
    "\n"
    "- BACK"
    "\n"
    "- FORWARD"
    "\n"
    "- STOP"
    "\n"
    "- REFRESH"
    "\n"
    "- BOOKMARKS"
    "\n"));
}