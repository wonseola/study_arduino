#include <Servo.h>
const int SERVO = 10;
Servo servo;
const int btn = 8;
int state= 30;
bool state_changed=false;
void btnPressed(){
  state = (state ==30)?150:30;
  state_changed=true;
}

void setup() {
  // put your setup code here, to run once:
pinMode(btn,INPUT);
attachInterrupt(digitalPinToInterrupt(btn),btnPressed,RISING);
servo.attach(SERVO);
servo.write(0);
delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
if(state_changed){
  state_changed=false;
  servo.write(state);
}
}
