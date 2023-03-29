const int led[3]={3,4,5};
const int btn = 8;

void setup(){
  for(int x = 0; x<3; x++){
pinMode(led[x],OUTPUT);
  }
  pinMode(btn,INPUT);
}
void loop(){
  int btnInput = digitalRead(btn);
  if(btnInput==HIGH){
    for(int x = 0 ; x<3; x++){
      for(int x = 0 ; x<3; x++)
      digitalWrite(led[x],LOW);
    digitalWrite(led[x],HIGH);
    btnInput=digitalRead(btn);
    if(btnInput==LOW)
    break;

    delay(200);
    }
  }
}

