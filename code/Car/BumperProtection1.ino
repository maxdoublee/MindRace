void BumperProtection1(){
  UpdateTime1();
  if(bumperFlag == 1){
    straight_reset1_var = 1;
    Straight_reset1(); //resets both encoders, when its just one I use reset[]EncoderCnt()
    setMotorDirection(BOTH_MOTORS, MOTOR_DIR_BACKWARD);
    Mindflex1();
    Off();
    hit = 1;
    while(hit == 1){
      RightEncoder = getEncoderRightCnt();
      UpdateTime1();
      DisplayProtection();
      if(RightEncoder < backwards2 && display == 0){
        Serial.println("here");
        if(wham == 0){ //similar effect when you are in bumper car and when you hit a wall and rock left and right backwards until you're ready to drive again 
          if(motorSpeed == 15){
            pauseMotor(LEFT_MOTOR);
            resumeMotor(RIGHT_MOTOR);
            setMotorSpeed(RIGHT_MOTOR, motorSpeed);
            delay(250);
            wham = 1;
          }
          else if(motorSpeed == 25){
            pauseMotor(LEFT_MOTOR);
            resumeMotor(RIGHT_MOTOR);
            setMotorSpeed(RIGHT_MOTOR, (motorSpeed - 10));
            delay(250);
            wham = 1;
          }
          else if(motorSpeed == 40){
            pauseMotor(LEFT_MOTOR);
            resumeMotor(RIGHT_MOTOR);
            setMotorSpeed(RIGHT_MOTOR, (motorSpeed - 20));
            delay(250);
            wham = 1;
          }
          else if(motorSpeed == 50){
            pauseMotor(LEFT_MOTOR);
            resumeMotor(RIGHT_MOTOR);
            setMotorSpeed(RIGHT_MOTOR, (motorSpeed - 25));
            delay(250);
            wham = 1;
          }
          else if(motorSpeed == 60){
            pauseMotor(LEFT_MOTOR);
            resumeMotor(RIGHT_MOTOR);
            setMotorSpeed(RIGHT_MOTOR, (motorSpeed - 30));
            delay(250);
            wham = 1;
          }
        }
        else{
          if(motorSpeed == 15){
            pauseMotor(RIGHT_MOTOR);
            resumeMotor(LEFT_MOTOR);
            setMotorSpeed(LEFT_MOTOR, motorSpeed);
            delay(250);
            wham = 0;
          }
          else if(motorSpeed == 25){
            pauseMotor(RIGHT_MOTOR);
            resumeMotor(LEFT_MOTOR);
            setMotorSpeed(LEFT_MOTOR, (motorSpeed - 10));
            delay(250);
            wham = 0;
          }
          else if(motorSpeed == 40){
            pauseMotor(RIGHT_MOTOR);
            resumeMotor(LEFT_MOTOR);
            setMotorSpeed(LEFT_MOTOR, (motorSpeed - 15));
            delay(250);
            wham = 0;
          }
          else if(motorSpeed == 50){
            pauseMotor(RIGHT_MOTOR);
            resumeMotor(LEFT_MOTOR);
            setMotorSpeed(LEFT_MOTOR, (motorSpeed - 20));
            delay(250);
            wham = 0;
          }
          else if(motorSpeed == 60){
            pauseMotor(RIGHT_MOTOR);
            resumeMotor(LEFT_MOTOR);
            setMotorSpeed(LEFT_MOTOR, (motorSpeed - 25));
            delay(250);
            wham = 0;
          }
        }
      }
      else{
        resetRightEncoderCnt();
        hit = 2;
        wham = 0;
      }
    }
    while(hit == 2 && display == 0){
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
        hit = 0;
      }
    }
    hit = 0;
    bumperFlag = 0; 
    straight_reset1_var = 1;
    setMotorDirection(BOTH_MOTORS, MOTOR_DIR_FORWARD);
  }
  else if(bumperFlag == 2){
    straight_reset1_var = 1;
    Straight_reset1(); //resets both encoders, when its just one I use reset[]EncoderCnt()
    setMotorDirection(BOTH_MOTORS, MOTOR_DIR_BACKWARD);
    hit = 1;
    Mindflex1();
    Off();
    while(hit == 1){
      LeftEncoder = getEncoderLeftCnt();
      UpdateTime1();
      DisplayProtection();
      if(LeftEncoder < backwards2 && display == 0){
        if(wham == 0){
          if(motorSpeed == 15){
            pauseMotor(RIGHT_MOTOR);
            resumeMotor(LEFT_MOTOR);
            setMotorSpeed(LEFT_MOTOR, motorSpeed);
            delay(250);
            wham = 1;
          }
          else if(motorSpeed == 25){
            pauseMotor(RIGHT_MOTOR);
            resumeMotor(LEFT_MOTOR);
            setMotorSpeed(LEFT_MOTOR, (motorSpeed - 10));
            delay(250);
            wham = 1;
          }
          else if(motorSpeed == 40){
            pauseMotor(RIGHT_MOTOR);
            resumeMotor(LEFT_MOTOR);
            setMotorSpeed(LEFT_MOTOR, (motorSpeed - 20));
            delay(250);
            wham = 1;
          }
          else if(motorSpeed == 50){
            pauseMotor(RIGHT_MOTOR);
            resumeMotor(LEFT_MOTOR);
            setMotorSpeed(LEFT_MOTOR, (motorSpeed - 20));
            delay(250);
            wham = 1;
          }
          else if(motorSpeed == 60){
            pauseMotor(RIGHT_MOTOR);
            resumeMotor(LEFT_MOTOR);
            setMotorSpeed(LEFT_MOTOR, (motorSpeed - 30));
            delay(250);
            wham = 1;
          }
        }
        else{
          if(motorSpeed == 15){
            pauseMotor(LEFT_MOTOR);
            resumeMotor(RIGHT_MOTOR);
            setMotorSpeed(RIGHT_MOTOR, motorSpeed);
            delay(250);
            wham = 0;
          }
          else if(motorSpeed == 25){
            pauseMotor(LEFT_MOTOR);
            resumeMotor(RIGHT_MOTOR);
            setMotorSpeed(RIGHT_MOTOR, (motorSpeed - 10));
            delay(250);
            wham = 0;
          }
          else if(motorSpeed == 40){
            pauseMotor(LEFT_MOTOR);
            resumeMotor(RIGHT_MOTOR);
            setMotorSpeed(RIGHT_MOTOR, (motorSpeed - 20));
            delay(250);
            wham = 0;
          }
          else if(motorSpeed == 50){
            pauseMotor(LEFT_MOTOR);
            resumeMotor(RIGHT_MOTOR);
            setMotorSpeed(RIGHT_MOTOR, (motorSpeed - 25));
            delay(250);
            wham = 0;
          }
          else if(motorSpeed == 60){
            pauseMotor(LEFT_MOTOR);
            resumeMotor(RIGHT_MOTOR);
            setMotorSpeed(RIGHT_MOTOR, (motorSpeed - 30));
            delay(250);
            wham = 0;
          }
        }
      }
      else{
        resetLeftEncoderCnt();
        hit = 2;
        wham = 0;
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
    setMotorDirection(BOTH_MOTORS, MOTOR_DIR_FORWARD);
  }
}
