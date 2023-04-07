const int buttonPin = 8;
const int ledPin1 = 5;
const int ledPin2 = 3;
const int ledPin3 = 7;
int buttonPushCounter = 0;
int buttonState = 0;
int lastButtonState = 0;
void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      buttonPushCounter++;
      Serial.println(buttonPushCounter);
    }
  }
  lastButtonState = buttonState;
  if (buttonPushCounter ==1) {
    digitalWrite(ledPin1, HIGH);
  } 
  else if(buttonPushCounter ==2){
    digitalWrite(ledPin2, HIGH);
  }
  else if(buttonPushCounter ==3){
  digitalWrite(ledPin3, HIGH);
  }
  else if (buttonPushCounter >= 4){
    buttonPushCounter = 0;
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }
}
