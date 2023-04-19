#include <TimerOne.h>

const int sev = 9;

const int period=20000;
const int minduty = (1024/20)*0.7;
const int maxduty=(1024.20)*2.3;

void setup() {
  Timer1.initialize();
  Timer1.pwm(sev, 0);
  Timer1.setPeriod(period);
  Timer1.setPwmDuty(sev, minduty);

  delay(1000);

  for (int angle=minduty; angle<=maxduty;angle++){
    Timer1.setPwmDuty(sev, angle);
    delay(30);
  }
  Timer1.disablePwm(sev);
}
void loop() {
}
