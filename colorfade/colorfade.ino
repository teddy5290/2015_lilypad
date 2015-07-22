
/*
 * LilyPad tutorial: color (RGB LEDs)
 *
 * Uses a LilyPad RGB LED module to play with
  * dynamic colored light. See this web color chart
  * for the (Red,Green,Blue) values of different colors:
 * http://www.visibone.com/colorlab/
 */
 
int ledPin = 13;	// LED is connected to digital pin 13
int redPin = 9;	// R petal on RGB LED module connected to digital pin 11
int greenPin = 11;	// G petal on RGB LED module connected to digital pin 9
int bluePin = 10;	// B petal on RGB LED module connected to digital pin 10
int switchPin = 2;	// switch connected to digital pin 2
int switchValue;	// a variable to keep track of when switch is pressed	 
int R=0;
int B=0;
int G=0;
int fadeAmount = 5;    // how many points to fade the LED by
 
void setup()	 
{	 
         pinMode(ledPin, OUTPUT);	// sets the ledPin to be an output
         pinMode(redPin, OUTPUT);	// sets the redPin to be an output
         pinMode(greenPin, OUTPUT);	// sets the greenPin to be an output
         pinMode(bluePin, OUTPUT);	// sets the bluePin to be an output
         
         pinMode(switchPin, INPUT);	// sets the switchPin to be an input
         digitalWrite(switchPin, HIGH);	// sets the default (unpressed) state of switchPin to HIGH
}	 
 	 
void loop()	// run over and over again
{	 
  
          switchValue = digitalRead(switchPin);	// check to see if the switch is pressed
          if (switchValue == LOW) {	// if the switch is pressed then,
             // Basic colors:
          R=255;
          
          //red->orange
          while(G<128)
          { color(R,G,B);
            G=G+fadeAmount;
            delay(100);
          }
          
          while(G<255)
          { color(R,G,B);
            G=G+fadeAmount;
            delay(100);
          }
          
          while(R>0)
          { color(R,G,B);
            R=R-fadeAmount;
            delay(100);
          }
          
          while(G>0)
          { color(R,G,B);
            G=G-fadeAmount;
            B=B+fadeAmount;
            delay(100);
          }
          
          while(R<64)
          { color(R,G,B);
            R=R+fadeAmount;
            delay(100);
          }
          
          while(R<128)
          { color(R,G,B);
            R=R+fadeAmount;
            delay(100);
          }
          
          while(R<255)
          {color(R,G,B);
           R=R+fadeAmount;
           B=B-fadeAmount;
           if(B<0)
           B=0;
          
          }
          
          }	 
          else {	// otherwise,
                   color(0,0,0);	// turn the RGB LED off
          }
         
}	 
 	 
void color (unsigned char red, unsigned char green, unsigned char blue)     // the color generating function
{	 
          analogWrite(redPin, 255-red);	 
          analogWrite(bluePin, 255-blue);
          analogWrite(greenPin, 255-green);
}	 
 
