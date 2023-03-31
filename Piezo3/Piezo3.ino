#include <TimerOne.h>
const int Buzzer=10;
void setup() {
Timer1.initialize();
Timer1.pwm(Buzzer,0);
Timer1.setPwmDuty(Buzzer,512);
Timer1.setPeriod(1000000/262);
delay(3000);
Timer1.setPwmDuty(Buzzer,0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
