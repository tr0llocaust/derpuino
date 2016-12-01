byte potPin   = 0;
byte latchPin = 8;
byte clockPin = 12;
byte dataPin  = 11;

//128
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
  Serial.begin(19200);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
 
}

void loop(){
  byte potReading = map(analogRead(0), 0, 1019, 0, 99);

  byte tens = floor(potReading / 10);
  byte ones = potReading - (tens * 10);

  digitalWrite(latchPin, LOW);

  shiftOut(dataPin, clockPin, MSBFIRST, numbers[ones]);
  shiftOut(dataPin, clockPin, MSBFIRST, numbers[tens]);
  
  digitalWrite(latchPin, HIGH);
}
