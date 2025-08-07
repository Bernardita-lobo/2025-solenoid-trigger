
bool notaON[] = { false, false, false, false, false, false, false, false };

void setupMIDI() {
  usbMIDI.setHandleNoteOn(myNoteOn);
  usbMIDI.setHandleNoteOff(myNoteOff);
}

void loopMIDI() {
  usbMIDI.read();

  for (int i = 0; i < solenoides; i++) {
    if (nota % 12 == notas[i] % 12) {
      int ancho = map(vel, 0, 127, anchoMinimo, anchoMaximo);
      if (notaON[i]) {
        digitalWrite(outPin[i], 1);
        // analogWrite(outPin[i], 255);
      } else {
        digitalWrite(outPin[i], 0);
      }
    }
  }
}

void myNoteOff(byte channel, byte note, byte velocity) {
  nota = note;
  canal = channel;
  vel = velocity - 64;

  for (int i = 0; i < solenoides; i++) {
    if (nota % 12 == notas[i] % 12) {
      notaON[i] = false;
    }
  }
}

void myNoteOn(byte channel, byte note, byte velocity) {
  nota = note;
  canal = channel;
  vel = velocity;

  for (int i = 0; i < solenoides; i++) {
    if (nota % 12 == notas[i] % 12) {
      notaON[i] = true;
    }
  }
}