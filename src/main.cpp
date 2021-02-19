//#include <Arduino.h>

//#include "../lib/modules/blink3.cpp"
//#include "../lib/modules/input_digital_pin02.cpp"
//#include "../lib/modules/input_analog_pin0.cpp"
#include "Fade/Fade.h"

#define WORKSPACE Fade

void setup()
{
    // blink3::module_setup();
    // input_digital_pin02::module_setup();
    WORKSPACE::module_setup();
}

void loop()
{
    // blink3::module_loop();
    // input_digital_pin02::module_loop();
    WORKSPACE::module_loop();
}