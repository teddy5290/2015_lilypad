
// Display the temperature every two second
// you should open the serial moniter (ctrl+shift+m);


int tempsensorPin=A1;
float supply_voltage=5.0;

void setup(){
Serial.begin(9600);
delay(300);
Serial.println("Hello Hello");
delay(700);

}

void loop(){
  Serial.println( get_temperature() );
  delay (3000);
}

const float get_temperature(){
  const int sensor_voltage=analogRead(tempsensorPin);
  const float voltage=sensor_voltage*supply_voltage/1024;
  return (voltage*1000-500)/10;
}
