void setupMIDI() {
  usbMIDI.setHandleNoteOn(myNoteOn);
  usbMIDI.setHandleNoteOff(myNoteOff);
}

void loopMIDI() {
  usbMIDI.read();
  for (int i = 0; i < channels - 2; i++) {
    if (nota % 12 == notas[i] % 12) {
      digitalWrite(outPin[i], vel);
    }
  }


  for (int i = 6; i < channels; i++) {
    if (nota % 12 == notas[i] % 12) {
      digitalWrite(outPin[i], vel);
    }
  }
}

void myNoteOff(byte channel, byte note, byte velocity) {
  nota = note;
  canal = channel;
  vel = velocity - 64;
}

void myNoteOn(byte channel, byte note, byte velocity) {
  nota = note;
  canal = channel;
  vel = velocity;
}