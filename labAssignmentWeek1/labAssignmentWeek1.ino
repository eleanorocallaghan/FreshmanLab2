//Set up timing and trig function variables
int delayValue; //value of delay during main loop
const float freq=3.14159; //frequency of sine function
float timeSeconds; //number of seconds since program started
float sineOutput;
float cosineOutput;

//Set up pushbutton pin variables
const int buttonPin = 8; //This is a digital input/output pin
boolean buttonState=LOW; //set to LOW if off, HIGH if on

//Set up potentiometer pin variables
const int potPin = A0; //This is an analog input pin
int potValue; //This will be a number between 0(0v) and 1024(5v)
float potVoltage; //This will be a value between 0v and 5v

//Set up green LED pin variable
const int greenLEDPin = 4; //This is a digital input/output pin

//Set up blue LED pin variables
const int blueLEDPin = 3; //This is a digital input/output/PWM pin
float blueLEDVoltage; //This is the equivalent voltage sent to the blue LED
int blueLEDPWMValue; //This will be a number between 0 (0v) and 255 (5v)

void setup() {
  // put your setup code here, to run once:

  //Establish communication with the computer, at a rate of bits per sec
  Serial.begin(9600);

  //Ask user for delay time
  Serial.println(); //Begin a new line
  Serial.println("Enter the time delay, in milliseconds (integer values only)");

  //Wait 5 seconds
  delay(5000);

  //Check if user entered a value through the serial monitor
  //If yes, then set delayValue to the entered value
  //Otherwise, set delayValue to 10 ms

  if (Serial.available()!=0)
  {
    delayValue=Serial.parseInt();
  }
  else
  {
    delayValue=10;
  }
  pinMode(buttonPin, INPUT); //Read a 0v or 5v signal from this pin
  pinMode(potPin, INPUT); //Read a 0-5v signal from this pin
  pinMode(greenLEDPin, OUTPUT); //Send a 0v or 5v signal to this pin
  pinMode(blueLEDPin, OUTPUT); //Send a 5v PWM signal to this pin
}

void loop() {
  // put your main code here, to run repeatedly:

  //Get the number of milliseconds since the program started
  timeSeconds=millis()/1000.0;

  //Compute sine and cosine values
  sineOutput=sin(freq*timeSeconds);
  cosineOutput=cos(freq*timeSeconds);

  //Check the state of the pushbutton
  buttonState=digitalRead(buttonPin);

  //Read voltage signal from potentiometer
  potValue= analogRead(potPin);
  //Convert potValue into the signal voltage
  potVoltage = 5.*potValue/1023.;

  //Turn on green LED when pushbutton is pressed
  if (buttonState==HIGH)
  {
    digitalWrite(greenLEDPin,HIGH);
  }
  else
  {
    digitalWrite(greenLEDPin,LOW);
  }

  //Set blue LED voltage to be equal to the potentiometer signal voltage
  blueLEDVoltage=potVoltage;
  //Convert blue LED voltage value to the PWM signal
  blueLEDPWMValue=255.0*blueLEDVoltage/5.;
  analogWrite(blueLEDPin, blueLEDPWMValue);

  //Send output to the computer
  Serial.println();
  Serial.print(sineOutput);
  Serial.print("\t");
  Serial.print(cosineOutput);
  Serial.print("\t");
  Serial.print(buttonState);
  Serial.print("\t");
  Serial.print(potValue);
  Serial.print("\t");
  Serial.print(potVoltage);
  Serial.print("\t");
  Serial.print(blueLEDVoltage);
  Serial.print("\t");
  Serial.print(blueLEDPWMValue);

  //Wait for the delay value
  delay(delayValue);
}
