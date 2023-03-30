void setup() {
  for(int a = 3; a<6; a++)
    pinMode(a,OUTPUT);
  pinMode(3,OUTPUT);

}

void loop() {
  for(int b = 0; b<=10; b++){
    digitalWrite(3,HIGH);
    delay(b);
    digitalWrite(3,LOW);
    delay(10-b);
  }
}


