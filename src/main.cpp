#include <Arduino.h>
#include <TM1637Display.h>

// Modules
#include "Input.cpp"

void setup();
void loop();
void onMainButtonPressed(int pressDuration);

void setup()
{
    Serial.begin(115200);
    Input::initialize();
    Input::setCallback(Input::MAIN, &onMainButtonPressed);
}

void loop()
{
    Input::poll();
}

void onMainButtonPressed(int pressDuration)
{
    Serial.print("@ Button Press for");
    Serial.println(pressDuration);
}