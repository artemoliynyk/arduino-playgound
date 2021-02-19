//
// Created by Artem Oliynyk on 17/02/21.
//

#ifndef UNO_01_FADE_H
#define UNO_01_FADE_H

#include <Base.h>

namespace Fade {
    void module_setup() {
        Base::initSerial();
//        Serial.begin(BAUD_RATE);
//        Serial.write("TEST");
    }

    void module_loop() {

    }
};

#endif //UNO_01_FADE_H
