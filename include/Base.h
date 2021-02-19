//
// Created by Artem Oliynyk on 17/02/21.
//

#ifndef UNO_01_BASE_H
#define UNO_01_BASE_H

#include <Arduino.h>

#define BAUD_RATE 9600

namespace Base {
    void initSerial() {
        // show serial info
        char info[50];
        Serial.begin(BAUD_RATE);

        sprintf(info, "Serial initialized with %d baud rate", BAUD_RATE);
        Serial.println(info);
    }
}

#endif //UNO_01_BASE_H
