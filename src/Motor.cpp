#include "vex.h"
#include "Motor.h"
#include <string>
 
using namespace vex;
using namespace std;
 
Motor::Motor(string a):name(a){} //Motor constructor
string Motor::getName(){return name;} //Getter (If needed?)
void Motor::wait(int time){vex::task::sleep(time);} //Shorter function for wait
 
//Shorter drive function for just speed
void Motor::go(int speed){
  if (speed > 0){
    if (name == "Left"){MLeft1.spin(vex::directionType::fwd,  speed, vex::velocityUnits::rpm); MLeft2.spin(vex::directionType::fwd,  speed, vex::velocityUnits::rpm);}
    else if (name == "Right"){MRight1.spin(vex::directionType::rev,  speed, vex::velocityUnits::rpm); MRight2.spin(vex::directionType::rev,  speed, vex::velocityUnits::rpm);}
    else if (name == "Input"){MInput1.spin(vex::directionType::fwd,  speed, vex::velocityUnits::rpm); MInput2.spin(vex::directionType::rev,  speed, vex::velocityUnits::rpm);}
    else if (name == "Roller"){MRoller.spin(vex::directionType::rev,  speed, vex::velocityUnits::rpm);}
    else if (name == "Output"){MOutput.spin(vex::directionType::fwd,  speed, vex::velocityUnits::rpm);} 
  }
  else{
    speed = 0 - speed;
    if (name == "Left"){MLeft1.spin(vex::directionType::rev,  speed, vex::velocityUnits::rpm); MLeft2.spin(vex::directionType::rev,  speed, vex::velocityUnits::rpm);}
    else if (name == "Right"){MRight1.spin(vex::directionType::fwd,  speed, vex::velocityUnits::rpm); MRight2.spin(vex::directionType::fwd,  speed, vex::velocityUnits::rpm);}
    else if (name == "Input"){MInput1.spin(vex::directionType::rev,  speed, vex::velocityUnits::rpm); MInput2.spin(vex::directionType::fwd,  speed, vex::velocityUnits::rpm);}
    else if (name == "Roller"){MRoller.spin(vex::directionType::fwd,  speed, vex::velocityUnits::rpm);}
    else if (name == "Output"){MOutput.spin(vex::directionType::rev,  speed, vex::velocityUnits::rpm);} 
  } 
}

//Shorter brake function (brake)
void Motor::brake1(){
  if (name == "Left"){MLeft1.stop(vex::brakeType::brake); MLeft2.stop(vex::brakeType::brake);}
  else if (name == "Right"){MRight1.stop(vex::brakeType::brake); MRight2.stop(vex::brakeType::brake);}
  else if (name == "Input"){MInput1.stop(vex::brakeType::brake); MInput2.stop(vex::brakeType::brake);}
  else if (name == "Roller"){MRoller.stop(vex::brakeType::brake);}
  else if (name == "Output"){MOutput.stop(vex::brakeType::brake);} 
}
//Shorter brake function (coast)
void Motor::brake2(){
  if (name == "Left"){MLeft1.stop(vex::brakeType::coast); MLeft2.stop(vex::brakeType::coast);}
  else if (name == "Right"){MRight1.stop(vex::brakeType::coast); MRight2.stop(vex::brakeType::coast);}
  else if (name == "Input"){MInput1.stop(vex::brakeType::coast); MInput2.stop(vex::brakeType::coast);}
  else if (name == "Roller"){MRoller.stop(vex::brakeType::coast);}
  else if (name == "Output"){MOutput.stop(vex::brakeType::coast);} 
}
void Motor::stop(){brake1(); wait(50); brake2();} //Brake 1 and 2 with wait
