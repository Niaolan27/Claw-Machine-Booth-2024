const int stepPin = 3;
const int dirPin = 4; 
const int leftButton = 12;
const int rightButton = 13;
const int limitSwitchLeft = 8;
const int limitSwitchRight = 7;
const int pulleyButton = 10;
const int fullRev = 2700;
int left_pressed = 0;
int right_pressed = 0;
//full revolution should be 1800

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  Serial.begin(9600);
  left_pressed = 0;
  right_pressed = 0;
}

void loop() { 
  Serial.println("hello world");
  int left = digitalRead(leftButton);
  int right = digitalRead(rightButton);
  int pulley = digitalRead(pulleyButton);

  //for testing
  /*
  int left_button = digitalRead(limitSwitchLeft);
  int right_button = digitalRead(limitSwitchRight);
  Serial.println(left_button);
  Serial.println(right_button);
  */



  /*
  Serial.println(left_pressed);
  Serial.println(right_pressed);

  Serial.println(left);
  Serial.println(right);
  */
  
  /*
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
  */
  
  while(left && !left_pressed){
      right_pressed = false;
      Serial.println("TOUCHED LEFT BUTTON");
      //right_pressed = false;
      digitalWrite(dirPin, HIGH); 
      for (int i = 0; i < 10; i++){
        digitalWrite(stepPin, HIGH); 
        delayMicroseconds(500); 
        digitalWrite(stepPin, LOW); 
        delayMicroseconds(5000);
      }
      left = digitalRead(leftButton);
      left_pressed = digitalRead(limitSwitchLeft);
      Serial.println(left_pressed);
  }
  digitalWrite(stepPin, LOW);

  while(right && !right_pressed){
      Serial.println("TOUCHED RIGHT BUTTON");
      left_pressed = false;
      digitalWrite(dirPin, LOW); 
      for (int i = 0; i < 10; i++){
        digitalWrite(stepPin, HIGH); 
        delayMicroseconds(500); 
        digitalWrite(stepPin, LOW); 
        delayMicroseconds(5000);
      }
      right = digitalRead(rightButton);
      right_pressed = digitalRead(limitSwitchRight);
      Serial.println(right_pressed);
  }
  digitalWrite(stepPin, LOW);
}
