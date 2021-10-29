#pragma once

#include "Profiles.hpp"

namespace Profiles
{
    uint8_t gProfileCount = 1;
    uint8_t currentProfile = 0;
    uint8_t profileValues[2];

    void initialize(uint8_t profileCount)
    {
        gProfileCount = profileCount;
    }

    void poll()
    {

    }

    void nextProfile()
    {
        uint8_t _nextProfile = currentProfile + 1;
        if (_nextProfile >= gProfileCount) {
            _nextProfile = 0;
        }
        setProfile(_nextProfile);
    }

    void setProfile(uint8_t newProfile)
    {
        currentProfile = newProfile;
    }

    void setProfileValue(uint8_t profileNum, uint8_t profileValue)
    {
        profileValues[profileNum] = profileValue;
        Serial.println(profileValue);
    }

    uint8_t getProfileValue(uint8_t profileNum)
    {
        return profileValues[profileNum];
    }

    uint8_t getCurrentProfileValue()
    {
        return getProfileValue(currentProfile);
    }
}