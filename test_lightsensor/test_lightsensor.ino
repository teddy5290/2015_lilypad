
// Display the voltage by the light sensor every three second
// you should open the serial moniter (ctrl+shift+m);

/*
This is a simple to use light sensor that outputs an analog value from 0 to HIGH (the highest voltage in your circuit). 
With exposure to daylight, this sensor will output HIGH. Covering the sensor with your hand, the sensor will output 0V. 
In a normal indoor lighting situation, the sensor will output a voltage between 1/4 and 1/3 of your HIGH voltage
*/

int lightsensorPin=A6;
float supply_voltage=5.0;
float voltage;

void setup(){
Serial.begin(9600);
delay(300);
Serial.println("Hello Hello");
delay(700);

}

void loop(){
  voltage=analogRead(lightsensorPin)*supply_voltage/1024;
  Serial.print( voltage );
  Serial.println(" V");
  delay (3000);
}
