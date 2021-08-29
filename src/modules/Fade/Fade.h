/*
 * Created by Artem Oliynyk on 17/02/21.
 * Example implementation: https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fade
*/

#ifndef UNO_01_FADE_H
#define UNO_01_FADE_H

#include <Base.h>

namespace Fade {
    int brightnessRed = 0;    // how bright the LED is
    int brightnessBlue = 255;    // how bright the LED is
    int fadeAmount = 51;

    void module_setup() {
        // init serial
        Base::initSerial();

        // declare pin 9 to be an output:
        pinMode(PIN9, OUTPUT);
        pinMode(PIN11, OUTPUT);
    }

    void module_loop() {
        analogWrite(PIN9, brightnessRed);

        brightnessRed = brightnessRed + fadeAmount;
//        // reverse the direction of the fading at the ends of the fade:
//        if (brightnessRed <= 0 || brightnessRed >= 255) {
//            fadeAmount = -fadeAmount;
//        }


        analogWrite(PIN11, brightnessBlue);

        brightnessBlue = brightnessBlue + (fadeAmount * -1);
        // reverse the direction of the fading at the ends of the fade:
        if (brightnessBlue <= 0 || brightnessBlue >= 255) {
            fadeAmount = -fadeAmount;
        }

        Serial.print("Fade Amount: ");
        Serial.println(fadeAmount);

        Serial.print("Brightness Red: ");
        Serial.println(brightnessRed);

        Serial.print("Brightness Blue: ");
        Serial.println(brightnessBlue);

        // wait
        delay(5);
        Serial.println("\n");
        Serial.clearWriteError();
    }
};

#endif //UNO_01_FADE_H
