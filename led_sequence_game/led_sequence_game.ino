const int buttonPin = 8;     // 버튼 핀 번호
const int ledPin1 = 5;      // LED1 핀 번호
const int ledPin2 = 3;      // LED2 핀 번호
const int ledPin3 = 7;      // LED3 핀 번호
int buttonPushCounter = 0;  // 버튼 누름 횟수 카운터
int buttonState = 0;        // 현재 버튼 상태
int lastButtonState = 0;    // 이전 버튼 상태
int targetLED = 0;         // 정답 LED 번호
int userLED = 0;           // 사용자가 누른 LED 번호
unsigned long lastBlinkTime = 0;  // 마지막으로 LED가 깜빡이기 시작한 시간
unsigned long blinkInterval = 100;  // LED 깜빡이는 간격 (밀리초)
bool isBlinking = false;   // LED가 깜빡이는 중인지 여부

void setup() {
  pinMode(buttonPin, INPUT);  // 버튼 핀을 입력으로 설정
  pinMode(ledPin1, OUTPUT);   // LED1 핀을 출력으로 설정
  pinMode(ledPin2, OUTPUT);   // LED2 핀을 출력으로 설정
  pinMode(ledPin3, OUTPUT);   // LED3 핀을 출력으로 설정
  Serial.begin(9600);         // 시리얼 통신 시작
  nextRound();                // 다음 라운드로 이동
}

void loop() {
  buttonState = digitalRead(buttonPin);  // 버튼 상태 읽기
  if (buttonState != lastButtonState) {  // 버튼 상태가 변경되었을 경우
    if (buttonState == HIGH) {           // 버튼이 눌렸을 경우
      buttonPushCounter++;              // 버튼 누름 횟수 증가
      Serial.println(buttonPushCounter); // 버튼 누름 횟수 시리얼 모니터에 출력
      userLED = buttonPushCounter;       // 사용자가 누른 LED 번호 저장
      delay(500);                        // 버튼 디바운스를 위한 딜레이
    }
  }
  lastButtonState = buttonState; // 현재 버튼 상태를 이전 버튼 상태로 저장

  if (buttonPushCounter == targetLED) {  // 사용자가 정답을 맞췄을 경우
    Serial.println("정답!");              // "정답!" 메시지 시리얼 모니터에 출력
    blinkLEDs();                        // 정답일 경우 LED 3개를 깜빡이게 함
    delay(1000);                        // 1초 딜레이
    nextRound();                        // 다음 라운드로 이동
  } else if (buttonPushCounter > 3) {    // 버튼 누름 횟수가 3회를 초과할 경우
    Serial.println("실패!");              // "실패!" 메시지 시리얼 모니터에 출력
    delay(1000);                        // 1초 딜레이
    nextRound();                        // 다음 라운드로 이동
  }

  // LED 깜빡이기
  if (isBlinking) {  // LED가 깜빡이는 중인 경우
    unsigned long currentMillis = millis();  // 현재 시간 읽기
    if (currentMillis - lastBlinkTime >= blinkInterval) {  // LED 깜빡이는 간격이 지났을 경우
      lastBlinkTime = currentMillis;    // 마지막 깜빡이는 시간 업데이트
      digitalWrite(ledPin1, !digitalRead(ledPin1));  // LED1 상태 토글
      digitalWrite(ledPin2, !digitalRead(ledPin2));  // LED2 상태 토글
      digitalWrite(ledPin3, !digitalRead(ledPin3));  // LED3 상태 토글
    }
  }
}

// 다음 라운드로 이동하는 함수
void nextRound() {
  targetLED = random(1, 4);  // 1부터 3까지의 랜덤한 숫자를 정답 LED 번호로 설정
  userLED = 0;               // 사용자가 누른 LED 번호 초기화
  buttonPushCounter = 0;    // 버튼 누름 횟수 카운터 초기화
  Serial.println("다음 라운드!");  // "다음 라운드!" 메시지 시리얼 모니터에 출력
  Serial.print("정답 LED: ");
  Serial.println(targetLED);  // 정답 LED 번호 시리얼 모니터에 출력
  isBlinking = true;         // LED 깜빡이기 시작
  delay(1000);
  isBlinking = false;


  // targetLED에 따라 LED를 켜주는 코드 추가
  digitalWrite(ledPin1, LOW);  // LED1 끄기
  digitalWrite(ledPin2, LOW);  // LED2 끄기
  digitalWrite(ledPin3, LOW);  // LED3 끄기
  switch (targetLED) {
    case 1:
      digitalWrite(ledPin1, HIGH);  // LED1 켜기
      break;
    case 2:
      digitalWrite(ledPin2, HIGH);  // LED2 켜기
      break;
    case 3:
      digitalWrite(ledPin3, HIGH);  // LED3 켜기
      break;
    default:
      break;
  }
    delay(500);
    // targetLED를 꺼주는 코드 추가
    digitalWrite(ledPin1, LOW);  // LED1 끄기
    digitalWrite(ledPin2, LOW);  // LED2 끄기
    digitalWrite(ledPin3, LOW);  // LED3 끄기
}

// LED 3개를 깜빡이는 함수
void blinkLEDs() {
  digitalWrite(ledPin1, HIGH);  // LED1 켜기
  digitalWrite(ledPin2, HIGH);  // LED2 켜기
  digitalWrite(ledPin3, HIGH);  // LED3 켜기
  delay(500);                    // 0.5초 딜레이
  digitalWrite(ledPin1, LOW);   // LED1 끄기
  digitalWrite(ledPin2, LOW);   // LED2 끄기
  digitalWrite(ledPin3, LOW);   // LED3 끄기
  isBlinking = false;           // LED 깜빡이기 중단
}


