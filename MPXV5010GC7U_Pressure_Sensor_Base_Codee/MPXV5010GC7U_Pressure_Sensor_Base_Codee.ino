//Set up timing and trig function variables
const int delayValue=50; //value of delay during main loop

//Set up psensor pin variables
const int psensorPin=A0; //This is an analog input pin
int psensorValue; //This will be a number between 0 (0v) and 1023 (5v)
float psensorVoltage; //This will be a value between 0v and 5v

float pressureValue; //This is the actual measured pressure, in kPa
float pressureSlope=2.3544;
float pressureIntercept=-1.35683;


void setup() {
  
  //Establish communication with the computer, at a rate of bits per sec
  Serial.begin(9600);

  pinMode(psensorPin, INPUT); //Read a 0-5v signal from this pin

}

void loop() {
  // put your main code here, to run repeatedly:

  //Read 10-bit signal from sensor pin
  psensorValue=analogRead(psensorPin);
  //Convert 10-bit signal into the input voltage
  psensorVoltage=5.*psensorValue/1023.;
  //Convert input voltage into pressure value
  pressureValue=pressureSlope*psensorVoltage+pressureIntercept;
  

  //Send output to the computer
  Serial.println();
  Serial.print(psensorValue);
  Serial.print("\t");
  Serial.print(psensorVoltage);
  Serial.print("\t");
  Serial.print(pressureValue);


  //Wait for the delay value
  delay(delayValue);
}
