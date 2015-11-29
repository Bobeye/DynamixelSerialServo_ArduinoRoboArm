#include <DynamixelSerial1.h>
#include <SPI.h>  
#include <Pixy.h>


int jointSpeed1 = 350;
int jointSpeed = 150;

Pixy pixy;

void setup(){
  
  Serial.begin(9600);
  
  Dynamixel.begin(1000000,2);  // Inicialize the servo at 1Mbps and Pin Control 2
  delay(1000);
  pixy.init();
  Serial.println("Let's ROck!!!");
}

void loop(){
  uint16_t blocks;
  
  blocks = pixy.getBlocks();
  if(blocks) {
    Serial.println("no blocks!!!!!!!!");
    Dynamixel.moveSpeed(1,200,jointSpeed1);
  //Dynamixel.move(3,random(200,800));  // Move the Servo radomly from 200 to 800

  Dynamixel.moveSpeed(3,300,jointSpeed);

  //Dynamixel.move(5,random(200,800));  // Move the Servo radomly from 200 to 800

  Dynamixel.moveSpeed(5,400,jointSpeed);
  Dynamixel.moveSpeed(7,500,jointSpeed);

  delay(1000);
  }
  else {
    Serial.println("blocks!!!!!!!!");
  //Dynamixel.move(1,random(200,800));  // Move the Servo radomly from 200 to 800
  Dynamixel.moveSpeed(1,random(200,1000),jointSpeed1);
  //Dynamixel.move(3,random(200,800));  // Move the Servo radomly from 200 to 800

  Dynamixel.moveSpeed(3,random(200,800),jointSpeed);

  //Dynamixel.move(5,random(200,800));  // Move the Servo radomly from 200 to 800

  Dynamixel.moveSpeed(5,random(200,800),jointSpeed);
  Dynamixel.moveSpeed(7,random(200,800),jointSpeed);
  delay(200);
    
    
   
  }
  
 
delay(100);

}
