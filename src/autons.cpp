#include "main.h"
#include "functions.h"
/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 110; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;



///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void one_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void two_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

// DO NOT TOUCH ABOVE
//efopyz
//dgnqx
//chmrw
//bilsv
//
// DO NOT TOUCH

void quals_far()
{
    IntakeOut();
    chassis.set_drive_pid(30, 127, false);
    chassis.wait_drive();
    IntakeIn();
    chassis.set_drive_pid(-90.5, 100, false);
    chassis.wait_drive();
    chassis.set_turn_pid(180, 100);
    chassis.wait_drive();
    chassis.set_drive_pid(25.5, 100, false);
    chassis.wait_drive();
    chassis.set_turn_pid(135, 100);
    chassis.wait_drive();
    RightWingOut();
    IntakeOut();
    chassis.set_drive_pid(55, 100, false);
    chassis.wait_drive();
    // chassis.set_swing_pid(ez::RIGHT_SWING, 90, 100);
    chassis.set_turn_pid(90, 100);
    chassis.wait_drive();
    chassis.set_drive_pid(35, 100, false);
    chassis.wait_drive();
    chassis.set_drive_pid(-45, 100, false);
    chassis.wait_drive();
    IntakeIn();
    RightWingIn();
    chassis.set_turn_pid(270, 100);
    chassis.wait_drive();
    BothWingsOut();
    chassis.set_drive_pid(-45, 100, false);
    chassis.wait_drive();
    BothWingsIn();
    chassis.set_drive_pid(45, 100, false);
    chassis.wait_drive();
    chassis.set_turn_pid(135, 100);
    chassis.wait_drive();
    chassis.set_drive_pid(-47.5, 100, false);
    chassis.wait_drive();
    chassis.set_turn_pid(177.5, 127);
    chassis.wait_drive();
    chassis.set_drive_pid(-96.5, 40, false);
    chassis.wait_drive();
}

//void fifteensec_blue()
// {
//   IntakeIn();
//   BothWingsOut();
//   chassis.set_drive_pid(50, 100, false);
//   chassis.wait_drive();

//   chassis.set_turn_pid(45, 100);
//   chassis.wait_drive();

//   IntakeOut();

//   chassis.set_drive_pid(45, 100, false);
//   chassis.wait_drive();

//   chassis.set_drive_pid(-40, 100, false);
//   chassis.wait_drive();

//   BothWingsIn();

//   chassis.set_turn_pid(225, 100);
//   chassis.wait_drive();

//   BothWingsOut();

//   chassis.set_drive_pid(-45, 100, false);
//   chassis.wait_drive();
  
//   chassis.set_drive_pid(45, 100, false);
//   chassis.wait_drive();

//   chassis.set_drive_pid(-50, 100, false);
//   chassis.wait_drive();
  
//   chassis.set_drive_pid(50, 100, false);
//   chassis.wait_drive();


//   BothWingsIn();

//   chassis.set_turn_pid(0, 100);
//   chassis.wait_drive();

//   chassis.set_drive_pid(-45, 100);
//   chassis.wait_drive();

//   chassis.set_turn_pid(-45, 100);
//   chassis.wait_drive();
// }

// void fifteensec_red()
// {
//   IntakeIn();
//   BothWingsOut();
//   chassis.set_drive_pid(50, 100, false);
//   chassis.wait_drive();

//   chassis.set_turn_pid(-45, 100);
//   chassis.wait_drive();

//   IntakeOut();

//   chassis.set_drive_pid(45, 100, false);
//   chassis.wait_drive();

//   chassis.set_drive_pid(-40, 100, false);
//   chassis.wait_drive();

//   BothWingsIn();

//   chassis.set_turn_pid(-225, 100);
//   chassis.wait_drive();

//   BothWingsOut();

//   chassis.set_drive_pid(-45, 100, false);
//   chassis.wait_drive();
  
//   chassis.set_drive_pid(45, 100, false);
//   chassis.wait_drive();

//   chassis.set_drive_pid(-50, 100, false);
//   chassis.wait_drive();
  
//   chassis.set_drive_pid(50, 100, false);
//   chassis.wait_drive();


//   BothWingsIn();

//   chassis.set_turn_pid(0, 100);
//   chassis.wait_drive();

//   chassis.set_drive_pid(-45, 100);
//   chassis.wait_drive();

//   chassis.set_turn_pid(45, 100);
//   chassis.wait_drive();
// }

// void fifteensec_blue1()
// {
// // releases the wings and intake so that we can get it out the barrier
//   IntakeIn();
//   BothWingsOut();
// // moves right in front of the triball
//   chassis.set_drive_pid(65, 100, false);
//   chassis.wait_drive();
// // gets it out of the barrier
//   chassis.set_turn_pid(45, 100);
//   chassis.wait_drive();

//   IntakeOut();
// // jams it into the goal
//   chassis.set_drive_pid(45, 100, false);
//   chassis.wait_drive();

//   chassis.set_drive_pid(-40, 100, false);
//   chassis.wait_drive();
// // uses the wings to plow the rest of the triball into the goal.
//   BothWingsIn();

//   chassis.set_turn_pid(225, 100);
//   chassis.wait_drive();

//   BothWingsOut();

//   chassis.set_drive_pid(-45, 100, false);
//   chassis.wait_drive();

//   chassis.set_drive_pid(45, 100, false);
//   chassis.wait_drive();

//   chassis.set_drive_pid(-50, 100, false);
//   chassis.wait_drive();

//   chassis.set_drive_pid(50, 100, false);
//   chassis.wait_drive();
//   // then turns parallel to the matchload bar
//   BothWingsIn();

//   chassis.set_turn_pid(0, 100);
//   chassis.wait_drive();
// // drives to the end
//   chassis.set_drive_pid(-45, 100);
//   chassis.wait_drive();
// // faces the barrier
//   chassis.set_turn_pid(-45, 100);
//   chassis.wait_drive();
// // touches the barrier
//   chassis.set_drive_pid(-80.5, 50, false);
//   chassis.wait_drive();
// }

// void fifteensec_red1()
// {
//   // releases the wings and intake so that we can get it out the barrier
//   IntakeIn();
//   BothWingsOut();
//   // moves right in front of the triball
//   chassis.set_drive_pid(65, 100, false);
//   chassis.wait_drive();
// // gets it out of the barrier
//   chassis.set_turn_pid(-45, 100);
//   chassis.wait_drive();

//   IntakeOut();
// // jams it into the goal
//   chassis.set_drive_pid(45, 100, false);
//   chassis.wait_drive();

//   chassis.set_drive_pid(-40, 100, false);
//   chassis.wait_drive();
// // uses the wings to plow the rest of the triball into the goal.
//   BothWingsIn();

//   chassis.set_turn_pid(-225, 100);
//   chassis.wait_drive();

//   BothWingsOut();

//   chassis.set_drive_pid(-45, 100, false);
//   chassis.wait_drive();
  
//   chassis.set_drive_pid(45, 100, false);
//   chassis.wait_drive();

//   chassis.set_drive_pid(-50, 100, false);
//   chassis.wait_drive();
  
//   chassis.set_drive_pid(50, 100, false);
//   chassis.wait_drive();
//   // then turns parallel to the matchload bar

//   BothWingsIn();

//   chassis.set_turn_pid(0, 100);
//   chassis.wait_drive();
// // drives to the end

//   chassis.set_drive_pid(-45, 100);
//   chassis.wait_drive();
// // faces the barrier

//   chassis.set_turn_pid(45, 100);
//   chassis.wait_drive();
// // touches the barrier

//   chassis.set_drive_pid(-80.5, 50, false);
//   chassis.wait_drive();
// }

void skills()
{
  // removes flywheel code because of puncher
  // Flywheel_PROTO.move(-127);

  // makes robot move backward 7 inches
  chassis.set_drive_pid(-70, 100, false);
  chassis.wait_drive();

  // then makes the robot turn 45 degrees
  chassis.set_turn_pid(45, 100);
  chassis.wait_drive();

  // makes robot move forward 6 inches
  chassis.set_drive_pid(-60, 100, false);
  chassis.wait_drive();

  // makes robot move backward 6 inches
  chassis.set_drive_pid(60, 100, false);
  chassis.wait_drive();
  
  chassis.set_turn_pid(115, 100);
  chassis.wait_drive();

  chassis.set_drive_pid(10, 100);
  chassis.wait_drive();

  pros::delay(25000);

  // Flywheel_PROTO.move(0);
  // // m0akes robot turn 0 degrees (face the value from the beginning)

  chassis.set_turn_pid(0, 100);
  chassis.wait_drive();
  
  // makes robot move forward 7.7 inches
  chassis.set_drive_pid(70, 100, false);
  chassis.wait_drive();

  // makes robot turn 135 degrees
  chassis.set_turn_pid(135, 100);
  chassis.wait_drive();

  // makes robot move forward 25.5 inches
  chassis.set_drive_pid(-235, 100, true);
  chassis.wait_drive();

  //sets the robot degree (heading) to 0
  chassis.reset_gyro();

  //turn 45
  chassis.set_turn_pid(-45, 100);
  chassis.wait_drive();

  //drive 5 in
  chassis.set_drive_pid(-85.7, 100);
  chassis.wait_drive();

  //turns 90
  chassis.set_turn_pid(-90, 100);
  chassis.wait_drive();

  //drives 5.9 in
  chassis.set_drive_pid(-55, 100);
  chassis.wait_drive();

  //drives 4.5 in
  chassis.set_drive_pid(55, 100);
  chassis.wait_drive();

  //drives 5.9 in
  chassis.set_drive_pid(-55, 100);
  chassis.wait_drive();

  //drives 4.5 in
  chassis.set_drive_pid(45, 100);
  chassis.wait_drive();

  chassis.set_turn_pid(0, 100);
  chassis.wait_drive();

  chassis.set_drive_pid(45, 100, false);
  chassis.wait_drive();
  
  chassis.set_turn_pid(45, 100);
  chassis.wait_drive();

  chassis.set_drive_pid(95, 100);
  chassis.wait_drive();

  //turns bot to plow triballs in center goal
  chassis.set_turn_pid(-25, 100);
  chassis.wait_drive();

  BothWingsOut();
  // plows triballs
  chassis.set_drive_pid(-85, 127, true);
  chassis.wait_drive();

  chassis.set_drive_pid(85, 127, true);
  chassis.wait_drive();

  BothWingsIn();
  // moves to front
  chassis.set_turn_pid(-70, 100);
  chassis.wait_drive();
  
  chassis.set_drive_pid(-60, 100);
  chassis.wait_drive();

  chassis.set_turn_pid(0, 100);
  chassis.wait_drive();

  BothWingsOut();
 // plows the rest
  chassis.set_drive_pid(-75, 127, true);
  chassis.wait_drive();

  chassis.set_drive_pid(75, 127, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-75, 127, true);
  chassis.wait_drive();

  chassis.set_drive_pid(75, 127, true);
  chassis.wait_drive();

  BothWingsIn();
}
void ranpo_skills(){
  //rei's code practices Below:
  //This moves the robot back 7 70=7in
  chassis.set_drive_pid(-70,100,false);
  chassis.wait_drive();
  
  chassis.set_drive_pid(-70,100,false);

}
void intake_skills()
{
  IntakeOut();
  chassis.set_drive_pid(27.5, 127);
  chassis.wait_drive();
  IntakeIn();
  chassis.set_drive_pid(-125, 65);
  chassis.wait_drive();
}