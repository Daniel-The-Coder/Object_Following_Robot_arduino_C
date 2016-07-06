#include <stdio.h>
#include <math.h>

#define LEFT_MOTOR 6
#define RIGHT_MOTOR 4
#define RED_LED 11
#define GREEN_LED 10
#define YELLOW_LED 9
#define LEFT_IR A0
#define CENTER_IR A1
#define RIGHT_IR A2

float cm(int IR_reading);

float cm(int IR_reading) {
  return 2.54*3616*(pow(IR_reading,-1.127));
}

void TURN_LEFT();

void TURN_LEFT(){
  analogWrite(RIGHT_MOTOR, 225);
  //analogWrite(LEFT_MOTOR, 100);
  digitalWrite(11,HIGH);
  delay(100);
  analogWrite(RIGHT_MOTOR, 0);
  analogWrite(LEFT_MOTOR, 0);
  digitalWrite(11,LOW);
}

void TURN_RIGHT();

void TURN_RIGHT(){
  analogWrite(LEFT_MOTOR, 225);
  //analogWrite(RIGHT_MOTOR, 100);
  digitalWrite(9,HIGH);
  delay(100);
  analogWrite(LEFT_MOTOR, 0);
  analogWrite(RIGHT_MOTOR, 0);
  digitalWrite(9,LOW);
}

void FORWARD();

void FORWARD(){
  analogWrite(LEFT_MOTOR,170);
  analogWrite(RIGHT_MOTOR,200);
  digitalWrite(10,HIGH);
  delay(100);
  analogWrite(LEFT_MOTOR,0);
  analogWrite(RIGHT_MOTOR,0);
  digitalWrite(10,LOW);
}

void setup() {
  Serial.begin(19200);
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {

  if ((cm(analogRead(CENTER_IR))>10) && (cm(analogRead(CENTER_IR))<20)){
    Serial.print("Center IR: ");
    Serial.println(cm(analogRead(CENTER_IR)));
    FORWARD();
  }
  else{
    if (cm(analogRead(LEFT_IR))<20){
      TURN_LEFT();
      Serial.print("Left IR: ");
      Serial.println(cm(analogRead(LEFT_IR)));
    }
    else{
      if (cm(analogRead(RIGHT_IR))<20){
        TURN_RIGHT();
        Serial.print("Right IR: ");
        Serial.println(cm(analogRead(RIGHT_IR)));
      }
      else{
      delay(100);
      }
    }
  }

}
