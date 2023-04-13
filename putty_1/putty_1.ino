void setup() {
Serial.begin(9600);
}

void loop() {
  int r = analogRead(A0);
  if (r>=100) Serial.println("100 up");
  else Serial.println(r);
delay(1000);
}
