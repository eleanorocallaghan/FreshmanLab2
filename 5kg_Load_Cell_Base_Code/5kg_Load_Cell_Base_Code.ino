//Include library for board
#include "HX711.h" // this is a library that has to be included into the sketch

const int DOUT = 13; // "DT" on the board
const int CLK = 12; // "SCK" on the board

float rawSignalValue;
int numToAverage = 10;

float loadValue; //Units?
float loadSlope=-2.39947*0.000001;
float loadIntercept=-1.8691;

//Set up red LED pin variables
const int redLEDPin = 3; //This is a digital input/output/PWM pin
float redLEDVoltage; //This is the equivalent voltage sent to the blue LED
int redLEDPWMValue; //This will be a number between 0 (0v) and 255 (5v)

//Set up green LED pin variables
const int greenLEDPin = 5; //This is a digital input/output/PWM pin
float greenLEDVoltage; //This is the equivalent voltage sent to the red LED
int greenLEDPWMValue; //This will be a number between 0 (0v) and 255 (5v)

HX711 loadCell(DOUT, CLK); // here we set up the HX711 object with name "loadCell"

void setup() {
  Serial.begin(9600);
}



void loop() { // run this over and over

  //Get the raw signal value from the load cell
  rawSignalValue=loadCell.get_units(numToAverage);

  //Convert the raw signal value into the actual load value
  loadValue=loadSlope*rawSignalValue+loadIntercept;

  redLEDVoltage = 5*loadValue/5.;

  if (redLEDVoltage<=4.5)
  {
   redLEDPWMValue=0; 
  }
  else
  {
    redLEDPWMValue=255;
  }

 greenLEDVoltage = 5*loadValue/5.;

  if (greenLEDVoltage<=5)
  {
   greenLEDPWMValue=255*(greenLEDVoltage)/5.; 
  }
  else
  {
    greenLEDPWMValue=0;
  }

  analogWrite(greenLEDPin, greenLEDPWMValue);
  analogWrite(redLEDPin, redLEDPWMValue);

  Serial.print(rawSignalValue);
  Serial.print("\t");
  Serial.print(redLEDPWMValue);
  Serial.print("\t");
  Serial.print(greenLEDPWMValue);
  Serial.print("\t");
  Serial.print(loadValue);
  Serial.println();

  delay(1000);
}
