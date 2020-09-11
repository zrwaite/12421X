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
    void go(int speed); //Shorter drive function
    void brake1(); //Shorter brake function (brake)
    void brake2(); //Shorter brake function (coast)
    void stop(); //Brake 1 and 2 with wait
    double DFT(float dist, int speed); // Returns the amount of time reuired to travel a given distance at a given speed
    void DD(float distance, int speed); // Drives For Distance at Inputted Speed
  private:
    string name;
};
#endif // MOTOR_H