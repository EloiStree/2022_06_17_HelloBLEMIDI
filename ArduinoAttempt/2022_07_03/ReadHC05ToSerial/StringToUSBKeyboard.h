 #ifndef StringToUSBKeyboard_H
#define StringToUSBKeyboard_H
#include "Arduino.h"

class StringToUSBKeyboard{
  public:
    bool m_useDebugLog=true;
    int m_defaultDelayWhenNeeded=10;
    StringToUSBKeyboard();
    void Init();
    void SwitchLanguageOnWindow();
    void TryToParseTextToUnicode(String commandline);
    void TryToParseTextToAction(String commandLine);
    
    void ConvertStringToNumpadKeys(String text);
    void WriteText(String text);
    void PressChar(char text);
    void ReleaseChar(char text);
    void PushLearningTest();
    void Push(uint8_t key, bool press, bool release);
    void Push(char key, bool press, bool release) ;
    void PushWithDelayIfNeeded(uint8_t key, bool press, bool release, int delayMS);
    void PushWithDelayIfNeeded(char key, bool press, bool release, int delayMS) ;
    void ReleaseAllKey();
};
#endif