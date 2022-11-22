/* ADC Routines ---------------------------------------------------------*/

float getADFrequency (){
  float adSample = analogRead(adFREC);
  /*Completar acondicionamiento de señal del conversor f/v */
  return adSample;
}
float getADBattery (){
  float adSample = analogRead(adBAT);
  /*Completar acondicionamiento de señal del medidor de tension de bateria */
  return adSample;  
}
float getADTemp (){
  float adSample = analogRead(adTEMP);
  /*Completar acondicionamiento de señal del termistor NTC*/
  return adSample;  
}
