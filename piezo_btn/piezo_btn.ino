const int bpin=10;
int btnStart=2;
int states=0;
int tones[] = {262,293,329,349,392,440,493,523};

void play(){
  for(int i = 0 ; i<8; i++){
    tone(bpin,tones[i]);
    delay(200);
  }
  noTone(bpin);
}

void setup() {
pinMode(bpin,OUTPUT);
pinMode(btnStart, INPUT);
}

void loop() {
states=digitalRead(btnStart);
if (states==1){
  play();
}
}