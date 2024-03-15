const int stepPin = 3;
const int dirPin = 4; 
const int fullRev = 500;
//full revolution should be 1800

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

void loop() { 
  for (int i = 0; i < fullRev; i++) {
      digitalWrite(dirPin, HIGH); 
      digitalWrite(stepPin, HIGH); 
      delayMicroseconds(1000); 
      digitalWrite(stepPin, LOW); 
      delayMicroseconds(5000);
  }
  while (true){
    Serial.println("hi");
  }
}
