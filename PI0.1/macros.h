/* Private macro -------------------------------------------------------------*/

/* PINES LIBRES
 * PC14 
 * PC15
 */

/* Declaracion de sinonimos de salida */
#define oLED      PC13
#define oSTEP1    PB12
#define oSTEP2    PB13
#define oSTEP3    PB14
#define oSTEP4    PB15
#define oCONTACTO PB3
#define oARRANQUE PB4
#define oPARADA   PB5
#define oMPREN    PA1
#define oCARGA1   PB8
#define oCARGA2   PB9

/* Declaracion de sinonimos de entrada */
#define iPRES   PA11
#define iTEMP   PA2
#define iEV     PA15
#define iBAT    PA8
#define iFDC    PB10
#define iBOTON1 PA7
#define iBOTON2 PB11
#define iBOTON3 PB1
#define iBOTON4 PA0

/* Declaracion de sinonimos de entradas ADC */
#define adBAT   PA6
#define adFREC  PA5
#define adTEMP  PA4

/* Declaracion de sinonimos de puertos de comunicacion */ 
#define MODBUSTX  PA2
#define MODBUSRX  PA3
#define ESP01TX   PA9
#define ESP01RX   PA10
#define ONEWIRE   PB11

/* Declaracion de sinonimos de banderas y constantes de uso */
#define MPRTX 1
#define MPRRX 0

#define VT 1
#define CT 50

#define RLON  0
#define RLOFF 1

#define CARGAOFF 0
#define CARGAON 1
