/*
 Plays JINGLE BELLS

 circuit:
 * 8-ohm speaker on digital pin 8

 created 27/12/2016
 by Boaz Andries

 */
#include "pitches.h"

// notes in the melody:
int melody_partA[] = {
  NOTE_E4,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_G4,NOTE_C4,NOTE_D4,NOTE_E4
};
int melody_partB[] = {
  NOTE_F4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_E4,NOTE_D4,NOTE_G4
};
int melody_partC[] = {
  NOTE_F4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_G4,NOTE_G4,NOTE_F4,NOTE_D4,NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations_partA[] = {
  4, 4, 2, 4, 4, 2, 4, 4, 4, 4, 1
};
int noteDurations_partB[] = {
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2
};
int noteDurations_partC[] = {
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1
};

void setup() {
  makeMelody(melody_partA, noteDurations_partA, 11);
  makeMelody(melody_partB, noteDurations_partB, 14);
  makeMelody(melody_partA, noteDurations_partA, 11);
  makeMelody(melody_partC, noteDurations_partC, 13);
}

void makeMelody(int melody[], int noteDurations[], int totalNotes) {
    // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < totalNotes; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(totalNotes);
  }
  }

void loop() {
  // no need to repeat the melody.
}
