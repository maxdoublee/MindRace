void InitSpin(){
  prevMillisSec = millis();
  prevMillisMin = millis();
  prevMillisHour = millis();
  resetLeftEncoderCnt();
  resetRightEncoderCnt();
  LeftEncoder = getEncoderLeftCnt();
  RightEncoder = getEncoderRightCnt();
  enableMotor(BOTH_MOTORS);
  setMotorDirection(BOTH_MOTORS, MOTOR_DIR_FORWARD);
  spin = 1;
  while(spin == 1){
    RightEncoder = getEncoderRightCnt();
    Mindflex2();
    if(RightEncoder < 400){
      Straight2();
    }
    else{
      spin = 2;
    }
  }
  resetRightEncoderCnt();
  while(spin == 2){
    RightEncoder = getEncoderRightCnt();
    Mindflex2();
    if(RightEncoder < 600){ // < # + randStart
      setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_FORWARD);
      setMotorDirection(LEFT_MOTOR, MOTOR_DIR_BACKWARD);
      setMotorSpeed(BOTH_MOTORS, motorSpeed); 
    }
    else{
      spin = 0;
      setMotorDirection(BOTH_MOTORS, MOTOR_DIR_FORWARD);
    }
  }
  resetLeftEncoderCnt();
  resetRightEncoderCnt();
  disableMotor(BOTH_MOTORS);
  ObstacleCourse();
}
