#define DATA 2
#define LATCH 4
#define CLOCK 7

byte leds = 0;
byte pins[] = {3, 5, 6};
bool digits[10][8] = {
    {false, false, true, true, true, true, true, true},
    {false, false, false, false, false, true, true, false},
    {false, true, false, true, true, false, true, true},
    {false, true, false, false, true, true, true, true},
    {false, true, true, false, false, true, true, false},
    {false, true, true, false, true, true, false, true},
    {false, true, true, true, true, true, false, true},
    {false, false, false, false, false, true, true, true},
    {false, true, true, true, true, true, true, true},
    {false, true, true, false, true, true, true, true}};
int dir = 0;

void setup()
{
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(DATA, OUTPUT);

  leds = 0;
  updateShiftRegister();
  delay(500);
}

void loop()
{
  delay(200);
  updateShiftRegister();
  if (!dir)
    leds <<= 1;
  else
    leds >>= 1;
  if (leds & 0x8000)
    dir = 1;
  if (leds & 0x0001)
    dir = 0;
}

void updateShiftRegister()
{
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, MSBFIRST, (0xff00 & leds) >> 8);
  shiftOut(DATA, CLOCK, MSBFIRST, 0xff00 & leds);
  digitalWrite(LATCH, HIGH);
}