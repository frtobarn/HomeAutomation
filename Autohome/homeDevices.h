/*PWM OUTPUTS*/
#define F1LR1RGBL1R  2
#define F1LR1RGBL1G  3
#define F1LR1RGBL1B  4
#define F1BR1WRL1  5
#define F1KT1WRL1  6
/*Digital OUTPUTS*/
#define F1ME1RGBI1R  22
#define F1ME1RGBI1G  23
#define F1ME1RGBI1B  24
#define F1BTR1FL1  25
#define F1ME1SAL1  26


/*Analog INPUTS*/
#define F1LR1RGBP1R  69
#define F1LR1RGBP1G 68
#define F1LR1RGBP1B  67
#define F1ME1DBB1  66
#define F1KT1STO1  65
#define F1ME1WS1  64
#define F1LR1PAB1  63
#define F1BR1LB1  62
#define F1KT1LB1  61
#define  F1BTR1LB1  60

void setupDevices(){
  
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
  pinMode(F1ME1RGBI1G, OUTPUT);
  pinMode(F1ME1RGBI1B, OUTPUT);
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
}
