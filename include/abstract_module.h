#ifndef UNO_ABSTRACT_MODULE
#define UNO_ABSTRACT_MODULE

#include <base_utils.h>
#include <Arduino.h>

class AbstractModule {
   public:
    virtual void moduleSetup();
    virtual void moduleLoop();

    AbstractModule() {
        // baseutils::SerialInit();
        // baseutils::SerialPrintln("Starting module");
    }
};

#endif