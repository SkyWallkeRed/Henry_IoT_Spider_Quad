/*
 * Author: David Ohana SkyWallkeRed, https://github.com/SkyWallkeRed/Henry_IoT_Spider_Quad
 */

#include <Servo.h>
// body moving parts
Servo FL_HIP; // front left hip etc.. 
Servo FL_FOOT;
Servo FR_HIP;
Servo FR_FOOT;
Servo BL_HIP; 
Servo BL_FOOT;
Servo BR_HIP;
Servo BR_FOOT;

Servo neckLR;
Servo neckUD;


const int trigPin = 13; // Trig Pin of Ultrasonic Sensor
const int echoPin = 12; // Echo Pin of Ultrasonic Sensor
const int lightSensorFrontPin = A5; // Light analog sensor 
const int lightSensorMidPin = A4; // Light analog sensor 
const int lightSensorBackPin = A3; // Light analog sensor 

int frontSensorValue = 0;
int midSensorValue = 0;
int backSensorValue = 0;

int scerdFront = 0;
int scerdMid = 0;
int scerdBack = 0;

char dataInput = 0;     //Variable for storing received data

void setup() { 
  Serial.begin(9600);    
 
  FL_HIP.attach(4); 
  FL_FOOT.attach(5);
  FR_HIP.attach(6);
  FR_FOOT.attach(7);
  BL_HIP.attach(8);
  BL_FOOT.attach(9);
  BR_HIP.attach(10);
  BR_FOOT.attach(11);

  neckLR.attach(3);
  neckUD.attach(2);
  
  
  homePos();
  delay(500);
  homePosHead();
 

}

void loop() 
{
   if(Serial.available() > 0)   // Send data only when you receive data:
{
dataInput = Serial.read();      //Read the incoming data and store it into variable data
Serial.print(dataInput);        //Print Value inside data in Serial monitor
Serial.print("\n");             //New line 


if(dataInput == '1')  leanRight();
if(dataInput == '0')  leanLeft();
if(dataInput == '2')  bow();                               
if(dataInput == '3')  homePos();
if(dataInput == '4')  leanDemo();
if(dataInput == '5')  walkForward();
if(dataInput == '6')  turnLeft();
if(dataInput == '7')  sayHelloL();
if(dataInput == 'a')  givRight();
if(dataInput == 'b')  wave();
if(dataInput == 'c')  avoidObstacles();
if(dataInput == 'd')  scan();
if(dataInput == 'e')  sit();
if(dataInput == 'f')  sitJump();
if(dataInput == 'g')  dancePUP();
if(dataInput == 'r')  turnRight();
if(dataInput == 'l')  turnLeft();
if(dataInput == 't')  test();
if(dataInput == 's')  sleep();



}
frontSensorValue = analogRead(lightSensorFrontPin); // read the value from the sensor
midSensorValue = analogRead(lightSensorMidPin); // read the value from the sensor
backSensorValue = analogRead(lightSensorBackPin); // read the value from the sensor

    
    Serial.println("");
    Serial.print("scerd back: ");
    Serial.print(backSensorValue);
    Serial.print(" . ");
    Serial.print("scerdFront: ");
    Serial.print(frontSensorValue);
    Serial.print(" . ");
    Serial.print(" . ");
    Serial.print("scerdTop: ");
    Serial.print(midSensorValue);
    Serial.println(" . ");
    
 if(midSensorValue < 25)
  {
    sleep();
  }   
 if(backSensorValue < 25)
  {
    Serial.println("scerd back: ");
    Serial.println(backSensorValue);
    walkForward();
    delay(100);
    homePos();
  }
if(frontSensorValue < 25)
{
 
  scared();  
  scerdFront ++;
  Serial.println("scerdFront: ");
  Serial.println(scerdFront);

  if(scerdFront > 1) aggression();
//  return;
//  if(scerdFront > 2) 
//  scared();
//  aggression();
//  delay(100);
//  homePos();
}

//delay(100);
////turnLeft();
//turnLeft();
//delay(2000);
//
//turnRight();
//turnRight();
//delay(2000);
//getDistance();
//walkForward();
//test();
//delay(2000);
//homePos();
//delay(2000);
//scared();
//delay(2000);
} 

void aggression()
{
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


void test()
{
  neckLR.write(50);
  sit();
  
  FL_HIP.write(120);
  BL_HIP.write(150);
  FL_FOOT.write(220);
//  FR_HIP.write(10); 
  
//  neckUD.write(50);
}

void lookRight()
{
  neckLR.write(140);
  delay(200);
  neckUD.write(30);
  }
  
void lookLeft()
{
  neckUD.write(30);
  delay(500);
  neckUD.write(150);
  delay(300);
  }
  
void scan()
{
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
  FR_FOOT.write(150);
  FL_FOOT.write(150);
  BR_FOOT.write(170);
  BL_FOOT.write(150);
  BL_HIP.write(130);
  neckLR.write(120);
}

void givRight()
{
   FL_HIP.write(90);
  BR_HIP.write(10);
  FR_FOOT.write(170);
  FR_HIP.write(40);

}

void dancePUP()
{
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
  homePos();
delay(100);
sit();  
delay(150);
}

void sayHelloR()
{
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
//  homePos();
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

void avoidObstacles()
{
  int distance = getDistance();
  homePosHead();
  if(distance < 6)
  {
    turnLeft();
    int leftDistance = getDistance();
    delay(500);
    for(int i = 0; i <= 1; i++){
      turnRight();
    }
    int rightDistance = getDistance();
    if(leftDistance > rightDistance)
    {
      for(int i = 0; i <= 4; i++)
      {
        turnLeft();
        grabHorizontalFront();
      }
    }
    else
    {
      for(int i = 0; i <= 3; i++)
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

void headDemo()
{
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
  leanLeft();
  delay(1000);
  homePos();
  delay(1000);
  leanRight();
  delay(1000);
  homePos();
  delay(1000);
}

void leanRight()
{
 FL_FOOT.write(15);
 FR_FOOT.write(15);
 BL_FOOT.write(140);
 BR_FOOT.write(140);
}

void leanLeft()
{
 FL_FOOT.write(140);
 FR_FOOT.write(140);
 BL_FOOT.write(15);
 BR_FOOT.write(15);
}

void homePos()
{
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

void turnLeft()
{
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
 FR_FOOT.write(50);
 BL_FOOT.write(50);

 delay(200);
//  
 FR_HIP.write(150);
 BL_HIP.write(110);
 FL_HIP.write(60);
 BR_HIP.write(20);

 delay(200);

 FR_FOOT.write(90);
 BL_FOOT.write(90);
//
 delay(200);
//
 FL_FOOT.write(110);
 BR_FOOT.write(130);
//
 delay(200);
//
 FL_HIP.write(20);
 BR_HIP.write(60);
 FR_HIP.write(110);
 BL_HIP.write(150);
//
 delay(200);
//
 FL_FOOT.write(110);
 BR_FOOT.write(110);
//
 delay(200);
 
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
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

void homePosHead()
{
  neckLR.write(160);
  neckUD.write(90);
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
