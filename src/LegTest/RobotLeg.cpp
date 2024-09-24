#include "RobotLeg.h"
#include "N20Servo.h"

RobotLeg::RobotLeg(float lengths [2], int side)
{

  _MA = (N20Servo *) malloc(sizeof(N20Servo *));
  _MA = (N20Servo *) malloc(sizeof(N20Servo *));
  _a1=lengths[0];
  _a2=lengths[1];
  _side=side;

}

RobotLeg::~RobotLeg()
{
    //dtor
}

void RobotLeg::create_motors(){

  _MA = new N20Servo();
  _MB = new N20Servo();

}

void RobotLeg::setup_motors(int A_pins[4],float A_ks[3],int A_refs[2],int B_pins[4],float B_ks[3],int B_refs[2]){

  _MA->assignpins(A_pins);
  _MA->setk(A_ks);
  _MA->setrefs(A_refs);
  _MB->assignpins(B_pins);
  _MB->setk(B_ks);
  _MB->setrefs(B_refs);

}

void RobotLeg::goToF(float q1, float q2, int pwm){
    _q1=q1;
    _q2=q2;
    _MA->goTo(q1,pwm);
    _MB->goTo(q2,pwm);
}

void RobotLeg::goToI(float x, float y, int pwm){

float q2=acos((x*x+y*y-_a1*_a1-_a2*_a2)/(2*_a1*_a2));
float q1=atan2(y,x)-atan2(_a2*sin(q2),_a1+_a2*cos(q2));

q2=q2*4068/71;
q1=q1*4068/71;

// Serial.print("q1: ");
// Serial.println(q1);
// Serial.print("q2: ");
// Serial.println(q2);
// Serial.print("x: " );
// Serial.println(x);
// Serial.print("y: ");
// Serial.println(y);

if(isnan(q1)){
  q1=_q1;
}
if(isnan(q2)){
  q2=_q2;
}

q1=q1-90;
q2=-q2+90;
goToF(q1,q2,pwm);

}

int RobotLeg::getPos(int i){
    
    if(i==1){
        return _MA->readSens();
    }
    else{
        return _MB->readSens();
    }
}

void RobotLeg::forwardk(float q1,float q2){

q1=q1*71/4068;
q2=q2*71/4068;

float x= 0;
float y= 0;

Serial.println(x);
Serial.println(y);

}
