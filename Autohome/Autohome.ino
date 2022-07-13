/*PWM OUTPUTS*/
const int F1LR1RGBL1R = 2;
const int F1LR1RGBL1G = 3;
const int F1LR1RGBL1B = 4;
const int F1BR1WRL1 = 5;
const int F1KT1WRL1 = 6;
/*Digital OUTPUTS*/
const int F1ME1RGBI1R = 22;
const int F1ME1RGBI1B = 23;
const int F1ME1RGBI1G = 24;
const int F1BTR1FL1 = 25;
const int F1ME1SAL1 = 26;


/*Analog INPUTS*/
const int F1LR1RGBP1R = A15;
const int F1LR1RGBP1G = A14;
const int F1LR1RGBP1B = A13;
const int F1ME1DBB1 = A12;
const int F1KT1STO1 = A11;
const int F1ME1WS1 = A10;
const int F1LR1PAB1 = A9;
const int F1BR1LB1 = A8;
const int F1KT1LB1 = A7;
const int F1BTR1LB1 = A6;


void setup() {
  /*Input pins*/
  pinMode(F1LR1RGBP1R, INPUT);
  pinMode(F1LR1RGBP1G, INPUT);
  pinMode(F1LR1RGBP1B, INPUT);
  pinMode(F1ME1DBB1, INPUT_PULLUP);
  pinMode(F1KT1STO1, INPUT_PULLUP);
  pinMode(F1ME1WS1, INPUT_PULLUP);
  pinMode(F1LR1PAB1, INPUT_PULLUP);
  pinMode(F1BR1LB1, INPUT_PULLUP);
  pinMode(F1KT1LB1, INPUT_PULLUP);
  pinMode(F1BTR1LB1, INPUT_PULLUP);

  /*Output pins*/
  pinMode(F1LR1RGBL1R, OUTPUT);
  pinMode(F1LR1RGBL1G, OUTPUT);
  pinMode(F1LR1RGBL1B, OUTPUT);
  pinMode(F1BR1WRL1, OUTPUT);
  pinMode(F1KT1WRL1, OUTPUT);
  pinMode(F1ME1RGBI1R, OUTPUT);
  pinMode(F1ME1RGBI1B, OUTPUT);
  pinMode(F1ME1RGBI1G, OUTPUT);
  pinMode(F1BTR1FL1, OUTPUT);
  pinMode(F1ME1SAL1, OUTPUT);

  /*Estados iniciales de salida*/
  digitalWrite(F1LR1RGBL1R, LOW);
  digitalWrite(F1LR1RGBL1G, LOW);
  digitalWrite(F1LR1RGBL1B, LOW);
  digitalWrite(F1BR1WRL1, LOW);
  digitalWrite(F1KT1WRL1, LOW);
  digitalWrite(F1ME1RGBI1R, LOW);
  digitalWrite(F1ME1RGBI1B, LOW);
  digitalWrite(F1ME1RGBI1G, LOW);
  digitalWrite(F1BTR1FL1, LOW);
  digitalWrite(F1ME1SAL1, LOW);
  Serial.begin(115200);
}

void loop() {
  //int F1LR1RGBP1R_value = analogRead(F1LR1RGBP1R);
  //int F1ME1DBB1_value = !digitalRead(F1ME1DBB1);
  //int inputs[] = {F1ME1DBB1, F1KT1STO1, F1ME1WS1, F1LR1PAB1, F1BR1LB1, F1KT1LB1, F1BTR1LB1};
  int inputs[] = {A12, A11, A10, A9, A8, A7, A6 };
  for (int i = 0; i < 7; i++) {
    bool value = !digitalRead(inputs[i]);
    if (value) {
      Serial.print(inputs[i]);
      Serial.print("=");
      Serial.println(value);
    }
  }
  delay(100);
}

void testPwm(int times, int vel) {
  for (int i = 0; i < times; i++) {
    for (int i = 0; i < 256; i++) {
      analogWrite(F1LR1RGBL1R, i );
      delay(vel);
    }
    for (int i = 254; i > 0; i--) {
      analogWrite(F1LR1RGBL1R, i );
      delay(vel);
    }
    for (int i = 0; i < 256; i++) {
      analogWrite(F1LR1RGBL1G, i );
      delay(vel);
    }
    for (int i = 254; i > 0; i--) {
      analogWrite(F1LR1RGBL1G, i );
      delay(vel);
    }
    for (int i = 0; i < 256; i++) {
      analogWrite(F1LR1RGBL1B, i );
      delay(vel);
    }
    for (int i = 254; i > 0; i--) {
      analogWrite(F1LR1RGBL1B, i );
      delay(vel);
    }




    for (int i = 0; i < 256; i++) {
      analogWrite(F1BR1WRL1, i );
      delay(vel * 2);
    }
    for (int i = 254; i > 0; i--) {
      analogWrite(F1BR1WRL1, i );
      delay(vel * 2);
    }
    for (int i = 0; i < 256; i++) {
      analogWrite(F1BR1WRL1, i );
      delay(vel);
    }
    for (int i = 254; i > 0; i--) {
      analogWrite(F1BR1WRL1, i );
      delay(vel);
    }

    for (int i = 0; i < 256; i++) {
      analogWrite(F1KT1WRL1, i );
      delay(vel * 2);
    }
    for (int i = 254; i > 0; i--) {
      analogWrite(F1KT1WRL1, i );
      delay(vel * 2);
    }
    for (int i = 0; i < 256; i++) {
      analogWrite(F1KT1WRL1, i );
      delay(vel);
    }
    for (int i = 254; i > 0; i--) {
      analogWrite(F1KT1WRL1, i );
      delay(vel);
    }

    /*Azul-violeta-rojo*/
    for (int i = 0; i < 256; i++) {
      analogWrite(F1LR1RGBL1R, i );
      analogWrite(F1LR1RGBL1B, 256 - i );
      delay(vel * 4);
    }
    for (int i = 254; i > 0; i--) {
      analogWrite(F1LR1RGBL1R, i );
      analogWrite(F1LR1RGBL1B, 256 - i );
      delay(vel * 4);
      analogWrite(F1LR1RGBL1B, 0);
    }

    /*Blanco*/
    for (int i = 0; i < 256; i++) {
      analogWrite(F1LR1RGBL1R, i );
      analogWrite(F1LR1RGBL1G, i );
      analogWrite(F1LR1RGBL1B, i );
      delay(vel * 3);
    }
    delay(1000);
    for (int i = 254; i > 0; i--) {
      analogWrite(F1LR1RGBL1R, i );
      analogWrite(F1LR1RGBL1G, i );
      analogWrite(F1LR1RGBL1B, i );
      delay(vel * 3);
    }

    delay(1000);
  }

}
void testOutputs(int times, int vel) {
  for (int i = 0; i < times; i++) {
    digitalWrite(F1LR1RGBL1R, HIGH);
    delay(vel);
    digitalWrite(F1LR1RGBL1R, LOW);
    digitalWrite(F1LR1RGBL1G, HIGH);
    delay(vel);
    digitalWrite(F1LR1RGBL1G, LOW);
    digitalWrite(F1LR1RGBL1B, HIGH);
    delay(vel);
    digitalWrite(F1LR1RGBL1B, LOW);
    digitalWrite(F1BR1WRL1, HIGH);
    delay(vel);
    digitalWrite(F1BR1WRL1, LOW);
    digitalWrite(F1KT1WRL1, HIGH);
    delay(vel);
    digitalWrite(F1KT1WRL1, LOW);

    digitalWrite(F1ME1RGBI1R, HIGH);
    delay(vel);
    digitalWrite(F1ME1RGBI1R, LOW);
    digitalWrite(F1ME1RGBI1G, HIGH);
    delay(vel);
    digitalWrite(F1ME1RGBI1G, LOW);
    digitalWrite(F1ME1RGBI1B, HIGH);
    delay(vel);
    digitalWrite(F1ME1RGBI1B, LOW);
    digitalWrite(F1BTR1FL1, HIGH);
    delay(vel);
    digitalWrite(F1BTR1FL1, LOW);
    digitalWrite(F1ME1SAL1, HIGH);
    delay(vel);
    digitalWrite(F1ME1SAL1, LOW);
  }
}
