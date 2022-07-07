#include "Arduino.h";
#include "String.h";
#include "ExecuteStruct.h";
#include "StructUtility.h";
#include "StructUtility.cpp";
#include "LogStruct.cpp";

bool wasConverted=false;
bool * converted = &wasConverted;

KeyboardExecutor* executor = new KeyboardExecutor();

PressionRequest* pressRequest = new PressionRequest();
CommandLineKeyValue* cmd = new CommandLineKeyValue();
MidiAction* midiAction = new MidiAction();
TransitToAllSerialText* transitionToAll = new TransitToAllSerialText();

static const void TryConvertAndExecute(String line){
	
	
	
// 	 cmd->Flush();
// ConvertToCommandLine(line, cmd );
// Log_Command(cmd);

//   line.trim();
//   Serial.print("Found Line:");
//   Serial.println(line);
//   int lineLenght = line.length();
//   if (lineLenght > 2 && line[0] == 'N' && line[1] == 'P') {
//     Serial.print("Keyboard Numpad parse:");
//     Serial.println(line);
//     //blePush.PushNumpad(line);
//   }  
//   else if (lineLenght > 1 && line[0] == 'K') {
//     Serial.print("Keyboard parse:");
//     Serial.println(line);
//     //blePush.PushKey(0x80, true, true);

//   } 
//   else if (lineLenght > 1 && line[0] == 'M') {
//     Serial.print("Midi parse:");
//     Serial.println(line);
//     TryConvertToMidi(converted, cmd, pressRequest, midiAction) ;
//     if(*converted)
//       Log(pressRequest, midiAction);
//     else 
//       Serial.println("Fail to convert Midi");
//     //blePush.PushMidi(50,127,5);

//   }  else if (lineLenght > 1 && line[0] == 'T') {

//     TryConvertTo(converted, cmd,  transitionToAll);
//     if(*converted)
//       Log(transitionToAll);
//     else 
//       Serial.println("Fail to convert  Transit All");
//   }  else if (lineLenght > 1 && line[0] == 'S') {

//       Serial.println("Fail to convert  Transit All");
//   }else if (lineLenght > 1 && line[0] == 'P') {

//     Serial.println(cmd->value);
//     // TryConvertToPinAction(converted, cmd,  );
//     // if(*converted)
//     //   Log(transitionToAll);
//     // else 
//     //   Serial.println("Fail to convert  Transit All");
//   }
//   else {
//     Serial.print("Unmanaged line:");
//     Serial.println(line);
//   }
	
	
	
// TryConvertTo(bool* converted, CommandLineKeyValue* cmd, KeyboardFunctionStroke* actionOut) {
//   TryConvertTo(bool* converted, CommandLineKeyValue* cmd, KeyboardNumpadStroke* actionOut) {
//     TryConvertTo(bool* converted, CommandLineKeyValue* cmd, TransitToAllSerialText* actionOut)
//     TryConvertToMidi(bool* converted, CommandLineKeyValue* cmd, PressionRequest* actionOut, MidiAction* midiOut) 
	
}
