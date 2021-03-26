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
vex::motor motors [8] = {
  MLeft1, 
  MLeft2,
  MRight1,
  MRight2,
  MRoller,
  MInput1,
  MInput2,
  MOutput,
  };
int motori = 0;
int motornum = 0;
int motortemp = 0;
 
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
void wallballside(){
  Input.go(-200);
  //Leave First Net
 for (int i=50; i<=200; i+=50){
   drive(-i);
   wait(30);
 }
 wait(480);
 for (int i=200; i>=0; i-=25){
   drive(-i);
   wait(40);
 }
 wait(100);
 Output.stop();
 Roller.stop();
 Input.stop();
 //Turn to Wall Ball
 aTurn(44, 70);
 //Grab Wall Ball
 Input.go(200);
 Roller.go(-200);
 for (int i=50; i<=200; i+=50){
   drive(i);
   wait(30);
 }
 wait(400);
 for (int i=200; i>=0; i-=25){
   drive(i);
   wait(25);
 }
 wait(100);
 for (int i=50; i<=200; i+=50){
   drive(-i);
   wait(30);
 }
 wait(50);
 for (int i=200; i>=0; i-=25){
   drive(-i);
   wait(25);
 }
 wait(300);
 Roller.stop();
 //Turn towards middle ball
 aTurn(87, 70);
 //Grab middle ball
 for (int i=50; i<=200; i+=50){
   drive(i);
   wait(30);
 }
 wait(680);
 for (int i=200; i>=25; i-=25){
   drive(i);
   wait(25);
 }
 wait(300);
 stop();
 //Turn to 2nd Net
 aTurn(-93, 80);
 Input.stop();
 //2nd Net
 aDrive(16, 70);
 wait(100);
 //Leave 2nd Net
 for (int i=50; i<=200; i+=50){
   drive(-i);
   wait(30);
 }
 wait(150);
 for (int i=200; i>=25; i-=25){
   drive(-i);
   wait(25);
 }
 wait(200);
 //Turn towards other wall
 aTurn(89, 80);
 //Swing Turn Wall ball
 for (int i=50; i<=200; i+=50){
   drive(i);
   wait(30);
 }
 wait(420);
 Left.stop();
 wait(620);
 drive(200);
 wait(400);
 stop();
 wait(200);
 //Spin turn to get in net without hitting ball
 Input.go(-200);
 for (int i=50; i<=200; i+=50){
   Right.go(-i);
   wait(30);
 }
 wait(400);
 for (int i=200; i>=0; i-=25){
   Right.go(-i);
   wait(20);
 }
 for (int i=50; i<=200; i+=50){
   drive(i);
   wait(30);
 }
 wait(360);
 Left.stop();
 wait(240);
 drive(200);
 wait(300);
 stop();
}
void leftAuto1(){//1 minute auto, starting turning left
 aDrive(16, 100);
 aTurn(-88, 100);
 Input.go(200); //For grabbing first ball
 for (int i=50; i<=200; i+=50){
   drive(i);
   wait(30);
 }
 Roller.go(); //starts moving pre-load
 wait(300);
 Roller.stop(); //stops moving pre-load
 wait(120);
 Left.stop(); //Starts turning left
 wait(300);
 drive(200); //drives towards net
 wait(50);
 Output.go(); //Throws pre-load then first ball
 wait(150);
 Roller.go(); //Starts moving 2nd ball
 for (int i=200; i>=50; i-=25){ //slows down towards net
   drive(i);
   wait(40);
 }
 drive(50);
 wait(200);
 drive(-20);
 wait(200);
 stop();
 wait(1000);
 //Arrived at first net
 wallballside();
 wallballside();
 wallballside();
 wallballside();
}
void spiny1 (){//Leave first net 15s auto
   Input.go(200);
  aDrive(-12, 100);
   for(int i=0; i<=200; i+=50){
    Left.go(-i);
    Right.go(0);
    wait(34);
  }
  wait(70);
  Input.stop();
  for(int i=0; i<=200; i+=50){
    Right.go(i);
    wait(34);
  }
  wait(70);
  for(int i=-150; i<=200; i+=50){
    Right.go(i);
    wait(39);
  }
  drive(200);
  wait(920);
 }
void spiny2 (){//Leave second net 15s auto
  aDrive(-6, 80);
   Input.go(-200);
   for(int i=0; i<=200; i+=50){
    Left.go(0);
    Right.go(-i);
    wait(30);
  }
  wait(450);
  Input.stop();
  for(int i=0; i<=200; i+=50){
    Left.go(i);
    wait(30);
  }
  wait(500);
  for(int i=-150; i<=200; i+=50){
    Right.go(i);
    wait(30);
  }
  drive(200);
  wait(600);
  drive(130);
  Right.stop();
  Input.go(200);
  wait(400);
  drive(200);
  wait(700);
 }

void leftAuto3(){//15 second auto starting with left turn
  drive(50);
  wait(20);
  drive(100);
  wait(20);
  drive(150);
  wait(20);
  drive(200);
  wait(200);
  Left.stop();
  Input.go(200);
  Roller.go(200);
  wait(1100);
  drive(150);
  wait(600);
  Output.go(200);
  wait(200);
  drive(30);
  wait(500);
  Output.stop();
  spiny1();
  Right.stop();
  wait(590);
  Right.go(200);
  Output.go(200);
  Input.go(200);
  Roller.go(200);
  wait(200);
  stop();
  wait(600);
  Output.stop();
  wait(1000);
  spiny2();
  stop();
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
 Roller.go();
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
   if (Controller1.ButtonL1.pressing()){Roller.go(); Output.go();}
   else if (Controller1.ButtonL2.pressing()){Roller.go(); Output.go(-200);}
   else if (Controller1.ButtonX.pressing()){Roller.go(-200); Output.go(-200);}
   else if (Controller1.ButtonB.pressing()){Roller.brake1(); Output.brake1(); }
   else {Roller.brake2(); Output.brake2(); }
   if(Controller1.ButtonA.pressing()){spiny1();}
   //Input Control
   if (Controller1.ButtonR1.pressing()){Input.go();}
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
     int leftValue = (Controller1.Axis3.position()+Controller1.Axis4.position()+lSpeed)*(ds/100.0);
     if (!leftValue){Left.brake1();}
     else{Left.go(leftValue);}
     int rightValue = (Controller1.Axis3.position()-Controller1.Axis4.position()+rSpeed)*(ds/100.0);
     if (!rightValue){Right.brake1();}
     else{Right.go(rightValue);}
   }
   //Screen Control
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
 leftAuto1();
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
