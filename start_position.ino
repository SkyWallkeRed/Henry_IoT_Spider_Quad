


void homePosHead()
{
  neckLR.write(160);
  neckUD.write(90);
}

void homePos()
{
  printToOled("home pos");
  delay(100);
  homePosHead();
  FL_HIP.write(80);
  FL_FOOT.write(110);
  FR_HIP.write(100);
  FR_FOOT.write(70);
  BL_HIP.write(110);
  BL_FOOT.write(70);
  BR_HIP.write(50);
  BR_FOOT.write(110);
}
