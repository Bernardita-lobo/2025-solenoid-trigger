#define channels 8

byte nota = 0;
byte canal = 1;
byte vel = 0;

// pines de salida
byte outPin[] = { 3, 4, 5, 6, 9, 10, 15, 16 };

void setupPinesSalida() {
  for (int i = 0; i < channels; i++) {
    pinMode(outPin[i], OUTPUT);
  }
}
