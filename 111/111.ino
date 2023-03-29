void setup() {
  Serial.begin(9600);
for(int i = 3 ; i <6; i++)
  pinMode(i,OUTPUT);
  pinMode(8,INPUT);
}
void loop() {
  Serial.println(digitalRead(8));
  if(digitalRead(8) == HIGH){
    for (int i = 3 ; i <6; i++)
      digitalWrite(i,HIGH);    
      }
    else{ 
      for (int i = 3 ; i <6; i++)
    digitalWrite(i,LOW);
  }
}