// This program is made to 
// find the motor values
// for the Smart SOlar Tracker
#include <Servo.h>
int servoPin=9;
int servoPos= 67.5
 
;
Servo myServo; 
 
void setup(){
Serial.begin(9600);
myServo.attach(servoPin);
}
 
void loop(){
myServo.write(servoPos);
Serial.println (servoPos);
delay (500);


}
