/* Private variables ---------------------------------------------------------*/

/* Constantes de uso multiple */
const int debounceTime = 200, //tiempo antirebote para los botones
          loadToggle = 100,
          timer1OF = 500000,  //tiempo de desborde del timer1
          timer2OF = 1000000, //tiempo de desborde del timer2
          deadtime = 10,      //tiempo de silencio para comunicacion MODBUS
          sizeTx = 8, sizeRx1 = 7, sizeRx2 = 83,  //tamaños de los buffers usados para comunicacion MODBUS
          tMaxArranque = 30;

/* Variables para comunicacion MODBUS */
char trama1[sizeTx]= {0x01, 0x03, 0x00, 0x1B, 0x00, 0x01, 0xF4, 0x0D}; //trama MODBUS para consultar la frecuencia
char trama2[sizeTx]= {0x01, 0x03, 0x00, 0x00, 0x00, 0x27, 0x05, 0xD0}; //trama MODBUS para consultar la los registros 0 a 38
char buffer1[sizeRx1], buffer2[sizeRx2];  //buffers de recepcion de las tramas MODBUS solicitadas

/* Variables para conversiones HEX to DATA de MODBUS */
uint8_t mediciones [39]= {3,5,7,          //Tensiones de fase y neutro  (3)
                          9,11,13,15,     //Corrientes de fase y total  (4)
                          17,19,21,       //Potencias activas de fase   (3)
                          23,25,27,       //Potencias reactivas de fase (3)
                          29,31,33,       //Potencias aparentes de fase (3)
                          35,37,39,       //Factores de potencia        (3)
                          41,43,45,       //Cos Fi de fase              (3)
                          47,49,51,53,55, //Tensiones de linea          (5)
                          57,             //Frecuencia                  (1)
                          59,61,63,       //Potencias totales           (3)
                          65,67,69,71,    //THD de tensiones            (4)
                          73,75,77,79};   //THD de corrientes           (4)
uint16_t registro16;  //registro auxiliar para unir los bytes MSB y LSB de cada medicion
float tempMed = 0, adFrec = 0, adBat = 0, adTemp = 0;  //medicion resultante, en coma flotante

/* Variables banderas de multiples rutinas */
uint8_t lastScreen = 0, //auxiliar para cambio de pantalla
        frecSet = 50,   //frecuencia seteada en modo manual (46hz a 60hz)
        ctrlSet = 1,    //tipo de control seteado en modo manual (0 = Lento, 1 = Normal, 2 = Rapido)
        remoteSet = 1,  //bandera de recepcion de mensajes remotos
        setupOK = 0,    //bandera para indicar que la configuracion se encuentra lista
        //Banderas de control del arranque: Inicio, etapa, tiempo de accion y finalizado
        doArranque = 0, stepArranque = 0, tArranque = 0, arrancado = 0, 
        doParada = 0, stepParada = 0, parada = 0,
        load = 0,
        fallaArranque = 0, fallaTemp = 0, fallaPres = 0, fallaWiFi = 0, fallaFrec = 0;

String ctrlStr = "Normal", remoteStr = "ON";  //mensajes complementarios para cada bandera
float minFrecArranque = 30.0;

/* Estructura para menu de configuraciones */
struct Menu {
  uint8_t type = 0;
  uint8_t line = 0; 
//  uint8_t row = 0;
//  uint8_t col = 0;
}; Menu lcd1; //inicializacion de instancia para lcd
