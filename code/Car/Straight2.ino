void Straight2() {
  UpdateTime2();
  LeftEncoder = getEncoderLeftCnt();
  RightEncoder = getEncoderRightCnt();
  if (RightEncoder - LeftEncoder < encoderLimit && RightEncoder - LeftEncoder >= encoderMin) { //will this return an error because of the unsigned?
    resumeMotor(BOTH_MOTORS);
    setMotorSpeed(BOTH_MOTORS, motorSpeed);
    Serial.print("Left Encoder: ");
      Serial.println(LeftEncoder);
      Serial.print("Right Encoder: ");
      Serial.println(RightEncoder);
      Serial.print("\n");
  }
  else if (RightEncoder - LeftEncoder >= encoderLimit) {
    pauseMotor(RIGHT_MOTOR);
    resumeMotor(LEFT_MOTOR);
    setMotorSpeed(LEFT_MOTOR, motorSpeed);
    Serial.print("Left Encoder: ");
      Serial.println(LeftEncoder);
      Serial.print("Right Encoder: ");
      Serial.println(RightEncoder);
      Serial.print("\n");
  }
  else if (LeftEncoder - RightEncoder < encoderLimit && LeftEncoder - RightEncoder >= encoderMin) {
    resumeMotor(BOTH_MOTORS);
    setMotorSpeed(BOTH_MOTORS, motorSpeed);
    Serial.print("Left Encoder: ");
      Serial.println(LeftEncoder);
      Serial.print("Right Encoder: ");
      Serial.println(RightEncoder);
      Serial.print("\n");
  }
  else if (LeftEncoder - RightEncoder >= encoderLimit) {
    pauseMotor(LEFT_MOTOR);
    resumeMotor(RIGHT_MOTOR);
    setMotorSpeed(RIGHT_MOTOR, motorSpeed);
    Serial.print("Left Encoder: ");
      Serial.println(LeftEncoder);
      Serial.print("Right Encoder: ");
      Serial.println(RightEncoder);
      Serial.print("\n");
  }
}
