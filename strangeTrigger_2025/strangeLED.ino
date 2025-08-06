void setupLedInterno() {
  pinMode(13, OUTPUT);
}

void loopLedInterno() {

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