#include <Arduino.h>
#include "Frog.h"
#include "sprites.h"

Frog::Frog()
{
    x = 39;
    y = 7;

    lastFrameTime = 0;
    currentFrame = 0;
}

int Frog::getX()
{
    return x;
}

int Frog::getY()
{
    return y;
}

void Frog::setX(int newX)
{
    x = newX;
}

void Frog::draw(Adafruit_SSD1306 &display)
{
    static const unsigned char* frames[] =
    {
        epd_bitmap_f_breathe_1,
        epd_bitmap_f_breathe_2,
        epd_bitmap_f_breathe_3,
        epd_bitmap_f_breathe_2
    };

    display.drawBitmap(
        x,
        y,
        frames[currentFrame],
        50,
        50,
        SSD1306_WHITE
    );
}

void Frog::update()
{
    if(millis() - lastFrameTime >= 400)
    {
        lastFrameTime = millis();
        currentFrame++;
        if(currentFrame > 3) currentFrame = 0;
    }
}

void Frog::think()
{
    // Implement the frog's thinking logic
}
