#pragma once

#include <TM1637Display.h>
#include "Display.hpp"

#include "Profiles.cpp"

namespace Display
{
    uint8_t CLK;
    uint8_t DIO;
    
    TM1637Display display(0, 0);

    void initialize(uint8_t _CLK, uint8_t _DIO)
    {
        CLK = _CLK;
        DIO = _DIO;

        display = TM1637Display(CLK, DIO);
        display.setBrightness(7);
    }

    void poll()
    {
        uint8_t value = Profiles::getCurrentProfileValue();
        display.showNumberDec(value);
        // Serial.println(value);
    }
}