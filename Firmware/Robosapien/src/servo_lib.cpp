#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "servo_lib.h"

Servo servos[9];

int servoEnabled[18] = {0};

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 150  // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 600  // This is the 'maximum' pulse length count (out of 4096)
#define USMIN 600     // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX 2400    // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

void initServo()
{
    // for (int i = 0; i < 9; i++)
    // {
    //     servos[i].attach(servo_pins[i]);
    // }

    pwm.begin();
    pwm.setOscillatorFrequency(27000000);
    pwm.setPWMFreq(SERVO_FREQ); // Analog servos run at ~50 Hz updates

    for (int i = 0; i < 9; i++)
    {
        pwm.setPWM(i, 0, 0);
    }

    delay(10);
}

void setServo(int id, int pos)
{
    if (!servoEnabled[id])
    {
        return;
    }

    if (id < 9)
    {
        servos[id].write(pos);
    }
    else
    {
        pwm.setPWM(id - 9, 0, map(pos, 0, 180, SERVOMIN, SERVOMAX));
    }
}

void setServoEnabled(int id, bool enabled)
{
    if (id < 9)
    {
        if (enabled)
        {
            servos[id].attach(servo_pins[id]);
        }
        else
        {
            servos[id].detach();
        }
    }
    else
    {
        if (enabled)
        {
            pwm.setPWM(id - 9, 0, SERVOMIN);
        }
        else
        {
            pwm.setPWM(id - 9, 0, 0);
        }
    }

    servoEnabled[id] = enabled;
}