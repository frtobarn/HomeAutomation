/*PWM INPUTS*/
const int F1LR1RGBL1R = 2;
const int F1LR1RGBL1G = 3;
const int F1LR1RGBL1B = 4;
const int F1BR1WRL1 = 5; 
const int F1KT1WRL1 = 6;
/*Digital*/
const int F1ME1RGBI1R = 22;
const int F1ME1RGBI1B = 23;
const int F1ME1RGBI1G = 24;
const int F1BTR1FL1 = 25;
const int F1ME1SAL1 = 26;

void setup() {
  pinMode(F1LR1RGBL1R , OUTPUT);
  pinMode(F1LR1RGBL1G , OUTPUT);
  pinMode(F1LR1RGBL1B , OUTPUT);
  pinMode(F1BR1WRL1 , OUTPUT);
  pinMode(F1KT1WRL1 , OUTPUT);
  pinMode(F1ME1RGBI1R , OUTPUT);
  pinMode(F1ME1RGBI1B , OUTPUT);
  pinMode(F1ME1RGBI1G , OUTPUT);
  pinMode(F1BTR1FL1 , OUTPUT);
  pinMode(F1ME1SAL1 , OUTPUT);

  /*Estados iniciales*/
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
  testOutputs(3, 1000);
  delay(3000);
}

void loop() {
  int vel = 2;
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
