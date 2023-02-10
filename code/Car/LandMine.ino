void LandMine(){
  UpdateTime2();
  readLineSensor(sensorVal);
  if(sensorVal[2] > 2000 || sensorVal[3] > 2000 || sensorVal[4] > 2000 || sensorVal[5] > 2000){
    if(turn == 0){
      resetRightEncoderCnt();
      boom = 1;
      while(boom == 1){
        RightEncoder = getEncoderRightCnt();
        UpdateTime2();
        Mindflex2();
        if(RightEncoder < randNum){ //does it know to get the value of randNum?
          setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_FORWARD);
          setMotorDirection(LEFT_MOTOR, MOTOR_DIR_BACKWARD);
          setMotorSpeed(BOTH_MOTORS, motorSpeed);
        }
        else{
          boom = 0;
          push = 1;
          resetRightEncoderCnt();
          setMotorDirection(BOTH_MOTORS, MOTOR_DIR_FORWARD);
        }
      }
      while(push == 1){ //once landmine is hit and direction is changed, give it a nudge to get back to playing 
        RightEncoder = getEncoderRightCnt();
        Mindflex2();
        if(RightEncoder < 200){
          Straight2();
        }
      }
      push = 0;
      turn = 1;
    }
    else{
      resetLeftEncoderCnt();
      boom = 1;
      while(boom == 1){
        LeftEncoder = getEncoderLeftCnt();
        UpdateTime2();
        Mindflex2();
        if(LeftEncoder < randNum){
          setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_BACKWARD);
          setMotorDirection(LEFT_MOTOR, MOTOR_DIR_FORWARD);
          setMotorSpeed(BOTH_MOTORS, motorSpeed);
        }
        else{
          boom = 0;
          push = 1;
          resetLeftEncoderCnt();
          setMotorDirection(BOTH_MOTORS, MOTOR_DIR_FORWARD);
        }
      }
      while(push == 1){
        LeftEncoder = getEncoderLeftCnt();
        Mindflex2();
        if(LeftEncoder < 200){
          Straight2();
        }
      }
      push = 0;
      turn = 0;
    }
    resetLeftEncoderCnt();
    resetRightEncoderCnt();
  }
}
