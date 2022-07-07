#ifndef ConvertStringToStruct_CPP
#define ConvertStringToStruct_CPP

#include "Arduino.h";
#include "String.h";
#include "ExecuteStruct.h";
#include "StructUtility.h";
#include "StructUtility.cpp";
#include "LogStruct.cpp";


static const void TryConvertAndExecute(String line){
	
bool wasConverted=false;
bool * converted = &wasConverted;
KeyboardExecutor* executor = new KeyboardExecutor();
PressionRequest* pressRequesRequest = new PressionRequest();
CommandLineKeyValue* cmd = new CommandLineKeyValue();
MidiAction* midiRequest = new MidiAction();
KeyboardFunctionStroke* keyboardfunctionRequest = new KeyboardFunctionStroke();
KeyboardNumpadStroke* numpadRequest = new KeyboardNumpadStroke();
KeyboardAlphaStroke* alphaRequest = new KeyboardAlphaStroke();
TransitToAllSerialText* transitionToAllRequest = new TransitToAllSerialText();

	cmd->Flush();
 ConvertToCommandLine(line, cmd );
 Log_Command(cmd);


// if(TryConvertTo(cmd,  keyboardfunctionRequest)){
// executor.Execute(keyboardfunctionRequest);
// }
// else 
// if(TryConvertTo(cmd, numpadRequest)){
// executor.Execute(numpadRequest);
// }

// else 
if( TryConvertToMidi(cmd, pressRequesRequest ,  midiRequest ) ){
    executor->Execute(pressRequesRequest, midiRequest);
}else if(TryConvertTo(cmd,  keyboardfunctionRequest)){
    executor->Execute(pressRequesRequest,keyboardfunctionRequest);
}
else if(TryConvertTo(cmd,  transitionToAllRequest)){
    executor->Execute(transitionToAllRequest);
}else if(TryConvertTo(cmd,  numpadRequest)){
    executor->Execute(pressRequesRequest,numpadRequest);
}else if(TryConvertTo(cmd,  alphaRequest)){
    executor->Execute(pressRequesRequest,alphaRequest);
}

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
	
	
	
	
}

#endif
