/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
* Crated by Dejan Nedelkovski,
* www.HowToMechatronics.com
*/

// defines pin numbers
const int trigPin = 8;
const int echoPin = 9;
// define variables
long duration; //time for pulse to travel to target and back (units: microsec)
int distance; //distance to target (units: cm)
float speedOfSound = 0.034; //speed of sound (units: cm/microsec) 

//Set up blue LED pin variables
const int blueLEDPin = 3; //This is a digital input/output/PWM pin
float blueLEDVoltage; //This is the equivalent voltage sent to the blue LED
int blueLEDPWMValue; //This will be a number between 0 (0v) and 255 (5v)

void setup() {
  Serial.begin(9600); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  pinMode(blueLEDPin, OUTPUT); //Send a 5v PWM signal to this pin
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance in cm
  distance= duration*speedOfSound / 2.0; 
  
  blueLEDVoltage = 5*distance/50.0;

  if (blueLEDVoltage<=5)
  {
   blueLEDPWMValue=255-255*(blueLEDVoltage)/5.; 
  }
  else
  {
    blueLEDPWMValue=0;
  }
  
  analogWrite(blueLEDPin, blueLEDPWMValue);

  // Prints the distance (in cm)
  Serial.println(distance);

  //delay(500);

}
