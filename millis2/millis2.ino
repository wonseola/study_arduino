const int led=6;
int t = 0;
unsigned long prev=0;
const unsigned long d=4;

const int led2=13;
int t2 = 0;
unsigned long prev2=0;
const unsigned long d2=0;

const int buttonPin = 2;
int buttonState = 0;

void setup() {
  pinMode(led2,OUTPUT);
  pinMode(buttonPin,INPUT);
}

void loop() {
  unsigned long now=millis();
  unsigned long now2=millis();
   buttonState = digitalRead(buttonPin);
   if (buttonState == HIGH) {
    if(now2 - prev2>= d2){  //13
     prev2=now2;
     t2++;
     if(t2>1)t=0;
     digitalWrite(led2,t);
     }
   }

    if(now - prev>= d){ // 6
     prev=now;
     t++;
     if(t>120)t=0;
     analogWrite(led,t);
}
}
