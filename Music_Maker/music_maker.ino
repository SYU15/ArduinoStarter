//set up the four notes with the frequencies C D E F 
int notes[] = {262, 294, 330, 349};

void setup() {
//setup serial communication with computer
Serial.begin(9600);
}

void loop() {
//each button has different value because resistors on buttons are different 
int keyVal = analogRead(A0);
Serial.print(keyVal);

//corresponds with the first button
if(keyVal == 1023) {
tone(8, notes[0]);
}

//good to give a range because there will be some noise on the board
else if(keyVal >= 990 && keyVal<=1010) {
tone(8, notes[1]);
}

else if(keyVal >= 505 && keyVal<=515) {
tone(8, notes[2]);
}
else if(keyVal >= 5 && keyVal<=10) {
tone(8, notes[3]);
}
//no tone/tone shut off when button isn't pressed
else{
noTone(8);
}
}
