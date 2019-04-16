const int enable1 = 5; //L293D pin 1
const int input1 = 4;  //L293D pin 2
const int input2 = 3;  //L293D pin 7
const int potPin = A0;

//Motor leads go to L293D pins 3 and 6
//5V goes to L293D pin 16
//GND goes to L293D pins 4,5,12, or 13
//Motor voltage source goes to L293D pin 8 and ground

int dirAndSpeed;

int potValue;

void setup() {
  Serial.begin(9600);
  pinMode(enable1, OUTPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(potPin, INPUT_PULLUP);
}

void loop() {
  
  potValue = analogRead(potPin); //Will be a value from 0 - 1023

  //Convert potValue into a value from -255 to +255
  dirAndSpeed = 0.5*potValue-255.;
  
  Serial.print(dirAndSpeed);
  analogWrite(enable1, abs(dirAndSpeed)); // set motor speed
  
  if (dirAndSpeed>0)
  {
    Serial.println("  CW");
    digitalWrite(input1, HIGH);
    digitalWrite(input2, LOW);
  }
  else
  {
    Serial.println("  CCW");
    digitalWrite(input1, LOW);
    digitalWrite(input2, HIGH);
  }
  
  delay(200);
  
}

