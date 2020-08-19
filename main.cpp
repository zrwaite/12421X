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

/*--------------------------|PID Auto Functions|--------------------------*/


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
Motor Left1("Left1");

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
  LeftDrive1.stop(vex::brakeType::brake);
  vex::task::sleep(50);
  LeftDrive1.stop(vex::brakeType::coast);
  vex::task::sleep(50);
  LeftDrive1.spin(vex::directionType::rev,  200, vex::velocityUnits::rpm);
  LeftDrive1.stop(vex::brakeType::brake);
  vex::task::sleep(50);
  LeftDrive1.stop(vex::brakeType::coast);
  vex::task::sleep(50);

  */
  Left1.drive(200);
  Left1.stop();
  Left1.drive(-200);
  Left1.stop();

}