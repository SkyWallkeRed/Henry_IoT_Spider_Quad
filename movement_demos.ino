
void headDemo()
{
  printToOled("head demo");
  grabHorizontalFront();
  delay(700);
  releaseHorizontalBack();
  delay(700);
  grabVerticalFront();
  delay(700);
  releaseVerticalBack();
  delay(700);
}

void leanDemo()
{
  printToOled("lean demo");
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