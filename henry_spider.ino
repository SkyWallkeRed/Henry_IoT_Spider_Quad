/*
   Author: David Ohana SkyWallkeRed, https://github.com/SkyWallkeRed/Henry_IoT_Spider_Quad
*/
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>
// oled start -----------------
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSansBold9pt7b.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define iRsensorePin A6
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
// olen end ----------------------

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

bool sleepStat = false;
const int trigPin = 13; // Trig Pin of Ultrasonic Sensor
const int echoPin = 12; // Echo Pin of Ultrasonic Sensor
const int lightSensorFrontPin = A5; // Light analog sensor
const int lightSensorMidPin = A4; // Light analog sensor
const int lightSensorBackPin = A3; // Light analog sensor


int armIRsensoreValue = 0;

int frontSensorValue = 0;
int midSensorValue = 0;
int backSensorValue = 0;

int scerdFront = 0;
int scerdMid = 0;
int scerdBack = 0;

char dataInput = 0;     //Variable for storing received data

void setup() {

  Serial.begin(9600);
  oled_init();
  //draw_bitmap_image();

  // save I2C bitrate
  uint8_t twbrbackup = TWBR;
  // must be changed after calling Wire.begin() (inside pwm.begin())
  TWBR = 12; // upgrade to 400KHz!

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

  pinMode(iRsensorePin, INPUT);

  homePos();
  homePosHead();
  //   sleep();
  delay(500);
}



void loop()
{

  seria_blutooth_listener_init();
  //  oled_sctoll_init();


  frontSensorValue = analogRead(lightSensorFrontPin); // read the value from the sensor
  midSensorValue = analogRead(lightSensorMidPin); // read the value from the sensor
  backSensorValue = analogRead(lightSensorBackPin); // read the value from the sensor

  armIRsensoreValue = analogRead(iRsensorePin); // read the value from the sensor

  proximity_listener_init();
  print_back_sensore();

  Serial.print(armIRsensoreValue);

  if (armIRsensoreValue < 150) {
    givRight();
    delay(500);
  } else {
    homePos();
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
  //avoidObstacles();
}


void test()
{
  printToOled("test");
  neckLR.write(50);
  sit();

  FL_HIP.write(120);
  BL_HIP.write(150);
  FL_FOOT.write(220);
  //  FR_HIP.write(10);

  //  neckUD.write(50);
}
