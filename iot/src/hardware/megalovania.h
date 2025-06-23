#ifndef MEGALOVANIA_H
#define MEGALOVANIA_H

#include <Arduino.h>
#include "../config/notes.h"

// Function declarations
void playSecurityAlarm();
void play(double note, int octave, double note_val);
void rest(double note_val);
void vibrato(double note, int octave, double note_val);

#endif