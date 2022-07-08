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
PrintDefaultSerialText* serialPrintRequest = new PrintDefaultSerialText();
CallFunctionInArduino* callFunctionRequest = new CallFunctionInArduino();
SwitchPinAsStringMode* pinStringRequest= new SwitchPinAsStringMode();
KeyboardStringPrintAction* writeTextRequest = new KeyboardStringPrintAction();
KeyboardCharTryToStrokeAction* charStrokeRequest =new KeyboardCharTryToStrokeAction();
KeyboardControlString*  writeControlTextRequest=new KeyboardControlString();

	cmd->Flush();
 ConvertToCommandLine(line, cmd );
 Log_Command(cmd);

if( TryConvertToMidi(cmd, pressRequesRequest ,  midiRequest ) ){
  Serial.println(">>0");
    executor->Execute(pressRequesRequest, midiRequest);
}
else if(TryConvertTo(cmd,  transitionToAllRequest)){
  Serial.println(">>1");
    executor->Execute(transitionToAllRequest);
}else if(TryConvertTo(cmd,  keyboardfunctionRequest)){
  Serial.println(">>2");
    executor->Execute(pressRequesRequest,keyboardfunctionRequest);
}
else if(TryConvertTo(cmd,  numpadRequest)){
  Serial.println(">>3");
    executor->Execute(pressRequesRequest,numpadRequest);
}else if(TryConvertTo(cmd,  alphaRequest)){
  Serial.println(">>4");
    executor->Execute(pressRequesRequest,alphaRequest);
}
else if (TryConvertTo(cmd,  serialPrintRequest) ){
  Serial.println(">>5");
    executor->Execute(serialPrintRequest);
}
else if (TryConvertTo(cmd,  callFunctionRequest)) {
  Serial.println(">>6");
    executor->Execute(callFunctionRequest);
}
else if (TryConvertTo(cmd,  pressRequesRequest , pinStringRequest)) {
  Serial.println(">>7");
    executor->Execute(pressRequesRequest,pinStringRequest);
}
else if (TryConvertToControl(cmd,  pressRequesRequest , writeControlTextRequest)) {
  Serial.println(">>8");
    executor->Execute(pressRequesRequest,writeControlTextRequest);
}
else if (TryConvertTo(cmd,  pressRequesRequest , charStrokeRequest)) {
  
    Serial.println(">>9");
    executor->Execute(pressRequesRequest,charStrokeRequest);
}
else if (TryConvertTo(cmd,   writeTextRequest)) {
    Serial.println(">>10");
    executor->Execute(writeTextRequest);
}
//TryConvertTo(CommandLineKeyValue* cmd,  KeyboardStringPrintAction* actionOut)

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
