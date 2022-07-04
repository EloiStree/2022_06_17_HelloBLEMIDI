#include "Arduino.h"
#include "StringToUSBKeyboard.h"
#include "Keyboard.h"

//#include "MouseAndKeyboard.h"

StringToUSBKeyboard::StringToUSBKeyboard() {}

void StringToUSBKeyboard::Init() {
  Keyboard.begin();
  Keyboard.releaseAll();
}
void StringToUSBKeyboard::SwitchLanguageOnWindow() {
  Keyboard.press(0x80);
  Keyboard.press(0x81);
  Keyboard.release(0x81);
  Keyboard.release(0x80);
}

void StringToUSBKeyboard::ConvertStringToNumpadKeys(String text) {

  int strLenght = text.length();
  for (int i = 0; i < strLenght; i++) {
    if (text[i] == '1') {
      Keyboard.press(225);
      delay(2);
      Keyboard.release(225);
    }
    if (text[i] == '2') {
      Keyboard.press(226);
      delay(2);
      Keyboard.release(226);
    }
    if (text[i] == '3') {
      Keyboard.press(227);
      delay(2);
      Keyboard.release(227);
    }
    if (text[i] == '4') {
      Keyboard.press(228);
      delay(2);
      Keyboard.release(228);
    }
    if (text[i] == '5') {
      Keyboard.press(229);
      delay(2);
      Keyboard.release(229);
    }
    if (text[i] == '6') {
      Keyboard.press(230);
      delay(2);
      Keyboard.release(230);
    }
    if (text[i] == '7') {
      Keyboard.press(231);
      delay(2);
      Keyboard.release(231);
    }
    if (text[i] == '8') {
      Keyboard.press(232);
      delay(2);
      Keyboard.release(232);
    }
    if (text[i] == '9') {
      Keyboard.press(233);
      delay(2);
      Keyboard.release(233);
    }
    if (text[i] == '0') {
      Keyboard.press(234);
      delay(2);
      Keyboard.release(234);
    }
  }
}


void StringToUSBKeyboard::TryToParseTextToUnicode(String commandline) {
  if (!(commandline[0] == 'W' && commandline[1] == 'U'))
    return;
  int removeIndex = commandline.indexOf('\n');
  if (removeIndex > -1)
    commandline.remove(removeIndex);
  removeIndex = commandline.indexOf('\r');
  if (removeIndex > -1)
    commandline.remove(removeIndex);

  int lineIndex = commandline.indexOf(':');
  String fChar = commandline.substring(lineIndex + 1);
  int strLenght = fChar.length();
  Keyboard.press(0x82);
  delay(2);
  if (m_useDebugLog)
    Serial.print("Unicode:");
  for (int i = 0; i < strLenght; i++) {
    if (fChar[i] == '1') {
      Keyboard.press(225);
      delay(2);
      Keyboard.release(225);
    }
    if (fChar[i] == '2') {
      Keyboard.press(226);
      delay(2);
      Keyboard.release(226);
    }
    if (fChar[i] == '3') {
      Keyboard.press(227);
      delay(2);
      Keyboard.release(227);
    }
    if (fChar[i] == '4') {
      Keyboard.press(228);
      delay(2);
      Keyboard.release(228);
    }
    if (fChar[i] == '5') {
      Keyboard.press(229);
      delay(2);
      Keyboard.release(229);
    }
    if (fChar[i] == '6') {
      Keyboard.press(230);
      delay(2);
      Keyboard.release(230);
    }
    if (fChar[i] == '7') {
      Keyboard.press(231);
      delay(2);
      Keyboard.release(231);
    }
    if (fChar[i] == '8') {
      Keyboard.press(232);
      delay(2);
      Keyboard.release(232);
    }
    if (fChar[i] == '9') {
      Keyboard.press(233);
      delay(2);
      Keyboard.release(233);
    }
    if (fChar[i] == '0') {
      Keyboard.press(234);
      delay(2);
      Keyboard.release(234);
    }
    if (m_useDebugLog)
      Serial.print(fChar[i]);
  }
  if (m_useDebugLog)
    Serial.println();
  delay(2);
  Keyboard.release(0x82);
}

void StringToUSBKeyboard::TryToParseTextToAction(String commandline) {

  if (commandline[0] != 'K')
    return;

  int removeIndex = commandline.indexOf('\n');
  if (removeIndex > -1)
    commandline.remove(removeIndex);
  removeIndex = commandline.indexOf('\r');
  if (removeIndex > -1)
    commandline.remove(removeIndex);

  int strLenght = commandline.length();
  if (strLenght < 2)
    return;
  if (m_useDebugLog) {

    Serial.print("Here A#");
    Serial.print(commandline);
    Serial.print("#");
    Serial.println();
    Serial.print("Lenght A:");
    Serial.println(strLenght);
  }

  //IS it Stroke, press or release
  bool press = true;
  bool release = true;
  uint8_t whatToPress;

  // CHECK IF IT IS SPECIAL COMMAND:
  //https://github.com/arduino-libraries/Keyboard/blob/master/src/Keyboard.h

  // Check if it is char{
  if (strLenght == 3 && commandline[1] == ':') {
    char c = commandline[2];
    PushWithDelayIfNeeded(c, true, true, m_defaultDelayWhenNeeded);
    return;
  } else if (strLenght == 4 && commandline[1] == 'P' && commandline[2] == ':') {
    char c = commandline[3];
    PushWithDelayIfNeeded(c, true, false, m_defaultDelayWhenNeeded);
    return;
  } else if (strLenght == 4 && commandline[1] == 'R' && commandline[2] == ':') {
    char c = commandline[3];
    PushWithDelayIfNeeded(c, false, true, m_defaultDelayWhenNeeded);
    return;
  } else if (strLenght > 2) {

    int lineIndex = commandline.indexOf(':');
    if (lineIndex > -1) {
      if (commandline[1] == 'P') {
        press = true;
        release = false;
      } else if (commandline[1] == 'R') {
        release = true;
        press = false;
      } else {
        press = true;
        release = true;
      }

      //F12
      // Code later be sure that lineIndex + 2 & lineIndex + 3 exist
      if (commandline[lineIndex + 1] == 'F') {
        String fChar = commandline.substring(lineIndex + 2);
        Serial.print("Parse to F:");
        Serial.println(fChar);
        if (fChar.equals("1"))
          whatToPress = 0xC2;  // #define KEY_F1            0xC2
        else if (fChar.equals("2"))
          whatToPress = 0xC3;  // #define KEY_F2            0xC3
        else if (fChar.equals("3"))
          whatToPress = 0xC4;  // #define KEY_F3            0xC4
        else if (fChar.equals("4"))
          whatToPress = 0xC5;  // #define KEY_F4            0xC5
        else if (fChar.equals("5"))
          whatToPress = 0xC6;  // #define KEY_F5            0xC6
        else if (fChar.equals("6"))
          whatToPress = 0xC7;  // #define KEY_F6            0xC7
        else if (fChar.equals("7"))
          whatToPress = 0xC8;  // #define KEY_F7            0xC8
        else if (fChar.equals("8"))
          whatToPress = 0xC9;  // #define KEY_F8            0xC9
        else if (fChar.equals("9"))
          whatToPress = 0xCA;  // #define KEY_F9            0xCA
        else if (fChar.equals("10"))
          whatToPress = 0xCB;  // #define KEY_F10           0xCB
        else if (fChar.equals("11"))
          whatToPress = 0xCC;  // #define KEY_F11           0xCC
        else if (fChar.equals("12"))
          whatToPress = 0xCD;  // #define KEY_F12           0xCD
        else if (fChar.equals("13"))
          whatToPress = 0xF0;  // #define KEY_F13           0xF0
        else if (fChar.equals("14"))
          whatToPress = 0xF1;  // #define KEY_F14           0xF1
        else if (fChar.equals("15"))
          whatToPress = 0xF2;  // #define KEY_F15           0xF2
        else if (fChar.equals("16"))
          whatToPress = 0xF3;  // #define KEY_F16           0xF3
        else if (fChar.equals("17"))
          whatToPress = 0xF4;  // #define KEY_F17           0xF4
        else if (fChar.equals("18"))
          whatToPress = 0xF5;  // #define KEY_F18           0xF5
        else if (fChar.equals("19"))
          whatToPress = 0xF6;  // #define KEY_F19           0xF6
        else if (fChar.equals("20"))
          whatToPress = 0xF7;  // #define KEY_F20           0xF7
        else if (fChar.equals("21"))
          whatToPress = 0xF8;  // #define KEY_F21           0xF8
        else if (fChar.equals("22"))
          whatToPress = 0xF9;  // #define KEY_F22           0xF9
        else if (fChar.equals("23"))
          whatToPress = 0xFA;  // #define KEY_F23           0xFA
        else if (fChar.equals("24"))
          whatToPress = 0xFB;  // #define KEY_F24           0xFB
        PushWithDelayIfNeeded(whatToPress, press, release, m_defaultDelayWhenNeeded);
        return;

      }
      //NP5
      // Code later be sure lineIndex + 3 exist
      else if ((lineIndex + 3) < strLenght && commandline[lineIndex + 1] == 'N') {
        char numChar = commandline[lineIndex + 3];
        Serial.print("Parse to NP:");
        Serial.println(numChar);
        if (numChar == '1')
          whatToPress = 225;  // 225 '\341' Keypad 1 and End
        else if (numChar == '2')
          whatToPress = 226;  // 226 '\342' Keypad 2 and Down A
        else if (numChar == '3')
          whatToPress = 227;  // 227 '\343' Keypad 3 and PageDn
        else if (numChar == '4')
          whatToPress = 228;  // 228 '\344' Keypad 4 and Left A
        else if (numChar == '5')
          whatToPress = 229;  // 229 '\345' Keypad 5
        else if (numChar == '6')
          whatToPress = 230;  // 230 '\346' Keypad 6 and Right
        else if (numChar == '7')
          whatToPress = 231;  // 231 '\347' Keypad 7 and Home
        else if (numChar == '8')
          whatToPress = 232;  // 232 '\350' Keypad 8 and Up Arr
        else if (numChar == '9')
          whatToPress = 233;  // 233 '\351' Keypad 9 and PageUp
        else if (numChar == '0')
          whatToPress = 234;  // 234 '\352' Keypad 0 and Insert
        else if (numChar == '.')
          whatToPress = 235;  // 235 '\353' Keypad . and Delete
        else if (numChar == '/')
          whatToPress = 220;  // 220 '\334' Keypad /
        else if (numChar == '*')
          whatToPress = 221;  // 221 '\335' Keypad *
        else if (numChar == '-')
          whatToPress = 222;  // 222 '\336' Keypad -
        else if (numChar == '+')
          whatToPress = 223;  // 223 '\337' Keypad +
        else if (numChar == 'E')
          whatToPress = 224;  // 224 '' Keypad Enter
        PushWithDelayIfNeeded(whatToPress, press, release, m_defaultDelayWhenNeeded);
        return;
      }

      else if (strLenght > lineIndex) {
        String cmd = commandline.substring(lineIndex + 1);
        cmd.toLowerCase();
        whatToPress = 0;
        // Modifiers
        if (cmd.equals("ctrl")) whatToPress = 0x80;  //#define KEY_LEFT_CTRL     0x80
        else if (cmd.equals("shift"))
          whatToPress = 0x81;  //#define KEY_LEFT_SHIFT    0x81
        else if (cmd.equals("alt"))
          whatToPress = 0x82;  //#define KEY_LEFT_ALT      0x82
        else if (cmd.equals("window"))
          whatToPress = 0x83;  //#define KEY_LEFT_GUI      0x83
        else if (cmd.equals("rctrl"))
          whatToPress = 0x84;  //#define KEY_RIGHT_CTRL    0x84
        else if (cmd.equals("rshift"))
          whatToPress = 0x85;  //#define KEY_RIGHT_SHIFT   0x85
        else if (cmd.equals("ralt"))
          whatToPress = 0x86;  //#define KEY_RIGHT_ALT     0x86
        else if (cmd.equals("rwindow"))
          whatToPress = 0x87;  //#define KEY_RIGHT_GUI     0x87
        else if (cmd.equals("up"))
          whatToPress = 0xDA;  //#define KEY_UP_ARROW      0xDA
        else if (cmd.equals("down"))
          whatToPress = 0xD9;  //#define KEY_DOWN_ARROW    0xD9
        else if (cmd.equals("left"))
          whatToPress = 0xD8;  //#define KEY_LEFT_ARROW    0xD8
        else if (cmd.equals("right"))
          whatToPress = 0xD7;  //#define KEY_RIGHT_ARROW   0xD7
        else if (cmd.equals("backspace"))
          whatToPress = 0xB2;  //#define KEY_BACKSPACE     0xB2
        else if (cmd.equals("tab"))
          whatToPress = 0xB3;  //#define KEY_TAB           0xB3
        else if (cmd.equals("return"))
          whatToPress = 0xB0;  //#define KEY_RETURN        0xB0
        else if (cmd.equals("menu"))
          whatToPress = 0xED;  //#define KEY_MENU          0xED // "Keyboard Application" in USB standard
        else if (cmd.equals("escape"))
          whatToPress = 0xB1;  //#define KEY_ESC           0xB1
        else if (cmd.equals("insert"))
          whatToPress = 0xD1;  //#define KEY_INSERT        0xD1
        else if (cmd.equals("delete"))
          whatToPress = 0xD4;  //#define KEY_DELETE        0xD4
        else if (cmd.equals("pageup"))
          whatToPress = 0xD3;  //#define KEY_PAGE_UP       0xD3
        else if (cmd.equals("pagedown"))
          whatToPress = 0xD6;  //#define KEY_PAGE_DOWN     0xD6
        else if (cmd.equals("home"))
          whatToPress = 0xD2;  //#define KEY_HOME          0xD2
        else if (cmd.equals("end"))
          whatToPress = 0xD5;  //#define KEY_END           0xD5
        else if (cmd.equals("shiftlock") || cmd.equals("caplock"))
          whatToPress = 0xC1;  //#define KEY_CAPS_LOCK     0xC1
        else if (cmd.equals("print"))
          whatToPress = 0xCE;  //#define KEY_PRINT_SCREEN  0xCE // Print Screen / SysRq
        else if (cmd.equals("scrolllock"))
          whatToPress = 0xCF;  //#define KEY_SCROLL_LOCK   0xCF
        else if (cmd.equals("pause") || cmd.equals("break"))
          whatToPress = 0xD0;  //#define KEY_PAUSE         0xD0 // Pause / Break
        else if (cmd.equals("numlock"))
          whatToPress = 0xDB;  //#define KEY_NUM_LOCK      0xDB
        else if (cmd.equals("stop"))
          whatToPress = 0x78;  //120	0x78			Keyboard Stop
        else if (cmd.equals("replay"))
          whatToPress = 0x79;  //121	0x79			Keyboard Again
        else if (cmd.equals("undo"))
          whatToPress = 0x7A;  //122	0x7A			Keyboard Undo
        else if (cmd.equals("cut"))
          whatToPress = 0x7B;  //123	0x7B			Keyboard Cut
        else if (cmd.equals("copy"))
          whatToPress = 0x7C;  //124	0x7C			Keyboard Copy
        else if (cmd.equals("past"))
          whatToPress = 0x7D;  //125	0x7D			Keyboard Paste
        else if (cmd.equals("find"))
          whatToPress = 0x7E;  //126	0x7E			Keyboard Find
        else if (cmd.equals("mute"))
          whatToPress = 0x7F;  //127	0x7F			Keyboard Mute
        else if (cmd.equals("v+") || cmd.equals("volume+"))
          whatToPress = 0x80;  //128	0x80			Keyboard Volume Up
        else if (cmd.equals("v-") || cmd.equals("volume-"))
          whatToPress = 0x81;  //129	0x81			Keyboard Volume Down



        Serial.print("T");
        Serial.print(whatToPress);
        Serial.print("-");
        Serial.print(cmd);
        Serial.print("-");
        Serial.print(press);
        Serial.print("-");
        Serial.print(release);
        Serial.println();
        if (whatToPress > 0) {
          PushWithDelayIfNeeded(whatToPress, press, release, m_defaultDelayWhenNeeded);
        } else {
          Keyboard.print(cmd);
        }

        return;
      }
    }
  }

  Serial.println("Try to translate but key code not found");
}



void StringToUSBKeyboard::Push(uint8_t key, bool press, bool release) {

  if (press)
    Keyboard.press(key);
  if (release)
    Keyboard.release(key);
}
void StringToUSBKeyboard::Push(char key, bool press, bool release) {

  if (press)
    Keyboard.press(key);
  if (release)
    Keyboard.release(key);
}
void StringToUSBKeyboard::PushWithDelayIfNeeded(uint8_t key, bool press, bool release, int delayMS) {

  if (press)
    Keyboard.press(key);
  if (press && release)
    delay(delayMS);
  if (release)
    Keyboard.release(key);
  Keyboard.flush();
}
void StringToUSBKeyboard::PushWithDelayIfNeeded(char key, bool press, bool release, int delayMS) {

  if (press)
    Keyboard.press(key);
  if (press && release)
    delay(delayMS);
  if (release)
    Keyboard.release(key);
  Keyboard.flush();
}

void StringToUSBKeyboard::PushLearningTest() {
}
void StringToUSBKeyboard::ReleaseAllKey() {

  Keyboard.releaseAll();
}














/*
Keyboard.write(65);         // sends ASCII value 65, or A
Keyboard.write('A');            // same thing as a quoted character
Keyboard.write(0x41);       // same thing in hexadecimal
Keyboard.write(0b01000001); // same thing in binary (weird choice, but it works)
*/

/**
//Source:https://forum.arduino.cc/t/keyboard-write-with-number-pad-keys-from-leonardo/175304/6
220 '\334' Keypad /
221 '\335' Keypad *
222 '\336' Keypad -
223 '\337' Keypad +
224 '\340' Keypad ENTER
225 '\341' Keypad 1 and End
226 '\342' Keypad 2 and Down Arrow
227 '\343' Keypad 3 and PageDn
228 '\344' Keypad 4 and Left Arrow
229 '\345' Keypad 5
230 '\346' Keypad 6 and Right Arrow
231 '\347' Keypad 7 and Home
232 '\350' Keypad 8 and Up Arrow
233 '\351' Keypad 9 and PageUp
234 '\352' Keypad 0 and Insert
235 '\353' Keypad . and Delete

*/


//If unrecognized or too long
//Push as a text
//A is 65, 97



// void WriteText(String text);
// void PressChar(char text);
// void ReleaseChar(char text);