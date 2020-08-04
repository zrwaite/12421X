using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LeftDrive1;
extern motor LeftDrive2;
extern motor RightDrive1;
extern motor RightDrive2;
extern motor LiftMotor;
extern motor ClawMotor1;
extern motor ClawMotor2;
extern motor TrayMotor;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );