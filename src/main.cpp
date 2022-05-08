//#include "../lib/modules/blink3.cpp"
//#include "../lib/modules/input_digital_pin02.cpp"
//#include "../lib/modules/input_analog_pin0.cpp"
// #include <modules/AnalogVoltageRead/AnalogVoltageRead.h>

#include "modules/rgb/rgb.h"
#include <Arduino.h>

RgbModule module;

void setup() {
    module.moduleSetup();
}

void loop() {
    module.moduleLoop();
}