#pragma once
#include <Adafruit_SSD1306.h>
#include "ThoughtGenerator.h"

class WorldState;

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

        void textBubble(Adafruit_SSD1306 &display);

        void update(WorldState &worldState);
        void think();
        
    private:
        int x;
        int y;

        unsigned long lastFrameTime;
        int currentFrame;

        FrogState state;
        unsigned long stateTimer;

        ThoughtGenerator thoughtGenerator;
        String currentThought;

        static const int IDLE_X = 39;
        static const int THINKING_X = 5;
};
