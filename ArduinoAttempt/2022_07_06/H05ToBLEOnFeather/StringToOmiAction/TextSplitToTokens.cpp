#include "Arduino.h"
#include "String.h"

#define SPTR_SIZE   20
char   *sPtr [SPTR_SIZE];

int
splitToTokens (
    String str,
    char   **p,
    int    size )
{
    int  n;
    char s [100];
    strcpy (s, str.c_str ());
    *p++ = strtok (s, ",");
    for (n = 1; NULL != (*p++ = strtok (NULL, ",")); n++)
        if (size == n)
            break;
    return n;
}

//EXAMPLE OF USE
//Source:https://forum.arduino.cc/t/how-to-split-a-string-with-space-and-store-the-items-in-array/888813/6
// String  str= "A1N c2 t120 d4 t0 b5 t0 a2 t368 e2 t452 1c t0 e1 t600";

// void
// setup (void) {
//     Serial.begin (9600);

//     Serial.println (str);

//     int N = separate (str, sPtr, SPTR_SIZE);
//     for (int n = 0; n < N; n++)
//         Serial.println (sPtr [n]);
// }