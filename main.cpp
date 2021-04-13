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
void wallballside(){
  /*
  //Leave First Net
  for (int i=50; i<=200; i+=50){Right.go(-i/2); Left.go(-i);wait(30);} //Accelerate away from net
  wait(100);
  Input.go(-200); //Start spitting out blue balls
  Roller.go(-200);
  wait(490);
  for (int i=200; i>=0; i-=25){Right.go(-i/2); Left.go(-i); wait(40);}//Decelerate and stop
  wait(100);
  Output.stop();
  Roller.stop();
  //Turn to Wall Ball
  aTurn(86, 70);
  //Grab Wall Ball
  Input.go();
  Roller.go();
  for (int i=50; i<=200; i+=50){drive(i); wait(30);} //Accelerate to ball
  wait(400);
  for (int i=200; i>=0; i-=25){drive(i); wait(25);} //Decelerate to ball
  wait(100);
  for (int i=50; i<=200; i+=50){Right.go(-i);wait(30);} //Turn away from wall to next ball
  wait(405);
  for (int i=200; i>=0; i-=25){Right.go(-i); wait(40);}//Decelerate and stop
  wait(100);
  //Grab middle ball
  for (int i=25; i<=200; i+=25){drive(i); wait(30);} //Accelerate towards ball
  wait(230);
  Roller.stop(); //Stop ball
  Input.go();//Grab ball
  for (int i=200; i>=100; i-=25){drive(i); wait(40);} //Decelerate to ball
  wait(250); //Slowly move into ball
  for (int i=100; i<=200; i+=25){drive(i); wait(40);} //Acclerate into place of net
  for (int i=200; i>=0; i-=25){drive(i); wait(40);} //Decelerate into place of net
  stop();
  //Turn to 2nd Net
  aTurn(-96, 80);
  //2nd Net
  for (int i=50; i<=100; i+=50){drive(i); wait(30);} //Accelerate to net
  Output.go();
  wait(350);
  Roller.go();
  for (int i=100; i>=0; i-=25){drive(i); wait(25);} //Decelerate to net
  */
  Roller.go(); //Comment line above for start at 2nd net, delete these 
  Output.go();
  Input.go();
  wait(800);
  Roller.stop();
  wait(400);
  //Leave 2nd Net
  for (int i=50; i<=200; i+=50){drive(-i); wait(30);}
  Output.stop();
  wait(150);
  for (int i=200; i>=25; i-=25){drive(-i); wait(25);}
  wait(200);
  Input.go(); //Spittin straight facts (and blue balls)
  Roller.go();
  Output.go(-200);
  //Turn towards other wall
  aTurn(89, 80);
  //Swing Turn Wall ball
  for (int i=50; i<=200; i+=50){drive(i); wait(30);} //Drive straight
  wait(350);
  Input.go();
  Left.stop(); //Start turning left
  wait(620);
  drive(200);
  Output.stop();
  Roller.stop();
  wait(400);
  stop(); //Slam into wall
  wait(200);
  //Spin turn to get in net without hitting ball
  for (int i=50; i<=200; i+=50){Right.go(-i); wait(30);} //Accelerate turning clockwise with right
  wait(400);
  Roller.go();
  for (int i=200; i>=0; i-=25){Right.go(-i); wait(20);} //Decelerate turning clockwise with right. 
  for (int i=50; i<=200; i+=50){drive(i); wait(30);} //Accelerate forward
  wait(360);
  Left.stop(); //Turn towards net
  wait(240);
  drive(200); //Drive stright to net
  Roller.go();
  Output.go();
  wait(300);
  stop(); 
}
void wshapeside1(){//Net G to D
  Input.go();
  Roller.go();
  Output.go();
  wait(800);
  Output.go(-200);
  wait(300);
  for (int i=25; i<=100; i+=25){drive(-i); wait(30);} //Backs up 
  wait(280);
  for (int i=100; i>=0; i-=25){drive(-i); wait(20);} //Decelerates
  wait(100);
  for (int i=0; i<=200; i+=25){Right.go(-i); Left.go(i); wait(30);} //Point turn clockwise
  wait(220);
  Left.go(-20); //Spin turn
  Input.stop(); //Stop inputting temporarily to save energy
  Roller.stop();//Stop pooping when slamming into wall
  wait(200);
  Output.stop();
  wait(200);
  Left.go(-200);
  Right.go(-50);//Align using wall
  wait(400);
  drive(-200);
  wait(200);
  stop(); //Stop 
  for (int i=0; i<=200; i+=25){drive(i); wait(30);} //Accelerate forward
  Input.go();
  Roller.go(); //Commence the pooping
  Output.go(-200);
  drive(); //Drive towards ball
  wait(1000);
  Left.stop(); //Spin turn into net
  wait(300);
  Output.go();
  wait(500);
  drive(200); //Drive into net
  wait(350);
  stop(); //@2nd net in line
  wait(800);
}
void wshapeside2(){//Net C to F
  Input.go();
  Roller.go();
  Output.go();
  wait(1000);
  Output.go(-200);
  wait(300);
  for (int i=25; i<=100; i+=25){drive(-i); wait(30);} //Backs up 
  wait(280);
  for (int i=100; i>=0; i-=25){drive(-i); wait(20);} //Decelerates
  wait(100);
  for (int i=0; i<=200; i+=25){Right.go(-i); Left.go(i); wait(30);} //Point turn clockwise
  wait(180);
  Left.stop(); //Spin turn
  Input.stop(); //Stop inputting temporarily to save energy
  wait(200);
  Roller.stop();//Stop pooping when slamming into wall
  Output.stop();
  wait(200);
  Left.go(-200);
  Right.go(-50);//Align using wall
  wait(400);
  drive(-200);
  wait(200);
  stop(); //Stop 
  for (int i=0; i<=200; i+=25){drive(i); wait(30);} //Accelerate forward
  Input.go();
  Roller.go(); //Commence the pooping
  Output.go(-200);
  drive(); //Drive towards ball
  wait(1070);
  Left.stop(); //Spin turn into net
  wait(270);
  Output.go();
  wait(600);
  drive(200); //Drive into net
  wait(350);
  stop(); //@2nd net in line
  wait(800);
}
void farcorner(){ //Net D to net A
  for (int i=50; i<=200; i+=50){drive(-i); wait(40);}//Accelerate away from net
  Input.go(); //Pooper
  Roller.go();
  Output.go(-200);
  wait(50);
  for (int i=200; i>=0; i-=25){drive(-i); wait(40);} //Decelerate
  wait(50);
  //Turn towards other ball
  aTurn(91, 80);
  for (int i=50; i<=200; i+=50){drive(i); wait(30);}//Accelerate towards ball
  drive(200);
  wait(350);
  drive(150);
  Output.stop();
  Roller.stop();
  wait(250);
  drive(200);
  wait(250);
  Left.stop(); //Starts turning left
  wait(280);
  drive(200); //drives towards net
  wait(250);
  Output.go(); //Throws pre-load then first ball
  wait(120);
  Roller.go(); //Starts moving 2nd ball
  for (int i=200; i>=25; i-=25){drive(i); wait(25);} //slows down towards net
  drive(25); //Moves slowly to net
  wait(50);
  stop(); //Stay in place distanced from net
  wait(1000);
  Roller.stop();
  wait(500);
}
void leftAuto1(){//1 minute auto, starting turning left
  drive(50);
  wait(150);
  Left.stop();
  for (int i=100; i<=200; i+=50){Right.go(i); wait(30);}
  Input.go(200); //For grabbing first ball
  wait(430);
  for (int i=100; i<=200; i+=50){Left.go(i); wait(10);}
  for (int i=50; i<=200; i+=50){drive(i); wait(30);}
  Roller.go(); //starts moving pre-load
  wait(230);
  Roller.stop(); //stops moving pre-load
  Left.stop(); //Starts turning left
  wait(410);
  drive(200); //drives towards net
  wait(220);
  Output.go(); //Throws pre-load then first ball
  wait(120);
  Roller.go(); //Starts moving 2nd ball
  for (int i=200; i>=25; i-=25){drive(i); wait(25);} //slows down towards net
  drive(25); //Moves slowly to net
  wait(50);
  stop(); //Stay in place distanced from net
  wait(1100);
  //Arrived at first net
  wallballside();
  wshapeside1();
  farcorner();
  wallballside();
  wshapeside2();
}
void spiny1 (){//Leave first net 15s auto
  aDrive(-13, 100);
  Output.stop();
  Right.go(0);
  for(int i=0; i<=200; i+=50){Left.go(-i); wait(34);} //accelerate to back spin turn counter clockwise
  wait(100);
  Roller.stop();
  for(int i=0; i<=200; i+=50){Right.go(i); wait(34);} //accelerate to spin
  wait(247);
  for(int i=150; i<=200; i+=50){Left.go(i); wait(34);} //accelerate from spin turn to drive straight
  drive(200); //Drive straight
  Input.stop();
  wait(610);
 }
void spiny2 (){//Leave second net 15s auto
  Output.stop();
  Roller.go();
  Input.go(-200);
  aDrive(-6, 80); //Get out of net
  for(int i=0; i<=200; i+=50){Left.go(-i); wait(34);} //accelerate to back spin turn counter clockwise
  wait(100);
  Roller.stop();
  for(int i=0; i<=200; i+=50){Right.go(i); wait(34);} //accelerate to spin
  wait(140);
  for(int i=150; i<=200; i+=50){Left.go(i); wait(34);} //accelerate from spin turn to drive straight
  drive(200); //Drive straight
  Roller.stop();
  wait(750);
  drive(130); //slow down, and stop right to start left forward clockwise spin turn
  Right.stop();
  Input.go(200); // Start inputting balls
  wait(400);
  Output.go();
  Roller.go();
  drive(200); //drive into net
  wait(500);
  wait(200);
  Output.go();
  Input.go();
  Roller.go();
  wait(2000);
}

void leftAuto2(){//15 second auto starting with left turn
  for (int i=50; i<=200; i+=50){drive(i); wait(20);} //Accelerate forward
  wait(130);
  Left.stop(); //Start turning counter clockwise
  wait(950);
  Input.go(200); //Grab ball
  Roller.go(200); //Load up pre-load
  drive(150); //Drive straight to net after -135 deg
  wait(600);
  Output.go(200); //Start throwing first ball
  drive(30);
  wait(500);
  stop();
  wait(1600); //Throws 2 balls
  Output.stop();
  Roller.stop(); 
  Input.go(-200); //Spitting balls (that's what she said)
  spiny1(); //Leave first net fancy
  Right.stop(); //Turns towards net 2
  wait(450); 
  Input.go(200);
  wait(300);
  Right.go(200); //Drive straight
  wait(100);
  Output.go(200);
  Roller.go(200);
  wait(400);
  stop();
  wait(1300);
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
void autonomous(void) {
  //pre_auton();
  //wallballside();
  wshapeside1();
  farcorner();
  wallballside();
  //wshapeside2();
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
