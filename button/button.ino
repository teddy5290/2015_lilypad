/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */
const int buttonPin = A5;     // the number of the pushbutton pin
const int ledPin =  5
 ;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status





// the setup function runs once when you press reset or power the board
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(A5, INPUT);     
  digitalWrite(A5, HIGH);	
}

// the loop function runs over and over again forever
void loop() {

  // read the state of the pushbutton value:
  buttonState = digitalRead(A5);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
  }
  

}
