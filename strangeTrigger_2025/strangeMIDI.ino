
#include "NotaSolenoide.h"

NotaSolenoide solenoides[] = {
  NotaSolenoide(outPin[0], notas[0]),
  NotaSolenoide(outPin[1], notas[1]),
  NotaSolenoide(outPin[2], notas[2]),
  NotaSolenoide(outPin[3], notas[3]),
  NotaSolenoide(outPin[4], notas[4]),
  NotaSolenoide(outPin[5], notas[5]),
  NotaSolenoide(outPin[6], notas[6]),
  NotaSolenoide(outPin[7], notas[7])
};


// bool notaON[] = { false, false, false, false, false, false, false, false };

void setupMIDI() {
  usbMIDI.setHandleNoteOn(myNoteOn);
  // usbMIDI.setHandleNoteOff(myNoteOff);
}

void loopMIDI() {
  usbMIDI.read();

  for (int i = 0; i < numeroSolenoides; i++) {
    solenoides[i].update();
  }

  // for (int i = 0; i < numeroSolenoides; i++) {
  //   if (nota % 12 == notas[i] % 12) {
  //     if (notaON[i]) {
  //       digitalWrite(outPin[i], 1);
  //       // analogWrite(outPin[i], 255);
  //     } else {
  //       digitalWrite(outPin[i], 0);
  //     }
  //   }
  // }
}

// void myNoteOff(byte channel, byte note, byte velocity) {
//   nota = note;
//   canal = channel;
//   vel = velocity - 64;

//   for (int i = 0; i < numeroSolenoides; i++) {
//     if (nota % 12 == notas[i] % 12) {
//       notaON[i] = false;
//     }
//   }
// }

void myNoteOn(byte channel, byte note, byte velocity) {
  // nota = note;
  // canal = channel;
  // vel = velocity;

  for (int i = 0; i < numeroSolenoides; i++) {
    solenoides[i].trigger(note, velocity);
  }



  // for (int i = 0; i < numeroSolenoides; i++) {
  //   if (nota % 12 == notas[i] % 12) {
  //     notaON[i] = true;
  //   }
  // }
}