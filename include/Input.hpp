#pragma once

namespace Input
{
    void initialize();

    void poll();

    typedef void (*Function)(int pressDuration);

    enum Button : uint8_t {
        MAIN = 0
    };

    void setCallback(Button button, Function cb);
}