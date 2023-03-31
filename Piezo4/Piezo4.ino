const int ACTIVE_BUZZER = 10;
const int buttonPin =2;
#include "pitches.h"

int buzzer_state = LOW;
bool buzzer_state_changed = false;

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void buttonPressed(){
  buzzer_state = (buzzer_state == LOW)?HIGH:LOW;
  buzzer_state_changed = true;
}

void setup() {
  Serial.begin(9600);
  pinMode(ACTIVE_BUZZER, OUTPUT); 
  pinMode(buttonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonPressed, RISING);
  // put your setup code here, to run once:
}

void loop() {
  if(buzzer_state_changed){
    //Serial.println(buzzer_state);
    //buzzer_state_changed = false;
    //digitalWrite(ACTIVE_BUZZER, buzzer_state);

    for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(10, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(10);
    buzzer_state_changed = false;
    digitalWrite(ACTIVE_BUZZER, buzzer_state);

  }
  }
}