/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
 
//Configuration
#include "vex.h"
#include "Motor.h"
#include <cmath>
#include <string>
#include <math.h>
using namespace vex;
competition Competition;
 
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
void spiny1 (){//Leave first net 15s auto
  for(int i=0; i<=200; i+=25){drive(-i); wait(20);}
  wait(100);
  Roller.go(200);//Spitting balls (that's what she said)
  Input.go(-200); 
  wait(100);
  Output.stop();
  for(int i=-175; i<=175; i+=25){Right.go(i); wait(30);} //accelerate to back spin turn counter clockwise
  wait(70);
  for(int i=-175; i<=175; i+=50){Left.go(i); wait(20);} //accelerate from spin turn to drive straight
  drive(200); //Drive straight
 }
void spiny2 (){//Leave second net 15s auto
  Roller.go(-200);
  for(int i=0; i<=200; i+=25){drive(-i); wait(20);}
  wait(100);
  Output.stop();
  for(int i=-175; i<=150; i+=25){Right.go(i); wait(22);} //accelerate to back spin turn counter clockwise
  wait(125);
  Roller.stop();
  for(int i=-175; i<=150; i+=50){Left.go(i); wait(12);} //accelerate from spin turn to drive straight
  Input.go(-200);
  Roller.go(-200);
  drive(200); //Drive straight
}
void leftAuto2(){//15 second auto starting with left turn
  for (int i=50; i<=200; i+=50){drive(i); wait(20);} //Accelerate forward
  wait(100);
  Left.stop(); //Start turning counter clockwise
  wait(950);
  Input.go(200); //Grab ball
  Roller.go(200); //Load up pre-load
  drive(200); //Drive straight to net after -135 deg
  wait(200);
  drive(100);
  wait(200);
  Output.go(200); //Start throwing first ball
  wait(200);
  drive(50); //Move to net
  wait(500);
  stop(); //Stop in net
  wait(1110); //Throws 2 balls
  spiny1(); //Leave first net fancy jhgf hvgf dvhdxvgdxcgdxvgfdxvgd
  wait(100);
  Input.stop(); //Stop spitting balls
  Roller.stop();
  wait(235); //Timing for drive straight
  Right.stop(); //Turns towards net 2
  wait(430); 
  Input.go(200); //Input balls
  Roller.go(); //Throw ball
  wait(300); //Timing for turn
  Right.go(200); //Drive straight
  wait(200);
  Output.go();
  wait(200);
  stop();
  wait(1550);
  spiny2(); //Spinykuyfuyvfhjgfbvytfbjvhgbfiyfjftuy
  wait(410);
  Right.stop();
  wait(515);
  drive(200); //slow down, and stop right to start left forward clockwise spin turn
  Input.go();
  Roller.go();
  wait(200);
  drive(130); //drive into net
  wait(200); //Timing for driving to net
  drive(200); //drive into net
  wait(200); //Timing for driving to net
  drive(50);
  Output.go();//Start throwing ball
  Roller.go();
  wait(300);
  Output.go();
  Input.go();
  Roller.go();
  wait(3500);
  stop();
}
void spiny3 (){//Leave first net 15s auto
  for(int i=0; i<=200; i+=25){drive(-i); wait(20);}
  wait(100);
  Roller.go(200);//Spitting balls (that's what she said)
  wait(100);
  Output.stop();
  for(int i=-175; i<=175; i+=25){Right.go(i); wait(30);} //accelerate to back spin turn counter clockwise
  wait(90);
  for(int i=-175; i<=175; i+=50){Left.go(i); wait(20);} //accelerate from spin turn to drive straight
  drive(200); //Drive straight
 }
void spiny4 (){//Leave second net 15s auto
  Roller.go(-200);
  for(int i=0; i<=200; i+=25){drive(-i); wait(20);}
  wait(100);
  Output.stop();
  for(int i=-175; i<=150; i+=25){Right.go(i); wait(22);} //accelerate to back spin turn counter clockwise
  wait(60);
  Roller.stop();
  for(int i=-175; i<=150; i+=50){Left.go(i); wait(12);} //accelerate from spin turn to drive straight
  Input.go(-200);
  Roller.go(-200);
  drive(200); //Drive straight
}
void spiny5 (){//Leave second net 15s auto
  Input.go(-200);
  Roller.stop();
  for(int i=0; i<=200; i+=25){drive(-i); wait(20);}
  wait(100);
  Output.stop();
  Input.stop();
  for(int i=-175; i<=200; i+=25){Left.go(i); wait(30);} //accelerate to back spin turn counter clockwise
  wait(125);
  for(int i=-175; i<=200; i+=50){Right.go(i); wait(30);} //accelerate from spin turn to drive straight
  drive(200); //Drive straight
}
void leftAuto3(){//15 second auto starting with left turn
  for (int i=50; i<=200; i+=50){drive(i); wait(20);} //Accelerate forward
  wait(90);
  Left.stop(); //Start turning counter clockwise
  wait(460);
  Input.go(200); //Grab ball
  Roller.go(200); //Load up pre-load
  wait(500);
  drive(200); //Drive straight to net after -135 deg
  wait(200);
  drive(100);
  wait(200);
  Output.go(200); //Start throwing first ball
  wait(200);
  drive(50); //Move to net
  wait(450);
  stop(); //Stop in net
  wait(100); //Throws 1 balls
  Input.stop();
  wait(120);
  Input.go(-200); 
  wait(120);
  spiny3(); //Leave first net fancy jhgf hvgf dvhdxvgdxcgdxvgfdxvgd
  wait(100);
  Input.stop(); //Stop spitting balls
  Roller.stop();
  wait(210); //Timing for drive straight
  Right.stop(); //Turns towards net 2
  wait(400); 
  Input.go(200); //Input balls
  Roller.go(); //Throw ball
  wait(300); //Timing for turn
  Right.go(200); //Drive straight
  wait(200);
  Output.go();
  wait(200);
  stop();
  Input.stop();
  wait(650);
  Input.go(-200);
  wait(100);
  spiny4(); //Spinykuyfuyvfhjgfbvytfbjvhgbfiyfjftuy
  wait(550);
  Right.stop();
  wait(310);
  drive(200); //slow down, and stop right to start left forward clockwise spin turn
  Input.go();
  Roller.go();
  wait(200);
  drive(130); //drive into net
  wait(200); //Timing for driving to net
  drive(200); //drive into net
  wait(200); //Timing for driving to net
  Output.go();//Start throwing ball
  Roller.go();
  wait(300);
  drive(50);
  Input.go();
  wait(1100);
  Input.stop();
  wait(1000);
  //spiny5();
  //wait(1400);
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
  drive(200);
  wait(250);
  Roller.go(-90);
  drive(-200);
  wait(50);
  Right.go(-175);
  wait(550);
  Right.go(-200);
  wait(150);
  drive(-100);
  wait(500);
  stop();
  Roller.stop();
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
    if(Controller1.ButtonA.pressing()){pre_auton();}
    if(Controller1.ButtonY.pressing()){pre_auton();leftAuto3();}
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
void autonomous(void) {
  pre_auton();
  leftAuto3();
  //wallballside();
  //wshapeside1();
  //farcorner();
  //wallballside();
  //wshapeside2();
  //middleGoal();
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
