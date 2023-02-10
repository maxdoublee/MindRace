void PlayAgain(){
  OffLEDs();
  myScreen.clear();
  enableMotor(BOTH_MOTORS);
  delay(750);
  while(true){
    myScreen.text(11, 5, "YES");
    myScreen.text(0, 5, "NO");
    myScreen.text(0, 2, "Would you like to try again?");
    yesState = digitalRead(yespushbutton);
    noState = digitalRead(nopushbutton);
    if(yesState == 0){
      delay(100);
      Start_Game();
    }
    else if(noState == 0){
      delay(100);
      Farewell();
    }
  }
}
