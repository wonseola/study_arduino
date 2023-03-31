const int analogPin = A0;
const int led = 6;
int buzzer = 10;

void setup() {
Serial.begin(115200);
pinMode(buzzer, OUTPUT);
}

void loop() {
int analogValue = analogRead(analogPin);
analogValue=map(analogValue,0,1023,0,1023);
tone(buzzer,analogValue);
}
