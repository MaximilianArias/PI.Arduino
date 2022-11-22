/* LCD functions ---------------------------------------------------------*/

/* Mensaje estatico de bienvenida */
void printWelcome () {
  lcd.setCursor(0,0);
  lcd.print(F("     BIENVENIDOS    "));
  lcd.setCursor(0,1);
  lcd.print(F(" SISTEMA DE CONTROL "));
  lcd.setCursor(0,2);
  lcd.print(F(" REMOTO PARA GRUPOS  "));
  lcd.setCursor(0,3);
  lcd.print(F("ELECTROGENO A DIESEL"));
  delay(3000);
  lcd.clear();
  lcd1.type = 0;  //inicializacion de instancia del menu
  lcd1.line = 1;  //inicializacion de instancia del menu  
}

/* Menu de configuraciones para operacion manual */
void printConfig () {
  if (lcd1.type == 0) {
    lcd.setCursor(0,0);
    lcd.print(F("Configure el sistema"));
    if (lcd1.line == 1) {
      lcd.setCursor(0,1);
      lcd.print(F("Frecuencia = "));
      lcd.print(frecSet);
      lcd.print(F(" Hz"));          
    } else if (lcd1.line == 2) {
      lcd.setCursor(0,2);
      lcd.print(F("Control = "));
      lcd.print(ctrlStr);               
    } else if (lcd1.line == 3) {
      lcd.setCursor(0,3);
      lcd.print(F("Remoto = "));
      lcd.print(remoteStr);    
    }
  } 
}

/* Impresion de variables de estado por pantallas */
void printStatus () {
  if (lastScreen != lcd1.type) {  //verificacion de cambio de pantalla 
    lcd.clear();                  //para realizar limpieza de caracteres
    lastScreen = lcd1.type;       
  }
  switch (lcd1.type) {
    case 1:
      lcd.setCursor(0,0);
      lcd.print(F("Motor = "));
      lcd.print(getEngine());
      lcd.setCursor(0,1);
      lcd.print(F("Carga = "));
      lcd.print(getLoad());
      lcd.setCursor(0,2);
      lcd.print(F("Frecuencia = "));
      lcd.print(getADFrequency());
      lcd.print(F("Hz"));
      lcd.setCursor(0,3);
      lcd.print(F("Alarmas = "));
      lcd.print(getAlarms());
      break;  
    case 2: 
      for (int j = 0; j < 3; j++) {
        lcd.setCursor(3,j);
        lcd.print(F("VLN"));
        lcd.print(j+1);
        lcd.print(F(" = "));
        lcd.print(getVoltage (mediciones[j]));
        lcd.print(F("V"));
      } 
      lcd.setCursor(3, 3);
      lcd.print(F("Frec = "));
      lcd.print(getFrequency (mediciones[27]));
      lcd.print(F("Hz"));
      break;
    case 3:
      for (int j = 3; j < 6; j++) {
        lcd.setCursor(3,j - 3);
        lcd.print(F("ILN"));
        lcd.print(j-2);
        lcd.print(F(" = "));
        lcd.print(getCurrent (mediciones[j]));
        lcd.print(F("A"));
      } 
      lcd.setCursor(4,3);
      lcd.print(F("IT = "));
      lcd.print(getCurrent (mediciones[6]));
      lcd.print(F("A"));
      break;
    case 4:
      for (int j = 7; j < 10; j++) {
        lcd.setCursor(3,j - 7);
        lcd.print(F("P"));
        lcd.print(j-6);
        lcd.print(F(" = "));
        lcd.print(getPower (mediciones[j]));
        lcd.print(F("W"));
      } 
      lcd.setCursor(3,3);
      lcd.print(F("PT = "));
      lcd.print(getPower (mediciones[28]));
      lcd.print(F("W"));
      break;
    case 5:
      for (int j = 10; j < 13; j++) {
        lcd.setCursor(3,j - 10);
        lcd.print(F("Q"));
        lcd.print(j-9);
        lcd.print(F(" = "));
        lcd.print(getPower (mediciones[j]));
        lcd.print(F("VAr"));
      } 
      lcd.setCursor(3,3);
      lcd.print(F("QT = "));
      lcd.print(getPower (mediciones[29]));
      lcd.print(F("VAr"));
      break;
    case 6:
      for (int j = 13; j < 16; j++) {
        lcd.setCursor(3,j - 13);
        lcd.print(F("S"));
        lcd.print(j-12);
        lcd.print(F(" = "));
        lcd.print(getPowerS (mediciones[j]));
        lcd.print(F("VA"));
      } 
      lcd.setCursor(3,3);
      lcd.print(F("ST = "));
      lcd.print(getPowerS (mediciones[30]));
      lcd.print(F("VA"));
      break;
    case 7:
      for (int j = 16; j < 19; j++) {
        lcd.setCursor(5,j - 16);
        lcd.print(F("FP"));
        lcd.print(j-15);
        lcd.print(F(" = "));
        lcd.print(getFP (mediciones[j]));
      } break;
    case 8:
      for (int j = 19; j < 22; j++) {
        lcd.setCursor(3,j - 19);
        lcd.print(F("CosFi"));
        lcd.print(j-18);
        lcd.print(F(" = "));
        lcd.print(getFP (mediciones[j]));
      } break;
    case 9:
      for (int j = 22; j < 25; j++) {
        lcd.setCursor(3,j - 22);
        lcd.print(F("VL"));
        lcd.print(j-21);
        lcd.print(F(" = "));
        lcd.print(getVoltage (mediciones[j]));
        lcd.print(F("V"));
      } break;
    case 10:
      for (int j = 31; j < 34; j++) {
        lcd.setCursor(3,j - 31);
        lcd.print(F("THDV"));
        lcd.print(j-30);
        lcd.print(F(" = "));
        lcd.print(getTHD (mediciones[j]));
        lcd.print(F("%"));
      } break;
    case 11:
      for (int j = 35; j < 38; j++) {
        lcd.setCursor(3,j - 35);
        lcd.print(F("THDI"));
        lcd.print(j-34);
        lcd.print(F(" = "));
        lcd.print(getTHD (mediciones[j]));
        lcd.print(F("%"));
      } break;
    default:
      break;                 
  }
}
