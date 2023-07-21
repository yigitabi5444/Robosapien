#include "servo_lib.h"
#include <Arduino.h>

void setup()
{
    initServo();
    Serial.begin(115200);
    for (int i = 0; i < 18; i++)
    {
        setServoEnabled(i, 1);
    }
}

void loop()
{
    String input = Serial.readStringUntil('\n');
    //parse using ' ' as delimiter
    int spaceIndex = input.indexOf(' ');
    String command = input.substring(0, spaceIndex);
    int id = input.substring(spaceIndex + 1).toInt();
    spaceIndex = input.indexOf(' ', spaceIndex + 1);
    int pos = input.substring(spaceIndex + 1).toInt();
    if (command == "setServo")
    {
        setServo(id, pos);
        Serial.println("setServo " + String(id) + " to " + String(pos));
    }
    else if (command == "setServoEnabled")
    {
        setServoEnabled(id, pos);
        Serial.println((pos == 1 ? "Enabled" : "Disabled") + String(" servo id ") + String(id));
    }
}