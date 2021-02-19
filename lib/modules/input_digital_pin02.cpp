#define _INC_INPUT_PIN10

#include <Arduino.h>
#include "../ports_uno_ali.h"

namespace input_digital_pin02
{
    void module_setup()
    {
        //start serial connection
        Serial.begin(9600);

        // initialize LED digital pin as an output.
        pinMode(LED_BUILTIN, OUTPUT);
        pinMode(PIN7, OUTPUT);

        pinMode(PIN2, INPUT);

        digitalWrite(LED_BUILTIN, HIGH);
    }

    int prevState = LOW;
    void module_loop()
    {
        int pinState = digitalRead(PIN2);

        if (prevState != pinState)
        {
            prevState = pinState;
            digitalWrite(PIN7, pinState);

            Serial.println(pinState ? "Нажато" : "Не нажато");
        }

        delay(1);
    }
} // namespace input_pin10