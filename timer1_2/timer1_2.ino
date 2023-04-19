#include <TimerOne.h>

const int sev = 9;
const int period = 20000;
const int minduty = (1024 / 20) * 0.7;
const int maxduty = (1024 / 20) * 2.3;
int angle = minduty;

void setup() {
  Serial.begin(9600);
  Timer1.initialize();
  Timer1.pwm(sev, 0);
  Timer1.setPeriod(period);
}

void loop() {
  if (Serial.available() > 0) {
    int input = Serial.parseInt();
    int duty = 0;
    if (input >= 0 && input <= 180) {
      duty = map(input, 0, 180, minduty, maxduty);
    }
    while (angle != duty) {
      if (angle < duty) {
        angle++;
      } else if (angle > duty) {
        angle--;
      }
      Timer1.setPwmDuty(sev, angle);
      delay(30);
    }
    if (input == 0) {
      while (angle != minduty) {
        if (angle < minduty) {
          angle++;
        } else if (angle > minduty) {
          angle--;
        }
        Timer1.setPwmDuty(sev, angle);
        delay(30);
      }
    }
  }
}
