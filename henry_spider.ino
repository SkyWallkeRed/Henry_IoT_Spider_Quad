/*
 * Author: David Ohana SkyWallkeRed, https://github.com/SkyWallkeRed/Henry_IoT_Spider_Quad
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

int frontSensorValue = 0;
int midSensorValue = 0;
int backSensorValue = 0;

int scerdFront = 0;
int scerdMid = 0;
int scerdBack = 0;

char dataInput = 0;     //Variable for storing received data

// -------------------
static const unsigned char PROGMEM image_data_Saraarray[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x14, 0x9e, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x36, 0x3f, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x6d, 0xff, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0xfb, 0xff, 0x80, 0x1f, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x03, 0xd7, 0xff, 0x80, 0x0f, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x07, 0xef, 0xff, 0x80, 0x07, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x0f, 0xdf, 0xff, 0x90, 0x07, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x0f, 0xbf, 0xff, 0xd0, 0x07, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x1d, 0x7f, 0xff, 0xd0, 0x07, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x01, 0x1b, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x02, 0xa7, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x03, 0xff, 0xc0, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0xff, 0x80, 0x00, 0x0b, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x07, 0xff, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x0f, 0x07, 0xff, 0xf8, 0xf8, 0x03, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x0e, 0x01, 0xff, 0xc0, 0x38, 0x07, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x1c, 0x46, 0xff, 0xb1, 0x18, 0x07, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x3f, 0x97, 0xff, 0xc0, 0x7a, 0x07, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x03, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x03, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xfe, 0x01, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x01, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xfe, 0x01, 0xbf, 0xff, 0xff, 0xff, 0xfe, 0x81, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0xbf, 0xff, 0xff, 0xff, 0xfc, 0x81, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0xff, 0xff, 0xfe, 0xff, 0xfd, 0x83, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0xbf, 0xff, 0xfe, 0xff, 0xfd, 0x01, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x01, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xfb, 0x03, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x3f, 0xff, 0xdc, 0xff, 0xfa, 0x03, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xd8, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xf8, 0x03, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xd0, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xf8, 0x01, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0x90, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xf8, 0x02, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xb0, 0x00, 0x0f, 0xf5, 0xff, 0xd7, 0xf8, 0x01, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xb0, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x5f, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xa0, 0x00, 0x0f, 0xfb, 0xff, 0xff, 0xf0, 0x00, 0x3f, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x0f, 0xfd, 0xff, 0xdf, 0xf0, 0x00, 0x3f, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x07, 0xff, 0xff, 0xbf, 0xf0, 0x00, 0x0f, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x07, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x87, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x03, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x43, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0x60, 0x00, 0x01, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x73, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xfe, 0xe0, 0x00, 0x00, 0xff, 0xff, 0xff, 0x80, 0x00, 0x7b, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xfd, 0xe0, 0x00, 0x00, 0x7f, 0xff, 0xfe, 0x00, 0x00, 0x33, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xfd, 0xe0, 0x00, 0x00, 0x3f, 0xff, 0xf8, 0x00, 0x00, 0x27, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x0f, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0x60, 0x00, 0x00, 0x67, 0xff, 0xe0, 0x00, 0x00, 0x1b, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xfd, 0x40, 0x00, 0x00, 0xf3, 0xff, 0xc4, 0x00, 0x00, 0x0b, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xfe, 0x80, 0x00, 0x00, 0xfc, 0xff, 0x8c, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x7f, 0x3c, 0x3c, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x3f, 0xc0, 0x7c, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xfc, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff
};
// -------------------

void setup() { 
  
  Serial.begin(9600);    

  // oled start --------------------
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
//  display.setFont(&FreeSansBold9pt7b);
//  display.setFont();
  delay(2000);
  display.clearDisplay();

  display.setTextSize(2);
  
  display.setTextColor(WHITE);
  display.clearDisplay();
  display.setCursor(0, 0);
  // Display static text
  display.println(" Loading");
  display.println("  Henry");
  display.display(); 
  delay(1000);
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("  Henry");
  display.println("");
  display.println("  Ready");
  display.display(); 
  delay(1000);
// --------------------


    
  // --------------------
  // --------------------
  // draw image
//  display.drawBitmap(0, 0, image_data_Saraarray, 128, 64, 1);
  
  // oled end --------------------
  
  Serial.println("16 channel PWM test!");
//  pwm.begin();
//  pwm.setPWMFreq(1600);  // This is the maximum PWM frequency
   
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
  
  
  homePos();
 homePosHead();
//   sleep();
   delay(500);
  
 

}

void loop() 
{
//    display.startscrollright(0x00, 0x0F);
//  delay(2000);
//  display.stopscroll();
//  delay(1000);
//  display.startscrollleft(0x00, 0x0F);
//  delay(2000);
//  display.stopscroll();
//  delay(1000);
//  display.startscrolldiagright(0x00, 0x07);
//  delay(2000);
//  display.startscrolldiagleft(0x00, 0x07);
//  delay(2000);
//  display.stopscroll();
//  delay(1000);
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

  // Drive each PWM in a 'wave'
//  for (uint16_t i=0; i<4096; i += 8)
//  {
//    for (uint8_t pwmnum=0; pwmnum < 16; pwmnum++)
//    {
//      pwm.setPWM(pwmnum, 0, (i + (4096/16)*pwmnum) % 4096 );
//    }
//  }


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
    
 if(midSensorValue < 20)
  {
  printToOled("mid sensore");
  
  if(sleepStat = false){
      
      sleep();
      sleepStat = true;
      delay(500);
      return;
      
    }else{
        homePos();
        sleepStat = false;
    }
   
    
  }   
 if(backSensorValue < 25)
  {
       printToOled("back sensore");
       Serial.println("scerd back: ");
       Serial.println(backSensorValue);
       walkForward();
       delay(100);
      homePos();
  }
if(frontSensorValue < 20)
{
   if(sleepStat = false){
      delay(500);
      
      
    }else{
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
//avoidObstacles();

//for(uint16_t i=0; i<5; i ++){
//  walkForward();
//  }
  
} 

void printToOled( char *myString  ){
      display.clearDisplay();
       display.setCursor(0, 0);
    // Display static text
       display.println(myString);
       display.display(); 
  }

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
  printToOled("scared");
       
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
  printToOled("test");
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

void printSleep(){
       display.clearDisplay();
       display.setCursor(0, 0);
    // Display static text
       display.println("Z  z  Z  z  Z  z  Z  z  Z  z  Z  z   ");
       display.display(); 
}
void sleep()
{ 
  printToOled("sleep");
  printSleep();
  FR_FOOT.write(150);
  FL_FOOT.write(150);
  BR_FOOT.write(170);
  BL_FOOT.write(150);
  BL_HIP.write(130);
  neckLR.write(120);
  printSleep();
  delay(100);
}

void givRight()
{
  printToOled("give right");
   FL_HIP.write(90);
  BR_HIP.write(10);
  FR_FOOT.write(170);
  FR_HIP.write(40);

}

void dancePUP()
{
  printToOled("dance pupp");
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
  printToOled("sit jump");
  homePos();
delay(100);
sit();  
delay(150);
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
  printToOled("sit");
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
  printToOled("avoid obls.."); 
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
  printToOled("head demo");
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
  printToOled("lean demo");
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

void bow()
{
  printToOled("bow");
 FL_FOOT.write(140);
 FR_FOOT.write(15);
 BL_FOOT.write(130);
 BR_FOOT.write(30);
}

void bendBack()
{
  printToOled("bend back");
 FL_FOOT.write(30);
 FR_FOOT.write(130);
 BL_FOOT.write(15);
 BR_FOOT.write(140);
}

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
