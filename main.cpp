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
// LeftDrive1           motor         8               
// LeftDrive2           motor         5               
// RightDrive1          motor         4               
// RightDrive2          motor         3               
// LiftMotor            motor         1               
// ClawMotor1           motor         12              
// ClawMotor2           motor         11              
// TrayMotor            motor         2               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <cmath>

using namespace vex;

// A global instance of competition
competition Competition;

// Define your global instances of motors and other devices here

/*--------------------------|PID Auto Functions|--------------------------*/
bool autonomous_running = true;

bool blue;
bool red;
bool front;
bool variant;
bool anti_descore;

//Drive Forward
void driveforward(int inches, bool speed){
    
    int mastermotorpower;
    int slavemotorpower;
    LeftDrive1.resetRotation();
    RightDrive1.resetRotation();
    double Kp1 = .3; //when true
    float Kp2 = .4; //when false
   
    if (speed == true){
        while(autonomous_running == true && std::abs(LeftDrive1.rotation(vex::rotationUnits::deg))< inches * 28){   
            mastermotorpower = ((inches*28) - std::abs(LeftDrive1.rotation(vex::rotationUnits::deg)))* Kp1; 
            
            if (mastermotorpower > 120){
                mastermotorpower = 120;
            } 
            
            else if (mastermotorpower < 20){
                mastermotorpower = 20;
            }
            
            slavemotorpower = mastermotorpower; // + (0.3 * ((std::abs(FL_drive.rotation(vex::rotationUnits::deg))- std::abs(FR_drive.rotation(vex::rotationUnits::deg)))));

            LeftDrive1.spin(vex::directionType::fwd,mastermotorpower, vex::velocityUnits::rpm);
            LeftDrive2.spin(vex::directionType::fwd,mastermotorpower, vex::velocityUnits::rpm);
            RightDrive1.spin(vex::directionType::fwd,mastermotorpower, vex::velocityUnits::rpm);
            RightDrive2.spin(vex::directionType::fwd,mastermotorpower, vex::velocityUnits::rpm);

            vex::task::sleep(5);
        }

        LeftDrive1.stop(vex::brakeType::brake);
        LeftDrive2.stop(vex::brakeType::brake);
        RightDrive1.stop(vex::brakeType::brake);
        RightDrive2.stop(vex::brakeType::brake);

        vex::task::sleep(50);

        RightDrive1.stop(vex::brakeType::coast);
        RightDrive2.stop(vex::brakeType::coast);
        LeftDrive1.stop(vex::brakeType::coast);
        LeftDrive2.stop(vex::brakeType::coast);        
    } 
    
    else {
        while(autonomous_running == true && std::abs(LeftDrive1.rotation(vex::rotationUnits::deg))< inches * 28){   
            mastermotorpower = ((inches*28) - std::abs(LeftDrive1.rotation(vex::rotationUnits::deg)))* Kp2; 
            
            if (mastermotorpower > 50){
                mastermotorpower = 50;
            } 
            
            else if (mastermotorpower < 20){
                mastermotorpower = 20;
            }
            
            slavemotorpower = mastermotorpower; // + (0.3 * ((std::abs(FL_drive.rotation(vex::rotationUnits::deg))- std::abs(FR_drive.rotation(vex::rotationUnits::deg)))));

            LeftDrive1.spin(vex::directionType::fwd,mastermotorpower, vex::velocityUnits::rpm);
            LeftDrive2.spin(vex::directionType::fwd,mastermotorpower, vex::velocityUnits::rpm);
            RightDrive1.spin(vex::directionType::fwd,mastermotorpower, vex::velocityUnits::rpm);
            RightDrive2.spin(vex::directionType::fwd,mastermotorpower, vex::velocityUnits::rpm);

            vex::task::sleep(5);
        }

        LeftDrive1.stop(vex::brakeType::brake);
        LeftDrive2.stop(vex::brakeType::brake);
        RightDrive1.stop(vex::brakeType::brake);
        RightDrive2.stop(vex::brakeType::brake);

        vex::task::sleep(50);

        RightDrive1.stop(vex::brakeType::coast);
        RightDrive2.stop(vex::brakeType::coast);
        LeftDrive1.stop(vex::brakeType::coast);
        LeftDrive2.stop(vex::brakeType::coast);        
    } 
}

//Drive Backward
void drivebackward(int inches, bool speed){
    
    int mastermotorpower;
    int slavemotorpower;
    LeftDrive1.resetRotation();
    RightDrive1.resetRotation();
    double Kp1 = 0.2; //when true
    float Kp2 = 0.5;  //when false
   
    if (speed == true){        
        while (autonomous_running == true && std::abs(LeftDrive1.rotation(vex::rotationUnits::deg)) < inches * 28){            
            mastermotorpower = ((inches*28) - std::abs(LeftDrive1.rotation(vex::rotationUnits::deg))) * Kp1;
            
            if (mastermotorpower > 130){             
                mastermotorpower = 130;
            } 
            
            else if (mastermotorpower < 20){ 
                mastermotorpower = 20;             
            }
            
            // slavemotorpower = mastermotorpower; //+ (0.3 * (std::abs(FL_drive.rotation(vex::rotationUnits::deg)) - std::abs(FR_drive.rotation(vex::rotationUnits::deg))));

             LeftDrive1.spin(vex::directionType::rev,mastermotorpower , vex::velocityUnits::pct);
             LeftDrive2.spin(vex::directionType::rev,mastermotorpower, vex::velocityUnits::pct);
             RightDrive1.spin(vex::directionType::rev,mastermotorpower, vex::velocityUnits::pct);
             RightDrive2.spin(vex::directionType::rev, mastermotorpower, vex::velocityUnits::pct);

            vex::task::sleep(5);
        }

        LeftDrive1.stop(vex::brakeType::brake);
        LeftDrive2.stop(vex::brakeType::brake);
        RightDrive1.stop(vex::brakeType::brake);
        RightDrive2.stop(vex::brakeType::brake);


        vex::task::sleep(50);

        LeftDrive1.stop(vex::brakeType::coast);
        LeftDrive2.stop(vex::brakeType::coast);
        RightDrive1.stop(vex::brakeType::coast);
        RightDrive2.stop(vex::brakeType::coast);
    } 
    
    else {        
        while(autonomous_running == true && std::abs(LeftDrive1.rotation(vex::rotationUnits::deg))< inches * 28){    
            mastermotorpower = ((inches*28) - std::abs(LeftDrive1.rotation(vex::rotationUnits::deg)))* Kp2; 
            
            if (mastermotorpower > 50){             
                mastermotorpower = 50;
            } 
            
            else if (mastermotorpower < 10){             
                mastermotorpower = 10;             
            }
            
            slavemotorpower = mastermotorpower; //+ (0.3 * ((std::abs(FL_drive.rotation(vex::rotationUnits::deg))- std::abs(FR_drive.rotation(vex::rotationUnits::deg)))));

            LeftDrive1.spin(vex::directionType::fwd,mastermotorpower * -1, vex::velocityUnits::pct);
            LeftDrive2.spin(vex::directionType::rev,mastermotorpower * -1, vex::velocityUnits::pct);
            RightDrive1.spin(vex::directionType::fwd,slavemotorpower, vex::velocityUnits::pct);
            RightDrive2.spin(vex::directionType::rev,slavemotorpower, vex::velocityUnits::pct);

            vex::task::sleep(5);    
        }

        LeftDrive1.stop(vex::brakeType::brake);
        LeftDrive2.stop(vex::brakeType::brake);
        RightDrive1.stop(vex::brakeType::brake);
        RightDrive2.stop(vex::brakeType::brake);

        vex::task::sleep(50);

        LeftDrive1.stop(vex::brakeType::coast);
        LeftDrive2.stop(vex::brakeType::coast);
        RightDrive1.stop(vex::brakeType::coast);
        RightDrive2.stop(vex::brakeType::coast);   
    }
}

//Turn Right - To Be Tested
void turnright(float turn){
    
    int turn_power;
    int set_turn_power;
    int error;
    bool acceleration = true;
    float Kp1 = 0.75;
    double encoder_turning_proportional = 3.85;

    LeftDrive1.resetRotation();
    RightDrive1.resetRotation();
    
    while (autonomous_running == true && std::abs(LeftDrive1.rotation(vex::rotationUnits::deg)) / encoder_turning_proportional < turn ){
        vex::task::sleep(5);    
        
        error = turn - std::abs((LeftDrive1.rotation(vex::rotationUnits::deg) / encoder_turning_proportional));
        
        if (std::abs(LeftDrive1.rotation(vex::rotationUnits::deg)) / encoder_turning_proportional < (turn * 0.2)){       
            acceleration = true;      
        } 
        
        else {       
            acceleration = false;       
        }
        
        set_turn_power = (error * Kp1) * 2;
        
        if (set_turn_power - 10 > turn_power && acceleration == true){       
            turn_power += 5;
        }  
        
        else {
            turn_power = set_turn_power;
        }         
        
        if (turn_power < 20){
            turn_power = 20;
        } 
        
        else if (turn_power > 105){       
            turn_power = 105;
        }
       
        LeftDrive1.spin(vex::directionType::fwd,turn_power ,vex::velocityUnits::rpm);
        LeftDrive2.spin(vex::directionType::fwd,turn_power ,vex::velocityUnits::rpm);      
    }    
    
    LeftDrive1.stop(vex::brakeType::brake);
    LeftDrive2.stop(vex::brakeType::brake);

    
    vex::task::sleep(100);
    
    LeftDrive1.stop(vex::brakeType::coast);
    LeftDrive2.stop(vex::brakeType::coast);
  
    
    int turn_error = std::abs(LeftDrive1.rotation(vex::rotationUnits::deg)) - std::abs(RightDrive1.rotation(vex::rotationUnits::deg));
    
    while (turn_error > 20){
        turn_error = std::abs(LeftDrive1.rotation(vex::rotationUnits::deg)) - std::abs(RightDrive1.rotation(vex::rotationUnits::deg));
        
        RightDrive1.spin(vex::directionType::rev, turn_error,vex::velocityUnits::rpm);
        RightDrive2.spin(vex::directionType::rev, turn_error,vex::velocityUnits::rpm);
    }
    
    while(turn_error < -20){        
        turn_error = std::abs(LeftDrive1.rotation(vex::rotationUnits::deg)) - std::abs(RightDrive1.rotation(vex::rotationUnits::deg));
        
        LeftDrive1.spin(vex::directionType::fwd, turn_error,vex::velocityUnits::rpm);
        LeftDrive2.spin(vex::directionType::fwd, turn_error,vex::velocityUnits::rpm);        
    }
    
    LeftDrive1.stop(vex::brakeType::brake);
    LeftDrive2.stop(vex::brakeType::brake);
    RightDrive1.stop(vex::brakeType::brake);
    RightDrive2.stop(vex::brakeType::brake);
    
    vex::task::sleep(100);
    
    LeftDrive1.stop(vex::brakeType::coast);
    LeftDrive2.stop(vex::brakeType::coast);
    RightDrive1.stop(vex::brakeType::coast);
    RightDrive2.stop(vex::brakeType::coast);
}

//Turn Left -> To Be Test
void turnleft(float turn){
    
    int turn_power;
    int set_turn_power;
    int error;
    bool acceleration = true;
    float Kp1 = 0.8;
    double encoder_turning_proportional = 3.85;

    LeftDrive1.resetRotation();
    RightDrive1.resetRotation();

    while (autonomous_running == true && std::abs(LeftDrive1.rotation(vex::rotationUnits::deg)) / encoder_turning_proportional < turn){
        vex::task::sleep(5);    
        error = turn - std::abs((LeftDrive1.rotation(vex::rotationUnits::deg) / encoder_turning_proportional));
        
        if (std::abs(LeftDrive1.rotation(vex::rotationUnits::deg)) / encoder_turning_proportional < (turn * 0.2)){
            acceleration = true;
        } 
        
        else {
            acceleration = false;
        }
        
        set_turn_power = (error * Kp1) * 2; 
        
        if (set_turn_power - 10 > turn_power && acceleration == true){
            turn_power += 5;
        }  
        
        else {
            turn_power = set_turn_power;
        }
        
        if (turn_power < 20){       
            turn_power = 20;
        } 
        
        else if (turn_power > 200){
            turn_power = 200;
        }
       
        LeftDrive1.spin(vex::directionType::fwd,turn_power*-1,vex::velocityUnits::rpm);
        LeftDrive2.spin(vex::directionType::fwd,turn_power*-1,vex::velocityUnits::rpm);
        RightDrive1.spin(vex::directionType::rev,turn_power*-1,vex::velocityUnits::rpm);
        RightDrive2.spin(vex::directionType::rev,turn_power*-1,vex::velocityUnits::rpm);
    }  
      
    LeftDrive1.stop(vex::brakeType::brake);
    LeftDrive2.stop(vex::brakeType::brake);
    RightDrive1.stop(vex::brakeType::brake);
    RightDrive2.stop(vex::brakeType::brake);
    
    vex::task::sleep(100);
    
    LeftDrive1.stop(vex::brakeType::coast);
    LeftDrive2.stop(vex::brakeType::coast);
    RightDrive1.stop(vex::brakeType::coast);
    RightDrive2.stop(vex::brakeType::coast);
    
    int turn_error = std::abs(LeftDrive1.rotation(vex::rotationUnits::deg)) - std::abs(RightDrive1.rotation(vex::rotationUnits::deg));
    
    while (turn_error > 20){
        turn_error = std::abs(LeftDrive1.rotation(vex::rotationUnits::deg)) - std::abs(RightDrive1.rotation(vex::rotationUnits::deg));
        
        LeftDrive1.spin(vex::directionType::fwd,turn_error,vex::velocityUnits::rpm);
        LeftDrive2.spin(vex::directionType::fwd,turn_error,vex::velocityUnits::rpm);
    }
    
    while(turn_error < -20){
        turn_error = std::abs(LeftDrive1.rotation(vex::rotationUnits::deg)) - std::abs(RightDrive1.rotation(vex::rotationUnits::deg));
        
        RightDrive1.spin(vex::directionType::rev,turn_error ,vex::velocityUnits::rpm);
        RightDrive2.spin(vex::directionType::rev,turn_error ,vex::velocityUnits::rpm);        
    }
    
    LeftDrive1.stop(vex::brakeType::brake);
    LeftDrive2.stop(vex::brakeType::brake);
    RightDrive1.stop(vex::brakeType::brake);
    RightDrive2.stop(vex::brakeType::brake);
    
    vex::task::sleep(50);
    
    LeftDrive1.stop(vex::brakeType::coast);
    LeftDrive2.stop(vex::brakeType::coast);
    RightDrive1.stop(vex::brakeType::coast);
    RightDrive2.stop(vex::brakeType::coast);    
}

//Drive Forward -> Inches
void forwardDriveInches(int inches){
  LeftDrive1.resetRotation();
  RightDrive1.resetRotation();
  float turnDegrees = (inches / 12.5663706144) * 360;
  int leftMotorPower;
  int rightMotorPower;
  bool leftDone = false;
  bool rightDone = false;
    while (leftDone == false && rightDone == false){
      // Less than 1/36th rotation ~ .35 inches
      while (turnDegrees - (LeftDrive1.rotation(vex::rotationUnits::deg)) < 10){
          leftMotorPower = 0;
          leftDone = true;
      }
      while (turnDegrees - (RightDrive1.rotation(vex::rotationUnits::deg)) < 10){
          rightMotorPower = 0;
          rightDone = true;
        }

      // Less than 1/2 rotation ~ 6.25 inches
      while (turnDegrees - (LeftDrive1.rotation(vex::rotationUnits::deg)) < 180){
          leftMotorPower = 20;
      }
      while (turnDegrees - (RightDrive1.rotation(vex::rotationUnits::deg)) < 180){
          rightMotorPower = 20;
      }

      // Less than 1/2 rotation ~ 6.25 inches
      while (turnDegrees - (LeftDrive1.rotation(vex::rotationUnits::deg)) < 360){
          leftMotorPower = 60;
      }
      while (turnDegrees - (RightDrive1.rotation(vex::rotationUnits::deg)) < 360){
          rightMotorPower = 60;
      } 

      // Greater than 1 rotation ~ 12.5 inches
      if (turnDegrees - (LeftDrive1.rotation(vex::rotationUnits::deg)) > 360){
          leftMotorPower = 100;
      }
      if (turnDegrees - (RightDrive1.rotation(vex::rotationUnits::deg)) > 360){
          rightMotorPower = 100;  
      }

      LeftDrive1.spin(vex::directionType::fwd, leftMotorPower, vex::velocityUnits::rpm);
      LeftDrive2.spin(vex::directionType::fwd, leftMotorPower, vex::velocityUnits::rpm);
      RightDrive1.spin(vex::directionType::fwd, rightMotorPower, vex::velocityUnits::rpm);
      RightDrive2.spin(vex::directionType::fwd, rightMotorPower, vex::velocityUnits::rpm);

    vex::task::sleep(5);

    }

    LeftDrive1.stop(vex::brakeType::brake);
    LeftDrive2.stop(vex::brakeType::brake);
    RightDrive1.stop(vex::brakeType::brake);
    RightDrive2.stop(vex::brakeType::brake);

    vex::task::sleep(50);

    RightDrive1.stop(vex::brakeType::coast);
    RightDrive2.stop(vex::brakeType::coast);
    LeftDrive1.stop(vex::brakeType::coast);
    LeftDrive2.stop(vex::brakeType::coast);

}

//Drive Backwards -> Negative Inches
void backwardDriveInches(int inches){
  LeftDrive1.resetRotation();
  RightDrive1.resetRotation();
  float turnDegrees = (inches / 12.5663706144) * 360;
  int leftMotorPower;
  int rightMotorPower;
  bool leftDone = false;
  bool rightDone = false;
    while (leftDone == false && rightDone == false){
      // Less than 1/36th rotation ~ .35 inches
      while (-1 * turnDegrees + (LeftDrive1.rotation(vex::rotationUnits::deg)) < 10){
          leftMotorPower = 0;
          leftDone = true;
      }
      while (-1 * turnDegrees + (RightDrive1.rotation(vex::rotationUnits::deg)) < 10){
          rightMotorPower = 0;
          rightDone = true;
        }

      // Less than 1/2 rotation ~ 6.25 inches
      while (-1 * turnDegrees + (LeftDrive1.rotation(vex::rotationUnits::deg)) < 180){
          leftMotorPower = 20;
      }
      while (-1 * turnDegrees + (RightDrive1.rotation(vex::rotationUnits::deg)) < 180){
          rightMotorPower = 20;
      }

      // Less than 1/2 rotation ~ 6.25 inches
      while (-1 * turnDegrees + (LeftDrive1.rotation(vex::rotationUnits::deg)) < 360){
          leftMotorPower = 60;
      }
      while (-1 * turnDegrees + (RightDrive1.rotation(vex::rotationUnits::deg)) < 360){
          rightMotorPower = 60;
      } 

      // Greater than 1 rotation ~ 12.5 inches
      if (-1 * turnDegrees + (LeftDrive1.rotation(vex::rotationUnits::deg)) > 360){
          leftMotorPower = 100;
      }
      if (-1 * turnDegrees + (RightDrive1.rotation(vex::rotationUnits::deg)) > 360){
          rightMotorPower = 100;  
      }

      LeftDrive1.spin(vex::directionType::rev, leftMotorPower, vex::velocityUnits::rpm);
      LeftDrive2.spin(vex::directionType::rev, leftMotorPower, vex::velocityUnits::rpm);
      RightDrive1.spin(vex::directionType::rev, rightMotorPower, vex::velocityUnits::rpm);
      RightDrive2.spin(vex::directionType::rev, rightMotorPower, vex::velocityUnits::rpm);

    vex::task::sleep(5);

    }

    LeftDrive1.stop(vex::brakeType::brake);
    LeftDrive2.stop(vex::brakeType::brake);
    RightDrive1.stop(vex::brakeType::brake);
    RightDrive2.stop(vex::brakeType::brake);

    vex::task::sleep(50);

    RightDrive1.stop(vex::brakeType::coast);
    RightDrive2.stop(vex::brakeType::coast);
    LeftDrive1.stop(vex::brakeType::coast);
    LeftDrive2.stop(vex::brakeType::coast);

}


//Non PID

void startup(){

  LeftDrive1.spin(vex::directionType::fwd,  140, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 140, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd, 140, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 140, vex::velocityUnits::rpm);
  vex::task::sleep(400);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(100);

  LeftDrive1.spin(vex::directionType::rev,  140, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 140, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::rev, 140, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::rev, 140, vex::velocityUnits::rpm);
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
  vex::task::sleep(1400);
  
}

void placeStack(){
  ClawMotor1.spin(reverse, 40, vex::velocityUnits::rpm);
  ClawMotor2.spin(reverse, 40, vex::velocityUnits::rpm);
  vex::task::sleep(1750);
  ClawMotor1.stop(vex::brakeType::coast);
  ClawMotor2.stop(vex::brakeType::coast);
  TrayMotor.spin(forward, 80, vex::velocityUnits::rpm);
  vex::task::sleep(2000);
  TrayMotor.stop();
}

void redAutoFrontjan18(){
  startup();
  vex::task::sleep(50);

  ClawMotor1.spin(forward, 200, vex::velocityUnits::rpm);
  ClawMotor2.spin(forward, 200, vex::velocityUnits::rpm);
  vex::task::sleep(100);

  LeftDrive1.spin(vex::directionType::fwd,  120, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 120, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd, 120, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 120, vex::velocityUnits::rpm);
  vex::task::sleep(1050);

  LeftDrive1.stop(vex::brakeType::brake); 
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(300);

  ClawMotor1.stop(vex::brakeType::hold);
  ClawMotor2.stop(vex::brakeType::hold);

   //Turn Left

  RightDrive1.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  LeftDrive1.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  vex::task::sleep(790);

  ClawMotor1.spin(forward, 200, vex::velocityUnits::rpm);
  ClawMotor2.spin(forward, 200, vex::velocityUnits::rpm);
  vex::task::sleep(100);

  // RightDrive1.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  // RightDrive2.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  // vex::task::sleep(500);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(500);

  //Drive Forward

  LeftDrive1.spin(vex::directionType::fwd,  60, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 60, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd, 60, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 60, vex::velocityUnits::rpm);
  vex::task::sleep(2000);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(300);

  ClawMotor1.stop(vex::brakeType::hold);
  ClawMotor2.stop(vex::brakeType::hold);

  // LeftDrive1.spin(vex::directionType::fwd,  60, vex::velocityUnits::rpm);
  // LeftDrive2.spin(vex::directionType::fwd, 60, vex::velocityUnits::rpm);
  // RightDrive1.spin(vex::directionType::fwd, 60, vex::velocityUnits::rpm);
  // RightDrive2.spin(vex::directionType::fwd, 60, vex::velocityUnits::rpm);
  // vex::task::sleep(900);

  // LeftDrive1.stop(vex::brakeType::brake);
  // LeftDrive2.stop(vex::brakeType::brake);
  // RightDrive1.stop(vex::brakeType::brake);
  // RightDrive2.stop(vex::brakeType::brake);
  // vex::task::sleep(50);

  // LeftDrive1.stop(vex::brakeType::coast);
  // LeftDrive2.stop(vex::brakeType::coast);
  // RightDrive1.stop(vex::brakeType::coast);
  // RightDrive2.stop(vex::brakeType::coast);
  // vex::task::sleep(300);

  ClawMotor1.spin(reverse, 60, vex::velocityUnits::rpm);
  ClawMotor2.spin(reverse, 60, vex::velocityUnits::rpm);
  vex::task::sleep(3000);
  ClawMotor1.stop(vex::brakeType::coast);
  ClawMotor2.stop(vex::brakeType::coast);

  LeftDrive1.spin(vex::directionType::rev,  60, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  vex::task::sleep(1750);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(300);


}

void blueAutoFrontdec14(){
  startup();
  vex::task::sleep(50);

  ClawMotor1.spin(forward, 80, vex::velocityUnits::rpm);
  ClawMotor2.spin(forward, 80, vex::velocityUnits::rpm);
  vex::task::sleep(100);

  LeftDrive1.spin(vex::directionType::fwd,  80, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  vex::task::sleep(1500);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(300);

  ClawMotor1.stop(vex::brakeType::hold);
  ClawMotor2.stop(vex::brakeType::hold);

   //Turn Right

  LeftDrive1.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  vex::task::sleep(1300);

  ClawMotor1.spin(forward, 80, vex::velocityUnits::rpm);
  ClawMotor2.spin(forward, 80, vex::velocityUnits::rpm);
  vex::task::sleep(100);

  LeftDrive1.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  vex::task::sleep(500);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(500);

  //Drive Forward

  LeftDrive1.spin(vex::directionType::fwd,  60, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 60, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd, 60, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 60, vex::velocityUnits::rpm);
  vex::task::sleep(1000);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(300);

  ClawMotor1.stop(vex::brakeType::hold);
  ClawMotor2.stop(vex::brakeType::hold);

  LeftDrive1.spin(vex::directionType::fwd,  60, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 60, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd, 60, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 60, vex::velocityUnits::rpm);
  vex::task::sleep(900);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(300);

  ClawMotor1.spin(reverse, 40, vex::velocityUnits::rpm);
  ClawMotor2.spin(reverse, 40, vex::velocityUnits::rpm);
  vex::task::sleep(3000);
  ClawMotor1.stop(vex::brakeType::coast);
  ClawMotor2.stop(vex::brakeType::coast);

  LeftDrive1.spin(vex::directionType::rev,  60, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  vex::task::sleep(1750);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(300);


}

void frontRedAuto2Blocks15sec(){
  startup();
  vex::task::sleep(50);

  ClawMotor1.spin(forward, 200, vex::velocityUnits::rpm);
  ClawMotor2.spin(forward, 200, vex::velocityUnits::rpm);
  vex::task::sleep(100);

  LeftDrive1.spin(vex::directionType::fwd,  120, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 120, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd, 120, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 120, vex::velocityUnits::rpm);
  vex::task::sleep(1400);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(100);

  ClawMotor1.stop(vex::brakeType::hold);
  ClawMotor2.stop(vex::brakeType::hold);

  //Turn Left

  RightDrive1.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  LeftDrive1.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  vex::task::sleep(500);

  ClawMotor1.spin(forward, 200, vex::velocityUnits::rpm);
  ClawMotor2.spin(forward, 200, vex::velocityUnits::rpm);
  vex::task::sleep(100);

  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(1000);

  //Drive Forward

  LeftDrive1.spin(vex::directionType::fwd,  60, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 60, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd, 75, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 75, vex::velocityUnits::rpm);
  vex::task::sleep(1750);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(300);

  ClawMotor1.stop(vex::brakeType::hold);
  ClawMotor2.stop(vex::brakeType::hold);

  ClawMotor1.spin(reverse, 60, vex::velocityUnits::rpm);
  ClawMotor2.spin(reverse, 60, vex::velocityUnits::rpm);
  vex::task::sleep(1250);
  ClawMotor1.stop(vex::brakeType::coast);
  ClawMotor2.stop(vex::brakeType::coast);

  LeftDrive1.spin(vex::directionType::rev,  60, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  vex::task::sleep(1300);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(300);

}

void frontBlueAuto(){
  startup();
  vex::task::sleep(50);

  ClawMotor1.spin(forward, 80, vex::velocityUnits::rpm);
  ClawMotor2.spin(forward, 80, vex::velocityUnits::rpm);
  vex::task::sleep(100);

  LeftDrive1.spin(vex::directionType::fwd,  80, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  vex::task::sleep(750);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(100);

  ClawMotor1.stop(vex::brakeType::hold);
  ClawMotor2.stop(vex::brakeType::hold);

  //Turn Right

  LeftDrive1.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  vex::task::sleep(1000);

  ClawMotor1.spin(forward, 80, vex::velocityUnits::rpm);
  ClawMotor2.spin(forward, 80, vex::velocityUnits::rpm);
  vex::task::sleep(100);

  LeftDrive1.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  vex::task::sleep(500);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(1700);

  //Drive Forward

  LeftDrive1.spin(vex::directionType::fwd,  75, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 75, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd, 60, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 60, vex::velocityUnits::rpm);
  vex::task::sleep(1750);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(300);

  ClawMotor1.stop(vex::brakeType::hold);
  ClawMotor2.stop(vex::brakeType::hold);

  placeStack();

  ClawMotor1.spin(reverse, 80, vex::velocityUnits::rpm);
  ClawMotor2.spin(reverse, 80, vex::velocityUnits::rpm);
  vex::task::sleep(100);

  LeftDrive1.spin(vex::directionType::rev,  60, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  vex::task::sleep(1750);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(300);

}

void backRedAuto(){
  startup();
  vex::task::sleep(50);

  ClawMotor1.spin(forward, 80, vex::velocityUnits::rpm);
  ClawMotor2.spin(forward, 80, vex::velocityUnits::rpm);
  vex::task::sleep(100);

  LeftDrive1.spin(vex::directionType::fwd,  100, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  vex::task::sleep(2500);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(200);

  ClawMotor1.stop(vex::brakeType::hold);
  ClawMotor2.stop(vex::brakeType::hold);

  LeftDrive1.spin(vex::directionType::rev,  100, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  vex::task::sleep(2000);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(300);
  
  // Turn Right

  LeftDrive1.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  vex::task::sleep(800);

  ClawMotor1.spin(forward, 80, vex::velocityUnits::rpm);
  ClawMotor2.spin(forward, 80, vex::velocityUnits::rpm);
  vex::task::sleep(100);

  LeftDrive1.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  vex::task::sleep(500);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(300);

  //Drive Forward

  LeftDrive1.spin(vex::directionType::fwd,  75, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 75, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd, 60, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 60, vex::velocityUnits::rpm);
  vex::task::sleep(300);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(300);

  ClawMotor1.stop(vex::brakeType::hold);
  ClawMotor2.stop(vex::brakeType::hold);

  //Place the Stack and Drive Backwards

  placeStack();

  ClawMotor1.spin(reverse, 80, vex::velocityUnits::rpm);
  ClawMotor2.spin(reverse, 80, vex::velocityUnits::rpm);
  vex::task::sleep(100);

  LeftDrive1.spin(vex::directionType::rev,  60, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  vex::task::sleep(1750);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(300);

}

void backBlueAuto(){
  startup();
  vex::task::sleep(50);

  ClawMotor1.spin(forward, 80, vex::velocityUnits::rpm);
  ClawMotor2.spin(forward, 80, vex::velocityUnits::rpm);
  vex::task::sleep(100);

  LeftDrive1.spin(vex::directionType::fwd,  100, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  vex::task::sleep(2500);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(200);

  ClawMotor1.stop(vex::brakeType::hold);
  ClawMotor2.stop(vex::brakeType::hold);

  LeftDrive1.spin(vex::directionType::rev,  100, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  vex::task::sleep(2000);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(300);
}

void driverSkillsStart(){
  startup();
  vex::task::sleep(50);

  ClawMotor1.spin(forward, 80, vex::velocityUnits::rpm);
  ClawMotor2.spin(forward, 80, vex::velocityUnits::rpm);
  vex::task::sleep(100);

  LeftDrive1.spin(vex::directionType::fwd,  100, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  vex::task::sleep(2500);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(200);

  ClawMotor1.stop(vex::brakeType::hold);
  ClawMotor2.stop(vex::brakeType::hold);

  LeftDrive1.spin(vex::directionType::rev,  100, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  vex::task::sleep(2000);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(300);
}



// St Cathrines
void J_backRedAuto7blocks15sec(){
  startup();
  vex::task::sleep(50);

  ClawMotor1.spin(forward, 200, vex::velocityUnits::rpm);
  ClawMotor2.spin(forward, 200, vex::velocityUnits::rpm);
  vex::task::sleep(300);

  LeftDrive1.spin(vex::directionType::fwd,  100, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  vex::task::sleep(2200);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(600);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(200);

  ClawMotor1.stop(vex::brakeType::hold);
  ClawMotor2.stop(vex::brakeType::hold);

  // Drive Swerve Backwards

  LeftDrive1.spin(vex::directionType::rev,  100, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  vex::task::sleep(600);

  LeftDrive1.spin(vex::directionType::rev,  60, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  vex::task::sleep(1300);

  LeftDrive1.spin(vex::directionType::rev,  100, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  vex::task::sleep(1100);

  LeftDrive1.spin(vex::directionType::rev,  100, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  vex::task::sleep(600);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(300);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(200);

  ClawMotor1.stop(vex::brakeType::hold);
  ClawMotor2.stop(vex::brakeType::hold);

  // Drive Forwards

  ClawMotor1.spin(forward, 200, vex::velocityUnits::rpm);
  ClawMotor2.spin(forward, 200, vex::velocityUnits::rpm);
  vex::task::sleep(300);

  LeftDrive1.spin(vex::directionType::fwd,  100, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  vex::task::sleep(2200);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(600);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(200);

  ClawMotor1.stop(vex::brakeType::hold);
  ClawMotor2.stop(vex::brakeType::hold);

}

void J_backRedAuto5stack15sec(){
  startup();
  vex::task::sleep(50);

  ClawMotor1.spin(forward, 200, vex::velocityUnits::rpm);
  ClawMotor2.spin(forward, 200, vex::velocityUnits::rpm);
  vex::task::sleep(300);

  LeftDrive1.spin(vex::directionType::fwd,  80, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  vex::task::sleep(2200);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(100);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(50);

  // Drive Swerve Backwards

  LeftDrive1.spin(vex::directionType::rev,  100, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  vex::task::sleep(600);

  LeftDrive1.spin(vex::directionType::rev,  40, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 40, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  vex::task::sleep(1600);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(100);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(50);

  // Drive Swerve Forward

  ClawMotor1.spin(forward, 200, vex::velocityUnits::rpm);
  ClawMotor2.spin(forward, 200, vex::velocityUnits::rpm);
  vex::task::sleep(100);

  // LeftDrive1.spin(vex::directionType::fwd,  100, vex::velocityUnits::rpm);
  // LeftDrive2.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  // RightDrive1.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  // RightDrive2.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  // vex::task::sleep(600);

  LeftDrive1.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd, 95, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 95, vex::velocityUnits::rpm);
  
  ClawMotor1.spin(vex::directionType::rev, 140, vex::velocityUnits::rpm);
  ClawMotor2.spin(vex::directionType::rev, 140, vex::velocityUnits::rpm);
  vex::task::sleep(600);

  ClawMotor1.stop(vex::brakeType::brake);
  ClawMotor2.stop(vex::brakeType::brake);


  TrayMotor.spin(vex::directionType::fwd, 60, vex::velocityUnits::rpm);

  vex::task::sleep(600);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(3200);

  // ClawMotor1.spin(vex::directionType::fwd, 140, vex::velocityUnits::rpm);
  // ClawMotor2.spin(vex::directionType::fwd, 140, vex::velocityUnits::rpm);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(200);

  // ClawMotor1.spin(forward, 200, vex::velocityUnits::rpm);
  // ClawMotor2.spin(forward, 200, vex::velocityUnits::rpm);
  // vex::task::sleep(100);

  TrayMotor.stop(vex::brakeType::hold);

  ClawMotor1.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  ClawMotor2.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  vex::task::sleep(200);
  ClawMotor1.spin(vex::directionType::rev, 40, vex::velocityUnits::rpm);
  ClawMotor2.spin(vex::directionType::rev, 40, vex::velocityUnits::rpm);
  vex::task::sleep(500);

  LeftDrive1.spin(vex::directionType::rev,  20, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 20, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::rev, 20, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::rev, 20, vex::velocityUnits::rpm);




}

void J_blueAutoFront2InGoal15Sec(){
  startup();
  vex::task::sleep(50);

  ClawMotor1.spin(forward, 80, vex::velocityUnits::rpm);
  ClawMotor2.spin(forward, 80, vex::velocityUnits::rpm);
  vex::task::sleep(100);

  LeftDrive1.spin(vex::directionType::fwd,  80, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  vex::task::sleep(1500);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(300);

  ClawMotor1.stop(vex::brakeType::hold);
  ClawMotor2.stop(vex::brakeType::hold);

   //Turn Right

  LeftDrive1.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  vex::task::sleep(1300);

  ClawMotor1.spin(forward, 80, vex::velocityUnits::rpm);
  ClawMotor2.spin(forward, 80, vex::velocityUnits::rpm);
  vex::task::sleep(100);

  LeftDrive1.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  vex::task::sleep(500);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(500);

  //Drive Forward

  LeftDrive1.spin(vex::directionType::fwd,  60, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 60, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd, 60, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 60, vex::velocityUnits::rpm);
  vex::task::sleep(1000);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(300);

  ClawMotor1.stop(vex::brakeType::hold);
  ClawMotor2.stop(vex::brakeType::hold);

  LeftDrive1.spin(vex::directionType::fwd,  60, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 60, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd, 60, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 60, vex::velocityUnits::rpm);
  vex::task::sleep(900);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(300);

  ClawMotor1.spin(reverse, 40, vex::velocityUnits::rpm);
  ClawMotor2.spin(reverse, 40, vex::velocityUnits::rpm);
  vex::task::sleep(3000);
  ClawMotor1.stop(vex::brakeType::coast);
  ClawMotor2.stop(vex::brakeType::coast);

  LeftDrive1.spin(vex::directionType::rev,  60, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  vex::task::sleep(1750);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(300);


}

void J_driveStraightAuto(){
  startup();
  vex::task::sleep(50);

  ClawMotor1.spin(reverse, 80, vex::velocityUnits::rpm);
  ClawMotor2.spin(reverse, 80, vex::velocityUnits::rpm);
  vex::task::sleep(100);

  LeftDrive1.spin(vex::directionType::fwd,  80, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 80, vex::velocityUnits::rpm);
  vex::task::sleep(3000);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(300);

  // Drive Backwards

  LeftDrive1.spin(vex::directionType::rev,  80, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 80, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::rev, 80, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::rev, 80, vex::velocityUnits::rpm);
  vex::task::sleep(1500);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(50);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(300);

  ClawMotor1.stop(vex::brakeType::hold);
  ClawMotor2.stop(vex::brakeType::hold);
}


// Collingwood
void redBack7c60s(){
  ClawMotor1.spin(forward, 120, vex::velocityUnits::rpm);
  ClawMotor2.spin(forward, 120, vex::velocityUnits::rpm);
  driveforward(48, true);
  ClawMotor1.stop(vex::brakeType::hold);
  ClawMotor2.stop(vex::brakeType::hold);


  // Drive Swerve Backwards

  LeftDrive1.spin(vex::directionType::rev,  100, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  vex::task::sleep(600);

  LeftDrive1.spin(vex::directionType::rev,  60, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  vex::task::sleep(1300);

  LeftDrive1.spin(vex::directionType::rev,  100, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  vex::task::sleep(1100);

  LeftDrive1.spin(vex::directionType::rev,  100, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  vex::task::sleep(600);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(300);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(200);

    // Collect next 3 blocks
  ClawMotor1.spin(forward, 140, vex::velocityUnits::rpm);
  ClawMotor2.spin(forward, 140, vex::velocityUnits::rpm);
  driveforward(48, true);
  ClawMotor1.stop(vex::brakeType::hold);
  ClawMotor2.stop(vex::brakeType::hold);

  drivebackward(24, true);

  LeftDrive1.spin(forward, 120, vex::velocityUnits::rpm);
  LeftDrive2.spin(forward, 120, vex::velocityUnits::rpm);
  vex::task::sleep(1400);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(300);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);

  driveforward(37, true);



}


void redBack4c15s(){
  ClawMotor1.spin(forward, 120, vex::velocityUnits::rpm);
  ClawMotor2.spin(forward, 120, vex::velocityUnits::rpm);
  driveforward(48, true);
  ClawMotor1.stop(vex::brakeType::hold);
  ClawMotor2.stop(vex::brakeType::hold);


  // Drive Swerve Backwards

  LeftDrive1.spin(vex::directionType::rev,  100, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  vex::task::sleep(600);

  LeftDrive1.spin(vex::directionType::rev,  60, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::rev, 60, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  vex::task::sleep(1300);

  LeftDrive1.spin(vex::directionType::fwd,  100, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd, 30, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 30, vex::velocityUnits::rpm);
  vex::task::sleep(1100);
  
  LeftDrive1.spin(vex::directionType::fwd,  100, vex::velocityUnits::rpm);
  LeftDrive2.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  RightDrive1.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  RightDrive2.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);

  ClawMotor1.spin(reverse, 60, vex::velocityUnits::rpm);
  ClawMotor2.spin(reverse, 60, vex::velocityUnits::rpm);

  vex::task::sleep(1000);
  
  ClawMotor1.stop(vex::brakeType::hold);
  ClawMotor2.stop(vex::brakeType::hold);

  LeftDrive1.stop(vex::brakeType::brake);
  LeftDrive2.stop(vex::brakeType::brake);
  RightDrive1.stop(vex::brakeType::brake);
  RightDrive2.stop(vex::brakeType::brake);
  vex::task::sleep(300);

  LeftDrive1.stop(vex::brakeType::coast);
  LeftDrive2.stop(vex::brakeType::coast);
  RightDrive1.stop(vex::brakeType::coast);
  RightDrive2.stop(vex::brakeType::coast);
  vex::task::sleep(200);

  TrayMotor.spin(fwd, 100, vex::velocityUnits::pct);
  vex::task::sleep(500);
  ClawMotor1.spin(forward, 140, vex::velocityUnits::rpm);
  ClawMotor2.spin(forward, 140, vex::velocityUnits::rpm);
  vex::task::sleep(1000);

  ClawMotor1.stop(vex::brakeType::coast);
  ClawMotor2.stop(vex::brakeType::coast);

  ClawMotor1.spin(reverse, 100, vex::velocityUnits::rpm);
  ClawMotor2.spin(reverse, 100, vex::velocityUnits::rpm);
  vex::task::sleep(100);

  ClawMotor1.stop(vex::brakeType::coast);
  ClawMotor2.stop(vex::brakeType::coast);

  ClawMotor1.spin(reverse, 140, vex::velocityUnits::rpm);
  ClawMotor2.spin(reverse, 140, vex::velocityUnits::rpm);
  vex::task::sleep(1000);

  ClawMotor1.stop(vex::brakeType::coast);
  ClawMotor2.stop(vex::brakeType::coast);
  TrayMotor.stop();
  ClawMotor1.spin(reverse, 140, vex::velocityUnits::rpm);
  ClawMotor2.spin(reverse, 140, vex::velocityUnits::rpm);
  vex::task::sleep(1000);

  ClawMotor1.stop(vex::brakeType::coast);
  ClawMotor2.stop(vex::brakeType::coast);
  drivebackward(12, false);


}

/*------------------------------------------------------------------------*/

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
J_driveStraightAuto();
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
  // User control code here, inside the loop
  bool liftPresetA = false;
  bool liftPresetB = false;
  while (1) {
    // Display that the program has started to the screen.
    Brain.Screen.print("Driver Tank Control Program Started");

    //Set speed of lift
    int LiftMotorspeed = 80;
    int ClawMotorspeed = 100;
    int SlowClawMotor = 50;
    int DownTrayMotorSpeed = 100;
    int UpTrayMotorSpeed = 100;
    
    // Create an infinite loop so that the program can pull remote control values every iteration.
    // This loop causes the program to run forever.
    while(1) {
      //Drive Control
      //Set the left and right motor to spin forward using the controller's Axis positions as the velocity value.
      // LeftDrive1.spin(vex::directionType::fwd, Controller1.Axis3.position() / 5 * 3, vex::velocityUnits::pct);
      // LeftDrive2.spin(vex::directionType::fwd, Controller1.Axis3.position() / 5 * 3, vex::velocityUnits::pct);
      // RightDrive1.spin(vex::directionType::fwd, Controller1.Axis2.position() /5 * 3, vex::velocityUnits::pct);
      // RightDrive2.spin(vex::directionType::fwd, Controller1.Axis2.position() /5 * 3, vex::velocityUnits::pct);

      //Arcade Control
      LeftDrive1.spin(directionType::fwd, ((Controller1.Axis3.value() + Controller1.Axis4.value()*.75)/2), velocityUnits::pct); //(Axis3+Axis4)/2;
      RightDrive1.spin(directionType::fwd, ((Controller1.Axis3.value() - Controller1.Axis4.value()*.75)/2), velocityUnits::pct);//(Axis3-Axis4)/2;
      LeftDrive2.spin(directionType::fwd, ((Controller1.Axis3.value() + Controller1.Axis4.value()*.75)/2), velocityUnits::pct); //(Axis3+Axis4)/2;
      RightDrive2.spin(directionType::fwd, ((Controller1.Axis3.value() - Controller1.Axis4.value()*.75)/2), velocityUnits::pct);//(Axis3-Axis4)/2;

//Lift Motor Controls
  if (Controller1.ButtonUp.pressing()) {
      LiftMotor.spin(directionType::fwd, LiftMotorspeed, velocityUnits::pct);
  }

  else if (Controller1.ButtonA.pressing()) {
    LiftMotor.resetRotation();
  }

  else if (Controller1.ButtonDown.pressing()) {
      LiftMotor.spin(directionType::rev, LiftMotorspeed, velocityUnits::pct);
  }
  else if (Controller1.ButtonRight.pressing()){
    liftPresetA = true;
    liftPresetB = false;
  }
  else if (Controller1.ButtonLeft.pressing()){
    liftPresetA = false;
    liftPresetB = true;
  }

  else if (liftPresetA == true){
    if (LiftMotor.rotation(vex::rotationUnits::deg) <= 640){
        LiftMotor.spin(directionType::fwd, 100, velocityUnits::pct);
    }
    else{
      LiftMotor.stop(brakeType::hold);
      liftPresetA = false;
    }
  }

  else if (liftPresetB == true){
    if (LiftMotor.rotation(vex::rotationUnits::deg) <= 760){
        LiftMotor.spin(directionType::fwd, 100, velocityUnits::pct);
    }
    else{
      LiftMotor.stop(brakeType::hold);
      liftPresetB = false;
    }
  }

  else {
      LiftMotor.stop(brakeType::hold);
  }


//Tray Motor Controls
  if(Controller1.ButtonL1.pressing()) {
      TrayMotor.spin(directionType::fwd, UpTrayMotorSpeed, velocityUnits::pct);
  }
  else if(Controller1.ButtonL2.pressing()) {
      TrayMotor.spin(directionType::rev, DownTrayMotorSpeed, velocityUnits::pct);
  }
  else {
      TrayMotor.stop(brakeType::hold);
  }

//Claw Motor Controls
        if(Controller1.ButtonR1.pressing()) {
            ClawMotor1.spin(directionType::fwd, ClawMotorspeed, velocityUnits::pct);
            ClawMotor2.spin(directionType::fwd, ClawMotorspeed, velocityUnits::pct);
        }
        else if(Controller1.ButtonR2.pressing()) {
            ClawMotor1.spin(directionType::rev, ClawMotorspeed, velocityUnits::pct);
            ClawMotor2.spin(directionType::rev, ClawMotorspeed, velocityUnits::pct);
        }

        else if(Controller1.ButtonY.pressing()) {
            ClawMotor1.spin(directionType::fwd, SlowClawMotor, velocityUnits::pct);
            ClawMotor2.spin(directionType::fwd, SlowClawMotor, velocityUnits::pct);
        }
        else if(Controller1.ButtonX.pressing()) {
            ClawMotor1.spin(directionType::rev, SlowClawMotor, velocityUnits::pct);
            ClawMotor2.spin(directionType::rev, SlowClawMotor, velocityUnits::pct);
        }
        else {
            ClawMotor1.stop(brakeType::hold);
            ClawMotor2.stop(brakeType::hold);
        }

    // Sleep the task for a short amount of time to prevent wasted resources.
    vex::task::sleep(20);
    }

    wait(20, msec); // Sleep the task for a short amount of time to prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
