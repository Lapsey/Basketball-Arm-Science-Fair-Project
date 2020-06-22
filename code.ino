const int recordPin = 0;
const int executePin = 1;

int recordMoveState = 0;
int executeMoveState = 0;

const int shoulderPotPin = 1;
const int elbowPotPin = 2;
const int wristPotPin = 3;

int shoulderPosArr[2000] = {-1};
int elbowPosArr[2000] = {-1};
int wristPotArr[2000] = {-1};

int index = 0;

int lastMilis = 0;
int currentMillis = 0;

void setup() {
  lastMillis = millis();
  currentMillis = millis();
}

void draw() {
  recordMoveState = digitalRead(recordPin);
  executeMoveState = digitalRead(executePin);
  
  while (recordMoveState == HIGH) {
    currentMillis = millis();
    
    if (currentMillis - lastMillis >= 2) {
      shoulderPosArr[index] = analogRead(shoulderPotPin);
      elbowPosArr[index] = analogRead(elbowPotPin);
      wristPosArr[index] = analogRead(wristPotPin);
      
      index++
      lastMillis = currentMillis;
    }
  }
}
