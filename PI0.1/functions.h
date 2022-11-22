/* Private function prototypes -----------------------------------------------*/
// ✔ Terminada
// • Parcialmente terminada
// ✘ En desarrollo

void Timer1Callback (); // • Parcialmente terminada
void Timer2Callback (); // • Parcialmente terminada

void igniteEngine ();                                   // ✔ Terminada
void stopEngine ();                                     // ✘ En desarrollo
void correctFreq (uint8_t frecuencia, uint8_t control); // ✘ En desarrollo

void buttonOK ();     // ✔ Terminada
void buttonCANCEL (); // ✔ Terminada
void buttonPLUS ();   // ✔ Terminada
void buttonMINUS ();  // ✔ Terminada

void printConfig();   // ✔ Terminada
void printStatus ();  // ✔ Terminada

void getMPR ();                     // ✔ Terminada
float getVoltage (uint8_t indice);  // ✔ Terminada
float getCurrent (uint8_t indice);  // ✔ Terminada
float getPower (uint8_t indice);    // ✔ Terminada
float getPowerS (uint8_t indice);   // ✔ Terminada
float getFP (uint8_t indice);       // ✔ Terminada
float getFrequency (uint8_t indice);// ✔ Terminada
float getTHD (uint8_t indice);      // ✔ Terminada

float getADFrequency ();  // ✘ En desarrollo
float getADBattery ();    // ✘ En desarrollo
float getADTemp ();       // ✘ En desarrollo

String getEngine ();  // ✔ Terminada
String getLoad ();    // ✔ Terminada
String getAlarms ();  // ✔ Terminada
