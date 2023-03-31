const int led = 6;
const int btn=2;
int ledstate=LOW;
bool statechange=false;
void btnpressed(){
  ledstate=(ledstate==LOW)?HIGH:LOW;
  statechange=true;
}
void setup() {
pinMode(led,OUTPUT);
pinMode(btn,INPUT);
attachInterrupt(digitalPinToInterrupt(btn),btnpressed,RISING);
}

void loop() {
if(statechange){
  statechange=false;
  digitalWrite(led,ledstate);
}
}
