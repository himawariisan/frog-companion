#pragma once
#include <Adafruit_SSD1306.h>


class Frog 
{
    public:
        Frog();

        int getX();
        int getY();
        void setX(int newX);

        void draw(Adafruit_SSD1306 &display);

        void update();
        void think();
        
    private:
        int x;
        int y;
        unsigned long lastFrameTime;
        int currentFrame;
};
