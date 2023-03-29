const int buttonPin = 8;
const int ledPin4 = 4;
const int ledPin5 = 5;
const int ledPin3 = 3;
int ledState = HIGH;
int buttonState;
int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 10;
void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  digitalWrite(ledPin4, ledState);
  digitalWrite(ledPin5, ledState);
  digitalWrite(ledPin3, ledState);
}

void loop() {
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }
  digitalWrite(ledPin4, ledState);
  digitalWrite(ledPin5, ledState);
  digitalWrite(ledPin3, ledState);
  lastButtonState = reading;
}