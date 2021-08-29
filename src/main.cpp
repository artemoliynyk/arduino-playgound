//#include <Arduino.h>

//#include "../lib/modules/blink3.cpp"
//#include "../lib/modules/input_digital_pin02.cpp"
//#include "../lib/modules/input_analog_pin0.cpp"
#include <modules/AnalogVoltageRead/AnalogVoltageRead.h>

//#define WORKSPACE Fade
#define WORKSPACE AnalogVoltageRead

void setup()
{
    WORKSPACE::module_setup();
}

void loop()
{
    WORKSPACE::module_loop();
}