#define _INC_INPUT_PIN10

#include <Arduino.h>
#include <ports_uno_ali.h>
#include "input_analog_pin0.h"

namespace input_analog_pin0
{
    int leds[6] = {PIN2, PIN3, PIN4, PIN5, PIN6, PIN7};

    void setTypeForAllLED(int type)
    {
        type = (INPUT || OUTPUT ? type : OUTPUT);

        for (int i = 0; i < 6; i++)
        {
            int currentPIN = leds[i];
            pinMode(currentPIN, type);
        }
    }

    void blink(uint16_t delayT)
    {
        // on, wait and off
        setLevelForAllLED(HIGH);
        delay(delayT);
        setLevelForAllLED(LOW);
    }


    void testAllLED()
    {
        blink(200);

        for (int i = 0; i < 6; i++)
        {
            int currentPIN = leds[i];
            digitalWrite(currentPIN, HIGH);
            delay(200);
            digitalWrite(currentPIN, LOW);
        }
        
        blink(500);

    }

    void setLevelForLED(int pin, int level)
    {
        level = (HIGH || LOW ? level : HIGH);

        digitalWrite(pin, level);
    }

    void setLevelForAllLED(int level)
    {
        // // initialize LED digital pin as an output.
        for (int i = 0; i < 6; i++)
        {
            int currentPIN = leds[i];
            setLevelForLED(currentPIN, level);
        }
    }

    void setLevelForRange(int max, int level)
    {
        // // initialize LED digital pin as an output.
        for (int i = 0; i < max; i++)
        {
            int currentPIN = leds[i];
            setLevelForLED(currentPIN, level);
        }
    }

    void module_setup()
    {
        //start serial connection
        Serial.begin(9600);

        // set types and test all
        setTypeForAllLED(OUTPUT);
        testAllLED();

        // status
        pinMode(LED_BUILTIN, OUTPUT);
        digitalWrite(LED_BUILTIN, HIGH);
    }

    int prevState = LOW;
    void module_loop()
    {
        int stateA0 = analogRead(PIN_A0);
        int litCount = (stateA0 / 170);

        setLevelForAllLED(LOW);
        setLevelForRange(litCount, HIGH);

        Serial.println(stateA0);
        Serial.println(stateA0 / 170);
        Serial.println("");

        delay(1);
    }
} // namespace input_analog_pin0
