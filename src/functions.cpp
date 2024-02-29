#include "robot-config.h"

void IntakeOut()
{
    Intake.set_value(HIGH);
}

void IntakeIn()
{
    Intake.set_value(LOW);
}

void BothWingsOut()
{
    LeftWing.set_value(HIGH);
    RightWing.set_value(HIGH);
}
void BothWingsIn()
{
    LeftWing.set_value(LOW);
    RightWing.set_value(LOW);
}

void LeftWingOut()
{
    LeftWing.set_value(HIGH);
}
void LeftWingIn()
{
    LeftWing.set_value(LOW);
}

void RightWingOut()
{
    RightWing.set_value(HIGH);
}
void RightWingIn()
{
    RightWing.set_value(LOW);
}

