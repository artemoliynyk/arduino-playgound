#define _INC_INPUT_PIN10

#include <Arduino.h>
#include "../ports_uno_ali.h"

namespace input_analog_pin0
{
    void setTypeForAllLED(int type);
    void blink(uint16_t delayT = 500);
    void testAllLED();
    void setLevelForLED(int pin, int level);
    void setLevelForAllLED(int level);
    void setLevelForRange(int max, int level);
}