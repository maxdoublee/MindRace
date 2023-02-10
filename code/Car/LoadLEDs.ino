void LoadLEDs(){
  currentMillis = millis();
  digitalWrite(RIGHTREDLED, HIGH);
  if(currentMillis - previousMillis >= interval){
    digitalWrite(RIGHTREDLED, LOW);
    digitalWrite(LEFTGREENLED, HIGH);
  }
  if(currentMillis - previousMillis >= interval + 500){
    digitalWrite(LEFTGREENLED, LOW);
    digitalWrite(LEFTREDLED, HIGH);
  }
  if(currentMillis - previousMillis >= interval + 1000){
    digitalWrite(LEFTREDLED, LOW);
    digitalWrite(RIGHTGREENLED, HIGH);
  }
  if(currentMillis - previousMillis >= interval + 1500){
    digitalWrite(RIGHTGREENLED, LOW);
    previousMillis = currentMillis;
  }
}
