#pragma once
#include <Adafruit_SSD1306.h>


enum FrogState
{
    Idle,
    Thinking,
    Talking
};

class Frog 
{
    public:
        Frog();

        int getX();
        int getY();

        void draw(Adafruit_SSD1306 &display);

        void update();
        void think();
        
    private:
        int x;
        int y;

        unsigned long lastFrameTime;
        int currentFrame;

        FrogState state;
        unsigned long stateTimer;

        static const int IDLE_X = 39;
        static const int THINKING_X = 5;
};
