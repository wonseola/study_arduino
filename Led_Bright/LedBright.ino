void setup() {
  pinMode(5,OUTPUT);
}
void loop() {
  for(int b = 0; b<=10; b++){
     int cnt = 0 ;
      while(true){
      digitalWrite(5,HIGH);
      delay(b);
      digitalWrite(5,LOW);
      delay(10-b);
      cnt++;
      if(cnt==0) {break;}
      }
  }
}


