  void Calibration(){
  OffLEDs();
  myScreen.clear();
  delay(500);
  myScreen.text(2 , 2, "Starts in...");
  delay(1500);
  myScreen.clear();
  myScreen.text(7 , 2, "3");
  delay(1000);
  myScreen.clear();
  myScreen.text(7 , 2, "2");
  delay(1000);
  myScreen.clear();
  myScreen.text(7 , 2, "1");
  delay(1000);
  myScreen.clear();
  myScreen.text(1 , 2, "Calibrating");
  enableMotor(BOTH_MOTORS);
  setMotorDirection(BOTH_MOTORS, MOTOR_DIR_FORWARD);
  resetLeftEncoderCnt();
  resetRightEncoderCnt();
  for(int i = 0; i < 200; i++){
    CalStraight(); 
    readLineSensor(sensorVal);
    setSensorMinMax(sensorVal, sensorMinVal, sensorMaxVal);
    if(LeftEncoder >= 185){
      break;
    }
  }
  pauseMotor(BOTH_MOTORS);
  delay(250);
  setMotorDirection(BOTH_MOTORS, MOTOR_DIR_BACKWARD);
  resetLeftEncoderCnt();
  resetRightEncoderCnt();
  resumeMotor(BOTH_MOTORS);
  for(int j = 0; j < 200; j++){
    CalStraight();
    readLineSensor(sensorVal);
    setSensorMinMax(sensorVal, sensorMinVal, sensorMaxVal);
    if(LeftEncoder >= 185){
      break;
    }
  }
  disableMotor(BOTH_MOTORS);
  myScreen.clear();
  delay(750);
  nextFlag = 0;
  calFlag = 0;
  while(true){
    CalLEDs();
    myScreen.text(0, 0, "CAL");
    myScreen.text(10, 0, "NEXT");
    myScreen.text(0, 2, "Press NEXT to    confirm");
    myScreen.text(0, 4, "Press CAL  to  recalibrate");
    if(nextFlag == 1){
      nextFlag = 0;
      delay(100);
      Pre_Game();
    }
    else if(calFlag == 1){
      calFlag = 0;
      delay(100);
      Calibration();
    }
  }
}
