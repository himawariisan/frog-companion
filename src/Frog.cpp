#include <Arduino.h>
#include "Frog.h"
#include "sprites.h"
#include "WorldState.h"


Frog::Frog()
{
    x = 39;
    y = 7;

    lastFrameTime = 0;
    currentFrame = 0;

    state = Idle;
    stateTimer = 0;
}

int Frog::getX()
{
    return x;
}

int Frog::getY()
{
    return y;
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

    textBubble(display);
}

void Frog::textBubble(Adafruit_SSD1306 &display)
{
    if(state == Talking)
    {
        display.drawRoundRect(65, 5, 60, 50, 8, SSD1306_WHITE);
        display.setCursor(60, 5);
        display.println(currentThought);
    }
}

void Frog::update(WorldState &worldState)
{
    if(millis() - lastFrameTime >= 400)
    {
        lastFrameTime = millis();
        currentFrame++;
        if(currentFrame > 3) currentFrame = 0;
    }

    if(worldState.isButton1Pressed())
    {
        worldState.setButton1Pressed(false);
        think();
    }

    switch(state)
    {
        case Idle:
            break;

        case Thinking:
            if(millis() - stateTimer >= 3000)
            {
                state = Talking;
                currentThought = thoughtGenerator.generateThought();
                stateTimer = millis();
            }
            break;

        case Talking:
            if(millis() - stateTimer >= 10000)
            {
                x = IDLE_X;
                state = Idle;
            }
            break;
    }
}

void Frog::think()
{
    if(state != Idle)
        return;
    
    state = Thinking;
    x = THINKING_X;
    stateTimer = millis();
}
