#ifndef UNO_RGB_1
#define UNO_RGB_1

#include <abstract_module.h>

class RgbModule : public AbstractModule {
   public:
    RgbModule() {}

    ~RgbModule() {}

    virtual void moduleLoop();
    virtual void moduleSetup();
};

#endif