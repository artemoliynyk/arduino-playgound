#define _INC_BLINK3

#include <Arduino.h>
#include "../ports_uno_ali.h"

namespace blink3
{

    void module_setup()
    {
        // initialize LED digital pin as an output.
        pinMode(LED_BUILTIN, OUTPUT);
        pinMode(PIN2, OUTPUT);
        pinMode(PIN3, OUTPUT);
        pinMode(PIN4, OUTPUT);

        digitalWrite(LED_BUILTIN, HIGH);
    }

    int delayTime = 200;

    void module_loop()
    {
        digitalWrite(PIN2, HIGH);
        digitalWrite(PIN3, LOW);
        digitalWrite(PIN4, LOW);
        delay(delayTime);

        digitalWrite(PIN2, LOW);
        digitalWrite(PIN3, HIGH);
        digitalWrite(PIN4, LOW);
        delay(delayTime);

        digitalWrite(PIN2, LOW);
        digitalWrite(PIN3, LOW);
        digitalWrite(PIN4, HIGH);
        delay(delayTime);
    }
} // namespace blink3