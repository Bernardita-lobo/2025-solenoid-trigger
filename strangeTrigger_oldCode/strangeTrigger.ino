
//CUANTOS CANALES DE SALIDA SE UTILIZARAN
#define channels 8

int           inByte; //LEE PUERTO SERIAL
int           bandera = 0; // BANDERA QUE DIRIGE LO QUE ENTRA DEL PUERTO SERIAL

int           outPin[]  =   {3, 4, 5, 6, 9, 10, 15, 16}; // PINES DE SALIDA

int           sub[]     =   {0, 0, 0, 0, 0, 0, 0, 0};
unsigned long period[]  =   {1000, 900, 800, 700, 600, 500, 300, 200}; //Frecuencia de oscilación, en periodo
unsigned long periodV[] =   {1000, 900, 800, 700, 600, 500, 300, 200}; //Frecuencia de oscilación, en periodo
int           var[]     =   {0, 0, 0, 0, 0, 0, 0, 0}; // Variación de frecuencia
int           pw[]      =   {0, 0, 0, 0, 0, 0, 0, 0}; //Ancho de pulso de la salida
float         pwf[]     =   {0.5, 0.4, 0.5, 0.4, 0.5, 0.5, 0.4, 0.5}; //Ancho de pulso en flotante
bool          outState[] =  {0, 0, 0, 0, 0, 0, 0, 0}; //Estado de cada canal (low o high)

unsigned long timeOn[channels]; //Tiempo de encendido de cada canal
unsigned long timeOff[channels]; // Tiempo de apagado de cada canal (dependiente mas adelante de TimeOn y periodo)


elapsedMillis sinceOut[channels]; //Variante de millis(); integrada en Teensy 3.2


void setup() {
  Serial.begin(115200);

  for (int i = 0; i < channels; i++) {
    pinMode(outPin[i], OUTPUT);
    outState[i] = 0;
    period[i] = 0;
  }

  analogWriteFrequency(3, 375000);
  analogWriteFrequency(4, 375000);
  analogWriteFrequency(5, 375000);
  analogWriteFrequency(6, 375000);
  analogWriteFrequency(9, 375000);
  analogWriteFrequency(10, 375000);
}


void loop() {
  pin13On();

  if (Serial.available()) {
    // read the incoming byte:
    inByte = Serial.read();
    if        (inByte == 131) {
      bandera = 1;
    }
    else if   (inByte == 132) {
      bandera = 2;
    }
    else if   (inByte == 133) {
      bandera = 3;
    }
    else if   (inByte == 134) {
      bandera = 4;
    }
    else if   (inByte == 135) {
      bandera = 5;
    }
    else if   (inByte == 136) {
      bandera = 6;
    }
    else if   (inByte == 137) {
      bandera = 7;
    }
    else if   (inByte == 138) {
      bandera = 8;
    }
    else if   (inByte == 139) {
      bandera = 9;
    }
    else if   (inByte == 140) {
      bandera = 10;
    }
    else if   (inByte == 141) {
      bandera = 11;
    }
    else if   (inByte == 142) {
      bandera = 12;
    }
    else if   (inByte == 143) {
      bandera = 13;
    }
    else if   (inByte == 144) {
      bandera = 14;
    }
    else if   (inByte == 145) {
      bandera = 15;
    }
    else if   (inByte == 146) {
      bandera = 16;
    }
    else if   (inByte == 171) {
      bandera = 41;
    }
    else if   (inByte == 172) {
      bandera = 42;
    }
    else if   (inByte == 173) {
      bandera = 43;
    }
    else if   (inByte == 174) {
      bandera = 44;
    }
    else if   (inByte == 181) {
      bandera = 51;
    }
    else if   (inByte == 182) {
      bandera = 52;
    }
    else if   (inByte == 183) {
      bandera = 53;
    }
    else if   (inByte == 184) {
      bandera = 54;
    }
    else if   (inByte == 191) {
      bandera = 61;
    }
    else if   (inByte == 192) {
      bandera = 62;
    }
    else if   (inByte == 193) {
      bandera = 63;
    }
    else if   (inByte == 194) {
      bandera = 64;
    }
    else if   (inByte == 201) {
      bandera = 71;
    }
    else if   (inByte == 202) {
      bandera = 72;
    }
    else if   (inByte == 203) {
      bandera = 73;
    }
    else if   (inByte == 204) {
      bandera = 74;
    }

    else {
      if (bandera == 1) {
        period[0] = inByte;
      }

      if (bandera == 2) {
        if (inByte != 0) {
          pw[0] = inByte * 2 + 1;
        } else {
          pw[0] = 0;
        }
      }

      if (bandera == 3) {
        period[1] = inByte;
      }

      if (bandera == 4) {
        if (inByte != 0) {
          pw[1] = inByte * 2 + 1;
        } else {
          pw[1] = 0;
        }

      }

      if (bandera == 5) {
        period[2] = inByte;
      }

      if (bandera == 6) {
        if (inByte != 0) {
          pw[2] = inByte * 2 + 1;
        } else {
          pw[2] = 0;
        }

      }

      if (bandera == 7) {
        period[3] = inByte;
      }

      if (bandera == 8) {
        if (inByte != 0) {
          pw[3] = inByte * 2 + 1;
        } else {
          pw[3] = 0;
        }

      }

      if (bandera == 9) {
        period[4] = inByte;
      }

      if (bandera == 10) {
        if (inByte != 0) {
          pw[4] = inByte * 2 + 1;
        } else {
          pw[4] = 0;
        }

      }

      if (bandera == 11) {
        period[5] = inByte;
      }

      if (bandera == 12) {
        if (inByte != 0) {
          pw[5] = inByte * 2 + 1;
        } else {
          pw[5] = 0;
        }

      }

      if (bandera == 13) {
        period[6] = inByte;
      }

      if (bandera == 14) {
        if (inByte != 0) {
          pw[6] = inByte * 2 + 1;
        } else {
          pw[6] = 0;
        }

      }

      if (bandera == 15) {
        period[7] = inByte;
      }

      if (bandera == 16) {
        if (inByte != 0) {
          pw[7] = inByte * 2 + 1;
        } else {
          pw[7] = 0;
        }

      }

    }
  }


  for (int i = 0; i < channels - 2; i++) {

    outState[i] = period[i];
    analogWrite(outPin[i], outState[i]*pw[i]);
    //    outState[1] = period[1];
    //    analogWrite(outPin[1], outState[1]*pw[1]);
    //    outState[2] = period[2];
    //    analogWrite(outPin[2], outState[2]*pw[2]);
    //    outState[4] = period[4];
    //    analogWrite(outPin[3], outState[3]*pw[3]);
    //    outState[4] = period4];
    //    analogWrite(outPin[4], outState[4]*pw[4]);
    //    outState[4] = period4];
    //    analogWrite(outPin[4], outState[4]*pw[4]);


  }
  outState[6] = period[6];
  digitalWrite(outPin[6], outState[6]);
  outState[7] = period[7];
  digitalWrite(outPin[7], outState[7]);

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
