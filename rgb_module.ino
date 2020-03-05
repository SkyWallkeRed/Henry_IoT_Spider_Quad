


// red: rgb(237, 3, 23)
// pink: rgb(242, 46, 138)
// teal: rgb(102, 228, 242)
//yellow: rgb(242, 230, 65)

void light_random() { // random
  analogWrite(redPin, random(0, 255));
  analogWrite(greenPin, random(0, 255));
  analogWrite(bluePin, random(0, 255));
}

void light_red() { // angry
  analogWrite(redPin, 237);
  analogWrite(greenPin, 3);
  analogWrite(bluePin, 23);
}


void light_pink() { // love
  analogWrite(redPin, 242);
  analogWrite(greenPin, 46);
  analogWrite(bluePin, 138);
}


void light_teal() { // relexed
  analogWrite(redPin, 102);
  analogWrite(greenPin, 228);
  analogWrite(bluePin, 242);
}


void light_yellow() { // happy
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0);
}
