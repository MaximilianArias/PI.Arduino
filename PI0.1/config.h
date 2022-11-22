/* Private configurations ---------------------------------------------------------*/

/* Configuracion de GPIOs para entradas salidas y digitales */ 
void gpioInit () {
  pinMode(oLED, OUTPUT); pinMode(oMPREN, OUTPUT); 
  pinMode(oCARGA1, OUTPUT); pinMode(oCARGA2, OUTPUT);
  pinMode(oCONTACTO, OUTPUT); pinMode(oARRANQUE, OUTPUT); pinMode(oPARADA, OUTPUT);
  pinMode(oSTEP1, OUTPUT); pinMode(oSTEP2, OUTPUT); pinMode(oSTEP3, OUTPUT); pinMode(oSTEP4, OUTPUT);
  
  digitalWrite(oCONTACTO, RLOFF); digitalWrite(oARRANQUE, RLOFF); digitalWrite(oPARADA, RLOFF); 
  digitalWrite(oCARGA1, CARGAOFF); digitalWrite(oCARGA2, CARGAOFF); 

  pinMode(iPRES, INPUT); pinMode(iTEMP, INPUT); pinMode(iEV, INPUT); pinMode(iBAT, INPUT); pinMode(iFDC, INPUT);
  pinMode(iBOTON1, INPUT); pinMode(iBOTON2, INPUT); pinMode(iBOTON3, INPUT); pinMode(iBOTON4, INPUT);

  pinMode(iBOTON1, INPUT_PULLUP); pinMode(iBOTON2, INPUT_PULLUP); pinMode(iBOTON3, INPUT_PULLUP); pinMode(iBOTON4, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(iBOTON1), buttonOK, FALLING);
  attachInterrupt(digitalPinToInterrupt(iBOTON2), buttonCANCEL, FALLING);
  attachInterrupt(digitalPinToInterrupt(iBOTON3), buttonPLUS, FALLING);
  attachInterrupt(digitalPinToInterrupt(iBOTON4), buttonMINUS, FALLING);
}

/* Inicializacion de los puertos de comunicacion serial */ 
void serialInit () {
  Serial.begin(115200); // TX1 = PA9  / RX1 = PA10 
  Serial2.begin(9600);  // TX2 = PA2  / RX2 = PA3 
//  Serial3.begin(4800);  // TX3 = PB10 / RX3 = PB11 
}

/* Inicializacion del LCD 20x4 */ 
void lcdInit () {
  lcd.init();                      
  lcd.backlight();
  lcd.clear();
  lcd.cursor();
}

/* Inicializacion del Timer1 */ 
void Timer1Init () {
  HardwareTimer *Timer1 = new HardwareTimer(TIM1);
  Timer1->setOverflow(timer1OF, MICROSEC_FORMAT); 
  Timer1->attachInterrupt(Timer1Callback);
  Timer1->resume();
}

void Timer2Init () {
  HardwareTimer *Timer2 = new HardwareTimer(TIM2);
  Timer2->setOverflow(timer2OF, MICROSEC_FORMAT); 
  Timer2->attachInterrupt(Timer2Callback);
  Timer2->resume();
}

void configInit() {
  gpioInit();
  serialInit();
  lcdInit();
}
