void Mindflex2(){
  UpdateTime2();
  if(Serial1.available()){
    state = Serial1.read();
  }
  if(state == '0'){
    motorSpeed = 0;
  }
  else if(state == '1'){
    motorSpeed = 15;
  }
  else if(state == '2'){
    motorSpeed = 25;
  }
  else if(state == '3'){
    motorSpeed = 40;
  }
  else if(state == '4'){
    motorSpeed = 50;
  }
  else if(state == '5'){
    motorSpeed = 60;
  }
  else{
    motorSpeed = motorSpeed; //because the bluetooth transmission rate is not as fast as the clock speed, I need to have a statement preserving the last value.
  }
}
