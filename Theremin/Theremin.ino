int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

//indicator that sensor has finished calibrating, uses LED on arduino
const int ledPin = 13;

void setup() {
pinMode(ledPin, OUTPUT);
digitalWrite(ledPin, HIGH);

//calibrates sensor for 5000 miliseconds
while(millis() < 5000) {
  sensorValue = analogRead(A0);
if(sensorValue > sensorHigh) {
sensorHigh = sensorValue;
}
if(sensorValue < sensorLow) {
sensorLow = sensorValue;
}

}

//led turns off when done calibrating
digitalWrite(ledPin, LOW);
}

void loop() {
//set sensorValue as value through photoreceptor

sensorValue = analogRead(A0);

//sets range of frequencies that music will make (sensor low mapped to 50, sensorHigh mapped to 4000)

int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 2000);

//sets what pin to play on, frequency to play, how long it gets played
tone(8, pitch, 20);

delay(10);

}
