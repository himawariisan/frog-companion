#include "WorldState.h"

WorldState::WorldState()
{
    button1Pressed = false;
}

void WorldState::setButton1Pressed(bool pressed)
{
    button1Pressed = pressed;
}

bool WorldState::isButton1Pressed()
{
    return button1Pressed;
}

