#include <ezButton.h>

//ezButton limitSwitchLeft(8); 
//ezButton limitSwitchRight(7); 

const int stepPin = 3;
const int dirPin = 4; 
const int leftButton = 13;
const int rightButton = 12;
const int limitSwitchLeft = 8;
const int limitSwitchRight = 7;
const int pulleyUp = 11;
const int pulleyDown = 10;
const int fullRev = 2700;
//full revolution should be 1800

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  Serial.begin(9600);
}

void loop() { 
//  limitSwitchLeft.loop();
//  limitSwitchRight.loop();
  // digitalWrite(dirPin, HIGH); 
  // clockwise
  int left = digitalRead(leftButton);
  int right = digitalRead(rightButton);
  int up = digitalRead(pulleyUp);
  int down = digitalRead(pulleyDown);
  

  bool left_pressed = false;
  bool right_pressed = false;
  //Serial.print("Hello World");
//  Serial.println(left);
//  Serial.println(right);

  if (left_pressed) {
    Serial.println("TOUCHED LEFT");
  } else {
    Serial.println("UNTOUCHED LEFT");
  }
  
  if (right_pressed) {
    Serial.println("TOUCHED RIGHT");
  } else {
    Serial.println("UNTOUCHED RIGHT");
  }

  if (digitalRead(limitSwitchLeft)) {
        Serial.println("FLAGGED LEFT");
        left_pressed = true;
  }

  if (digitalRead(limitSwitchRight)) {
        Serial.println("FLAGGED RIGHT");
        right_pressed = true;
  }
     
  while(left && !left_pressed){
      Serial.println("TOUCHED LEFT BUTTON");
      right_pressed = false;
//      if (limitSwitchLeft.getState() == 1) {
//        Serial.println("FLAGGED LEFT");
//        left_pressed = true;
//        break;
//      }
      Serial.println("hello world");
      digitalWrite(dirPin, HIGH); 
      for (int i = 0; i < 100; i++){
       Serial.println("in for");
       //Serial.println(limitSwitchLeft.getState());
//       if (limitSwitchLeft.getState() == 1 || left_pressed) {
//          Serial.println("FLAGGED LEFT");
//          left_pressed = true;
//          digitalWrite(stepPin, LOW);
//          break;
//        }
        digitalWrite(stepPin, HIGH); 
        delayMicroseconds(500); 
        digitalWrite(stepPin, LOW); 
        delayMicroseconds(500);
      }
//      if (limitSwitchLeft.getState() == 1) {
//        Serial.println("FLAGGED LEFT");
//        left_pressed = true;
//        break;
//       }
      left = digitalRead(leftButton);
      left_pressed = digitalRead(limitSwitchLeft);
      Serial.println(left_pressed);
  }
  digitalWrite(stepPin, LOW);

  while(right && !right_pressed){
      Serial.println("TOUCHED RIGHT BUTTON");
      left_pressed = false;
//      if (limitSwitchRight.getState() == 1) {
//        Serial.println("FLAGGED RIGHT");
//        right_pressed = true;
//        break;
//      }
      Serial.println("hello world");
      digitalWrite(dirPin, LOW); 
      for (int i = 0; i < 100; i++){
        digitalWrite(stepPin, HIGH); 
        delayMicroseconds(500); 
        digitalWrite(stepPin, LOW); 
        delayMicroseconds(500);
      }
      right = digitalRead(rightButton);
      right_pressed = digitalRead(limitSwitchRight);
      Serial.println(right_pressed);
  }
  digitalWrite(stepPin, LOW);
  
 
//  for (int i = 0; i < fullRev; i++) { 
//    digitalWrite(stepPin, HIGH); 
//    delayMicroseconds(500); 
//    digitalWrite(stepPin, LOW); 
//    delayMicroseconds(500);
//  }
//  delay(1000);
//
//  digitalWrite(dirPin, LOW); 
//  // counter-clockwise
//
//  for (int j = 0; j < fullRev; j++) {
//    digitalWrite(stepPin, HIGH); 
//    delayMicroseconds(500); 
//    digitalWrite(stepPin, LOW); 
//    delayMicroseconds(500);
//  }
//  delay(1000);


}
