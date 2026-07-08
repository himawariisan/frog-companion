#include <Arduino.h>
#include "Frog.h"

Frog frog;

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    Serial.println(frog.getX());
    delay(1000);
}
