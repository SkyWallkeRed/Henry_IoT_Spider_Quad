



void turnLeft()
{
  printToOled("turn left");
  lookLeft();
  // Front left and back right leg
  // raises the foot in air
  FL_FOOT.write(140);
  BR_FOOT.write(140);

  delay(200);

  // turns the hip around
  FL_HIP.write(0);
  BR_HIP.write(0);

  delay(200);

  // puts the foot down again
  FL_FOOT.write(110);
  BR_FOOT.write(110);

  delay(200);
  //
  //  // puts the hip back in original place
  FL_HIP.write(40);
  BR_HIP.write(40);

  delay(200);
  //
  // Front Right and Back Left Leg
  // raises the foot in air
  FR_FOOT.write(50);
  BL_FOOT.write(50);

  delay(200);

  // turns the hip around
  FR_HIP.write(180);
  BL_HIP.write(180);

  delay(200);

  // puts the foot down again
  FR_FOOT.write(70);
  BL_FOOT.write(70);

  delay(200);

  //  // puts the hip back in original place
  //  FR_HIP.write(130);
  //  BL_HIP.write(130);
}

void turnRight()
{
  printToOled("turn right");
  // Front left and back right leg
  //raises the foot in air
  lookRight();
  FL_FOOT.write(130);
  BR_FOOT.write(130);

  delay(200);

  // turns the hip around
  FL_HIP.write(10);
  BR_HIP.write(10);

  delay(200);

  // puts the foot down again
  FL_FOOT.write(110);
  BR_FOOT.write(110);

  delay(200);

  // puts the hip back in original place
  FL_HIP.write(40);
  BR_HIP.write(40);

  delay(200);

  // Front Right and Back Left Leg
  // raises the foot in air
  FR_FOOT.write(50);
  BL_FOOT.write(50);

  delay(200);

  // turns the hip around
  FR_HIP.write(80);
  BL_HIP.write(80);

  delay(200);

  // puts the foot down again
  FR_FOOT.write(70);
  BL_FOOT.write(70);

  delay(200);

  // puts the hip back in original place
  FR_HIP.write(130);
  BL_HIP.write(130);
}

void walkForward()
{
  printToOled("backwards");
  FR_FOOT.write(50);
  BL_FOOT.write(50);

  delay(100);
  //
  FR_HIP.write(160);
  BL_HIP.write(120);
  FL_HIP.write(60);
  BR_HIP.write(20);

  delay(100);

  FR_FOOT.write(90);
  BL_FOOT.write(90);
  //
  delay(100);
  //
  FL_FOOT.write(110);
  BR_FOOT.write(130);
  //
  delay(100);
  //
  FL_HIP.write(20);
  BR_HIP.write(60);
  FR_HIP.write(110);
  BL_HIP.write(150);
  //
  delay(100);
  //
  FL_FOOT.write(110);
  BR_FOOT.write(110);
  //
  delay(100);

}
