
#define channels 8

byte       nota = 0;
byte       canal = 1;
byte       vel = 0;

byte      outPin[]    =   {3, 4, 5, 6, 9, 10, 15, 16}; // PINES DE SALIDA
byte      notas[]     =   {24, 25, 26, 27, 28, 29, 30, 31}; 
//NOTAS RECONOCIBLES POR MIDI EN LA OCTAVA 0 (C0-G0)

void setup() {
  Serial.begin(115200);
  usbMIDI.setHandleNoteOn(myNoteOn);
  usbMIDI.setHandleNoteOff(myNoteOff);
  usbMIDI.setHandleControlChange(myControlChange);

  for (int i = 0; i < channels; i++) {
    pinMode(outPin[i], OUTPUT);
    outState[i] = 0;
  }
}

void loop() {
  pin13On();

  usbMIDI.read();
  for (int i = 0; i < channels-2; i++) {
    if (nota == notas[i] || 
        nota == notas[i] + 12 ||
        nota == notas[i] + 24 ||
        nota == notas[i] + 36 ||
        nota == notas[i] + 48 ||
        nota == notas[i] + 60 ||
        nota == notas[i] + 72 ||
        nota == notas[i] + 84 ||
        nota == notas[i] + 96 ) {
      analogWrite(outPin[i], vel);
    }
  }


  for (int i = 6; i < channels; i++) {
    if (nota == notas[i] || 
        nota == notas[i] + 12 ||
        nota == notas[i] + 24 ||
        nota == notas[i] + 36 ||
        nota == notas[i] + 48 ||
        nota == notas[i] + 60 ||
        nota == notas[i] + 72 ||
        nota == notas[i] + 84 ||
        nota == notas[i] + 96 ) {
      digitalWrite(outPin[i], vel);
    }
  }
  Serial.println(nota);
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

void myControlChange(byte channel, byte control, byte value) {
  Serial.print("Control Change, ch=");
  Serial.print(channel, DEC);
  Serial.print(", control=");
  Serial.print(control, DEC);
  Serial.print(", value=");
  Serial.println(value, DEC);
}

elapsedMillis blinking;
bool          led13State = 0;
void pin13On() {
  //Funcion para evidenciar que Teensy funciona bien, encendiendo y apagando el led interno
  pinMode(13, OUTPUT);
  if (blinking >= 900 && led13State == HIGH) {
    led13State = LOW;
    blinking = blinking - 900;
  }
  if (blinking >= 100 && led13State == LOW) {
    led13State = HIGH;
    blinking = blinking - 100;
  }
  digitalWrite(13, led13State);

}
