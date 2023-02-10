void Victory(){
  UpdateTime2();
  readLineSensor(sensorVal);
  if(sensorVal[0] < 500 && sensorVal[7] < 500){
    myScreen.text(10, 0, "NEXT");
    CalStraight();
    delay(1000);
    setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_FORWARD);
    setMotorDirection(LEFT_MOTOR, MOTOR_DIR_BACKWARD);
    setMotorSpeed(BOTH_MOTORS, calSpeed); 
    delay(5000); 
    disableMotor(BOTH_MOTORS);
    nextFlag = 0;
    while(true){
      VictoryLEDs();
      if(nextFlag == 1){
        nextFlag = 0;
        delay(100);
        PlayAgain();
      }
    }
  }
}
