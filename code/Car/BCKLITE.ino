void BCKLITE(){
  backlight = (backlight == 0);
  myScreen.setBacklight(backlight);
}
