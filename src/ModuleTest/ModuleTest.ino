#include "N20SEA.h"

const int pinsA1[4] = {5,4,3,A0}; //DIR1 DIR1 PWM OuterSensor

const float kA[3] = {3.0,1.0,0.0005}; // PID values, kp, kd, ki
const int refsA[2] = {510,240}; //analog reference for outer sensor angle 0 (vertical) and 90 (horizontal to the right)
const int refsB[2] = {510,240}; //analog reference for inner sensor angle 0 (vertical) and 90 (horizontal to the right)

int c = 0;

N20SEA MA1;

void setup() {

 MA1.assignpins(pinsA1);
 MA1.assigntorquesens(A1); // inner angle sensor pin
 MA1.setrefsB(refsB); //refs for inner sensor
 MA1.setk(kA); 
 MA1.setrefs(refsA); //refs for outer sensor
 Serial.begin(9600);
 pinMode(6,OUTPUT); // needed for the driver
 digitalWrite(6,HIGH);

}

void loop() {

if(Serial.available()>0){

c=Serial.parseInt()*1.0;

}

MA1.goTo(c,200); // to position c at 200 pwm max

Serial.print(-800); //to graph the "torsion"
Serial.print(" ");
Serial.print(800);
Serial.print(" ");
Serial.println(MA1.torque());

}

