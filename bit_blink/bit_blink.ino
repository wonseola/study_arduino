void setup() {
  DDRB = B00100000;
}
void loop() {
  PORTB = B00100000;
  delay(100);
  PORTB = B00000000;
  delay(100);
}
