#include <Arduino.h>
#include <TM1637Display.h>

// Structure:
//  - Animations
//  - Initializer
//  - Actions
//  - Web
//  -

// Pin layout
#define CLK D5
#define DIO D6
#define BTN D1
#define LED1 D2
#define LED2 D3

// The amount of time (in milliseconds) between tests
#define TEST_DELAY 2000

int CURRENT_PROFILE = 0;
int MAX_PROFILES = 2;
int BRIGHTNESS = 7;

uint8_t PROFILE1_VALUE[] = {
    SEG_A | SEG_B | SEG_G | SEG_F | SEG_E, // P
    SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F, // O
    SEG_A | SEG_D | SEG_E | SEG_F | SEG_G, // E
    SEG_A | SEG_F | SEG_G | SEG_C | SEG_D  // S
};
int PROFILE1_ALERT = 0;

uint8_t PROFILE2_VALUE[] = {
    SEG_A | SEG_B | SEG_G | SEG_F | SEG_E, // P
    SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G, // A
    SEG_A | SEG_F | SEG_G | SEG_C | SEG_D,  // S
    0
};

int PROFILE2_ALERT = 0;

// Loading animation
const uint8_t ALL_ON[] = {0xff, 0xff, 0xff, 0xff};
const uint8_t ALL_OFF[] = {0x0, 0x0, 0x0, 0x0};

TM1637Display display(CLK, DIO);

void onButtonPress();
void updateDisplay();
void nextProfile();

void setup()
{
    // Set up presets
    CURRENT_PROFILE = 0;
    MAX_PROFILES = 2;
    display.setBrightness(7);
    pinMode(BTN, INPUT);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    Serial.begin(115200);
    display.setSegments(ALL_ON);
    delay(1000);

    display.setSegments(ALL_OFF);
    delay(1000);

    for (int i = 0; i <= 100; i++)
    {
        display.showNumberDec(i);
        delay(5);
    }

    display.setSegments(ALL_OFF);
    Serial.println("Load completed");
}

int tick = 0;

void loop()
{
    delay(10);
    // is being pressed
    int is_pressed = !digitalRead(BTN);
    if (is_pressed == HIGH)
    {
        onButtonPress();
    }

    if (tick % 100 == 0)
    {
        updateDisplay();
        Serial.println("Updating display..");
    }
    tick++;
}

void onButtonPress()
{
    Serial.println("User pressed button..");
    // Wait until you lose press
    int pressedMs = 0;

    int is_pressed = HIGH;
    while (is_pressed == HIGH)
    {
        is_pressed = !digitalRead(BTN);
        Serial.println(is_pressed);

        pressedMs++;
        delay(1);
    }

    Serial.println(pressedMs);

    if (pressedMs < 1000)
    {
        nextProfile();
    }
}

void updateDisplay()
{
    if (CURRENT_PROFILE == 0)
    {
        display.setSegments(PROFILE1_VALUE);
        digitalWrite(LED2, LOW);
        digitalWrite(LED1, HIGH);
    }
    if (CURRENT_PROFILE == 1)
    {
        display.setSegments(PROFILE2_VALUE);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);
    }
}

void setCurrentProfile(int newProfile)
{
    CURRENT_PROFILE = newProfile;
}

void nextProfile()
{
    CURRENT_PROFILE++;

    if (CURRENT_PROFILE == MAX_PROFILES)
    {
        CURRENT_PROFILE = 0;
    }
}