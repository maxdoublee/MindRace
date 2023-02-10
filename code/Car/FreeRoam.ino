void freeRoam(){
  AllLEDs();
  enableMotor(BOTH_MOTORS);
  setMotorDirection(BOTH_MOTORS, MOTOR_DIR_FORWARD);
  myScreen.clear();
  resetRightEncoderCnt();
  resetLeftEncoderCnt();
  delay(500);
  myScreen.text(0, 2, "Ready to Roam?");
  myScreen.text(11, 5, "YES");
  myScreen.text(0, 5, "NO");
  while(true){
    yesState = digitalRead(yespushbutton);
    noState = digitalRead(nopushbutton);
    if(yesState == 0){
      delay(100);
      realFreeRoam();
    }
    else if(noState == 0){
      delay(100);
      Start();
    }
  }
}
