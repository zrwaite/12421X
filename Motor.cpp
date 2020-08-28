#include "vex.h"
#include "Motor.h"
#include <string>

using namespace vex;
using namespace std;

Motor::Motor(string a):name(a)
{ 

}

string Motor::getName(){
  return name;
}

void Motor::setName(string a){
  name = a;
}

void Motor::wait(int time){vex::task::sleep(time);}

void Motor::drive(int speed){
  if (speed > 0){
    if (name == "Left1"){MLeft1.spin(vex::directionType::fwd,  speed, vex::velocityUnits::rpm);}
    else if (name == "Left2"){MLeft2.spin(vex::directionType::fwd,  speed, vex::velocityUnits::rpm);}
    else if (name == "Right1"){MRight1.spin(vex::directionType::fwd,  speed, vex::velocityUnits::rpm);}
    else if (name == "Right2"){MRight2.spin(vex::directionType::fwd,  speed, vex::velocityUnits::rpm);}
    else if (name == "Input1"){MInput1.spin(vex::directionType::fwd,  speed, vex::velocityUnits::rpm);}
    else if (name == "Input2"){MInput2.spin(vex::directionType::fwd,  speed, vex::velocityUnits::rpm);}
    else if (name == "Roller"){MRoller.spin(vex::directionType::fwd,  speed, vex::velocityUnits::rpm);}
    else if (name == "Output"){MOutput.spin(vex::directionType::fwd,  speed, vex::velocityUnits::rpm);}
  }
  else{
    speed = 0 - speed;
    if (name == "Left1"){MLeft1.spin(vex::directionType::rev,  speed, vex::velocityUnits::rpm);}
    else if (name == "Left2"){MLeft2.spin(vex::directionType::rev,  speed, vex::velocityUnits::rpm);}
    else if (name == "Right1"){MRight1.spin(vex::directionType::rev,  speed, vex::velocityUnits::rpm);}
    else if (name == "Right2"){MRight2.spin(vex::directionType::rev,  speed, vex::velocityUnits::rpm);}
    else if (name == "Input1"){MInput1.spin(vex::directionType::rev,  speed, vex::velocityUnits::rpm);}
    else if (name == "Input2"){MInput2.spin(vex::directionType::rev,  speed, vex::velocityUnits::rpm);}
    else if (name == "Roller"){MRoller.spin(vex::directionType::rev,  speed, vex::velocityUnits::rpm);}
    else if (name == "Output"){MOutput.spin(vex::directionType::rev,  speed, vex::velocityUnits::rpm);}
  }
  
}

void Motor::brake1(){
  if (name == "Left1"){MLeft1.stop(vex::brakeType::brake);}
  else if (name == "Left2"){MLeft2.stop(vex::brakeType::brake);}
  else if (name == "Right1"){MRight1.stop(vex::brakeType::brake);}
  else if (name == "Right2"){MRight2.stop(vex::brakeType::brake);}
  else if (name == "Input1"){MInput1.stop(vex::brakeType::brake);}
  else if (name == "Input2"){MInput2.stop(vex::brakeType::brake);}
  else if (name == "Roller"){MRoller.stop(vex::brakeType::brake);}
  else if (name == "Output"){MOutput.stop(vex::brakeType::brake);}
}
void Motor::brake2(){
  if (name == "Left1"){MLeft1.stop(vex::brakeType::coast);}
  else if (name == "Left2"){MLeft2.stop(vex::brakeType::coast);}
  else if (name == "Right1"){MRight1.stop(vex::brakeType::coast);}
  else if (name == "Right2"){MRight2.stop(vex::brakeType::coast);}
  else if (name == "Input1"){MInput1.stop(vex::brakeType::coast);}
  else if (name == "Input2"){MInput2.stop(vex::brakeType::coast);}
  else if (name == "Roller"){MRoller.stop(vex::brakeType::coast);}
  else if (name == "Output"){MOutput.stop(vex::brakeType::coast);}
}

void Motor::stop(){brake1(); wait(50); brake2();}
