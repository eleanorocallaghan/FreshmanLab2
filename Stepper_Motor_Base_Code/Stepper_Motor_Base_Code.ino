//Reference: https://www.pololu.com/product/1182

// defines pins numbers
const int stepNumPin = 4; 
const int directionPin = 3;
int numOfSteps; //200 full steps per rev
int stepDelay = 1; // milliseconds between steps. if too low, the stepper will skip
// Higher voltages allow for lower step times. This works at 12V.

boolean dir = HIGH; // HIGH if CW, LOW if CCW
int i; //Counter for stepping loop

void setup() { // do this once
  Serial.begin(9600);
  pinMode(stepNumPin,OUTPUT); 
  pinMode(directionPin,OUTPUT);
  Serial.println("Enter number of steps (positive = CW rotation)");
}

void loop() { // do this continuously
  
  if (Serial.available()) 
  {
    numOfSteps = Serial.parseInt();
    
    if (numOfSteps>0)
    {
      dir=HIGH; 
    }
    else
    {
      dir=LOW;
    }
    
    digitalWrite(directionPin, dir); // Changes the rotations direction
    
    numOfSteps=abs(numOfSteps);
    
    Serial.print("Spinning the shaft ");
    Serial.print(numOfSteps);
    Serial.print(" steps ");
    
    if (dir==HIGH) 
    {
      Serial.print("Clockwise");
    } 
    else 
    {
      Serial.print("Counter-clockwise");
    }
    Serial.println();
        
    Serial.print("Enter number of steps (positive = CW rotation)");
    Serial.println();

    //Move motor shaft
    for(i = 0; i < numOfSteps; i++) 
    {  
      digitalWrite(stepNumPin,HIGH);
      delay(stepDelay);
      digitalWrite(stepNumPin,LOW);
      delay(stepDelay); 
    }
  } 
}
