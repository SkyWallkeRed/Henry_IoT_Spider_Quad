

void proximity_listener_init() {

  if (midSensorValue < 20)
  {
    printToOled("mid sensore");

    if (sleepStat = false) {

      sleep();
      sleepStat = true;
      delay(500);
      return;

    } else {
      homePos();
      sleepStat = false;
    }


  }
  if (backSensorValue < 25)
  {
    printToOled("back sensore");
    Serial.println("scerd back: ");
    Serial.println(backSensorValue);
    walkForward();
    delay(100);
    homePos();
  }
  if (frontSensorValue < 20)
  {
    if (sleepStat = false) {
      delay(500);


    } else {
      //        homePos();
      sleepStat = false;

    }
    scared();
    sleep();

    sleepStat = true;
    printToOled("front sensore");
    printSleep();
    scerdFront ++;
    Serial.println("scerdFront: ");
    Serial.println(scerdFront);

    if (scerdFront > 1) aggression();
    //  return;
    //  if(scerdFront > 2)
    //  scared();
    //  aggression();
    //  delay(100);
    //  homePos();
  }
}

int getDistance()
{
  long duration, inches, cm;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
  return cm;
}
