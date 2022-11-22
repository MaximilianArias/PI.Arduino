/* Timer functions ---------------------------------------------------------*/
void Timer1Callback () {
  if (!setupOK) printConfig();
  if (setupOK) {
    //getMPR();
    printStatus();
  }
}

void Timer2Callback () {
  digitalWrite(oLED, !(digitalRead(oLED)));
  igniteEngine();
}
