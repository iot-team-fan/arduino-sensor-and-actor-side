const int analogInPin0 = A0;  // Analog input pin that the potentiometer is attached to
const int analogInPin1 = A1;  // Analog input pin that the potentiometer is attached to

#include <Servo.h>
Servo myservo;

int windowOpen = 50;
int windowClose = 51;
int motorCtrl = 10;
int incomingByte = 0;
int fanTurnOn = 49;
int fanTurnOff = 48;

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  analogReference(INTERNAL);
  myservo.attach(9);
}

void loop() {
  float sensorValue0 = analogRead(analogInPin0) / 9.31; // Raw value
  float sensorValue1 = analogRead(analogInPin1);
  int outputValue;
  Serial.print("{\"c\":");
  Serial.print(sensorValue0);
  Serial.print(",\"l:\"");
  Serial.print(sensorValue1);
  Serial.print(",\"t:\"");
  Serial.print(outputValue);
  Serial.println("}");

  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    if(incomingByte == fanTurnOn){
      digitalWrite(motorCtrl,HIGH);
    }else if(incomingByte == fanTurnOff){
      digitalWrite(motorCtrl,LOW);
    }
 }
  
  delay(1000);
}

