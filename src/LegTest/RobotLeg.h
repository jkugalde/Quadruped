#ifndef RobotLeg_h
#define RobotLeg_h

#include "N20Servo.h"

class RobotLeg
{

    public:
    N20Servo * _MA;
    N20Servo * _MB;
    RobotLeg(float lengths[2], int side);
    ~RobotLeg();
    void goToF(float q1, float q2, int pwm);
    void goToI(float x, float y, int pwm);
    int getPos(int i);
    void forwardk(float q1, float q2);
    void create_motors();
    void setup_motors(int A_pins[4],float A_ks[3],int A_refs[2],int B_pins[4],float B_ks[3],int B_refs[2]);

    private:

      float _x;
      float _y;
      float _q1;
      float _q2;
      float _a1;
      float _a2;
      int _side;


};

#endif //RobotLeg
