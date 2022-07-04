 #ifndef USBSerialToStringLine_H
#define USBSerialToStringLine_H
#include "Arduino.h"
#include <SoftwareSerial.h>

class USBSerialToStringLine{
  public:
    uint8_t RxD=11; 
    uint8_t TxD=10;
    SoftwareSerial *TargetSerial;
    String received = "";
    String lineFound = "";
    bool newCharFound;
    bool newLineFound;

    USBSerialToStringLine();
    void Init(uint8_t tx, uint8_t rx,int baud);
    bool CheckForAvailable();
    bool HasNewLine();
    String GetPreviousLine();
    String GetCurrentStack();
    void DisplayStateIfChanged();
};

#endif