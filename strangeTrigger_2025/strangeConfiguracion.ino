#define solenoides 8

byte nota = 0;
byte canal = 1;
byte vel = 0;

//NOTAS RECONOCIBLES POR MIDI EN LA OCTAVA 0 (C0-G0)
// do, re, mi, fa, sol, la, si, sib
byte notas[] = { 24, 26, 28, 29, 31, 33, 35, 34 };

// pines de salida
byte outPin[] = { 3, 4, 5, 6, 9, 10, 15, 16 };

void setupPinesSalida() {
  for (int i = 0; i < solenoides; i++) {
    pinMode(outPin[i], OUTPUT);
  }
}
