
//setting Pin
const int switchPin =2;
const int buzzerPin =7; 
const int motorPin =3;
const int LED1=5;
const int LED2=6;
const int LED3=A2;
const int LED4=A4;
const int LED5=A3;
const int LEDR=9;
const int LEDB=10;
const int LEDG=11;



int songlength = 64; // number of notes in the buzzer song
int score[] = {3,0,0,2,1,0,1,0,2,0,1,0,1,0,0,0,
               3,0,0,2,1,0,1,0,2,0,5,0,3,0,0,0,
               3,0,0,2,1,0,1,0,2,0,1,0,1,0,1,2,
               9,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0};
// tone duration
int motorscore[]={0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,
                  0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,
                  0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,
                  0,0,1,0,0,0,1,0,1,1,1,1,1,1,1,1};
int ledscore[] = {1,2,3,4,5,4,3,2,1,2,3,4,5,4,3,2,
                  1,2,3,4,5,4,3,2,1,6,7,6,7,6,7,6,
                  1,2,3,4,5,4,3,2,1,2,3,4,5,4,3,2,
                  6,7,6,7,6,7,6,7,6,7,6,7,6,7,6,7};

int switchValue;
int i = 0; 
int duration=170;



void setup(){
 Serial.begin(9600); 
 pinMode(switchPin, INPUT);
 digitalWrite(switchPin, HIGH);	
 pinMode(buzzerPin, OUTPUT); 
 pinMode(motorPin, HIGH); 
 pinMode(LED1, OUTPUT); 
 pinMode(LED2, OUTPUT); 
 pinMode(LED3, OUTPUT); 
 pinMode(LED4, OUTPUT); 
 pinMode(LED5, OUTPUT); 
 //pinMode(LEDR, OUTPUT); 
 //pinMode(LEDG, OUTPUT); 
 //pinMode(LEDB, OUTPUT); 


 }


void loop(){

   switchValue = digitalRead(switchPin);
   if (switchValue == LOW) {
      
     //reset
     if(i==songlength)
     {   
     digitalWrite(motorPin, LOW);
     led(0);
     i=0;
     delay (3000);
     }
     
   //motor
    if (motorscore[i]==1){
    digitalWrite(motorPin, HIGH);
    }else if(motorscore[i]==0)
    digitalWrite(motorPin, LOW);
   
   //tone
   
    if(score[i]!=0){
    
      if(score[i]==4 || score[i]==9){
    tone(buzzerPin,frequency(score[i]),duration*7);
    }
    tone(buzzerPin,frequency(score[i]),duration);
    }
    
    //LED
    led(ledscore[i]);
    
    //
    delay(duration);
    
    i++;
   }//end switch if 
     
   else{
     //reset 
     i=0;
     digitalWrite(motorPin, LOW);
     led(0);
   }
     
}



int frequency(int note) 
{ 
  // This function takes a note character (a-g), and returns the
  // corresponding frequency in Hz for the tone() function.

  int j;
  const int numNotes = 9;  // number of notes we're storing

  // The following arrays hold the note characters and their
  // corresponding frequencies. The last "C" note is uppercase
  // to separate it from the first lowercase "c". If you want to
  // add more notes, you'll need to use unique characters.

  // For the "char" (character) type, we put single characters
  // in single quotes.

  int names[] = { 1,2,3,4,5,6,7,8,9 };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523, 311};
  /*
  note  frequency
  c     262 Hz
  d     294 Hz
  e     330 Hz
  f     349 Hz
  g     392 Hz
  a     440 Hz
  b     494 Hz
  C     523 Hz
  d#    311 Hz
 */ 

  // Now we'll search through the letters in the array, and if
  // we find it, we'll return the frequency for that note.

  for (j = 0; j < numNotes; j++)  // Step through the notes
  {
    if (names[j] == note)         // Is this the one?
    {
      return(frequencies[j]);     // Yes! Return the frequency
    }
  }
 
  return(0);  // We looked through everything and didn't find it,
              // but we still need to return a value, so return 0.
}


void led(int pattern){
switch(pattern){
  case 1:
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
  digitalWrite(LED5,LOW);
  break;
  case 2:
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
  digitalWrite(LED5,LOW);
  break;
  case 3:
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,HIGH);
  digitalWrite(LED4,LOW);
  digitalWrite(LED5,LOW);
  break;
  case 4:
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,HIGH);
  digitalWrite(LED5,LOW);
  break;
  case 5:
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
  digitalWrite(LED5,HIGH);
  break;
  case 6:
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,HIGH);
  digitalWrite(LED4,LOW);
  digitalWrite(LED5,HIGH);
  break;
  case 7:
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,HIGH);
  digitalWrite(LED5,LOW);
  break;
  case 8:
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
  digitalWrite(LED5,LOW);
  break;
  default:
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
  digitalWrite(LED5,LOW);
}
}
 
 	 
void color (unsigned char red, unsigned char green, unsigned char blue)     // the color generating function
{	 
          analogWrite(LEDR, 255-red);	 
          analogWrite(LEDB, 255-blue);
          analogWrite(LEDG, 255-green);
}	 
