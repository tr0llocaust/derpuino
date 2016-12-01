byte potPin   = 0;
byte latchPin = 8;
byte clockPin = 12;
byte dataPin  = 11;

byte potReading; 
byte tens;
byte ones;

byte numbers[10]= 
  {63,  // 0
    6,  // 1
   91,  // 2 
   79,  // 3 
  102,  // 4 
  109,  // 5 
  125,  // 6 
  7,    // 7
  127,  // 8 
  103}; // 9  

void setup(){
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop(){
  potReading = map(analogRead(0), 0, 1019, 0, 99); // Map the range of input from the pot to a percentage
  tens = floor(potReading / 10); // Grab the tens digit
  ones = potReading % 10; //And the ones digit

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, numbers[ones]); // Feed the right digit from the left
  shiftOut(dataPin, clockPin, MSBFIRST, numbers[tens]); // Push it over with the left digit
  digitalWrite(latchPin, HIGH);
}
