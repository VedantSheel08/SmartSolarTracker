int eastLDR = 0;
int westLDR = 0;
int Einput = A3;
int Winput = A4;
int difference;

void setup(){ 
  
Serial.begin(9600);

}
 void loop() {
pinMode (Einput,INPUT);
pinMode (Winput,INPUT);
eastLDR =(analogRead(Einput));
westLDR =(analogRead(Winput));
difference = (eastLDR - westLDR);
Serial.println ("---------------------------------");
Serial.print ("East LDR value is ") ;
Serial.println (eastLDR);
Serial.print ("West LDR value is ") ;
Serial.println (westLDR);
Serial.print ("Difference is equal to ");
Serial.println (difference);
Serial.println ("---------------------------------");
delay (2500);


 }
