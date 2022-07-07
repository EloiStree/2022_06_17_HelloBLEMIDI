#ifndef LOGSTRUCT_H
#define LOGSTRUCT_H
#include "Arduino.h"
#include "String.h"
#include "StructUtility.h"


static const void Log_Command(CommandLineKeyValue* command) {


  Serial.println();
  Serial.print("> Command Start:");
  Serial.print(command->rawOrigine);
  Serial.print("|");
  Serial.print(command->rawOrigineTrimmed);
  Serial.print("|");
  Serial.print(command->key);
  Serial.print("|");
  Serial.print(command->keyLength);
  Serial.print("|");
  Serial.print(command->value);
  Serial.print("|");
  Serial.print(command->valueLength);
  Serial.println("> Command End");
}


static const void Log( TransitToAllSerialText* transitAction ){

Serial.println("");
Serial.println("Log to transit:");
Serial.print(transitAction->textToPrint);
Serial.println("<>");
}


static const void Log(MidiAction* midi){

Serial.println("");
Serial.println("Log Midi:");
  Serial.print("|");
Serial.print(midi->note);
  Serial.print("|");
Serial.print(midi->velocity);
  Serial.print("|");
Serial.print(midi->channel);
Serial.println("<>");
}


static const void Log(PressionRequest* action ,MidiAction* midi){

Serial.println("");
Serial.println("Log Midi:");
  Serial.print("|");
Serial.print(midi->note);
  Serial.print("|");
Serial.print(midi->velocity);
  Serial.print("|");
Serial.print(midi->channel);
  Serial.print("|");
Serial.print(action->press);
  Serial.print("|");
Serial.print(action->release);
Serial.println("<>");
}

#endif