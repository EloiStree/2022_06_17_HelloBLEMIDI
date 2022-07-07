#ifndef LOGSTRUCT_H
#define LOGSTRUCT_H
#include "Arduino.h"
#include "String.h"
#include "StructUtility.h"


static const void Log_Command(CommandLineKeyValue* command) {


  Serial.println();
  Serial.print("> Command Start:");
  Serial.println(command->rawOrigine);
  Serial.println(command->rawOrigineTrimmed);
  Serial.println(command->key);
  Serial.println(command->keyLength);
  Serial.println(command->value);
  Serial.println(command->valueLength);
  Serial.println("> Command End");
}


static const void Log( PrintToAllSerialText* transitAction ){

Serial.println("");
Serial.println("Log to transit:");
Serial.print(transitAction->textToPrint);
Serial.println("<>");
}


static const void Log(MidiAction* midi){

Serial.println("");
Serial.println("Log Midi:");
Serial.print(" ");
Serial.print(midi->note);
Serial.print(" ");
Serial.print(midi->velocity);
Serial.print(" ");
Serial.print(midi->channel);
Serial.println("<>");
}


static const void Log( PressionRequest* action ,MidiAction* midi){

Serial.println("");
Serial.println("Log Midi:");
Serial.print(" ");
Serial.print(midi->note);
Serial.print(" ");
Serial.print(midi->velocity);
Serial.print(" ");
Serial.print(midi->channel);
Serial.print(" ");
Serial.print(action->press);
Serial.print(" ");
Serial.print(action->release);
Serial.println("<>");
}

#endif