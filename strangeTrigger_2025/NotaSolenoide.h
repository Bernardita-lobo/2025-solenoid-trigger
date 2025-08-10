#include "Arduino.h"


class NotaSolenoide {
public:

  bool estado = false;
  unsigned long inicioNota;
  unsigned long duracionNota;

  int _pin;
  byte _nota;


  // constructor
  NotaSolenoide(int pin, byte nota) {
    _pin = pin;
    _nota = nota % 12;
  }

  void trigger(byte note, byte velocity) {
    // cuando le llega el trigger

    // guarda ese momento
    if (note % 12 == _nota) {
      Serial.println("hice un trigger");
      estado = true;
      inicioNota = millis();
      duracionNota = map(velocity, 0, 127, anchoMinimo, anchoMaximo);
      digitalWrite(_pin, 1);
    }
  }

  void update() {
    if (estado && inicioNota + duracionNota < millis()) {
      estado = false;
      Serial.println("apague esto");
      digitalWrite(_pin, 0);
    }
  }
};