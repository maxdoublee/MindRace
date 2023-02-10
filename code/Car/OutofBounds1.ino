void OutofBounds1(){
  UpdateTime1();
  float rightSensor = rightUS.dist();
  float leftSensor = leftUS.dist();
  if(rightSensor < edge1 && rightSensor < leftSensor){
    if(rightSensor < edge2 && leftSensor < edge2){ //for when the car is too close to wall and does not have room to do the turn specified in first if
      straight_reset1_var = 1;
      Straight_reset1(); //resets both encoders, when its just one I use reset[]EncoderCnt()
      setMotorDirection(BOTH_MOTORS, MOTOR_DIR_BACKWARD);
      hit = 1;
      while(hit == 1){
        RightEncoder = getEncoderRightCnt();
        UpdateTime1();
        Mindflex1();
        Off();
        DisplayProtection();
        if(RightEncoder < backwards && display == 0){
          Straight1();
        }
        else{
          resetRightEncoderCnt();
          hit = 2;
        }
      }
      while(hit == 2 && display == 0){ //does the exact same thing as while(boundary == 1)
        RightEncoder = getEncoderRightCnt();
        UpdateTime1();
        Mindflex1();
        Off();
        if(RightEncoder < randNum){ //i think randNum always gets the value because I store it at global meaning at any point in the code it could change. Or its cause I am in the same function looping
          if(motorSpeed == 15){
            resumeMotor(BOTH_MOTORS);
            setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_FORWARD); 
            setMotorDirection(LEFT_MOTOR, MOTOR_DIR_BACKWARD);
            setMotorSpeed(BOTH_MOTORS, motorSpeed); 
          }
          else if(motorSpeed == 25){
            resumeMotor(BOTH_MOTORS);
            setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_FORWARD); 
            setMotorDirection(LEFT_MOTOR, MOTOR_DIR_BACKWARD);
            setMotorSpeed(BOTH_MOTORS, (motorSpeed - 10)); 
          }
          else if(motorSpeed == 40){
            resumeMotor(BOTH_MOTORS);
            setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_FORWARD); 
            setMotorDirection(LEFT_MOTOR, MOTOR_DIR_BACKWARD);
            setMotorSpeed(BOTH_MOTORS, (motorSpeed - 20)); 
          }
          else if(motorSpeed == 50){
            resumeMotor(BOTH_MOTORS);
            setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_FORWARD); 
            setMotorDirection(LEFT_MOTOR, MOTOR_DIR_BACKWARD);
            setMotorSpeed(BOTH_MOTORS, (motorSpeed - 25)); 
          }
          else if(motorSpeed == 60){
            resumeMotor(BOTH_MOTORS);
            setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_FORWARD); 
            setMotorDirection(LEFT_MOTOR, MOTOR_DIR_BACKWARD);
            setMotorSpeed(BOTH_MOTORS, (motorSpeed - 30)); 
          }
        }
        else{
          hit = 0;
        }
      }
      hit = 0;
      bumperFlag = 0;
      straight_reset1_var = 1;
      display = 0;
      setMotorDirection(BOTH_MOTORS, MOTOR_DIR_FORWARD);
    }
    else{ //incase first two if statements are both true, error is happening here, make sure this else only runs if the first if statement is meet but the second isnt 
      resetRightEncoderCnt();
      boundary = 1;
      while(boundary == 1){ //does the exact same thing as while(hit == 2)
        RightEncoder = getEncoderRightCnt();
        UpdateTime1();
        Mindflex1();
        Off();
        if(RightEncoder < randNum){
          if(motorSpeed == 15){
            resumeMotor(BOTH_MOTORS);
            setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_FORWARD); 
            setMotorDirection(LEFT_MOTOR, MOTOR_DIR_BACKWARD);
            setMotorSpeed(BOTH_MOTORS, motorSpeed); 
          }
          else if(motorSpeed == 25){
            resumeMotor(BOTH_MOTORS);
            setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_FORWARD); 
            setMotorDirection(LEFT_MOTOR, MOTOR_DIR_BACKWARD);
            setMotorSpeed(BOTH_MOTORS, (motorSpeed - 10)); 
          }
          else if(motorSpeed == 40){
            resumeMotor(BOTH_MOTORS);
            setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_FORWARD); 
            setMotorDirection(LEFT_MOTOR, MOTOR_DIR_BACKWARD);
            setMotorSpeed(BOTH_MOTORS, (motorSpeed - 20)); 
          }
          else if(motorSpeed == 50){
            resumeMotor(BOTH_MOTORS);
            setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_FORWARD); 
            setMotorDirection(LEFT_MOTOR, MOTOR_DIR_BACKWARD);
            setMotorSpeed(BOTH_MOTORS, (motorSpeed - 25)); 
          }
          else if(motorSpeed == 60){
            resumeMotor(BOTH_MOTORS);
            setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_FORWARD); 
            setMotorDirection(LEFT_MOTOR, MOTOR_DIR_BACKWARD);
            setMotorSpeed(BOTH_MOTORS, (motorSpeed - 30)); 
          }
        }
        else{
          boundary = 0;
          straight_reset1_var = 1;
          setMotorDirection(BOTH_MOTORS, MOTOR_DIR_FORWARD);
        }
      }
    }
  } 
  else if(leftSensor < edge1 && leftSensor < rightSensor){
    if(leftSensor < edge2 && rightSensor < edge2){
      straight_reset1_var = 1;
      Straight_reset1(); //resets both encoders, when its just one I use reset[]EncoderCnt()
      setMotorDirection(BOTH_MOTORS, MOTOR_DIR_BACKWARD);
      hit = 1;
      while(hit == 1){
        LeftEncoder = getEncoderLeftCnt();
        UpdateTime1();
        Mindflex1();
        Off();
        DisplayProtection();
        if(LeftEncoder < backwards && display == 0){
          Straight1();
        }
        else{
          resetLeftEncoderCnt();
          hit = 2;
        }
      }
      while(hit == 2 && display == 0){
        LeftEncoder = getEncoderLeftCnt();
        UpdateTime1();
        Mindflex1();
        Off();
        if(LeftEncoder < randNum){
          if(motorSpeed == 15){
            resumeMotor(BOTH_MOTORS);
            setMotorDirection(LEFT_MOTOR, MOTOR_DIR_FORWARD); 
            setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_BACKWARD);
            setMotorSpeed(BOTH_MOTORS, motorSpeed); 
          }
          else if(motorSpeed == 25){
            resumeMotor(BOTH_MOTORS);
            setMotorDirection(LEFT_MOTOR, MOTOR_DIR_FORWARD); 
            setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_BACKWARD);
            setMotorSpeed(BOTH_MOTORS, (motorSpeed - 10)); 
          }
          else if(motorSpeed == 40){
            resumeMotor(BOTH_MOTORS);
            setMotorDirection(LEFT_MOTOR, MOTOR_DIR_FORWARD); 
            setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_BACKWARD);
            setMotorSpeed(BOTH_MOTORS, (motorSpeed - 20)); 
          }
          else if(motorSpeed == 50){
            resumeMotor(BOTH_MOTORS);
            setMotorDirection(LEFT_MOTOR, MOTOR_DIR_FORWARD); 
            setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_BACKWARD);
            setMotorSpeed(BOTH_MOTORS, (motorSpeed - 25)); 
          }
          else if(motorSpeed == 60){
            resumeMotor(BOTH_MOTORS);
            setMotorDirection(LEFT_MOTOR, MOTOR_DIR_FORWARD); 
            setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_BACKWARD);
            setMotorSpeed(BOTH_MOTORS, (motorSpeed - 30)); 
          }
        }
        else{
          hit = 0;
        }
      }
      hit = 0;
      bumperFlag = 0;
      straight_reset1_var = 1;
      display = 0;
      setMotorDirection(BOTH_MOTORS, MOTOR_DIR_FORWARD);
    }
    else{ //incase first two if statements are both true
      resetLeftEncoderCnt(); //figure out why it doesnt reset right away
      boundary = 1;
      while(boundary == 1){
        LeftEncoder = getEncoderLeftCnt();
        UpdateTime1();
        Mindflex1();
        Off();
        if(LeftEncoder < randNum){
          if(motorSpeed == 15){
            resumeMotor(BOTH_MOTORS);
            setMotorDirection(LEFT_MOTOR, MOTOR_DIR_FORWARD); 
            setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_BACKWARD);
            setMotorSpeed(BOTH_MOTORS, motorSpeed); 
          }
          else if(motorSpeed == 25){
            resumeMotor(BOTH_MOTORS);
            setMotorDirection(LEFT_MOTOR, MOTOR_DIR_FORWARD); 
            setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_BACKWARD);
            setMotorSpeed(BOTH_MOTORS, (motorSpeed - 10)); 
          }
          else if(motorSpeed == 40){
            resumeMotor(BOTH_MOTORS);
            setMotorDirection(LEFT_MOTOR, MOTOR_DIR_FORWARD); 
            setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_BACKWARD);
            setMotorSpeed(BOTH_MOTORS, (motorSpeed - 20)); 
          }
          else if(motorSpeed == 50){
            resumeMotor(BOTH_MOTORS);
            setMotorDirection(LEFT_MOTOR, MOTOR_DIR_FORWARD); 
            setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_BACKWARD);
            setMotorSpeed(BOTH_MOTORS, (motorSpeed - 25)); 
          }
          else if(motorSpeed == 60){
            resumeMotor(BOTH_MOTORS);
            setMotorDirection(LEFT_MOTOR, MOTOR_DIR_FORWARD); 
            setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_BACKWARD);
            setMotorSpeed(BOTH_MOTORS, (motorSpeed - 30)); 
          }
        }
        else{
          boundary = 0;
          straight_reset1_var = 1;
          setMotorDirection(BOTH_MOTORS, MOTOR_DIR_FORWARD);
        }
      }
    }
  }
}   
