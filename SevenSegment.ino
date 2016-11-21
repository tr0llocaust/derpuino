// These might be useful
int START_PIN = 9;
int END_PIN = 2;

// Map digipins to compenent PINOUT diagram
int a   = START_PIN,
    b   = 8,
    c   = 7,
    d   = 6,
    e   = 5,
    f   = 4,
    g   = 3,
    dot = END_PIN;

// Pattern Arrays
int ONE[]   = {b, c};
int TWO[]   = {a, b, d, e, g};
int THREE[] = {a, b, c, d, g};
int FOUR[]   = {b, c, f, g};
int FIVE[]   = {a, c, d, f, g};
int SIX[]   = {a, c, d, e, f, g};
int SEVEN[]   = {a, b, c};
int EIGHT[]   = {a, b, c, d, e, f, g};
int NINE[]   = {a, b, c, d, f, g};
int ZERO[]   = {a, b, c, d, e, f};

int h_[] = {c, e, f, g, dot};
int i_[] = {b,c, dot};
int d_[] = {b, c, d, e, g, dot};
int o_[] = {c, d, e, g, dot};


void setup() {
  resetSegments(LOW);
}

void loop() {
  toggleSegments(h_, sizeof(h_));
  delay(500);
  toggleSegments(i_, sizeof(i_));
  delay(500);
  
  resetSegments(LOW);
  delay(1000);
  
  toggleSegments(d_, sizeof(d_));
  delay(500);
  toggleSegments(o_, sizeof(o_));
  delay(500);
  resetSegments(LOW);
  delay(100);
  toggleSegments(o_, sizeof(o_));
  delay(500);
  toggleSegments(o_, sizeof(d_));
  delay(500);

  resetSegments(LOW);
  delay(1500);
}


void toggleSegments (int number[],int size)
{
  resetSegments(LOW);
  for (int pin = START_PIN; pin >= END_PIN; pin--)
  {
    for (int i = 0; i < size / 2 ; i++)
    {
      if (pin == number[i]) {
        digitalWrite(number[i], HIGH);
      }
    }
  }
}

void resetSegments(bool STATE)
{
  for (int pin = START_PIN; pin >= END_PIN; pin--)
  {
      pinMode(pin, OUTPUT);
      digitalWrite(pin, STATE);
  }
}

void toggleDot ()
{
  bool d = digitalRead(dot);
  digitalWrite(dot, !d);
}


