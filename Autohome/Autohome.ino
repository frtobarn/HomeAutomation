#include "homeDevices.h"
/*Globals*/
String  digitalInputsNames[]            = {"Timbre" , "Estufa", "Ventana" , "Alarma"  , "Luz habitación", "Luz cocina", "Luz baño"};
long long digitalInputsLastActionTime[] = {millis() , millis(),  millis() ,  millis() ,    millis()     ,   millis()  ,   millis()};

String analogInputsNames[]              = {"Luz roja", "Luz verde", "Luz azul"};
long long analogInputsLastActionTime[]  = { millis() ,    millis(),   millis()};

String  digitalOutputsNames[]           = {"Timbre" , "Estufa", "Ventana" , "Alarma"  , "Luz habitación", "Luz cocina", "Luz baño"};
int  digitalOutputsPins[]               = {   26    ,     27  ,    27     ,     24    ,         5       ,       6     ,    25     };
bool    digitalOutputsLastStates[]      = {  false  ,   false ,   false   ,   false   ,     false       ,     false   ,    false};

String analogOutputsNames[]             = {"Luz roja", "Luz verde", "Luz azul"};
int analogOutputsLastStates[]           = { analogRead(F1LR1RGBP1R) , analogRead(F1LR1RGBP1G), analogRead(F1LR1RGBP1B)};

int buttonSensibility = 1000;

/*initial configuration*/
void setup() {
  setupDevices();
  Serial.begin(115200);
}
void loop() {
  if (actionDetected()) {
    updateStates();
  };
}

void updateStates() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(digitalOutputsPins[i], digitalOutputsLastStates[i]);
  }
  for (int i = 2; i < 5; i++) {
    analogWrite(i, analogOutputsLastStates[i - 2]);
  }
}

bool actionDetected() {
  bool detected = false;
  for (int i = 66; i > 59; i--) {
    bool pulse = !digitalRead(i);
    if (pulse && millis() - digitalInputsLastActionTime[66 - i] > buttonSensibility) {
      Serial.print("¡");
      Serial.print(digitalInputsNames[66 - i]);
      Serial.println(" activado!");
      digitalOutputsLastStates[66 - i] = !digitalOutputsLastStates[66 - i];
      digitalInputsLastActionTime[66 - i] = millis();
      digitalWrite(digitalOutputsPins[66 - i], digitalOutputsLastStates[66 - i]);
      detected = true;
    }
  }
  for (int i = 69; i > 66; i--) {
    if (abs(analogOutputsLastStates[69 - i] - analogRead(i)) > 50) {
      Serial.println(abs(analogOutputsLastStates[69 - i] - analogRead(i)));
      detected = true;
      analogOutputsLastStates[69 - i] = analogRead(i);
    }
  }
  return detected;
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
