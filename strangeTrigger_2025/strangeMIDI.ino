void setupMIDI() {
  usbMIDI.setHandleNoteOn(myNoteOn);
  usbMIDI.setHandleNoteOff(myNoteOff);
  usbMIDI.setHandleControlChange(myControlChange);
}

void loopMIDI() {
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
}

void myControlChange(byte channel, byte control, byte value) {
  Serial.print("Control Change, ch=");
  Serial.print(channel, DEC);
  Serial.print(", control=");
  Serial.print(control, DEC);
  Serial.print(", value=");
  Serial.println(value, DEC);
}

void myNoteOff(byte channel, byte note, byte velocity) {
  Serial.print("Note Off, ch=");
  Serial.print(channel, DEC);
  Serial.print(", note=");
  Serial.print(note, DEC);
  Serial.print(", velocity=");
  Serial.println(velocity, DEC);
  nota = note;
  canal = channel;
  vel = velocity - 64;
}

void myNoteOn(byte channel, byte note, byte velocity) {
  // When using MIDIx4 or MIDIx16, usbMIDI.getCable() can be used
  // to read which of the virtual MIDI cables received this message.
  Serial.print("Note On, ch=");
  Serial.print(channel, DEC);
  Serial.print(", note=");
  Serial.print(note, DEC);
  Serial.print(", velocity=");
  Serial.println(velocity, DEC);

  nota = note;
  canal = channel;
  vel = velocity;
}