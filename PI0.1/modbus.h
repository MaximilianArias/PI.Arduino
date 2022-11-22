/* MODBUS functions ---------------------------------------------------------*/
extern uint16_t registro16; //definicion referida en variables.h

/* Rutina para comunicacion MODBUS RTU, mediante RS485 */
void getMPR () {
  digitalWrite(oMPREN, MPRTX);  Serial2.write(trama2, sizeTx); delay(deadtime);
  digitalWrite(oMPREN, MPRRX);  Serial2.readBytes(buffer2, sizeRx2); delay(deadtime);
}

/* Rutinas para conversion de datos HEX to DATA, segun manual de instrucciones de MPR63 */
float getVoltage (uint8_t indice){
  registro16 = buffer2[indice]<<8|buffer2[indice + 1]; 
  return tempMed = registro16 * VT * 0.1;
}
float getCurrent (uint8_t indice){
  registro16 = buffer2[indice]<<8|buffer2[indice + 1]; 
  return tempMed = registro16 * CT * 0.001;
}
float getPower (uint8_t indice){
  if (bitRead(buffer2[indice], 7)) registro16 = ~(buffer2[indice]<<8|buffer2[indice + 1]);
  else                             registro16 = buffer2[indice]<<8|buffer2[indice + 1];
  return tempMed = registro16 * VT * CT;
}
float getPowerS (uint8_t indice){
  registro16 = buffer2[indice]<<8|buffer2[indice + 1]; 
  return tempMed = registro16 * VT * CT;
}
float getFP (uint8_t indice){
  if (bitRead(buffer2[indice], 7)) registro16 = ~(buffer2[indice]<<8|buffer2[indice + 1]);
  else                             registro16 = buffer2[indice]<<8|buffer2[indice + 1];
  return tempMed = registro16 * 0.001;
}
float getFrequency (uint8_t indice){
  registro16 = buffer2[indice]<<8|buffer2[indice + 1]; 
  return tempMed = registro16 * 0.01;   
}
float getTHD (uint8_t indice){
  registro16 = buffer2[indice]<<8|buffer2[indice + 1]; 
  return tempMed = registro16 * 0.1;  
}
