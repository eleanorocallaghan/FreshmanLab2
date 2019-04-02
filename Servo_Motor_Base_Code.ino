#include <Servo.h>      //Loading Servo library (no semicolon at end of line)

int pos = 0;            //Declare and initialize the position variable
int servoPin = 9;       //Orange wire

int potPin = A0;         //
int potValue;            //Value from 0 to 1023;

Servo myServo;          //Create a servo object called myServo


void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);  //tell servo object which pin controls it

}

void loop() {

  potValue = analogRead(potPin);
  pos = 180. - (180. / 1023.) * potValue;
  myServo.write(pos);
  Serial.println(pos);




}
