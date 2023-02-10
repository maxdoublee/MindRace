void Mindflex1(){
  UpdateTime1();
  if(Serial1.available()){
    state = Serial1.read();
  }
  if(state == '0'){
    motorSpeed = 0;
  }
  else if(state == '1'){
    motorSpeed = 15;
    done++;
  }
  else if(state == '2'){
    motorSpeed = 25;
    done++;
  }
  else if(state == '3'){
    motorSpeed = 40;
    done++;
  }
  else if(state == '4'){
    motorSpeed = 50;
    done++;
  }
  else if(state == '5'){
    motorSpeed = 60;
    done++;
  }
  else{
    motorSpeed = motorSpeed;
    done++;
  }
}
