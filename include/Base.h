//
// Created by Artem Oliynyk on 17/02/21.
//

#ifndef UNO_01_BASE_H
#define UNO_01_BASE_H

#include <Arduino.h>
#include <ports_uno_ali.h>

#define BAUD_RATE 9600

namespace Base {
    void initSerial() {
        // show serial info
        char info[50];
        Serial.begin(BAUD_RATE);

        sprintf(info, "Serial initialized with %d baud rate", BAUD_RATE);
        Serial.println(info);
    }

    void setTypeForDigitalPins(int type, int pins[], size_t arrSize) {
        type = (INPUT || OUTPUT ? type : OUTPUT);

        for (uint32_t i = 0; i < arrSize; i++) {
            int currentPIN = pins[i];
            pinMode(currentPIN, type);
        }
    }

    void setLevelForLED(int pin, int level) {
        level = (HIGH || LOW ? level : HIGH);

        digitalWrite(pin, level);
    }


    void setLevelForPins(int level, int pins[], size_t arrSize) {
        level = (HIGH || LOW ? level : HIGH);

        for (uint32_t i = 0; i < arrSize; i++) {
            int currentPIN = pins[i];
            setLevelForLED(currentPIN, level);
        }
    }

    void testDigitalPinsLED(int pins[], size_t arrSize) {
        setLevelForPins(LOW, pins, arrSize);

        for (uint32_t i = 0; i < arrSize; i++) {
            int currentPIN = pins[i];
            setLevelForLED(currentPIN, HIGH);
            delay(100);
        }
        setLevelForPins(LOW, pins, arrSize);
        delay(100);
        setLevelForPins(HIGH, pins, arrSize);
        delay(300);
        setLevelForPins(LOW, pins, arrSize);
    }
}

#endif //UNO_01_BASE_H
