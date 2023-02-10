void Pre_Game(){
  AllLEDs();
  myScreen.clear();
  delay(1000);
  while(true){
    myScreen.text(11, 5, "YES");
    myScreen.text(0, 5, "NO");
    myScreen.text(0, 2, "Ready to play?");
    yesState = digitalRead(yespushbutton);
    noState = digitalRead(nopushbutton);
    if(yesState == 0){
      delay(100);
      Start_Game();
    }
    else if(noState == 0){
      delay(100);
      Start();
    }
  }
}
