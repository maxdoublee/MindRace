void PreCalibration(){
  myScreen.clear();
  OffLEDs();
  delay(750);
  myScreen.text(0, 2, "Calibrating...robotic voice");
  delay(3000);
  myScreen.clear();
  nextFlag = 0;
  while(true){
    CalLEDs();
    myScreen.text(10, 0, "NEXT");
    myScreen.text(0, 2, "  Car starts     on floor");
    myScreen.text(1, 5, "(Press NEXT)");
    if(nextFlag == 1){
      nextFlag = 0;
      delay(100);
      NextCal();
    }
  }
}
