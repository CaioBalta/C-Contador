int painel[] = {13, 12, 11, 10, 9, 8, 7};
int m_painel[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},  // 0
  {0, 1, 1, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1},  // 2
  {1, 1, 1, 1, 0, 0, 1},  // 3
  {0, 1, 1, 0, 0, 1, 1},  // 4
  {1, 0, 1, 1, 0, 1, 1},  // 5
  {1, 0, 1, 1, 1, 1, 1},  // 6
  {1, 1, 1, 0, 0, 0, 0},  // 7
  {1, 1, 1, 1, 1, 1, 1},  // 8
  {1, 1, 1, 1, 0, 1, 1}   // 9
};


int btn = 2; 
int vl = 0;
int ult_vl = 0;
int cont = 0;

void setup() {
  for (int p = 0; p < 7; p++) {
    pinMode(painel[p], OUTPUT);
  }
  pinMode(btn, INPUT);
  Serial.begin(9600);
  visor(cont);
}

void loop() {
  vl = digitalRead(btn);
  if (vl == 1 && ult_vl == 0) {
    cont++;
    if (cont > 9) {
      cont = 0;
    }
    visor(cont);
    Serial.println(cont);
  }
  ult_vl = vl;
  delay(50);
}
void visor(int num) {
  for (int p = 0; p < 7; p++) {
    digitalWrite(painel[p], m_painel[num][p]);
  }
}
