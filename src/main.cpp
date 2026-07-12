#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include "Frog.h"
#include "sprites.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

#define BUTTON_1 23

Frog frog;

Adafruit_SSD1306 display(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,
    OLED_RESET
);

void setup()
{
    Serial.begin(115200);
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        while (true);
    }

    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);  

    pinMode(BUTTON_1, INPUT_PULLUP);

    display.display();
}

void loop()
{
    display.clearDisplay();

    if (digitalRead(BUTTON_1) == LOW)
    {
        frog.think();
    }

    frog.update();
    frog.draw(display);

    display.display();
}
