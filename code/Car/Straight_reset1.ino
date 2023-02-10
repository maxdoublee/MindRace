void Straight_reset1(){
  UpdateTime1();
  if(straight_reset1_var == 1){
    resetRightEncoderCnt();
    resetLeftEncoderCnt();
  }
  straight_reset1_var = 0;
}
