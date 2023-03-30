#include <TimerOne.h>
const int LED = 10;
void setup() {
  Timer1.initialize();
  Timer1.pwm(LED,0);
  Timer1.setPeriod(1000);
  //Timer1.setPwmDuty(LED,900);
}
void loop() {
  for ( int t = 0 ; t<=1023; t++){
    Timer1.setPwmDuty(LED,t*100);
    delay(20);
  }
}
