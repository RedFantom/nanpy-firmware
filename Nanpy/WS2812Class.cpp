#include "cfg.h"

#if USE_WS2812

#include <Arduino.h>
#include "BaseClass.h"
#include "MethodDescriptor.h"
#include <stdlib.h>
#include "Adafruit_NeoPixel.h"
#include "WS2812Class.h"

const char* nanpy::WS2812Class::get_firmware_id() {
    return "WS2812";
}

void nanpy::WS2812Class::elaborate(MethodDescriptor* m) {
    ObjectsManager<Adafruit_NeoPixel>::elaborate(m);
    
    /** New Adafruit_NeoPixel instance */
    if (strcmp(m->getName(), "new") == 0) {
        Adafruit_NeoPixel *neopixel = new Adafruit_NeoPixel(
            m->getInt(0), m->getInt(1), m->getInt(2));
        v.insert(neopixel);
        m->returns(v.getLastIndex());
    }
    
    /** begin(void) */
    else if (strcmp(m->getName(), "begin")) {
        v[m->getObjectId()]->begin();
        
    }
    
    /** show(void)*/
    else if (strcmp(m->getName(), "show")) {
        v[m->getObjectId()]->show();
        m->returns(0);
    }
    
    /** setPin(uint8_t p) */
    else if (strcmp(m->getName(), "set_pin")) {
        v[m->getObjectId()]->setPin(m->getInt(0));
        m->returns(0);
    }
        
    /** setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b) */
    else if (strcmp(m->getName(), "set_pixel_color")) {
        v[m->getObjectId()]->setPixelColor(
            m->getInt(0), m->getInt(1), m->getInt(2), m->getInt(3));
        m->returns(0);
    }
    
    /** clear(void) */
    else if (strcmp(m->getName(), "clear")) {
        v[m->getObjectId()]->clear();
        m->returns(0);
    }
}

#endif
