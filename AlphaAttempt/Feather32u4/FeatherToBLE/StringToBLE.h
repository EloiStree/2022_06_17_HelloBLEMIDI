//  #ifndef StringToBLEKeyboard_H
// #define StringToBLEKeyboard_H
// #include "Arduino.h"

// class StringToBLEKeyboard{
//   public:
//     bool m_useDebugLog=true;
//     int m_defaultDelayWhenNeeded=10;
//     StringToBLEKeyboard();
//     void Init();
//     void SwitchLanguageOnWindow();
//     void TryToParseTextToUnicode(String commandline);
//     void TryToParseTextToAction(String commandLine);
    
//     void ConvertStringToNumpadKeys(String text);
//     void WriteText(String text);
//     void PressChar(char text);
//     void ReleaseChar(char text);
//     void PushLearningTest();
//     void Push(uint8_t key, bool press, bool release);
//     void Push(char key, bool press, bool release) ;
//     void PushWithDelayIfNeeded(uint8_t key, bool press, bool release, int delayMS);
//     void PushWithDelayIfNeeded(char key, bool press, bool release, int delayMS) ;
//     void ReleaseAllKey();
// };
// #endif