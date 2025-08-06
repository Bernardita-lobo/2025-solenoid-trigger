void setupMIDI() {
  usbMIDI.setHandleNoteOn(myNoteOn);
  usbMIDI.setHandleNoteOff(myNoteOff);
}

void loopMIDI() {
  usbMIDI.read();
  for (int i = 0; i < solenoides; i++) {
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