/* Buttons functions ---------------------------------------------------------*/

/* Rutina de interrupcion asociada al boton iBOTON1, designado como OK */ 
void buttonOK() {
  static unsigned long debounce_holder = 0;
  unsigned long debounce = millis();
  if (debounce - debounce_holder > debounceTime) {
    if (lcd1.type == 0) {
      if (lcd1.line == 1) lcd1.line = 2;
      else if (lcd1.line == 2) lcd1.line = 3;
      else if (lcd1.line == 3) {
        lcd1.type = 1;
        lcd.clear();
        lcd.noCursor();
        setupOK = 1;
        doArranque = 1; 
      }
    }
  }  
  debounce_holder = debounce;    
}

/* Rutina de interrupcion asociada al boton iBOTON2, designado como CANCEL */ 
void buttonCANCEL() {
  static unsigned long debounce_holder = 0;
  unsigned long debounce = millis();
  if (debounce - debounce_holder > debounceTime) {
    if (lcd1.type == 0) {
      if (lcd1.line == 2) lcd1.line = 1;
      else if (lcd1.line == 3) lcd1.line = 2;  
    } else if (lcd1.type >= 1) {
        doParada = 1;
    }
  }  
  debounce_holder = debounce;      
}

/* Rutina de interrupcion asociada al boton iBOTON3, designado como PLUS */ 
void buttonPLUS() {
  static unsigned long debounce_holder = 0;
  unsigned long debounce = millis();
  if (debounce - debounce_holder > debounceTime) {
    if (lcd1.type == 0) {
      if (lcd1.line == 1) {if (frecSet < 60) frecSet++;}
      else if (lcd1.line == 2) {
        if (ctrlSet == 0) {
          ctrlSet = 1;
          ctrlStr = "Normal";
      } else if (ctrlSet == 1) {
          ctrlSet = 2;
          ctrlStr = "Rapido";
      } else if (ctrlSet == 2) {
          ctrlSet = 0;
          ctrlStr = "Lento ";
        }
      } else if (lcd1.line == 3) {
        if (remoteSet == 0) {
          remoteSet = 1;
          remoteStr = "ON ";
        }
      }
    } else if (lcd1.type >= 1 && lcd1.type < 10)  lcd1.type++;
      else                                        lcd1.type = 1;                                         
  }  
  debounce_holder = debounce;
}

/* Rutina de interrupcion asociada al boton iBOTON4, designado como MINUS */ 
void buttonMINUS() {
  static unsigned long debounce_holder = 0;
  unsigned long debounce = millis();
  if (debounce - debounce_holder > debounceTime) {
    if (lcd1.type == 0) {
      if (lcd1.line == 1) {
        if (frecSet > 46) frecSet--;
      } else if (lcd1.line == 2) {
        if (ctrlSet == 0) {
          ctrlSet = 2;
          ctrlStr = "Rapido";
      } else if (ctrlSet == 1) {
          ctrlSet = 0;
          ctrlStr = "Lento ";
      } else if (ctrlSet == 2) {
          ctrlSet = 1;
          ctrlStr = "Normal";
        }
      } else if (lcd1.line == 3) {
          if (remoteSet == 1) {
          remoteSet = 0;
          remoteStr = "OFF";
        }
      }
    } else if (lcd1.type > 1) lcd1.type--;
      else                    lcd1.type = 11;  
  }  
  debounce_holder = debounce;    
}

void botonX() {
  static unsigned long debounce_holder = 0;
  unsigned long debounce = millis();
  if (debounce - debounce_holder > debounceTime) {
    //TO DO
  }  
  debounce_holder = debounce;    
}
  
