int ledPin[] = {1,2,3};
int ledState[3];
long randNumber;
void setup() {
  for (int i=0; i<=3; i++){
    pinMode(ledPin[i], OUTPUT);
  }
  randomSeed(analogRead(0));
  for (int i=0; i<=3; i++){
    ledState[i] = random(20, 201);
  }
}
void loop(){
  for (int i=0; i<=3; i++){
    analogWrite(ledPin[i], ledState[i]);
    randNumber = random(-40, 41);
    ledState[i] += randNumber;
    if (ledState[i] > 200) {
      ledState[i] = 200;
    }
    if (ledState[i] < 10) {
      ledState[i] = 10;
    }
  }
  delay(500);
}