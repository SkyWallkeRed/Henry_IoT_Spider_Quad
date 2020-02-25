

void proximity_listener_init() {

  if (midSensorValue < 30)
  {
    printToOled("mid sensore");

    if (sleepStat = false) {

      sleep();
      sleepStat = true;
      delay(500);
      return;

    } else {
      printToOled("home pos");
      homePos();
      sleepStat = false;
    }

  }
  if (backSensorValue < 30)
  {
    printToOled("back sensore");
    Serial.println("scerd back: ");
    Serial.println(backSensorValue);
    printToOled("wallk forward");
    walkForward();
    delay(100);
    printToOled("home pos");
    homePos();
  }
  if (frontSensorValue < 30)
  {
    if (sleepStat = false) {
      delay(500);


    } else {
      printToOled("home pos");
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

void initArmIRsensore() {
  if (armIRsensoreValue < 150) {
    givRight();
    delay(500);
  } else {
    homePos();
  }
}

void initHeadIRsendore() {
  if (headIRsensoreValue < 150) {
    sleep();
    delay(2000);
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
