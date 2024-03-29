using namespace vex;
using namespace std;

#ifndef MOTOR_H
#define MOTOR_H
#include <string>

class Motor{
  public:
    Motor(string name); //Constructor
    string getName(); //Getter for name
    void wait(int time); //Shorter wait function
    void go(int speed=200); //Shorter drive function
    void brake1(); //Shorter brake function (brake)
    void brake2(); //Shorter brake function (coast)
    void stop(); //Brake 1 and 2 with wait
  private:
    string name;
};
#endif // MOTOR_H
