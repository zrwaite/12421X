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
// MLeft1               motor         1               
// MLeft2               motor         2               
// MRight1              motor         3               
// MRight2              motor         4               
// MRoller              motor         5               
// MInput1              motor         6               
// MInput2              motor         7               
// MOutput              motor         8               
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
int AutoDriveSpeed = 100; //To set the speed for when the driver uses an auto-drive for all motors at once
double temps[8]; //To store the temperature values for all of the motors
double tempIndex = 1; //To store the index for displaying temperatures to the controller screen


//FUNCTION DECLARATION
void SpeedUp(){AutoDriveSpeed += 10;} //Adds 10 to the autodrive speed
void SpeedDown(){AutoDriveSpeed -= 10;} //Removes 10 from the autodrive speed
void wait(int time){vex::task::sleep(time);} //Shorter function for waiting
void clear(){Controller1.Screen.clearScreen();} //Shorter function for clearing the controller screen
template <class T>
void p(T words){Controller1.Screen.print(words);} //Shorter function for printing to the controller screen. 
void newLine(){Controller1.Screen.newLine();} //Shorter function for printing to the controller screen. 

//Variadic drive function takes speed and the names of the motors. 
void goes(int speed, ...){
  //Variadic function commencement
  va_list args;
  va_start(args, speed);
  string names[5]; //Array of names of motors
  int i=0;
  while (i<8){
    char* s = va_arg(args, char * );
    if (s == "Left" || s == "Right" || s == "Input" || s == "Output" || s == "Roller"){names[i] = s;}
    else {break;}
    i++; }
  for (int i2=0; i2<i; i2++){
    if (names[i] == "Left"){Left.go(speed);}
    else if (names[i] == "Right"){Right.go(speed);}
    else if (names[i] == "Input"){Input.go(speed);}
    else if (names[i] == "Output"){Output.go(speed);}
    else if (names[i] == "Roller"){Roller.go(speed);}
    else {break;} }
  va_end(args);
}

//Variadic brake function the names of the motors. 
void stops(string first, ...){
  //Variadic function commencement
  va_list args;
  va_start(args, first);
  string names[5];
  names[0] = first;
  int i=1;
  while (i<8){
    char* s = va_arg(args, char * );
    if (s == "Left" || s == "Right" || s == "Input" || s == "Output" || s == "Roller"){names[i] = s;}
    else {break;}
    i++; }
  //For loop goes through array and brakes the motors that were selected (type:brake)
  for (int i2=0; i2<i; i2++){
    if (names[i] == "Left"){Left.brake1();}
    else if (names[i] == "Right"){Right.brake1();}
    else if (names[i] == "Input"){Input.brake1();}
    else if (names[i] == "Output"){Output.brake1();}
    else if (names[i] == "Roller"){Roller.brake1();} }
  wait(50); //Wait to stop the wheels before coasting
  //For loop goes through array and switches the brakes of the motors that were selected (type:coast)
  for (int i2=0; i2<i; i2++){
    if (names[i] == "Left"){Left.brake2();}
    else if (names[i] == "Right"){Right.brake2();}
    else if (names[i] == "Input"){Input.brake2();}
    else if (names[i] == "Output"){Output.brake2();}
    else if (names[i] == "Roller"){Roller.brake2();} }
  //Variadic function ending
  va_end(args);
}

//Function for moving in a line with the drive motors. 
void drives(int speed){goes(speed, "Left","Right");}

//Function for moving in a line with the drive motors. 
void brakes(){stops("Left", "Right");}

//Function does Error Reporting for temperature
void temp(){
  //Puts current temperatures into temps array
  temps[0] = MLeft1.temperature(percent);
  temps[1] = MLeft2.temperature(percent);
  temps[2] = MRight1.temperature(percent);
  temps[3] = MRight2.temperature(percent);
  temps[4] = MInput1.temperature(percent);
  temps[5] = MInput2.temperature(percent);
  temps[6] = MOutput.temperature(percent);
  temps[7] = MRoller.temperature(percent);
  clear(); //Clears screen
  if (tempIndex >= 9){tempIndex = 1;} //Resets index 

  //Switch scrolls thorugh temperatures on controller screen
  switch (int(floor(tempIndex))){
    case 1:
      p("Left1: "); p(temps[0]); newLine();
      p("Left2: "); p(temps[1]); newLine();
      p("Right1: "); p(temps[2]); newLine();
      break;
    case 2:
      p("Left2: "); p(temps[1]); newLine();
      p("Right1: "); p(temps[2]); newLine();
      p("Right2: "); p(temps[3]); newLine();
      break;
    case 3:
      p("Right1: "); p(temps[2]); newLine();
      p("Right2: "); p(temps[3]); newLine();
      p("Input1: "); p(temps[4]); newLine();
      break;
    case 4:
      p("Right2: "); p(temps[3]); newLine();
      p("Input1: "); p(temps[4]); newLine();
      p("Input2: "); p(temps[5]); newLine();
      break;
    case 5:
      p("Input1: "); p(temps[4]); newLine();
      p("Input2: "); p(temps[5]); newLine();
      p("Output: "); p(temps[6]); newLine();
      break;
    case 6:
      p("Input2: "); p(temps[5]); newLine();
      p("Output: "); p(temps[6]); newLine();
      p("Roller: "); p(temps[7]); newLine();
      break;
    case 7:
      p("Output: "); p(temps[6]); newLine();
      p("Roller: "); p(temps[7]); newLine();
      p("Left1: "); p(temps[0]); newLine();
      break;
    case 8:
      p("Roller: "); p(temps[7]); newLine();
      p("Left1: "); p(temps[0]); newLine();
      p("Left2: "); p(temps[1]); newLine();
      break;
    default:
      p("Error");
  }
  //Increases temp index, so that the screen changes every second
  tempIndex+=0.02;
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
  Left.go(200);
  wait(500);
  Left.stop();

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
  wait(20);// Wait for a short amount of time to prevent wasted resources.
  while(1){

    // Roller Control
    if (Controller1.ButtonL1.pressing()){goes(200, "Roller", "Output");}
    else if (Controller1.ButtonL2.pressing()){
      Roller.go(200);
      Output.go(-200);}
    else if (Controller1.ButtonX.pressing()){goes(-200, "Roller", "Output");}
    else {
      Roller.brake1();
      Output.brake1(); }
  
    // Auto Speed Change
    Controller1.ButtonRight.pressed(SpeedUp);
    Controller1.ButtonLeft.pressed(SpeedDown);

    // Auto Drive Forward
    if (Controller1.ButtonUp.pressing()){drives(AutoDriveSpeed); }
    else if (Controller1.ButtonDown.pressing()){drives(-AutoDriveSpeed); }
    else {
      // Tank Drive Control
      Left.go((Controller1.Axis3.position() * 2));
      Right.go((Controller1.Axis2.position() * 2)); }
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
  stops("Left", "Right", "Input", "Output", "Roller");
}


// Main will set up the competition functions and callbacks.
int main() {
  // Set up callbacks for autonomous and driver control periods.
  //Competition.autonomous(autonomous);
  //Competition.drivercontrol(usercontrol);

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
