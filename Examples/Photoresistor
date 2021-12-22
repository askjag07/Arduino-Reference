#define CLOCK 9
#define LATCH 11
#define DATA 12
#define PHOTORESISTOR A0

byte leds = 0;

void setup()
{
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(PHOTORESISTOR, INPUT);

  updateShiftRegister();
}

void loop()
{
  int numLEDSLIT = analogRead(PHOTORESISTOR) / 57;
  for (byte i = 0; i < analogRead(PHOTORESISTOR) / 57; i++)
  {
    leds = 0;
    bitSet(leds, i);
    updateShiftRegister();
  }
}

void updateShiftRegister()
{
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, LSBFIRST, leds);
  digitalWrite(LATCH, HIGH);
}
