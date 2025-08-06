//NOTAS RECONOCIBLES POR MIDI EN LA OCTAVA 0 (C0-G0)
// do, re, mi, fa, sol, la, si, sib
byte notas[] = { 24, 26, 28, 29, 31, 33, 35, 34 };

// setup() ocurre una vez al principio
void setup() {

  setupLedInterno();

  setupPinesSalida();

  setupMIDI();
}

// loop() ocurre despues de setup(), en bucle
void loop() {

  loopLedInterno();

  loopMIDI();
}
