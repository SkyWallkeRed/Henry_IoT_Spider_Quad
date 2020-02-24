

void seria_blutooth_listener_init() {
  if (Serial.available() > 0)  // Send data only when you receive data:
  {
    dataInput = Serial.read();      //Read the incoming data and store it into variable data
    Serial.print(dataInput);        //Print Value inside data in Serial monitor
    Serial.print("\n");             //New line


    if (dataInput == '1')  leanRight();
    if (dataInput == '0')  leanLeft();
    if (dataInput == '2')  bow();
    if (dataInput == '3')  homePos();
    if (dataInput == '4')  leanDemo();
    if (dataInput == '5')  walkForward();
    if (dataInput == '6')  turnLeft();
    if (dataInput == '7')  sayHelloL();
    if (dataInput == 'a')  givRight();
    if (dataInput == 'b')  wave();
    if (dataInput == 'c')  avoidObstacles();
    if (dataInput == 'd')  scan();
    if (dataInput == 'e')  sit();
    if (dataInput == 'f')  sitJump();
    if (dataInput == 'g')  dancePUP();
    if (dataInput == 'r')  turnRight();
    if (dataInput == 'l')  turnLeft();
    if (dataInput == 't')  test();
    if (dataInput == 's')  sleep();

    // Drive each PWM in a 'wave'
    //  for (uint16_t i=0; i<4096; i += 8)
    //  {
    //    for (uint8_t pwmnum=0; pwmnum < 16; pwmnum++)
    //    {
    //      pwm.setPWM(pwmnum, 0, (i + (4096/16)*pwmnum) % 4096 );
    //    }
    //  }
  }
}
