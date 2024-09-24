#include "RobotLeg.h"

const int pinsA1[4] = {10,11,2,A0};
const int pinsA2[4] = {13,12,3,A2};
const int pinsB1[4] = {14,15,4,A4};
const int pinsB2[4] = {16,17,5,A6};
const int pinsC1[4]= {19,18,6,A8};
const int pinsC2[4]= {20,21,7,A10};
const int pinsD1[4]= {23,22,8,A12};
const int pinsD2[4]= {25,24,9,A14};
const float kA1[3] = {3.0,5.0,0.005}; // PID values, kp, kd, ki
const float kA2[3] = {3.0,5.0,0.005}; // PID values, kp, kd, ki
const float kB1[3] = {3.0,5.0,0.005}; // PID values, kp, kd, ki
const float kB2[3] = {3.0,5.0,0.005}; // PID values, kp, kd, ki
const float kC1[3] = {3.0,5.0,0.005}; // PID values, kp, kd, ki
const float kC2[3] = {3.0,5.0,0.005}; // PID values, kp, kd, ki
const float kD1[3] = {3.0,5.0,0.005}; // PID values, kp, kd, ki
const float kD2[3] = {3.0,5.0,0.005}; // PID values, kp, kd, ki
const float kB[3] = {5.0,1.5,0.00001}; // PID values, kp, kd, ki
const int refsA1[2] = {510,255}; //analog reference for angle 0 and 90 (from the horizontal)
const int refsA2[2] = {510,255}; 
const int refsB1[2] = {510,255}; 
const int refsB2[2] = {510,255}; 
const int refsC1[2] = {510,255}; //analog reference for angle 0 and 90 (from the horizontal)
const int refsC2[2] = {510,255}; 
const int refsD1[2] = {510,255}; 
const int refsD2[2] = {510,255}; 
const int refsA[2] = {510,255}; 

const int refsA45[2] = {638,383}; 
const int refsB45[2] = {383,128}; 
const int refsC45[2] = {383,128}; 
const int refsD45[2] = {128,383}; 


RobotLeg * L11;
RobotLeg * L12;
RobotLeg * L21;
RobotLeg * L22;

float leglengths[2] = {50.0,55.0};

unsigned long timer = 0;
unsigned long dt = 100;
unsigned long timer2 = 0;
unsigned long dt2 = 1;

float x0 = 0;
float y0 = 0;
float x = -50;
float y = 50;

String input = "";

//elliptical

float a = 30.0;
float b = 12.0;
float c = 10.0;
float d = 0.0;

float r = 0.5;
float theta = 0;

void setup() {

L11 = new RobotLeg(leglengths,1);
L11 -> create_motors();
L11 -> setup_motors(pinsA1,kB,refsA45,pinsA2,kB,refsA);
L12 = new RobotLeg(leglengths,-1);
L12 -> create_motors();
L12 -> setup_motors(pinsB1,kB,refsB45,pinsB2,kB,refsA);
L21 = new RobotLeg(leglengths,-1);
L21 -> create_motors();
L21 -> setup_motors(pinsC1,kB,refsA45,pinsC2,kB,refsA);
L22 = new RobotLeg(leglengths,-1);
L22 -> create_motors();
L22 -> setup_motors(pinsD1,kB,refsB45,pinsD2,kB,refsA);
Serial.begin(9600);
timer=millis();
timer2=millis();
pinMode(28,OUTPUT);
digitalWrite(28,HIGH);
pinMode(29,OUTPUT);
digitalWrite(29,HIGH);
pinMode(30,OUTPUT);
digitalWrite(30,HIGH);
pinMode(31,OUTPUT);
digitalWrite(31,HIGH);

}

void loop() {

// if(millis()-timer>=dt){
// // r=a*b/(sqrt(a*sin(theta)*a*sin(theta)+b*cos(theta)*b*cos(theta)));
// timer=millis();
// d=d+r;  
// if(d>=5){
// r=-r;
// }
// if(d<=-25){
// r=-r;
// }
// }


// if(Serial.available()>0){

// d=Serial.parseInt()*1.0;

// }


if(millis()-timer>=dt){


r=a*b/sqrt(b*sin(theta)*b*sin(theta)+a*cos(theta)*a*cos(theta));
theta=(theta*4068/71)-c;
timer=millis();
theta=theta*71/4068;


}

if(millis()-timer2>=dt2){

timer2=millis();
L11->goToI(x-x0+r*cos(theta),y-y0+r*sin(theta),255);
//L12->goToI(x-x0+r*cos(theta),y-y0+r*sin(theta),255);
//L21->goToI(x-x0+r*cos(theta+180),y-y0+r*sin(theta+180),255);
L22->goToI(x-x0+r*cos(theta+180),y-y0+r*sin(theta+180),255);

}

// L11->goToF(-55,-d,255);
// L12->goToF(55,d,255);
// L21->goToF(-55,-d,255);
// L22->goToF(55,d,255);

}
