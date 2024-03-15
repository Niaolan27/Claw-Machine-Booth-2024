const int stepPin = 3;
const int dirPin = 4; 
const int pulleyButton = 10;
const int fullRev = 2700;
//full revolution should be 1800
bool pulleyMoving = false;
int pulleyCount = 0;
const int pulleyMid = 8;
const int pulleyMax = 2 * pulleyMid;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(10, INPUT);
  Serial.begin(9600);
}

void loop() { 
  int pulley = digitalRead(pulleyButton);
  Serial.println(pulley);

  if (pulley && !pulleyMoving) {
    pulleyMoving = true;
    pulleyCount = 0;
  }

  while (pulleyMoving) {
    //max height reached
    if (pulleyCount >= pulleyMax) {
      pulleyMoving = false;
      pulleyCount = 0;
      break;
    }
    if (pulleyCount < pulleyMid) {
      digitalWrite(dirPin, HIGH);
    }
    
    else if (pulleyCount < pulleyMax) {
      //put a short delay before switching dir
      if (pulleyCount == pulleyMid) {
      delay(1000);
      }
      digitalWrite(dirPin, LOW);
    }

    for (int i = 0; i < 50; i++){
      digitalWrite(stepPin, HIGH); 
      delayMicroseconds(500); 
      digitalWrite(stepPin, LOW); 
      //longer delay to reduce speed
      delayMicroseconds(5000);
    }

    digitalWrite(stepPin, LOW);
    pulleyCount++;
  }

}
