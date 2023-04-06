#include <Ultrasonic.h>
Ultrasonic ultrasonic(9, 10);
int distance;
int led1 = 6;
int led2 = 3;
int b=11;
int btn = 8;

void setup() {
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(btn, INPUT);
}

void loop() {
  distance = ultrasonic.read();
  Serial.println(distance);
  delay(80);
   
  if(distance>=10 && distance<15){
    digitalWrite(led1,HIGH);
    tone(11, 262, 1000);
  }
  else if(distance>=15 && distance<20){
    digitalWrite(led2,HIGH);
    tone(11, 294, 1000);
  }
    else if(distance>=20 && distance<25){
    digitalWrite(led1,HIGH);
    tone(11, 330, 1000);
  }
    else if(distance>=25 && distance<30){
    digitalWrite(led2,HIGH);
    tone(11, 349, 1000);
  }
    else if(distance>=30 && distance<35){
    digitalWrite(led1,HIGH);
    tone(11, 392, 1000);
  }
    else if(distance>=35 && distance<40){
    digitalWrite(led2,HIGH);
    tone(11, 440, 1000);
  }
    else if(distance>5 && distance<10){
    write(led1,10);
    write(led2,10);
    tone(11, 700, 1000);
  }
  else{
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    noTone(11);
    }
}

void write(int led, int delay1){
  digitalWrite(led,HIGH);
  delay(delay1);
  digitalWrite(led,LOW);
  delay(delay1);
}
