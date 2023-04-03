const int buttonPin = 8;
int buttonState = 0;
void setup() {
for(int i = 3 ; i <6; i ++){
 pinMode(i,OUTPUT);
 }
pinMode(buttonPin,INPUT);
}

void loop() {
    buttonState = digitalRead(buttonPin);
    for(int i = 3 ; i <6; i ++){
   if (buttonState == HIGH) {
    digitalWrite(i, LOW);
  } else {
    digitalWrite(i, HIGH);
  }
    }
}