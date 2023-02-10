void realFreeRoam(){
  myScreen.clear();
  delay(500);
  while(true){
    myScreen.text(0, 1, " Press middle   button to     free roam");
    startState = digitalRead(STRTBUTTON);
    if(startState == 0){
      delay(100);
      myScreen.clear();
      delay(750);
      myScreen.text(0 , 2, "  Place  car    on   floor");
      delay(3000);
      myScreen.clear();
      delay(750);
      myScreen.text(2 , 2, "Starts in...");
      delay(1500);
      myScreen.clear();
      myScreen.text(7 , 2, "3");
      delay(1000);
      myScreen.clear();
      myScreen.text(7 , 2, "2");
      delay(1000);
      myScreen.clear();
      myScreen.text(7 , 2, "1");
      delay(1000);
      myScreen.clear();
      prevMillisSec = millis();
      prevMillisMin = millis();
      prevMillisHour = millis();
      actuallyFreeRoam();
    }
  }
}
