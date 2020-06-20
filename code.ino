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

void setup() {
  
}

void draw() {
  recordMoveState = digitalRead(recordPin);
  executeMoveState = digitalRead(executePin);
  
  while (recordMoveState == HIGH) {
    
  }
}
