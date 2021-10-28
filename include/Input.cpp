#pragma once

#include "Input.hpp"

#define INPUT_HIGH !HIGH

namespace Input
{
    const uint8_t cButtonCount = 1;

    Function gCallback[cButtonCount];
    int gDuration[cButtonCount];

    void initialize()
    {
        pinMode(D1, INPUT);
    }

    void setCallback(Button button, Function cb)
    {
        gCallback[static_cast<uint8_t>(button)] = cb;
    }

    void poll()
    {
        for (int i = 0; i < cButtonCount; i++) {
            int result = digitalRead(D1);

            if (result == INPUT_HIGH) {
                gDuration[i]++;
            }
            else if (gDuration[i] != 0) {
                gCallback[i](gDuration[i]);
                gDuration[i] = 0;
            }
        }
    }
}