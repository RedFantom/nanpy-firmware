#ifndef WS2812_CLASS
#define WS2812_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"

class Adafruit_NeoPixel;


namespace nanpy {
    class WS2812Class: public ObjectsManager<Adafruit_NeoPixel> {
        public:
            void elaborate(nanpy::MethodDescriptor* m);
            const char* get_firmware_id();
    };
}

#endif // WS2812_CLASS
