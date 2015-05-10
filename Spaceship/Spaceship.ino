int switchState = 0;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);

}

void loop() {
  //reads the 2 pin, if there is voltage(button is pressed) will be read as high
  //no voltage is low
  //13 is Red, 10 is Blue, 6 is Yellow, 3 is Green, 4 and 5 are Purple
switchState = digitalRead(2);

if (switchState == LOW) {
  
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
  digitalWrite(5, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(6, LOW);
  digitalWrite(13, HIGH);
   
   //delay in miliseconds
   delay(250);
   //toggles LEDs
  digitalWrite(4, HIGH); 
  digitalWrite(5, LOW);
  digitalWrite(10, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(13, LOW);
  
  delay(250);
  digitalWrite(4, LOW); 
  digitalWrite(5, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(13, HIGH);
  
    delay(250);
  digitalWrite(4, HIGH); 
  digitalWrite(5, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(13, HIGH);
  
  //loop is called 1000 times a second, so add a delay before loop restarts
  delay(250);
  
}

else {
  //digitalWrite controls voltage
  digitalWrite(3, HIGH); //green LED on
  digitalWrite(4, LOW); //purple LED off
  digitalWrite(5, LOW); //purple LED off
  digitalWrite(10, LOW);
  digitalWrite(6, LOW);
  digitalWrite(13, LOW);
  
  
}

}
