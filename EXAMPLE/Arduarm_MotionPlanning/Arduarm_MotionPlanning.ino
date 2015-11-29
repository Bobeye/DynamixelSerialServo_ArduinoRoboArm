// A SCARA based robotic arm with inverse kinematics included for 3D movement

#include <DynamixelSerial1.h>
#include <math.h>

int linkA = 43;
int linkB = 136;
int linkC = 127;
int UpperJoint = 750;
int LowerJoint = 250;
int x, y, z, distance, disproject;
int alpha, belta, gama, theta;



int jointSpeed[5], jointPos[5];
int ID;
int i;

void setup(){
  
  Serial.begin(115200);
  
  Dynamixel.begin(1000000,2);  // Inicialize the servo at 1Mbps and Pin Control 2
  delay(1000);
  
  Serial.println("Let's ROck!!!");
}

void STARTPOS() {
  //jointSet
  int jointSpeed[5] = {100, 100, 100, 100};
  int jointPos[5] = {250, 250, 250, 250};
  
  //MOVE!
  for(i=0; i<4; i++) {
    ID = (2*i) + 1;
    Dynamixel.moveSpeed(ID, jointPos[i], jointSpeed[i]);
    Serial.println("StartPos");
  }
}



void loop(){
  
  STARTPOS();
  delay(5000);
  
  //jointSet
  int jointSpeed[5] = {100, 100, 100, 100};
  int jointPos[5] = {random(LowerJoint,UpperJoint), random(LowerJoint,UpperJoint), random(LowerJoint,UpperJoint), random(LowerJoint,UpperJoint)};
  
  
  //inverse kinematics
  // with given aimed postion (x, y, z), an aimed joint angle (alpha, belta, gama, theta) is calculated
  disproject = sqrt((x^2)+(y^2));
  distance = sqrt((x^2)+(y^2)+(z^2));
  float alpha = atan(y/x);
  float belta = (acos(((linkB^2)+(distance^2)-(linkC^2)) / (2 * linkB * distance))) + asin(z/distance);
  float gama = asin(distance * sin(belta) / linkC);
  
  
  
  //range check
  if (alpha < 250) { alpha = 250; }
  else if (alpha > 750) { alpha = 750; }
  else { Serial.println("alpha checked!"); }
  if 
  
  //MOVE!
  for(i=0; i<4; i++) {
    ID = (2*i) + 1;
    Dynamixel.moveSpeed(ID, jointPos[i], jointSpeed[i]);
    Serial.print(ID);
    Serial.print(jointPos[i]);
    Serial.println(jointSpeed[i]);
  }
  delay(4000);
}
