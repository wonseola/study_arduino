#define TRIG 6 //TRIG
#define ECHO 7 //ECHO
#define Ser 9 //servo
#include <Servo.h>
Servo s;
int pos = 0;
void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  s.attach(9);
  s.write(0);
}

void loop(){
  long duration, distance;
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn (ECHO, HIGH); //물체에 반사되어돌아온 초음파의 시간을 변수에 저장합니다.
  distance = duration * 17 / 1000; //PC모니터로 초음파 거리값을 확인
  Serial.println(distance);
  delay(1000); //1초마다 측정값을 보여줍니다.

  if(distance <=10){
    Serial.println("ooooo");
    s.write(180);
  }
  else{
    s.write(0);
  }

}