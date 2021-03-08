// set to 1 if we're debugging
#define DEBUG 1
// 6 consecutive digital pins for the LEDs
// int first = 27;
// int second = 33;
// int third = 15;
// int fourth = 32;
// int fifth = 14;
// int sixth = 22;
// keep an array of pins instead of relying on sequential order of pin numbers
int pins[] = {27, 33, 15, 32, 14, 22};
// pin for the button switch
int button = 12;
// value to check state of button switch
int pressed = 0;
void setup() {
  // set all LED pins to OUTPUT
  for (int i=0; i<6; i++) {
    pinMode(pins[i], OUTPUT);
  }
  // set buttin pin to INPUT
  pinMode(button, INPUT);
  // initialize random seed by noise from analog pin 0 (should be unconnected)
  randomSeed(analogRead(0));
  // if we're debugging, connect to serial
  #ifdef DEBUG
    Serial.begin(9600);
  #endif
}
void buildUpTension() {
  // light LEDs from left to right and back to build up tension
  // while waiting for the dice to be thrown
  // left to right
  for (int i=0; i<6; i++) {
    if (i!=0) {
      digitalWrite(pins[i-1], LOW);
    }
    digitalWrite(pins[i], HIGH);
    delay(100);
  }
  // right to left
  for (int i=0; i<6; i--) {
    if (i!=0) {
      digitalWrite(pins[i+1], LOW);
    }
    digitalWrite(pins[i], HIGH);
    delay(100);
  }
}
void showNumber(int number) {
  digitalWrite(pins[0], HIGH);
  if (number >= 2) {
    digitalWrite(pins[1], HIGH);
  }
  if (number >= 3) {
    digitalWrite(pins[2], HIGH);
  }
  if (number >= 4) {
    digitalWrite(pins[3], HIGH);
  }
  if (number >= 5) {
    digitalWrite(pins[4], HIGH);
  }
  if (number == 6) {
    digitalWrite(pins[5], HIGH);
  }
}
int throwDice() {
  // get a random number in the range [1,6]
  int randNumber = random(1,7);
  #ifdef DEBUG
    Serial.println(randNumber);
  #endif
  return randNumber;
}
void setAllLEDs(int value) {
  for (int i=0; i<6; i++) {
    digitalWrite(pins[i], value);
  }
}
void loop() {
  // if button is pressed - throw the dice
  pressed = digitalRead(button);
  Serial.println(pressed);
  if (pressed == HIGH) {
    // remove previous number
    setAllLEDs(LOW);
    buildUpTension();
    int thrownNumber = throwDice();
    showNumber(thrownNumber);
  }
}
