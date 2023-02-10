void OutofBounds2(){
  UpdateTime2();
  if(rightUS.dist() < edge1 && rightUS.dist() < leftUS.dist()){
    if(leftUS.dist() < edge2 && rightUS.dist() < edge2){ //for when the car is too close to wall and does have room to do the turn specified in first if
      Serial.println("You here?"); 
      resetRightEncoderCnt();
      resetLeftEncoderCnt();
      setMotorDirection(BOTH_MOTORS, MOTOR_DIR_BACKWARD);
      hit = 1;
      while(hit == 1){
        RightEncoder = getEncoderRightCnt();
        UpdateTime2();
        Mindflex2();
        if(RightEncoder < backwards && display == 0){
          Straight2();
          DisplayProtection();
        }
        else{
          resetRightEncoderCnt();
          display = 0;
          hit = 2;
        }
      }
      while(hit == 2){ //does the exact same thing as while(boundary == 1)
        RightEncoder = getEncoderRightCnt();
        UpdateTime2();
        Mindflex2();
        if(RightEncoder < randNum){
          setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_FORWARD); //do i need to initialize both forward before doing this line?
          setMotorDirection(LEFT_MOTOR, MOTOR_DIR_BACKWARD);
          setMotorSpeed(BOTH_MOTORS, motorSpeed); 
        }
        else{
          hit = 0;
          resetRightEncoderCnt();
          resetLeftEncoderCnt();
          setMotorDirection(BOTH_MOTORS, MOTOR_DIR_FORWARD);
          bumperFlag = 0;
        }
      }
    }
    else{ //incase first two if statements are both true
      resetRightEncoderCnt();
      boundary = 1;
      while(boundary == 1){ //does the exact same thing as while(hit == 2)
        Serial.println(randNum);
        Serial.println(RightEncoder);
        RightEncoder = getEncoderRightCnt();
        UpdateTime1();
        Mindflex1();
        if(RightEncoder < randNum){
          setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_FORWARD);
          setMotorDirection(LEFT_MOTOR, MOTOR_DIR_BACKWARD);
          setMotorSpeed(BOTH_MOTORS, motorSpeed);
        }
        else{
          boundary = 0;
          resetRightEncoderCnt();
          resetLeftEncoderCnt();
          setMotorDirection(BOTH_MOTORS, MOTOR_DIR_FORWARD);
        }
      }
    }
  }
  else if(leftUS.dist() < edge1 && leftUS.dist() < rightUS.dist()){
    if(leftUS.dist() < edge2 && rightUS.dist() < edge2){
      Serial.println("2You here?"); 
      resetLeftEncoderCnt();
      setMotorDirection(BOTH_MOTORS, MOTOR_DIR_BACKWARD);
      hit = 1;
      while(hit == 1){
        LeftEncoder = getEncoderLeftCnt();
        UpdateTime2();
        Mindflex2();
        if(LeftEncoder < backwards && display == 0){
          setMotorSpeed(BOTH_MOTORS, motorSpeed);
          DisplayProtection();
        }
        else{
          resetLeftEncoderCnt();
          display = 0;
          hit = 2;
        }
      }
      while(hit == 2){
        LeftEncoder = getEncoderLeftCnt();
        UpdateTime2();
        Mindflex2();
        if(LeftEncoder < randNum){
          setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_BACKWARD);
          setMotorDirection(LEFT_MOTOR, MOTOR_DIR_FORWARD);
          setMotorSpeed(BOTH_MOTORS, motorSpeed); 
        }
        else{
          hit = 0;
          resetRightEncoderCnt();
          resetLeftEncoderCnt();
          setMotorDirection(BOTH_MOTORS, MOTOR_DIR_FORWARD);
          bumperFlag = 0;
        }
      }
    }
    else{ //incase first two if statements are both true
      resetLeftEncoderCnt();
      boundary = 1;
      while(boundary == 1){
        LeftEncoder = getEncoderLeftCnt();
        UpdateTime2();
        Mindflex2();
        if(LeftEncoder < randNum){
          setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_BACKWARD);
          setMotorDirection(LEFT_MOTOR, MOTOR_DIR_FORWARD);
          setMotorSpeed(BOTH_MOTORS, motorSpeed); 
        }
        else{
          boundary = 0;
          resetRightEncoderCnt();
          resetLeftEncoderCnt();
          setMotorDirection(BOTH_MOTORS, MOTOR_DIR_FORWARD);
        }
      }
    }
  }
}
        
