/**
 * This module perform some basic RGB manipulation.
 *
 * Digital pins wirind:
 *  PIN 10 - blue
 *  PIN 09 - green
 *  PIN 08 - red
 */

#include "rgb.h"

#include <ports_uno_ali.h>

int P_BLUE = PIN10;
int P_GREEN = PIN9;
int P_RED = PIN8;

int PINS[3] = {P_BLUE, P_GREEN, P_RED};

void RgbModule::moduleSetup() {
    baseutils::SerialInit();
    baseutils::SerialPrintln("Starting module rgb");

    baseutils::SetTypeForDigitalPins(OUTPUT, PINS, 3);
}

int level = 0;
int factor = 15;

void RgbModule::moduleLoop() {
    // baseutils::SetLevelForLED(P_BLUE, rand() % 2);
    // baseutils::SetLevelForLED(P_GREEN, rand() % 2);
    // baseutils::SetLevelForLED(P_RED, rand() % 2);

    analogWrite(P_BLUE, level);
    analogWrite(P_GREEN, level);
    analogWrite(P_RED, level);
    delay(200);

    char s[100];
    sprintf(s, "Level: %d", level);
    baseutils::SerialPrintln(s);

    level += factor;
    if (level >= 255 || level <= 0) {
        factor *= -1;
    }
}