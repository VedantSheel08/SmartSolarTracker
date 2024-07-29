
  // This Program moves solar panel with respect to Sun movement. 
#include <Servo.h> //includes the servo library
Servo Vedantservo; // This is Servo motor name
#define ldrE A3 // Set ldr 1 as Analog input pin of East 
#define ldrW A4 // set ldr 2 as Analog input pin of West ldr as an integer
float pos = 100 ; // initial position of servo so that Solar Panel is in Center position
int tolerance = 20; // allowable tolerance setting - so solar servo motor isn't constantly in motion

void setup(){
Vedantservo.attach(9); // attaches the servo on digital pin 9 to the horizontal movement servo motor 
pinMode(ldrE, INPUT); //set East ldr pin as an input
pinMode(ldrW, INPUT); //set West ldr pin as an input
Vedantservo.write(pos); // write the starting position of the horizontal movement servo motor 
delay(1000); // 1 second delay to allow solar panel to move to its staring position before comencing solar tracking
}

void loop(){      
int EastValue = analogRead(ldrE); // read the value of ldr 1
int WestValue = analogRead(ldrW); // read the value of ldr 2

if((abs(EastValue - WestValue) <= tolerance) || (abs(WestValue - EastValue) <= tolerance)) 
{
//no servo motor horizontal movement will take place if the ldr value is within the allowable tolerance
}else {
if(EastValue > WestValue) // if ldr1 senses more light than ldr2 
{
pos = pos-1; // decrement the poistion of the horizontal servo motor - this will move the panel position Eastward
}
if(EastValue < WestValue) // if ldr2 senses more light than ldr1
{
pos = pos+1; // increment the 90 degree position of the horizontal motor - this will move the panel position Westward
 }
}
if(pos > 145) {pos = 145;} // reset the horizontal postion of the motor to 180 if it tries to move past this point
if(pos < 20) {pos = 20;} // reset the horizontal position of the motor to 0 if it tries to move past this point
Vedantservo.write(pos); // write the starting position to the horizontal motor
delay(50);
}
