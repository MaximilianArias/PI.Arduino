/* Private instances ---------------------------------------------------------*/
LiquidCrystal_I2C lcd(0x27,20,4); //Direccion 0x27, 20 columnas, 4 filas, SDA = PB7 / SCL = PB6

HardwareSerial Serial2(PA3 , PA2);      // RX2 = PA3  / TX2 = PA2 
//HardwareSerial Serial3(PB11, PB10);     // RX3 = PB11 / TX3 = PB10 *Configurarlo como 1WIRE
