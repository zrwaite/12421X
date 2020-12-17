#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor MLeft1 = motor(PORT11, ratio18_1, false);
motor MLeft2 = motor(PORT8, ratio18_1, false);
motor MRight1 = motor(PORT9, ratio18_1, false);
motor MRight2 = motor(PORT5, ratio18_1, false);
motor MRoller = motor(PORT15, ratio18_1, false);
motor MInput1 = motor(PORT18, ratio18_1, false);
motor MInput2 = motor(PORT7, ratio18_1, false);
motor MOutput = motor(PORT10, ratio18_1, false);
controller Controller1 = controller(primary);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}