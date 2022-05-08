#include "base_utils.h"
#include <Arduino.h>

void baseutils::SerialInit() {
    // show serial info
    char info[50];
    Serial.begin(BAUD_RATE);

    sprintf(info, "Serial initialized with %d baud rate", BAUD_RATE);
    Serial.println(info);
}

void baseutils::SerialClose() {
    SerialPrintln("Closing serial");
    Serial.end();
}

void baseutils::SerialPrintln(const char* text) {
    Serial.println(text);
}

void baseutils::SetTypeForDigitalPins(int type, int pins[], size_t arrSize) {
    type = (INPUT || OUTPUT ? type : OUTPUT);

    for (uint32_t i = 0; i < arrSize; i++) {
        int currentPIN = pins[i];
        pinMode(currentPIN, type);
    }
}

void baseutils::SetLevelForLED(int pin, int level) {
    level = (HIGH || LOW ? level : HIGH);

    digitalWrite(pin, level);
}

void baseutils::SetLevelForPins(int level, int pins[], size_t arrSize) {
    level = (HIGH || LOW ? level : HIGH);

    for (uint32_t i = 0; i < arrSize; i++) {
        int currentPIN = pins[i];
        SetLevelForLED(currentPIN, level);
    }
}

void baseutils::TestDigitalPinsLED(int pins[], size_t arrSize) {
    SetLevelForPins(LOW, pins, arrSize);

    for (uint32_t i = 0; i < arrSize; i++) {
        int currentPIN = pins[i];
        SetLevelForLED(currentPIN, HIGH);
        delay(100);
    }
    SetLevelForPins(LOW, pins, arrSize);
    delay(100);
    SetLevelForPins(HIGH, pins, arrSize);
    delay(300);
    SetLevelForPins(LOW, pins, arrSize);
}
