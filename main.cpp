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
double circ = 15.97*3.14;
int lSpeed = 0;
int rSpeed = 0;
 
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
 
//Automated Drive Functions:
double TFD(float dist, int speed){return 0.9*60000*dist/(wheel*speed);} // Returns the amount of time reuired to travel a given distance at a given speed(milliseconds)
double SFT(int time, float dist){return 60000*dist/(time*wheel);} // Returns the amount of time reuired to travel a given distance at a given speed(milliseconds)
void drive(int speed = ds){Left.go(speed); Right.go(speed);}
void turn(int speed = ds){Left.go(speed); Right.go(-speed);}
void brake(){
 Left.brake2(); Right.brake2();
 wait(100);
 Left.brake1(); Right.brake1();}
void stop(){Left.brake1(); Right.brake1();}
void aDrive(int dist, int maxSpeed=200){
 //if(dist>(3/2*60000)*wheel*maxSpeed*(3*maxSpeed-1)){ds=69;return;}
 int speed = 0;
 double distTravelled = 0;
 if (dist>0){
   while(speed<maxSpeed){
     drive(speed);
     speed++;
     wait(3);
     distTravelled+=(3*wheel*speed)/60000;
   }
   int ans = TFD(dist-2*distTravelled, maxSpeed);
   drive(maxSpeed);
   wait(ans);
   while(speed>0){
     drive(speed);
     speed--;
     wait(3);
   }
 }
 else{
   while(speed<maxSpeed){
     drive(-speed);
     speed++;
     wait(3);
     distTravelled+=(3*wheel*speed)/60000;
   }
   int ans = TFD(-dist-2*distTravelled, maxSpeed);
   drive(-maxSpeed);
   wait(ans);
   while(speed>0){
     drive(-speed);
     speed--;
     wait(3);
   }
 }
}
void aTurn(double deg, int maxSpeed=200){
 double dist = circ*deg/360.0;
 //if(dist>(1/2*60000)*wheel*maxSpeed*(maxSpeed-1)){ds=69;return;}
 int speed = 0;
 double distTravelled = 0;
 if (dist>0){
   while(speed<maxSpeed){
     turn(speed);
     speed++;
     wait(1);
     distTravelled+=(wheel*speed)/60000;
   }
   int ans = TFD(dist-2*distTravelled, maxSpeed);
   turn(maxSpeed);
   wait(ans+deg/4.0);
   while(speed>0){
     turn(speed);
     speed--;
     wait(1);
   }
 }
 else{
   while(speed<maxSpeed){
     turn(-speed);
     speed++;
     wait(1);
     distTravelled+=(wheel*speed)/60000;
   }
   int ans = TFD(-dist-2*distTravelled, maxSpeed);
   turn(-maxSpeed);
   wait(ans-deg/4.0);
   while(speed>0){
     turn(-speed);
     speed--;
     wait(1);
   }
 }
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
 drive(200);
 wait(500);
 stop();
}
void score(int net){  
 if (net==1){
   Roller.go(-200);
   Output.go(200);
   Input.go(200);
   //drive(-15);
   wait(100);
   drive(30);
   wait(500);
   Roller.stop();
   wait(200);
   Roller.go(-200);
   wait(300);
   drive(10);
   wait(1000);
   drive(-30);
   wait(1000);
   Input.stop();
   wait(200);
 }
 else if(net==2){
   drive(-10);
   wait(50);
   stop();
   Roller.go(-200);
   Output.go(200);
   Input.go(200);
   drive(-20);
   wait(100);
   stop();
   wait(550);
   wait(550);
   drive(-20);
   wait(1200);
 }
 Roller.go(200);
 Output.go(-200);
 Input.go(-200);
 }
void leftAuto(){
 aDrive(15, 100);
 aTurn(-92, 100);
 Input.go(200);
 aDrive(34, 150);
 aTurn(-48, 80);
 Input.stop();
 //First Net
 aDrive(14, 70);
 score(1);
 aDrive(-26, 120);
 wait(400);
 Output.stop();
 Roller.stop();
 Input.stop();
 aTurn(48, 80);
 //Wall Ball
 Input.go(200);
 Roller.go(-200);
 aDrive(24, 100);
 wait(200);
 aDrive(-12, 50);
 Roller.stop();
 aTurn(92, 100);
 aDrive(35, 130);
 aTurn(-88, 100);
 Input.stop();
 //2nd Net
 aDrive(16, 70);
 Left.go(50);
 wait(100);
 score(2);
 aDrive(-5, 50);
 Input.go(-200);
 wait(200);
 aTurn(180, 100);
 Input.go(200);
 Output.stop();
 Roller.go(-200);
 //3rd Net
 aDrive(15, 70);
 wait(200);
 aDrive(20, 100);
 Roller.stop();
 Input.go(-200);
 aDrive(-10, 120);
 aDrive(11, 120);
 aDrive(-10, 120);
 aDrive(11, 120);
 aDrive(-10, 120);
 aDrive(11, 120);
 aDrive(-10, 120);
 aDrive(11, 120);
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
 drive(100);
 wait(100);
 drive(200);
 wait(200);
 drive(-200);
 Roller.go(-200);
 wait(200);
 Roller.stop();
 drive(-100);
 wait(300);
 drive(-50);
 wait(800);
 stop();
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
   if (Controller1.ButtonL1.pressing()){Roller.go(-200); Output.go(200);}
   else if (Controller1.ButtonL2.pressing()){Roller.go(-200); Output.go(-200);}
   else if (Controller1.ButtonX.pressing()){Roller.go(200); Output.go(-200);}
   else if (Controller1.ButtonB.pressing()){Roller.brake1(); Output.brake1(); }
   else {Roller.brake2(); Output.brake2(); }
   if(Controller1.ButtonA.pressing()){pre_auton();}
   //Input Control
   if (Controller1.ButtonR1.pressing()){Input.go(200);}
   else if (Controller1.ButtonR2.pressing()){Input.go(-200);}
   else {Input.brake1();}
   // Auto Speed Change
   if(Controller1.ButtonRight.pressing()){sUp();}
   if(Controller1.ButtonLeft.pressing()){sDown();}
   // Auto Drive Forward
   if (Controller1.ButtonUp.pressing()){drive(ds); }
   else if (Controller1.ButtonDown.pressing()){drive(-ds); }
   else {
     if (Controller1.Axis1.position()>0){
       lSpeed = Controller1.Axis1.position();
       rSpeed = 0;
     } else if (Controller1.Axis1.position()<0){
       rSpeed = -Controller1.Axis1.position();
       lSpeed = 0;
     } else{
       rSpeed = 0;
       lSpeed = 0;
     }
     // Arcade Drive Control
     Left.go((Controller1.Axis3.position()+Controller1.Axis4.position()+lSpeed)*(ds/100.0));
     Right.go((Controller1.Axis3.position()-Controller1.Axis4.position()+rSpeed)*(ds/100.0)); }
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
 pre_auton();
 leftAuto();
 stop();
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
   wait(50, msec);
 }
}
 

