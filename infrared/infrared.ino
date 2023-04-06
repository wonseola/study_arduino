int sensor = 2;
int led = 5;
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
}
void loop() {
  int val = digitalRead(sensor);
  Serial.println(val);
  if (val == HIGH) { 
    digitalWrite(led,HIGH);
    delay(100);
  } else {
    digitalWrite(led,LOW);
    delay(100);
  }
}