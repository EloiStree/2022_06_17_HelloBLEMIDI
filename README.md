# 2022_06_17_HelloBLEMIDI
I bought an Arduino with BLE in it to create OMI interface. So I need to learn how to use it.


Lib MIDI USB: https://github.com/FortySevenEffects/arduino_midi_library  
Lib MIDI BLE: https://github.com/lathoub/Arduino-BLE-MIDI  

My current target device own and so targeted for now :  
- For low cost user that know Arduino:
  - Ardino Leonardo/ Micro wiht HC-06
  - Ardino Leonardo/ Micro wiht HC-05
- For user that just want a "ready to go"
  - Arduino BLE 33
  - Arduino Feather 32u4


## What I try to do ?

> During my reseach this week (2022-06-30), I lost myself a  lot so let's define my intent of this project.

### Goals: BLE To Midi

> Note: The only reason to push midi is not to play music but to have a standard to convert in "action(s)" / macro on the device.

- Through BLE some instruction are push on a Arduino. Depending of this information, some Midi note are push on USB Mini.
- Through BLE some instruction are push on a Arduino. Depending of this information, some key stroke are push on USB port.
- From Passthrough device, the user put a key on a computer or linked it by bluetooth and is now able to send keycode and midi on this target.

Secondary:
- To have perfect timing macro, the user push sequence of key with timing to be push on the computer at <1ms execution timing.
- From a computer control a pair computer with BLE actions to do action without installing software.

Fun secondary but the most useful:
- Use Infrared Red to Action on linked computer.


Sad Note :
- Unfortunately, Midi USB is understood by NAudio but not the BLE one.
