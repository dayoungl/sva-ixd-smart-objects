void setup()
{
  Serial.begin(9600);
  pinMode(19, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  digitalWrite(19, HIGH);
  delay(500);
  digitalWrite(16, HIGH);
  delay(500);
  digitalWrite(17, HIGH);
  delay(500);
}

void loop()
{
  if (analogRead(A12) > 60)
  {
    digitalWrite(17, HIGH);
  }
  else
  {
    digitalWrite(17, LOW);
  }
  if (analogRead(A12) > 20)
  {
    digitalWrite(19, HIGH);
  }
  else
  {
    digitalWrite(19, LOW);
  }
  if (analogRead(A12) > 45)
  {
    digitalWrite(16, HIGH);
  }
  else
  {
    digitalWrite(16, LOW);
  }

  Serial.println(analogRead(A12));
  delay(20);
}
