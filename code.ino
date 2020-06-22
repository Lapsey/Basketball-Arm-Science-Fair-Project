//Pins for the record movement and execute movement buttons
const int recordPin = 0;
const int executePin = 1;

//Analog pins for the joint angle measuring potentiometers
const int shoulderPotPin = 1;
const int elbowPotPin = 2;
const int wristPotPin = 3;

//Arrays for the different angles at different points in time of the movement
int shoulderPosArr[2000] = {-1};
int elbowPosArr[2000] = {-1};
int wristPotArr[2000] = {-1};

int index = 0; //Variable to keep track of were we are in the movement

int flag1 = 0; //Variable to make sure that we will only execute a function once when the record button is pressed
int flag2 = 0; //Variable to make sure that we will only execute a function once when the execute button is pressed

//Variables for timers
int lastMilis = 0;
int currentMillis = 0;

void setup() {
  lastMillis = millis(); //Set the last time to the millis function
  currentMillis = millis(); //Set the current time to the millis function
  
  //Set the pin mode of the record pin and execute pin to input
  pinMode(recordPin, INPUT); 
  pinMode(executePin, INPUT);
}

void draw() {
  if (digitalRead(recordPin) == HIGH && flag == 0) { //Check if the record button has been pressed
    flag = 1; //this makes sure that we will only execute this block of code once per button press
    
    //Set all of the position arrays to empty or -1 in this case
    for (int i = 0; i < sizeOf(shoulderPosArr); i++) {
      shoulderPosArr[i] = -1;
      elbowPosArr[i] = -1;
      wristPosArr[i] = -1;
    }
  }
  
  if (digitalRead(recordPin) == LOW && flag == 1) { //check if the button is no longer pressed
    flag = 0; //set the flag to zero so the button pressed code can execute
  }
  
  while (digitalRead(recordPin) == HIGH) { //As long as the record button is pressed execute the following code
    currentMillis = millis(); //set the current time to the output of the millis function
    
    if (currentMillis - lastMillis >= 2) { //if 2 milliseconds have past execute the following code
      //Set the current index of each array to the analog value of the coresponding potentiometers
      shoulderPosArr[index] = analogRead(shoulderPotPin);
      elbowPosArr[index] = analogRead(elbowPotPin);
      wristPosArr[index] = analogRead(wristPotPin);
      
      index++; //increase the index so we can store the next point of the movement
      lastMillis = currentMillis; //Set the last time checked to the current time
    }
  } 
}
