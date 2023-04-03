const int led = 6;
int o = 0;
unsigned long prev=0;
const unsigned long d=500;
void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  unsigned long now=millis();
  if(now - prev >= d){
    prev=now;
    o++;
    if(o>1)o=0;
    digitalWrite(led,o);
  }
}

