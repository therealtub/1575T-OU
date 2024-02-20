#include "robot-config.h"

void IntakeOut()
{
    Intake.set_value(HIGH);
}

void IntakeIn()
{
    Intake.set_value(LOW);
}

void WingsOut()
{
    Wings.set_value(HIGH);
}
void WingsIn()
{
    Wings.set_value(LOW);
}