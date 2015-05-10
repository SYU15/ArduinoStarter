const int sensorPin = A0;
//degrees in celsius
const float baselineTemp = 22.0;

void setup() {
  //opens a serial port, 9600 bits per second
Serial.begin(9600);
//write for loop to iterate through all LEDs (which are the same)
for(int pinNumber = 2; pinNumber < 5; pinNumber ++) {
pinMode(pinNumber, OUTPUT);
digitalWrite(pinNumber, LOW);
}

}

void loop() {
//takes the reading of the temperature sensor  
  int sensorVal = analogRead(sensorPin);
  
  //prints out what the value is
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  
  //converts the sensor reading into voltage
  float voltage = (sensorVal/1024.0)*5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  
  //10 milivolts = 1 degree Celsius change
  //convert voltage to temperature in degrees
  float temperature = (voltage - .5) *100;
  Serial.println(temperature);
  
  //lights light up based on temperature levels
  if(temperature < baselineTemp) {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  }
 else if(temperature >= baselineTemp +2 && temperature < baselineTemp +4) {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  }
  else if(temperature >= baselineTemp +4 && temperature < baselineTemp +6) {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  }
  else if(temperature >= baselineTemp +6) {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  }
  //add delay at the end so results are not erratic
delay(1);
}
