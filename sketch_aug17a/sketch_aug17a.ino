const int analogInPin0 = A0;  // Analog input pin that the potentiometer is attached to
const int analogInPin1 = A1;  // Analog input pin that the potentiometer is attached to

#include <Servo.h>

Servo myservo;

int motorCtrl = 10;
int lightCtrl = 7;

int incomingByte = 0;
int lightIsOn = 0;

int fanTurnOff = 48;
int fanTurnOn = 49;

int windowClose = 50;
int windowOpen = 51;

int lightTurnOff = 52;
int lightTurnOn = 53;

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(motorCtrl,OUTPUT);
  analogReference(INTERNAL);
  myservo.attach(5);
}

void loop() {
  float sensorValue0 = analogRead(analogInPin0) / 9.31; // Raw value
  float sensorValue1 = analogRead(analogInPin1);
  int outputValue;
  Serial.print("{\"c\":");
  Serial.print(sensorValue0);
  Serial.print(",\"l\":");
  Serial.print(sensorValue1);
  Serial.print(",\"t\":");
  Serial.print(outputValue);
  Serial.print(",\"led\":");
  Serial.print(lightIsOn);
  Serial.println("}");

   if (sensorValue1 < 100) //turn on light when the light sensor is covered
  {
    outputValue = 1; 
    digitalWrite(8, HIGH);
  }
  else
  {
    outputValue = 0;
    digitalWrite(8, LOW);
  }

 

 if (sensorValue0 >= 27) //turn on light when temp sensor is above 28C
{
   
  digitalWrite(7, HIGH);
  digitalWrite(motorCtrl, HIGH);
  if(myservo.read() != 180)
  {
    myservo.write(180);
    Serial.println("degree = 180");
   }
}

 if(sensorValue0 < 27) //turn off light when temp sensor is below 28C
{
  digitalWrite(7, LOW);
  digitalWrite(motorCtrl, LOW);
  if(myservo.read() != 100)
  {
    myservo.write(100);
    Serial.println("degree = 100");
   }
}


//  if (Serial.available() > 0) {
//     incomingByte = Serial.read();
//    // read the incoming byte:
//    if(incomingByte == fanTurnOn){
//      digitalWrite(motorCtrl,HIGH);
//    } else if (incomingByte == fanTurnOff){
//      digitalWrite(motorCtrl,LOW);
//    } else if (incomingByte == windowOpen) {
//      myservo.write(180);
//    } else if (incomingByte == windowClose) {
//      myservo.write(100);
//    } else if (incomingByte == lightTurnOff) {
//      digitalWrite(lightCtrl, LOW);
//    } else if (incomingByte == lightTurnOn) {
//      digitalWrite(lightCtrl, HIGH);
//    }
// }
  
  delay(1000);
}

