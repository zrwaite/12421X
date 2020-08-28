/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// MLeft1               motor         8               
// MLeft2               motor         5               
// MRight1              motor         4               
// MRight2              motor         3               
// MRoller              motor         1               
// MInput1              motor         12              
// MInput2              motor         11              
// MOutput              motor         2               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "Motor.h"
#include <cmath>

using namespace vex;

// A global instance of competition
competition Competition;

// Define your global instances of motors and other devices here
Motor Left1("Left1");
Motor Left2("Left2");
Motor Right1("Right1");
Motor Right2("Right2");
Motor Input1("Input1");
Motor Input2("Input2");
Motor Roller("Roller");
Motor Output("Output");

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  
    // Sleep the task for a short amount of time to prevent wasted resources.
    vex::task::sleep(20);
    while(1){
      Left1.drive(Controller1.Axis3.position());
      Left2.drive(Controller1.Axis3.position());
      Right1.drive(Controller1.Axis2.position());
      Right2.drive(Controller1.Axis2.position());
    

    wait(20, msec); // Sleep the task for a short amount of time to prevent wasted resources.
    }
}

//Shorter wait function in milliseconds. 
void wait(int time){
  vex::task::sleep(time);
}

//Function takes Speed,  number of motors, and the names of the motors to be turned on. 
void drives(int speed, int num, ...){
  va_list args;
  va_start(args, num);
  string names[num];
  for (int i=0; i<num; i++){
    char* s = va_arg(args, char * );
    names[i] = s;
  }
  for (int i=0; i<num; i++){
    if (names[i] == "Left1"){Left1.drive(speed);}
    else if (names[i] == "Left2"){Left2.drive(speed);}
    else if (names[i] == "Right1"){Right1.drive(speed);}
    else if (names[i] == "Right2"){Right2.drive(speed);}
    else if (names[i] == "Input1"){Input1.drive(speed);}
    else if (names[i] == "Input2"){Input2.drive(speed);}
    else if (names[i] == "Output"){Output.drive(speed);}
    else if (names[i] == "Roller"){Roller.drive(speed);}
  }
  va_end(args);
}
//Function takes number of motors, and the names of the motors to be turned off. 
void stops(int num, ...){
  va_list args;
  va_start(args, num);
  string names[num];
  for (int i=0; i<num; i++){
    char* s = va_arg(args, char * );
    names[i] = s;
  }
  for (int i=0; i<num; i++){
    if (names[i] == "Left1"){Left1.brake1();}
    else if (names[i] == "Left2"){Left2.brake1();}
    else if (names[i] == "Right1"){Right1.brake1();}
    else if (names[i] == "Right2"){Right2.brake1();}
    else if (names[i] == "Input1"){Input1.brake1();}
    else if (names[i] == "Input2"){Input2.brake1();}
    else if (names[i] == "Output"){Output.brake1();}
    else if (names[i] == "Roller"){Roller.brake1();}
  }
  wait(50);
  for (int i=0; i<num; i++){
    if (names[i] == "Left1"){Left1.brake2();}
    else if (names[i] == "Left2"){Left2.brake2();}
    else if (names[i] == "Right1"){Right1.brake2();}
    else if (names[i] == "Right2"){Right2.brake2();}
    else if (names[i] == "Input1"){Input1.brake2();}
    else if (names[i] == "Input2"){Input2.brake2();}
    else if (names[i] == "Output"){Output.brake2();}
    else if (names[i] == "Roller"){Roller.brake2();}
  }
  va_end(args);
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  //Competition.autonomous(autonomous);
  //Competition.drivercontrol(usercontrol);

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}


void example(){
  /*
  LeftDrive1.spin(vex::directionType::fwd,  200, vex::velocityUnits::rpm);
  vex::task::sleep(500);
  LeftDrive1.stop(vex::brakeType::brake);
  vex::task::sleep(50);
  LeftDrive1.stop(vex::brakeType::coast);
  vex::task::sleep(50);

  LeftDrive1.spin(vex::directionType::fwd,  200, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd,  200, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd,  200, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd,  200, vex::velocityUnits::rpm);
  vex::task::sleep(500);
  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);
  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  */
  Left1.drive(200);
  wait(500);
  Left1.stop();

  drives(200, 4, "Left1", "Left2","Right1", "Right2");
  wait(500);
  stops(4, "Left1", "Left2","Right1", "Right2");
}