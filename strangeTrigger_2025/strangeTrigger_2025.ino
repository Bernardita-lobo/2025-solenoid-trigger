#define channels 8

byte nota = 0;
byte canal = 1;
byte vel = 0;

// pines de salida
byte outPin[] = { 3, 4, 5, 6, 9, 10, 15, 16 };

//NOTAS RECONOCIBLES POR MIDI EN LA OCTAVA 0 (C0-G0)
byte notas[] = { 24, 25, 26, 27, 28, 29, 30, 31 };

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

  usbMIDI.read();
  for (int i = 0; i < channels - 2; i++) {
    // if (nota == notas[i] || nota == notas[i] + 12 || nota == notas[i] + 24 || nota == notas[i] + 36 || nota == notas[i] + 48 || nota == notas[i] + 60 || nota == notas[i] + 72 || nota == notas[i] + 84 || nota == notas[i] + 96) {
    if (nota == notas[i] % 12) {
      analogWrite(outPin[i], vel);
    }
  }


  for (int i = 6; i < channels; i++) {
    // if (nota == notas[i] || nota == notas[i] + 12 || nota == notas[i] + 24 || nota == notas[i] + 36 || nota == notas[i] + 48 || nota == notas[i] + 60 || nota == notas[i] + 72 || nota == notas[i] + 84 || nota == notas[i] + 96) {
    if (nota == notas[i] % 12) {
      digitalWrite(outPin[i], vel);
    }
  }
  Serial.println(nota);
}

