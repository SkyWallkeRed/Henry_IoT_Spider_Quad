
void headDemo()
{
  draw_dance();
  grabHorizontalFront();
//  delay(150);
  releaseHorizontalBack();
//  delay(150);
  grabVerticalFront();
//  delay(150);
  releaseVerticalBack();
//  delay(150);
}

void leanDemo()
{
  leanLeft();
  delay(1000);
  homePos();
  delay(1000);
  leanRight();
  delay(1000);
  homePos();
  delay(1000);
}


void dancePUP()
{
  printToOled("dance pupp");
  // combo cool
  homePos();
  delay(100);
  sayHelloR();
  delay(400);
  sayHelloL();
  delay(300);
  wave();
  delay(400);
  sit();
  delay(500);
  sitJump();
  sitJump();
  sitJump();
  sitJump();
  givRight();

}

void sitJump()
{
  printToOled("sit jump");
  homePos();
  delay(100);
  sit();
  delay(150);
}
