void VictoryLEDs(){
  digitalWrite(RIGHTREDLED, HIGH);
  digitalWrite(LEFTREDLED, HIGH);
  delay(500);
  digitalWrite(RIGHTREDLED, LOW);
  digitalWrite(LEFTREDLED, LOW);
  digitalWrite(RIGHTGREENLED, HIGH);
  digitalWrite(LEFTGREENLED, HIGH);
  delay(500);
  digitalWrite(RIGHTGREENLED, LOW);
  digitalWrite(LEFTGREENLED, LOW);
}
