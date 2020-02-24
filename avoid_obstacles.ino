



void avoidObstacles()
{
  printToOled("avoid obls..");
  int distance = getDistance();
  homePosHead();
  if (distance < 6)
  {
    turnLeft();
    int leftDistance = getDistance();
    delay(500);
    for (int i = 0; i <= 1; i++) {
      turnRight();
    }
    int rightDistance = getDistance();
    if (leftDistance > rightDistance)
    {
      for (int i = 0; i <= 4; i++)
      {
        turnLeft();
        grabHorizontalFront();
      }
    }
    else
    {
      for (int i = 0; i <= 3; i++)
      {
        turnRight();
        grabHorizontalFront();
      }
    }
  }
  else
  {
    walkForward();
  }
}
