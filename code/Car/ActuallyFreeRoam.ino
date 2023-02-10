void actuallyFreeRoam(){
  while(true){
    randNum = random(250); //edit random value so that I can get a min turn I like and the max being a full revolution on highest setting 
    UpdateTime1(); 
    Mindflex1();
    Straight_reset1();
    Straight1();
    OutofBounds1();
    BumperProtection1();
    Off();
  }
}
