//asigns the switchpin to the value
const int switchPin = 8;

//keeps track of the time the LED was changed
unsigned long previousTime = 0;

int switchState = 0;
int prevSwitchState = 0;

int led = 2;

//interval to when the next LED will turn on
long interval = 6000;

void setup() {
//uses a for list to iterate through all pins
for (int x=2; x<8; x++) {
pinMode(x, OUTPUT);
}
//makes tiltswitch an input
pinMode(switchPin, INPUT);

}

void loop() {
  //keeps track of the time
unsigned long currentTime = millis();

//see if enough time has passed to turn LED on
if(currentTime - previousTime > interval) {
  //current time is set to previous time to keep track of when next LED gets turned on
previousTime = currentTime;
digitalWrite(led, HIGH);
//add 1 to LED value so that the next LED will be turned on next
led++;
if(led==7) {

}
}
switchState = digitalRead(switchPin);
//when you tilt the board, the clock will restart, checks orientation
//of the tilt switch
if(switchState != prevSwitchState) {
  //turns off all LEDS
for(int x =2; x < 8; x++) {
digitalWrite(x, LOW);
}
//resets LED turn on value
led = 2;
//resets clock
previousTime = currentTime;
}
prevSwitchState = switchState;
}
