void UpdateTime2(){
  if (currentMillisSec < 60) {
    currentMillisSec = ((millis() - prevMillisSec) / 1000);
  }
  else if (currentMillisSec == 60) {
    prevMillisSec = millis();
    currentMillisSec = (millis() - prevMillisSec);
  }

  if (currentMillisMin < 60) {
    currentMillisMin = (((millis() - prevMillisMin) / 1000) / 60);
  }
  else if (currentMillisMin == 60) {
    prevMillisMin = millis();
    currentMillisMin = (millis() - prevMillisMin);
  }

  if (currentMillisHour < 24) {
    currentMillisHour = ((((millis() - prevMillisHour) / 1000) / 60) / 60);
  }
  else if (currentMillisHour == 24) {
    prevMillisHour = millis();
    currentMillisHour = (millis() - prevMillisHour);
  }

  convert1 = String(currentMillisSec);
  convert2 = String(currentMillisMin);
  convert3 = String(currentMillisHour);

  myScreen.setFont(0);
  myScreen.text(0, 1, " Time to reach    target:");
  myScreen.text(8, 4, ":");
  myScreen.text(5, 4, ":");

  if (currentMillisSec <= 9) {
    myScreen.text(9, 4, "0");
    myScreen.text(10, 4, convert1);
  }
  else if (currentMillisSec > 9) {
    myScreen.text(10, 4, "");
    myScreen.text(9, 4, convert1);
  }

  if (currentMillisMin <= 9) {
    myScreen.text(6, 4, "0");
    myScreen.text(7, 4, convert2);
  }
  else if (currentMillisMin > 9) {
    myScreen.text(7, 4, "");
    myScreen.text(6, 4, convert2);
  }

  if (currentMillisHour <= 9) {
    myScreen.text(3, 4, "0");
    myScreen.text(4, 4, convert3);
  }
  else if (currentMillisHour > 9) {
    myScreen.text(4, 4, "");
    myScreen.text(3, 4, convert3);
  }
} 
