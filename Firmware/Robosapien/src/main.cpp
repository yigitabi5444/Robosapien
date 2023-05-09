#include "servo_lib.h"
#include <Arduino.h>

void setup()
{
    initServo();
    Serial.begin(115200);
}

void loop()
{
    String input = Serial.readStringUntil('\n');
    //parse using ' ' as delimiter
    int spaceIndex = input.indexOf(' ');
    String command = input.substring(0, spaceIndex);
    int id = input.substring(spaceIndex + 1).toInt();
    int pos = input.substring(spaceIndex + 1).toInt();
    if (command == "setServo")
    {
        setServo(id, pos);
    }
    else if (command == "setServoEnabled")
    {
        setServoEnabled(id, pos);
    }
    else
    {
        Serial.println("Invalid command");
    }
}