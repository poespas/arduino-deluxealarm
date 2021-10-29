#pragma once

namespace Profiles
{
    void initialize();

    void poll();

    void nextProfile();

    void setProfile(uint8_t newProfile);

    void setProfileValue(uint8_t profileNum, uint8_t profileValue);

    uint8_t getProfileValue(uint8_t profileNum);

    uint8_t getCurrentProfileValue();
}