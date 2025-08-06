#define channels 8


byte nota = 0;
byte canal = 1;
byte vel = 0;

// pines de salida
byte outPin[] = { 3, 4, 5, 6, 9, 10, 15, 16 };

//NOTAS RECONOCIBLES POR MIDI EN LA OCTAVA 0 (C0-G0)
// do, re, mi, fa, sol, la, si
byte notas[] = { 24, 26, 28, 29, 31, 33, 35 };

elapsedMillis blinking;

bool led13State = 0;

// setup() ocurre una vez al principio
void setup() {

  setupLedInterno();

  setupMIDI();

  Serial.begin(115200);

  for (int i = 0; i < channels; i++) {
    pinMode(outPin[i], OUTPUT);
    outState[i] = 0;
  }
}

// loop() ocurre despues de setup(), en bucle
void loop() {

  loopLedInterno();

  loopMIDI();
  
  Serial.println(nota);
}

