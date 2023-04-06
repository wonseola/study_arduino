/*void setup() {

  Serial.begin(9600);
  pinMode(3, INPUT); 
}
void loop() {

  if (digitalRead(3) == HIGH) {
    Serial.println("CDS off");
  }
 delay(500);
}

*/
void setup() {
  Serial.begin(9600);
}
void loop() {
  Serial.println(analogRead(A0));  //조도센서의 감지되는 광량을 출력합니다.
  delay(500);
}