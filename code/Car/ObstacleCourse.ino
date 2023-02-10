void ObstacleCourse(){
  while(true){ // turn off us sensors until cars meet 
    randNum = random(500); //make sure this number is being reached in the functions below | I think it is based on my print statements
    UpdateTime2();
    Mindflex2();
    Straight2();
//    LandMine();
    OutofBounds2();
    BumperProtection2();
//    Victory();
  }
}
