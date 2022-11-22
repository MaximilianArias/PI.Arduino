/* Drive functions ---------------------------------------------------------*/

void igniteEngine () {
  if (doArranque) {
    arrancado = 1;
    switch (stepArranque) {
      case 0:
        digitalWrite(oCARGA2, CARGAOFF);
        digitalWrite(oCARGA1, CARGAON);
        stepArranque++; 
      break;
      case 1: 
        digitalWrite(oCARGA1, CARGAOFF);
        digitalWrite(oCONTACTO, RLON);
        stepArranque++;
      break;
      case 2:
        digitalWrite(oARRANQUE, RLON);
        stepArranque++;
      break;
      case 3:
        if (tArranque > tMaxArranque || !digitalRead(iBAT) || getADFrequency() > minFrecArranque) {
          if (tArranque > tMaxArranque) {
            arrancado = 0;
            fallaArranque = 1;
          } else {
            arrancado = 2;
          }
          digitalWrite(oARRANQUE, RLOFF);
          doArranque = 0;
          tArranque = 0;    
        } else {
          tArranque++;
        }
      break;
      default:
      break;
    }
  }
}

void stopEngine () {
  
}

void correctFreq (uint8_t frecuencia, uint8_t control){
  if (arrancado) {
    float adTemp = getADFrequency();
    //TO DO rutina de correccion
  } 
}

String getEngine () {
  if (arrancado == 0)       return "Parado       ";
  else if (arrancado == 1)  return "Arrancando...";
  else if (arrancado == 2)  return "En marcha... ";
}

String getLoad () {
  if (load) return "Conect.   ";
  else      return "Disconect.";
}

String getAlarms () {
  if (fallaArranque)  return "Arr.";
  else if (fallaTemp) return "Temp.";
  else if (fallaPres) return "Pres.";
  else if (fallaWiFi) return "Comm.";
  else if (fallaFrec) return "Frec.";
  else                return "OK";
}
