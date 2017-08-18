const int analogInPin0 = A0;  // Analog input pin that the potentiometer is attached to
const int analogInPin1 = A1;  // Analog input pin that the potentiometer is attached to

#include <Servo.h>
Servo myservo;

int windowOpen = 50;
int windowClose = 51;
int motorCtrl = 10;


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

 

 if (sensorValue0 >= 28) //turn on light when temp sensor is above 28C
{
   
  digitalWrite(7, HIGH);
  digitalWrite(motorCtrl, HIGH);
  if(myservo.read() != 180)
  {
    myservo.write(180);
    Serial.println("degree = 180");
   }
}

 if(sensorValue0 < 28) //turn off light when temp sensor is below 28C
{
  digitalWrite(7, LOW);
  digitalWrite(motorCtrl, LOW);
  if(myservo.read() != 100)
  {
    myservo.write(100);
    Serial.println("degree = 100");
   }
}




  // Temperature (C)
  Serial.print("c =");
  Serial.print(sensorValue0);
  Serial.print("|");
  // RAW light sensor data
  Serial.print("l=");
  Serial.print(sensorValue1);
  Serial.print("|");
  // ACTOR toggle
  Serial.print("t=");
  Serial.println(outputValue);
  Serial.println("JSON OBJECT ");
  Serial.print(" {c:");
  Serial.print(sensorValue0);
  Serial.print(", l");
  Serial.print(sensorValue1);
  Serial.print(", t:");
  Serial.print(outputValue);
  Serial.println(" }");
  
  delay(1000);
}
