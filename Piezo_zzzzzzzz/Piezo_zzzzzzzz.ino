/*
int tones[]={587, 659, 784, 784, 784, 784, 784, 784, 784, 784, 587, 659, 784, 0, 784, 784, 784, 784, 784, 784, 587, 659, 784, 0, 784, 784, 784, 784, 784, 784, 784, 784, 740, 740, 0, 587, 659, 784, 784, 784, 784, 784, 784, 784, 784, 587, 659, 784, 0, 784, 784, 784, 784, 784, 784, 587, 659, 784, 0, 784, 784, 784, 784, 784, 784, 784, 784, 740, 740, 0, 587, 659, 784, 784, 784, 784, 784, 784, 784, 784, 587, 659, 784, 0, 784, 784, 784, 784, 784, 784, 587, 659, 784, 0, 784, 784, 784, 784, 784, 784, 784, 784, 740, 740, 0, 587, 659, 784, 784, 784, 784, 784, 784, 784, 784, 587, 659, 784, 0, 784, 784, 784, 784, 784, 784, 587, 659, 784, 0, 784, 784, 784, 784, 784, 784, 784, 784, 740, 740, 0, 587, 659, 784, 784, 784, 784, 784, 784, 784, 784, 587, 659, 784, 0, 784, 784, 784, 784, 784, 784, 587, 659, 784, 0, 784, 784, 784, 784, 784, 784, 784, 784, 740, 740, 0, 587, 659, 784, 784, 784, 784, 784, 784, 784, 587, 659, 784, 0, 784, 784, 784, 784, 784, 784, 587, 659, 784, 0, 784, 784, 784, 784, 784, 784, 784, 784, 740, 740, 0};
int beats[]={10, 10, 5, 5, 5, 2.5, 2.5, 2.5, 2.5, 5, 5, 5, 5, 5, 5, 2.5, 2.5, 2.5, 2.5, 5, 5, 5, 5, 5, 5, 2.5, 2.5, 2.5, 2.5, 2.5, 5, 5, 5, 5, 10, 10, 10, 5, 5, 5, 2.5, 2.5, 2.5, 2.5, 5, 5, 5, 5, 5, 5, 2.5, 2.5, 2.5, 2.5, 5, 5, 5, 5, 5, 5, 2.5, 2.5, 2.5, 2.5, 2.5, 5, 5, 5, 5, 10, 10, 10, 5, 5, 5, 2.5, 2.5, 2.5, 2.5, 5, 5, 5, 5, 5, 5, 2.5, 2.5, 2.5, 2.5, 5, 5, 5, 5, 5, 5, 2.5, 2.5, 2.5, 2.5, 2.5, 5, 5, 5, 5, 10, 10, 10, 5, 5, 5, 2.5, 2.5, 2.5, 2.5, 5, 5, 5, 5, 5, 5, 2.5, 2.5, 2.5, 2.5, 5, 5, 5, 5, 5, 5, 2.5, 2.5, 2.5, 2.5, 2.5, 5, 5, 5, 5, 10, 10, 10, 5, 5, 5, 2.5, 2.5, 2.5, 2.5, 5, 5, 5, 5, 5, 5, 2.5, 2.5, 2.5, 2.5, 5, 5, 5, 5, 5, 5, 2.5, 2.5, 2.5, 2.5, 2.5, 5, 5, 5, 5, 10, 10, 10, 10, 5, 2.5, 2.5, 2.5, 2.5, 5, 5, 5, 5, 5, 5, 2.5, 2.5, 2.5, 2.5, 5, 5, 5, 5, 5, 5, 2.5, 2.5, 2.5, 2.5, 5, 5, 5, 5, 5, 10};
int tempo=100;
*/


int tones[]={0, 988, 880, 784, 988, 1175, 0, 988, 880, 784, 988, 880, 0, 0, 988, 880, 784, 880, 880, 0, 784, 880, 784, 988, 784, 0, 988, 880, 784, 880, 784, 988, 1175, 0, 988, 880, 784, 988, 880, 0, 988, 880, 784, 880, 880, 0, 784, 880, 784, 988, 784, 0, 988, 880, 784, 784, 784, 1319, 1175, 988, 880, 784, 988, 880, 0, 0, 784, 784, 784, 1319, 1175, 988, 880, 784, 880, 784, 0, 0, 784, 784, 784, 1319, 1568, 1319, 1319, 1568, 1319, 1175, 0, 784, 784, 784, 1319, 1175, 988, 880, 784, 880, 784, 0};
int beats[]={5, 5, 5, 5, 5, 15, 5, 5, 5, 5, 5, 15, 10, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 15, 5, 5, 5, 5, 5, 5, 5, 15, 5, 5, 5, 5, 5, 15, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 15, 5, 5, 5, 5, 5, 5, 10, 5, 15, 5, 5, 5, 15, 10, 5, 5, 5, 5, 10, 5, 15, 5, 5, 5, 5, 10, 5, 5, 5, 5, 10, 5, 15, 5, 5, 5, 15, 5, 5, 5, 5, 10, 5, 15, 5, 5, 5, 15, 10};
int tempo=100;




int piezo=10;
int btnStart=2;
int states=0;
void setup()
{
  pinMode(btnStart, INPUT);
}
void loop()
{
  states=digitalRead(btnStart);
  
  if (states==1)
  {
    for (int i=0;i<sizeof(beats)/sizeof(int);i++)
    {
      if (tones[i]==0)
      {
        noTone(piezo);
        delay(tempo/2*beats[i]);
      }
      else
      {
        tone(piezo, tones[i]);
        delay(tempo/2*beats[i]);
        noTone(piezo);
      }
    }
  
    noTone(piezo);
    delay(1000);
  }
}

