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
// MLeft1               motor         11              
// MRight1              motor         9               
// MRoller              motor         15              
// MInput1              motor         18              
// MInput2              motor         7               
// MOutput              motor         10              
// MRight2              motor         6               
// MLeft2               motor         8               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "Motor.h"
#include <cmath>
#include <string>

using namespace vex;

// A global instance of competition
competition Competition;

// Define your global instances of motors and other devices here

//OBJECT DECLARATION
//New objects of type motor for better, shorter and more modular functions to control the motors. 
Motor Left("Left");
Motor Right("Right");
Motor Input("Input");
Motor Roller("Roller");
Motor Output("Output");

//VARIABLE DECLARATION
int ds = 200; //To set the speed for when the driver uses an auto-drive for all motors at once
double wheel = 4*3.14;
double width = 15.75*3.14;

//FUNCTION DECLARATION
//Shortening Functions:
void sUp(){
  ds += 25;
  if (ds>200){ds = 0;} } //Adds 10 to the autodrive speed
void sDown(){
  ds -= 25;
  if (ds<0){ds = 200;} } //Removes 10 from the autodrive speed
void wait(int time){vex::task::sleep(time);} //Shorter function for waiting
void clear(){Controller1.Screen.clearScreen();} //Shorter function for clearing the controller screen
template <class T>
void p(T words){Controller1.Screen.print(words);} //Shorter function for printing to the controller screen. 
void newLine(){Controller1.Screen.newLine();} //Shorter function for printing to the controller screen. 

//Function for moving in a line with the drive motors. 
void drives(int speed){Left.go(speed); Right.go(speed);}
//Function for moving in a line with the drive motors. 
void brakes(){Left.stop(); Right.stop();}

//Automated Drive Functions:
double TFD(float dist){return 60000*dist/(wheel*ds);} // Returns the amount of time reuired to travel a given distance at a given speed(milliseconds)
double SFT(int time, float dist){return 60000*dist/(time*wheel);} // Returns the amount of time reuired to travel a given distance at a given speed(milliseconds)
double TFTurnD(int deg){return 0.9*ds-75+ 1.2*60000*(width*(deg/360))/(wheel*ds);} // Returns the amount of time reuired to turn a given degree at a given speed(milliseconds)
double SFTurnT(int time, int deg){
  double value = 9000/time + (1.2*60000*width*(deg/360))/(wheel*time);
  if (value>200){p("Not enough Time"); ds = 200; value = TFTurnD(deg);}
  return value;
  } 
void drive(int speed){Left.go(speed); Right.go(speed);}
void stops(){Left.stop(); Right.stop();}
void turn(int speed){Left.go(speed); Right.go(-speed);}
void goD(float d){ //Function for driving a specific distance. 
  if (d>0){
    Left.go(ds);
    Right.go(ds);
    wait(TFD(d));
  }
  else{
    Left.go(-ds);
    Right.go(-ds);
    wait(TFD(-d));
  }
  Left.stop();
  Right.stop(); 
}
void turnD(float deg){ //Turns clockwise for a certain distance, in degrees. 
  if (deg>0){
    Left.go(ds);
    Right.go(-ds);
    wait(TFTurnD(deg));
  }
  else{
    Left.go(-ds);
    Right.go(ds);
    wait(TFTurnD(-deg));
  }
  Left.stop();
  Right.stop(); 
}
void example(){
  // Written in plain VexCode:
  /*
  MLeft1.spin(vex::directionType::fwd,  200, vex::velocityUnits::rpm);
  vex::task::sleep(500);
  MLeft1.stop(vex::brakeType::brake);
  vex::task::sleep(50);
  MLeft1.stop(vex::brakeType::coast);
  vex::task::sleep(50);
  
  MLeft1.spin(vex::directionType::fwd,  200, vex::velocityUnits::rpm);
  MLeft2.spin(vex::directionType::fwd,  200, vex::velocityUnits::rpm);
  MRight1.spin(vex::directionType::fwd,  200, vex::velocityUnits::rpm);
  MRight2.spin(vex::directionType::fwd,  200, vex::velocityUnits::rpm);
  vex::task::sleep(500);
  MLeft1.stop(vex::brakeType::brake);
  MLeft2.stop(vex::brakeType::brake);
  MRight1.stop(vex::brakeType::brake);
  MRight2.stop(vex::brakeType::brake);
  vex::task::sleep(50);
  MLeft1.stop(vex::brakeType::coast);
  MLeft2.stop(vex::brakeType::coast);
  MRight1.stop(vex::brakeType::coast);
  MRight2.stop(vex::brakeType::coast);
  */

  //Written in our code:
  drives(200);
  wait(500);
  brakes();
}

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
}
  
/*---------------------------------------------------------------------------*/
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  while(1){
    // Roller Control
    if (Controller1.ButtonL1.pressing()){Roller.go(200); Output.go(200);}
    else if (Controller1.ButtonL2.pressing()){Roller.go(200); Output.go(-200);}
    else if (Controller1.ButtonX.pressing()){Roller.go(-200); Output.go(-200);}
    else {Roller.brake1(); Output.brake1(); }
    // Auto Speed Change
    if(Controller1.ButtonRight.pressing()){sUp();}
    if(Controller1.ButtonLeft.pressing()){sDown();}
    // Auto Drive Forward
    if (Controller1.ButtonUp.pressing()){drives(ds);}
    else if (Controller1.ButtonDown.pressing()){drives(-ds);}
    else {
      // Tank Drive Control
      Left.go(Controller1.Axis3.position()*(ds/100));
      Right.go(Controller1.Axis2.position()*(ds/100)); }
    
    //Screen Control
    p("Speed: ");
    p(ds);
    p("; ");
    newLine();
    clear();
    wait(20);// Wait for a short amount of time to prevent wasted resources.
  }
}
/*---------------------------------------------------------------------------*/
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
  brakes();
  Roller.stop();
  Input.stop();
  Output.stop();
}


// Main will set up the competition functions and callbacks.
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
