#include "megalovania.h"

#define buzz 7  // Speaker pin

void playSecurityAlarm() {
  play(dnat, 4, .25);
  play(dnat, 4, .25);
  play(dnat, 5, .25);
  rest(.25);
  play(anat, 4, .25);
  rest(.5);
  play(gsharp, 4, .25);
  rest(.25);
  play(gnat, 4, .25);
  rest(.25);
  play(fnat, 4, .5);
  play(dnat, 4, .25);
  play(fnat, 4, .25);
  play(gnat, 4, .25);
}

void play(double note, int octave, double note_val) {
  tone(buzz, oct(note, octave));
  delay((beat * note_val) - 20);
  noTone(buzz);
  delay(20);
}

void rest(double note_val) {
  delay(beat * note_val);
}

void vibrato(double note, int octave, double note_val) {
  for (int i = 0; i < 4; i++) {
    tone(buzz, oct(note, octave));
    delay(beat * note_val / 16);
    tone(buzz, oct(note, octave) - 20);
    delay(beat * note_val / 16);
    tone(buzz, oct(note, octave));
    delay(beat * note_val / 16);
    tone(buzz, oct(note, octave) + 20);
    delay(beat * note_val / 16);
  }
}