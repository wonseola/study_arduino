int ledPin3 = 3;
int ledPin4 = 4;
int ledPin5 = 5;
int buttonPin = 8;

void setup() {
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

unsigned int long button_delay = 0;
bool button_hold = false;
bool pre_button_state = 1; // PULL_UP button 접점 붙은 상태: 0, 떨어진 상태: 1 -> 초기값 1
bool button_state = 1;  
bool Led_state = LOW;

void loop() {
  button();
  button_state = digitalRead(buttonPin);
  if (button_hold == false) {
    if (button_state != pre_button_state) {
      button_hold = true;
      button_delay = millis();
      if (button_state == 0) {
        Led_state = !Led_state;
        digitalWrite(ledPin3, Led_state);
        digitalWrite(ledPin4, Led_state);
        digitalWrite(ledPin5, Led_state);
      }
      pre_button_state = button_state;
    }
  }
}

void button() {
  if (button_hold == true) {
    if (millis() - button_delay >= 100) {
      button_hold = false;
    }
  }
}