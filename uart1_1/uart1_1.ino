int n = 1;
void setup() {
  Serial.begin(9600);
}

void loop() {
  if (n){    // 1 입력 대기
    n = 0;   // 0 출력 상태로
  }
  while(Serial.available() == 0) {};
  int v1 = Serial.parseInt();

  while(Serial.available() == 0) {}
  int v2 = Serial.parseInt();
  int sum = v1+v2;

  Serial.print(v1);
  Serial.print(" + ");
  Serial.print(v2);
  Serial.print(" = ");
  Serial.println(sum);

  n = 1;   //입력 대기
}
