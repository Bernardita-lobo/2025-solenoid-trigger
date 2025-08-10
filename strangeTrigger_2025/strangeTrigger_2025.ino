void setup() {

  Serial.begin(9600);
  
  setupLedInterno();

  setupPinesSalida();

  setupMIDI();

}

void loop() {

  loopLedInterno();

  loopMIDI();
}
