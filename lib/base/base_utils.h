#ifndef UNO_BASE_H
#define UNO_BASE_H

#include <stdlib.h>
#include <WString.h>
#define BAUD_RATE 9600

namespace baseutils {
    void SerialInit();
    void SerialPrintln(const char* text);
    void SerialClose();

    void SetTypeForDigitalPins(int type, int pins[], size_t arrSize);
    void SetLevelForLED(int pin, int level);
    void SetLevelForPins(int level, int pins[], size_t arrSize);
    void TestDigitalPinsLED(int pins[], size_t arrSize);
}

#endif