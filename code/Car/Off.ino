void Off(){
  UpdateTime1();
  check++;
  if(check - done > 1){ 
    disableMotor(BOTH_MOTORS);
    OffLEDs();
    while(true){
      myScreen.text(10, 0, "NEXT");
      myScreen.text(1,5, "(Press Next)");
      nextState = digitalRead(nextpushbutton);
      if(nextState == 0){
        delay(100);
        check = 0;
        done = 0;
        freeRoam();
      }
    } 
  }
}
