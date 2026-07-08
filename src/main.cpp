#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include "Frog.h"
#include "sprites.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

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

    display.display();
}

void loop()
{
    display.clearDisplay();

    display.setCursor(0, 0);

    display.drawBitmap(
      frog.getX(),
      frog.getY(),
      epd_bitmap_f_breathe_1,
      50,
      50,
      SSD1306_WHITE
    );

    display.display();

    delay(1000);
}
