
//CUANTOS CANALES DE SALIDA SE UTILIZARAN
#define channels 8

int           inByte; //LEE PUERTO SERIAL
int           bandera = 0; // BANDERA QUE DIRIGE LO QUE ENTRA DEL PUERTO SERIAL

int           outPin[]  =   {3, 4, 5, 6, 9, 10, 20, 21}; // PINES DE SALIDA

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
  }


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
    else if   (inByte == 151) {
      bandera = 21;
    }
    else if   (inByte == 152) {
      bandera = 22;
    }
    else if   (inByte == 153) {
      bandera = 23;
    }
    else if   (inByte == 154) {
      bandera = 24;
    }
    else if   (inByte == 161) {
      bandera = 31;
    }
    else if   (inByte == 162) {
      bandera = 32;
    }
    else if   (inByte == 163) {
      bandera = 33;
    }
    else if   (inByte == 164) {
      bandera = 34;
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
        //PARA FRECUENCIAS
        if (sub[0] == 3) {
          //FREQ HIGH (5 Hz a 50 Hz)
          period[0] = map(inByte, 0, 127, 200, 20);
        }
        if (sub[0] == 2) {
          //FREQ FULL
          period[0] = map(inByte, 0, 127, 5000, 20);
        }
        if (sub[0] == 1) {
          //FREQ FULL
          period[0] = map(inByte, 0, 127, 5000, 200);
        }

      }
      if (bandera == 2) {
        //PARA PWM
        pw[0] = map(inByte, 0, 127, 0, 999); // OJO CON LA CONVERSION DE INT A FLOTANTE
        pwf[0] = pw[0] * 0.001;
      }
      if (bandera == 3) {
        //PARA VARIACIONES DE FRECUENCIA
        var[0] = (inByte - 64  ) * -1;
      }
      if (bandera == 4) {
        //analogWrite(5, inByte*2);
        sub[0] = inByte;
      }



      if (bandera == 11) {//DE ACA
        //PARA FRECUENCIAS
        if (sub[1] == 3) {
          //FREQ HIGH (5 Hz a 50 Hz)
          period[1] = map(inByte, 0, 127, 200, 20);
        }
        if (sub[1] == 2) {
          //FREQ FULL
          period[1] = map(inByte, 0, 127, 5000, 20);
        }
        if (sub[1] == 1) {
          //FREQ FULL
          period[1] = map(inByte, 0, 127, 5000, 200);
        }

      }
      if (bandera == 12) {
        //analogWrite(5, inByte*2);
        pw[1] = map(inByte, 0, 127, 0, 999);
        pwf[1] = pw[1] * 0.001;
      }
      if (bandera == 13) {
        //analogWrite(5, inByte*2);
        var[1] = (inByte - 64  ) * -1;
      }
      if (bandera == 14) {
        //analogWrite(5, inByte*2);
        sub[1] = inByte;
      } // HASTA ACA

      if (bandera == 21) {//DE ACA
        //PARA FRECUENCIAS
        if (sub[2] == 3) {
          //FREQ HIGH (5 Hz a 50 Hz)
          period[2] = map(inByte, 0, 127, 200, 20);
        }
        if (sub[2] == 2) {
          //FREQ FULL
          period[2] = map(inByte, 0, 127, 5000, 20);
        }
        if (sub[2] == 1) {
          //FREQ FULL
          period[2] = map(inByte, 0, 127, 5000, 200);
        }

      }
      if (bandera == 22) {
        //analogWrite(5, inByte*2);
        pw[2] = map(inByte, 0, 127, 0, 999);
        pwf[2] = pw[2] * 0.001;
      }
      if (bandera == 23) {
        //analogWrite(5, inByte*2);
        var[2] = (inByte - 64  ) * -1;
      }
      if (bandera == 24) {
        //analogWrite(5, inByte*2);
        sub[2] = inByte;
      } // HASTA ACA

      if (bandera == 31) {//DE ACA
        //PARA FRECUENCIAS
        if (sub[3] == 3) {
          //FREQ HIGH (5 Hz a 50 Hz)
          period[3] = map(inByte, 0, 127, 200, 20);
        }
        if (sub[3] == 2) {
          //FREQ FULL
          period[3] = map(inByte, 0, 127, 5000, 20);
        }
        if (sub[3] == 1) {
          //FREQ FULL
          period[3] = map(inByte, 0, 127, 5000, 200);
        }

      }
      if (bandera == 32) {
        //analogWrite(5, inByte*2);
        pw[3] = map(inByte, 0, 127, 0, 999);
        pwf[3] = pw[3] * 0.001;
      }
      if (bandera == 33) {
        //analogWrite(5, inByte*2);
        var[3] = (inByte - 64  ) * -1;
      }
      if (bandera == 34) {
        //analogWrite(5, inByte*2);
        sub[3] = inByte;
      } // HASTA ACA

      if (bandera == 41) {//DE ACA
        //PARA FRECUENCIAS
        if (sub[4] == 3) {
          //FREQ HIGH (5 Hz a 50 Hz)
          period[4] = map(inByte, 0, 127, 200, 20);
        }
        if (sub[4] == 2) {
          //FREQ FULL
          period[4] = map(inByte, 0, 127, 5000, 20);
        }
        if (sub[4] == 1) {
          //FREQ FULL
          period[4] = map(inByte, 0, 127, 5000, 200);
        }

      }
      if (bandera == 42) {
        //analogWrite(5, inByte*2);
        pw[4] = map(inByte, 0, 127, 0, 999);
        pwf[4] = pw[4] * 0.001;
      }
      if (bandera == 43) {
        //analogWrite(5, inByte*2);
        var[4] = (inByte - 64  ) * -1;
      }
      if (bandera == 44) {
        //analogWrite(5, inByte*2);
        sub[4] = inByte;
      } // HASTA ACA

      if (bandera == 51) {//DE ACA
        //PARA FRECUENCIAS
        if (sub[5] == 3) {
          //FREQ HIGH (5 Hz a 50 Hz)
          period[5] = map(inByte, 0, 127, 200, 20);
        }
        if (sub[5] == 2) {
          //FREQ FULL
          period[5] = map(inByte, 0, 127, 5000, 20);
        }
        if (sub[5] == 1) {
          //FREQ FULL
          period[5] = map(inByte, 0, 127, 5000, 200);
        }

      }
      if (bandera == 52) {
        //analogWrite(5, inByte*2);
        pw[5] = map(inByte, 0, 127, 0, 999);
        pwf[5] = pw[5] * 0.001;
      }
      if (bandera == 53) {
        //analogWrite(5, inByte*2);
        var[5] = (inByte - 64  ) * -1;
      }
      if (bandera == 54) {
        //analogWrite(5, inByte*2);
        sub[5] = inByte;
      } // HASTA ACA

      if (bandera == 61) {//DE ACA
        //PARA FRECUENCIAS
        if (sub[6] == 3) {
          //FREQ HIGH (5 Hz a 50 Hz)
          period[6] = map(inByte, 0, 127, 200, 20);
        }
        if (sub[6] == 2) {
          //FREQ FULL
          period[6] = map(inByte, 0, 127, 5000, 20);
        }
        if (sub[6] == 1) {
          //FREQ FULL
          period[6] = map(inByte, 0, 127, 5000, 200);
        }

      }
      if (bandera == 62) {
        //analogWrite(5, inByte*2);
        pw[6] = map(inByte, 0, 127, 0, 999);
        pwf[6] = pw[6] * 0.001;
      }
      if (bandera == 63) {
        //analogWrite(5, inByte*2);
        var[6] = (inByte - 64  ) * -1;
      }
      if (bandera == 64) {
        //analogWrite(5, inByte*2);
        sub[6] = inByte;
      } // HASTA ACA

      if (bandera == 71) {//DE ACA
        //PARA FRECUENCIAS
        if (sub[7] == 3) {
          //FREQ HIGH (5 Hz a 50 Hz)
          period[7] = map(inByte, 0, 127, 200, 20);
        }
        if (sub[7] == 2) {
          //FREQ FULL
          period[7] = map(inByte, 0, 127, 5000, 20);
        }
        if (sub[7] == 1) {
          //FREQ FULL
          period[7] = map(inByte, 0, 127, 5000, 200);
        }

      }
      if (bandera == 72) {
        //analogWrite(5, inByte*2);
        pw[7] = map(inByte, 0, 127, 0, 999);
        pwf[7] = pw[7] * 0.001;
      }
      if (bandera == 73) {
        //analogWrite(5, inByte*2);
        var[7] = (inByte - 64  ) * -1;
      }
      if (bandera == 74) {
        //analogWrite(5, inByte*2);
        sub[7] = inByte;
      } // HASTA ACA

    }
  }


  for (int i = 0; i < channels; i++) {
    //Calcula tiempo de encendido
    periodV[i] = period[i] + var[i];
    timeOn[i]  = periodV[i] * pwf[i];
    timeOff[i] = periodV[i] - timeOn[i];

    //Enciende por tiempo indicado
    if (sinceOut[i] >= timeOn[i] && outState[i] == HIGH) {
      outState[i] = LOW;
      sinceOut[i] = sinceOut[i] - timeOn[i];
    }
    if (sinceOut[i] >= timeOff[i] && outState[i] == LOW) {
      outState[i] = HIGH;
      sinceOut[i] = sinceOut[i] - timeOff[i];
    }

    //Apaga la salida si PW está en 0
    if (pw[i] != 0) {
      digitalWrite(outPin[i], outState[i]);
    } else {
      digitalWrite(outPin[i], LOW);
    }

  }

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
