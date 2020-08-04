#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftDrive1 = motor(PORT8, ratio18_1, false);
motor LeftDrive2 = motor(PORT5, ratio18_1, false);
motor RightDrive1 = motor(PORT4, ratio18_1, true);
motor RightDrive2 = motor(PORT3, ratio18_1, true);
motor LiftMotor = motor(PORT1, ratio36_1, false);
motor ClawMotor1 = motor(PORT12, ratio18_1, false);
motor ClawMotor2 = motor(PORT11, ratio18_1, true);
motor TrayMotor = motor(PORT2, ratio36_1, true);
controller Controller1 = controller(primary);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}