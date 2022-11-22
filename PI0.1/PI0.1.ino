/*
  ******************************************************************************
  * @file           : .ino
  * @brief          : ""
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#include "macros.h"
#include "variables.h"
#include "instances.h"
#include "functions.h"
#include "config.h"
#include "timers.h"

#include "buttons.h"
#include "adc.h"
//#include "step.h"
#include "modbus.h"
//#include "esp01.h"
#include "drive.h"
#include "lcd.h"


/* Private user code ---------------------------------------------------------*/

void setup() {
  configInit();
  printWelcome();
  Timer1Init();
  Timer2Init();
  
}

void loop() {  
}
