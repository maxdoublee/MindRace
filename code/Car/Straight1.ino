void Straight1() {
  UpdateTime1();
  LeftEncoder = getEncoderLeftCnt();
  RightEncoder = getEncoderRightCnt();
  /*Serial.print("Right Encoder: ");
  Serial.print(RightEncoder);
  Serial.print("\n");
  Serial.print("Left Encoder: ");
  Serial.print(LeftEncoder);
  Serial.print("\n");*/
  if(RightEncoder - LeftEncoder < encoderLimit && RightEncoder - LeftEncoder >= encoderMin){ 
    resumeMotor(BOTH_MOTORS);
    setMotorSpeed(BOTH_MOTORS, motorSpeed);
  }
  else if(RightEncoder - LeftEncoder >= encoderLimit){
    pauseMotor(RIGHT_MOTOR);
    resumeMotor(LEFT_MOTOR);
    setMotorSpeed(LEFT_MOTOR, motorSpeed);
  }
  else if(LeftEncoder - RightEncoder < encoderLimit && LeftEncoder - RightEncoder >= encoderMin){
    resumeMotor(BOTH_MOTORS);
    setMotorSpeed(BOTH_MOTORS, motorSpeed);
  }
  else if(LeftEncoder - RightEncoder >= encoderLimit){
    pauseMotor(LEFT_MOTOR);
    resumeMotor(RIGHT_MOTOR);
    setMotorSpeed(RIGHT_MOTOR, motorSpeed);
  }
}
