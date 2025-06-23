#ifndef NOTES_H
#define NOTES_H

#include <Arduino.h>

// Musical notes frequency definitions (base frequencies)
#define cnat 16.35
#define csharp 17.32
#define dnat 18.35
#define eb 19.45
#define enat 20.60
#define fnat 21.83
#define fsharp 23.12
#define gnat 24.50
#define gsharp 25.96
#define anat 27.50
#define bb 29.14
#define bnat 30.87

// Function to calculate octave frequencies
#define oct(note, octave) note * pow(2, octave)

#define beat 500 // = 60 s / 120 bpm * 1000 ms

#endif