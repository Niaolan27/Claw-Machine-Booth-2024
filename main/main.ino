const int stepPinLR = 3;
const int dirPinLR = 4;
const int stepPinPulley = 5;
const int dirPinPulley = 6;
const int limitSwitchRight = 7;
const int limitSwitchLeft = 8;
const int pulleyButton = 10;
const int leftButton = 12;
const int rightButton = 13;

// Reference: full revolution is 1800;
const int pulseCountPulley = 400;
const int pulseCountLR = 10;
const int pulseHighLength = 500;
const int pulseLowLength = 500;
const int pulsePulleyDelay = 2000;
int leftLimit = 0;
int rightLimit = 0;
bool pulleyMoving = false;

// Short pulse for horizontal motion
void pulseLR()
{
  for (int i = 0; i<pulseCountLR; i++) {
      digitalWrite(stepPinLR, HIGH);
      delayMicroseconds(pulseHighLength);
      digitalWrite(stepPinLR, LOW);
      delayMicroseconds(pulseLowLength);
  }
}

// Entire pulse motion for pulley
void pulsePulley()
{
    pulleyMoving = true;
    digitalWrite(dirPinPulley, HIGH);
    for (int i = 0; i < pulseCountPulley; i++) {
        digitalWrite(stepPinPulley, HIGH);
        delayMicroseconds(pulsePulleyDelay);
        digitalWrite(stepPinPulley, LOW);
        delayMicroseconds(pulsePulleyDelay);
    }
    delay(1000);
    digitalWrite(dirPinPulley, LOW);
    for (int i = 0; i < pulseCountPulley; i++) {
        digitalWrite(stepPinPulley, HIGH);
        delayMicroseconds(pulsePulleyDelay);
        digitalWrite(stepPinPulley, LOW);
        delayMicroseconds(pulsePulleyDelay);
    }
    pulleyMoving = false;
}


void setup()
{
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);

    pinMode(7, INPUT);
    pinMode(8, INPUT);
    pinMode(10, INPUT);
    pinMode(12, INPUT);
    pinMode(13, INPUT);
    Serial.begin(9600);

    // coil the pulley up
    pulleyMoving = true;
    delay(300);
    digitalWrite(dirPinPulley, LOW);
    for (int i = 0; i < pulseCountPulley; i++) {
        digitalWrite(stepPinPulley, HIGH);
        delayMicroseconds(pulsePulleyDelay);
        digitalWrite(stepPinPulley, LOW);
        delayMicroseconds(pulsePulleyDelay);
    }
    pulleyMoving = false;
}


void loop()
{
    int left = digitalRead(leftButton);
    int right = digitalRead(rightButton);
    int pulley = digitalRead(pulleyButton);
    int leftLimit = digitalRead(limitSwitchLeft);
    int rightLimit = digitalRead(limitSwitchRight);
      
//    Serial.println(left);
//    Serial.println(right);
//    Serial.println(pulley);
//    Serial.println(leftLimit);
//    Serial.println(rightLimit);
   
    if (pulley) {
        pulsePulley();
    } else if (left && !leftLimit && !pulleyMoving) {
        Serial.println("MOVING LEFT");
        digitalWrite(dirPinLR, LOW);
        pulseLR();
    } else if (right && !rightLimit && !pulleyMoving) {
        Serial.println("MOVING RIGHT");
        digitalWrite(dirPinLR, HIGH);
        pulseLR();
    }
}
