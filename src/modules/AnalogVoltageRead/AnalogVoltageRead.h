/*
 * Created by Artem Oliynyk on 17/02/21.
 * Example implementation: https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fade
*/

#ifndef UNO_VOLTAGE_READ_H
#define UNO_VOLTAGE_READ_H

#include <Base.h>


namespace AnalogVoltageRead {
    const int PINS_USED = 8;
    int pinList[PINS_USED] = {PIN5, PIN6, PIN7, PIN8, PIN9, PIN10, PIN11, PIN12};
//    int pinList[PINS_USED] = {PIN12,PIN11,PIN10,PIN9,PIN8,PIN7,PIN6,PIN5};
//    int pinList[PINS_USED] = {PIN5, PIN7, PIN6, PIN9, PIN8, PIN12, PIN11, PIN10};

    void module_setup() {
        // init serial
        Base::initSerial();

        Base::setTypeForDigitalPins(OUTPUT, pinList, PINS_USED);
        Base::testDigitalPinsLED(pinList, PINS_USED);
    }

    void module_loop() {
        // read the input on analog pin 0:
        int sensorValue = analogRead(A0);

        // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
//        int voltage = sensorValue * (5.0 / 1023.0);
        int voltage = sensorValue * (PINS_USED / 1023.0);

        Base::setLevelForPins(LOW, pinList, PINS_USED);
        Base::setLevelForPins(HIGH, pinList, voltage);

        // print out the value you read:
        Serial.println(voltage);
        Serial.print(" / ");
        Serial.print(sensorValue);
        Serial.println("\n");

    }
};

#endif //UNO_VOLTAGE_READ_H
