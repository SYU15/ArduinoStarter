//imports the liquidcrystal library
#include <LiquidCrystal.h>
//sets the liquid crystal to use the specific pins
LiquidCrystal lcd(12,11,5,4,3,2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup(){
//starts the lcd library, set the size of the lcd board  
lcd.begin(16,2);
pinMode(switchPin,INPUT);
//cursor begins at the top line of the lcd
lcd.print("Ask the");
//tells the lcd to move the cursor
lcd.setCursor(0,1);
lcd.print("Crystal Ball!");

}

void loop() {
switchState = digitalRead(switchPin);
//if the switch has been tited and switchState is low, will choose random response
if(switchState !=prevSwitchState) {
if(switchState == LOW) {
reply = random(8);
//clears the lcd screen
lcd.clear();
//resets the cursor
lcd.setCursor(0,0);
lcd.print("The ball says: ");
lcd.setCursor(0,1);
switch(reply) {
case 0:
lcd.print("Yes");
break;
case 1:
lcd.print("Most Likely");
break;
case 2:
lcd.print("Definitely");
break;
case 3:
lcd.print("Sure");
break;
case 4:
lcd.print("No idea");
break;
case 5:
lcd.print("No way");
break;
case 6:
lcd.print("Probably not");
break;
case 7:
lcd.print("Ice cream");
break;
}
}
}
prevSwitchState = switchState;
}
