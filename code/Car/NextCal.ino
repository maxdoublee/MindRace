void NextCal(){
  myScreen.clear();
  delay(500);
  for(int x = 0; x < 6; x++){
    myScreen.text(0, 1, " Pick up  car when it stops. Lights will      flash");
    delay(500);
    myScreen.text(0, 1, " Pick up  car when it stops. Lights will           ");
    delay(500);
  }
  myScreen.clear();
  delay(1000);
  while(true){
    myScreen.text(0, 0, "CAL");
    myScreen.text(0, 2, "  Press  CAL    to   begin");
    calState = digitalRead(calpushbutton);
    if(calState == 0){
      delay(100);
      Calibration();
    }
  }
}
