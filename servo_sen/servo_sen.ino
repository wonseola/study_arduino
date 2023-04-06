#include <Ultrasonic.h>
#include <Servo.h>
Ultrasonic ultrasonic(12, 10);
int distance;
int led1 = 7;
int led2 = 3;
int b=11;
int btn = 8;
Servo myservo;
int pos = 0;
void setup() {
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(btn, INPUT);
  myservo.attach(9);
  myservo.write(0);
}

void loop() {
  distance = ultrasonic.read();
  Serial.println(distance);
  delay(80);
   
  if(distance>=10 && distance<15){
    digitalWrite(led1,HIGH);
    tone(b, 262, 1000);

  }
  else if(distance>=15 && distance<20){
    digitalWrite(led2,HIGH);
    tone(b, 294, 1000);
    myservo.write(0);
  }
    else if(distance>=20 && distance<25){
    digitalWrite(led1,HIGH);
    tone(b, 330, 1000);
  }
    else if(distance>=25 && distance<30){
    digitalWrite(led2,HIGH);
    tone(b, 349, 1000);
  }
    else if(distance>=30 && distance<35){
    digitalWrite(led1,HIGH);
    tone(b, 392, 1000);
  }
    else if(distance>=35 && distance<40){
    digitalWrite(led2,HIGH);
    tone(b, 440, 1000);
  }
    else if(distance>5 && distance<10){
    write(led1,10);
    write(led2,10);
    tone(b, 700, 1000);
        for(int p = 0 ; p<=180; p++){
    myservo.write(p);
    }
    delay(200);
  }
  else{
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    noTone(b);
    }
}

void write(int led, int delay1){
  digitalWrite(led,HIGH);
  delay(delay1);
  digitalWrite(led,LOW);
  delay(delay1);
}
