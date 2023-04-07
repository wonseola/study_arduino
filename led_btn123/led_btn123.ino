int led1=5;
int led2= 3;
int led3 = 7;
int btn=8;

int states=0;
int counts=0;
long cnt=0;

void setup()
{
	Serial.begin(9600);
	pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
	pinMode(btn, INPUT);
}

void loop()
{
	if (digitalRead(btn) && counts==0)
	{
		cnt=millis();
		counts++;
	}
	 else if (millis() > cnt+500)
	 {
	 	states=counts;
	 	counts=0;
	 }
	else if (digitalRead(btn) && millis() > cnt+200)
	{
		cnt=millis();
		counts++;
		if (counts >= 4)
		{
			cnt=0;
			states=counts;
			counts=0;
		}
	}

	switch (states)
	{
		case 0:
		break;
		case 1:
		digitalWrite(led1, HIGH);
    Serial.println("led1 on ");
		break;
		case 2:
		digitalWrite(led2, HIGH);
    Serial.println("led2 on ");
		break;
		case 3:
		digitalWrite(led3, HIGH);
    Serial.println("led3 on ");
		break;
    case 4:
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    Serial.println("led off ");
    break;
	}
	if (states > 0)
	{
		cnt=0;
		states=0;
		counts=0;
	}
}