
//Include library for TC board
#include "max6675.h"

int SO = 8; //Looks like "90" on the TC board
int CS = 9;
int CLK = 10; //"SCK" on the TC board

float degreeCelsius;

//Set up blue LED pin variables
const int blueLEDPin = 3; //This is a digital input/output/PWM pin
float blueLEDVoltage; //This is the equivalent voltage sent to the blue LED
int blueLEDPWMValue; //This will be a number between 0 (0v) and 255 (5v)

//Set up red LED pin variables
const int redLEDPin = 5; //This is a digital input/output/PWM pin
float redLEDVoltage; //This is the equivalent voltage sent to the red LED
int redLEDPWMValue; //This will be a number between 0 (0v) and 255 (5v)

MAX6675 thermoCouple(CLK, CS, SO);

  
void setup() {
  Serial.begin(9600);
  // give the MAX a little time to settle
  delay(500);
}

void loop() {

  //Read the temperature in Celsius
  degreeCelsius=thermoCouple.readCelsius();

  blueLEDVoltage = 5*degreeCelsius/100.0;

  if (blueLEDVoltage<=5)
  {
   blueLEDPWMValue=255-255*(blueLEDVoltage)/5.; 
  }
  else
  {
    blueLEDPWMValue=0;
  }

 redLEDVoltage = 5*degreeCelsius/100.0;

  if (redLEDVoltage<=5)
  {
   redLEDPWMValue=255*(blueLEDVoltage)/5.; 
  }
  else
  {
    redLEDPWMValue=0;
  }

  analogWrite(redLEDPin, redLEDPWMValue);
  analogWrite(blueLEDPin, blueLEDPWMValue);

  Serial.print(blueLEDPWMValue);
  Serial.print('\t');
  Serial.print(redLEDPWMValue);
  Serial.print('\t');
  Serial.print(degreeCelsius);
  Serial.println();
 
  delay(200); //Don't decrease this, or board may not work
}
