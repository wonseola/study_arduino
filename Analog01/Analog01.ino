const int analogPin = A0;
const int led = 6;
void setup() {
Serial.begin(115200);
}

void loop() {
int analogValue = analogRead(analogPin);
analogValue=map(analogValue,0,1023,0,255);
if(analogValue<=75 && analogValue >=70){
  analogWrite(led,analogValue);
}
else{analogWrite(led,0);}
Serial.println(analogValue);
}
