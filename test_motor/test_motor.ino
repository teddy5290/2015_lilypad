/*	
* LilyPad sample code, vibrate a motor attached to pin 9	
*/


int motor = 3;	// motor is connected to digital pin 5

void setup()	
{	
pinMode(motor, HIGH);

}	
void loop()	// run over and over again
{	
digitalWrite(motor, HIGH);	// turn the motor on
delay(1000);	// delay for 1 second
digitalWrite(motor, LOW);	// turn the motor off
delay(1000);	// delay for 1 second



}	
 

 

