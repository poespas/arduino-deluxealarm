#include <Arduino.h>

// Modules
#include "Input.cpp"
#include "Profiles.cpp"
#include "Display.cpp"
#include "Light.cpp"

void setup();
void loop();
void onMainButtonPressed(int pressDuration);

void setup()
{
    Serial.begin(115200);
    delay(2000);

    Input::initialize();
    Profiles::initialize(2);
    Display::initialize(D5, D6);
    Light::initialize();

    Input::setCallback(Input::MAIN, &onMainButtonPressed);

    Profiles::setProfileValue(0, 5);
    Profiles::setProfileValue(1, 10);
}

void loop()
{
    Input::poll();
    Profiles::poll();
    Display::poll();
    Light::poll();
    delay(10);
}

void onMainButtonPressed(int pressDuration)
{
    Profiles::nextProfile();
}