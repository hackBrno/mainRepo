void setup() {
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
}

void loop() {
  digitalWrite(8, HIGH);
  delay(1000);
  digitalWrite(8, LOW);
  delay(3000);
}
