
void aggression()
{
  printToOled("aggression");
  scan();
  neckLR.write(180);
  neckUD.write(90);
  givRight();
  delay(50);
  //  bendBack();
  homePos();
  scerdFront = 0;
}

void scared()
{
  draw_warn();
  //FR_HIP.write(10);
  //delay(1000);
  //FR_HIP.write(180);
  //delay(1000);
  //FR_HIP.write(10);
  //delay(1000);
  //FR_HIP.write(180);
  neckLR.write(120);
  FR_FOOT.write(130);
  FL_FOOT.write(130);
  neckUD.write(80);
  delay(100);
  neckUD.write(130);
  delay(100);
  neckUD.write(80);
  homePos();
}


void lookRight()
{
  printToOled("look right");
  neckLR.write(140);
  delay(200);
  neckUD.write(30);
}

void lookLeft()
{
  printToOled("look left");
  neckUD.write(30);
  delay(500);
  neckUD.write(150);
  delay(300);
}

void scan()
{
  printToOled("scan");
  neckLR.write(140);
  delay(150);
  neckUD.write(30);
  delay(150);
  neckUD.write(150);
  delay(150);
  //  neckLR.write(160);
}

void wave()
{
  printToOled("wave");
  FR_FOOT.write(130);
  FL_FOOT.write(130);
  BR_FOOT.write(150);
  BL_FOOT.write(130);
  delay(300);
  FR_FOOT.write(50);
  FL_FOOT.write(50);
  BR_FOOT.write(70);
  BL_FOOT.write(50);

}


void sleep()
{
  draw_sleep();
  FR_FOOT.write(150);
  FL_FOOT.write(150);
  BR_FOOT.write(170);
  BL_FOOT.write(150);
  BL_HIP.write(130);
  neckLR.write(120);
  delay(100);
}

void givRight()
{
  draw_fist();
  FL_HIP.write(90);
  BR_HIP.write(10);
  FR_FOOT.write(170);
  FR_HIP.write(40);

}


void sayHelloR()
{
  printToOled("say hello");
  homePos();
  FL_HIP.write(90);
  BR_HIP.write(10);
  FR_FOOT.write(170);
  FR_HIP.write(10);
  delay(200);
  FR_HIP.write(50);
  delay(200);
  FR_HIP.write(10);

  //  FR_HIP.write(40);
}
void sayHelloL()
{
  homePos();

  FL_HIP.write(110);
  FR_HIP.write(110);
  FL_FOOT.write(170);
  BL_HIP.write(140);
  delay(200);
  FL_FOOT.write(40);
  delay(200);
  FL_FOOT.write(170);

}
void sit()
{
  draw_sit();
  FR_HIP.write(40);
  BR_HIP.write(80);
  FL_HIP.write(130);
  BL_HIP.write(80);

  FR_FOOT.write(20);
  FL_FOOT.write(40);

  BR_HIP.write(10);
  BL_HIP.write(150);

  BR_FOOT.write(140);
  BL_FOOT.write(100);
  delay(300);

}

void leanRight()
{
  printToOled("lean right");
  FL_FOOT.write(15);
  FR_FOOT.write(15);
  BL_FOOT.write(140);
  BR_FOOT.write(140);
}

void leanLeft()
{
  printToOled("lean left");
  FL_FOOT.write(140);
  FR_FOOT.write(140);
  BL_FOOT.write(15);
  BR_FOOT.write(15);
}

void bow()
{
  FL_FOOT.write(140);
  FR_FOOT.write(15);
  BL_FOOT.write(130);
  BR_FOOT.write(30);
}

void bendBack()
{
  FL_FOOT.write(30);
  FR_FOOT.write(130);
  BL_FOOT.write(15);
  BR_FOOT.write(140);
}


long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

void grabHorizontalFront()
{
  bow();
  neckLR.write(170);
  neckUD.write(130);
  delay(700);
  homePosHead();
}

void grabVerticalFront()
{
  bow();
  neckLR.write(170);
  neckUD.write(130);
  delay(700);
  homePosHead();
}

void grabHorizontalBack()
{
  bendBack();

  neckLR.write(40);
  neckUD.write(0);
  delay(700);
  homePosHead();
}

void grabVerticalBack()
{
  bendBack();
  neckLR.write(40);
  neckUD.write(0);
  delay(700);
  homePosHead();
}

void releaseHorizontalFront()
{
  bow();
  neckLR.write(170);
  neckUD.write(130);
  delay(700);
  homePosHead();
}

void releaseVerticalFront()
{
  bow();
  neckLR.write(170);
  neckUD.write(130);
  delay(700);
  homePosHead();
}

void releaseHorizontalBack()
{
  bendBack();
  neckLR.write(40);
  neckUD.write(0);
  delay(700);
  homePosHead();
}

void releaseVerticalBack()
{
  bendBack();
  neckLR.write(40);
  neckUD.write(0);
  delay(1000);
  homePosHead();
}

void homePosGrabBall()
{
  homePos();
  homePosHead();
  delay(1000);

}

void homePosGrabHatch()
{
  homePos();
  homePosHead();
  delay(1000);
}
