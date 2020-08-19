using namespace vex;
using namespace std;

#ifndef MOTOR_H
#define MOTOR_H
#include <string>

class Motor
{
  public:
    Motor(string name);
    string getName();
    void setName(string);
    void drive(int speed);
    void stop();

  private:
    string name;
};

#endif // MOTOR_H