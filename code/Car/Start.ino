void Start(){
  AllLEDs();
  enableMotor(BOTH_MOTORS);
  setMotorDirection(BOTH_MOTORS, MOTOR_DIR_FORWARD);
  myScreen.clear();
  delay(500);
  myScreen.text(0, 0, "CAL");
  delay(500);
  myScreen.text(10, 0, "NEXT");
  delay(500);
  myScreen.text(0, 5, "NO");
  delay(500);
  myScreen.text(11, 5, "YES");
  delay(500);
  myScreen.text(0, 2, " Four corners  four buttons");
  delay(4000);
  myScreen.clear();
  while(true){
    myScreen.text(11, 5, "YES");
    myScreen.text(0, 5, "NO");
    myScreen.text(0, 0, "CAL");
    myScreen.text(10, 0, "NEXT");
    myScreen.text(0, 2, " Press YES to    continue");
    yesState = digitalRead(yespushbutton);
    noState = digitalRead(nopushbutton);
    if(yesState == 0){
      delay(100);
      PreCalibration();
    }
    else if(noState == 0){
      delay(100);
      Start();
    }
  }
}
