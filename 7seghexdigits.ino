#include <math.h>

//global variables
int pinsOutputLevels[16][7] = { 
  {1,1,1,1,1,1,0}, {0,1,1,0,0,0,0}, {1,1,0,1,1,0,1}, {1,1,1,1,0,0,1}, 
  {1,1,1,0,0,1,1}, {1,0,1,1,0,1,1}, {1,0,1,1,1,1,1}, {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1}, {1,1,1,1,0,1,1}, {1,1,1,0,1,1,1}, {0,0,1,1,1,1,1},
  {1,0,0,1,1,1,0}, {0,1,1,1,1,0,1}, {1,0,0,1,1,1,1}, {1,0,0,0,1,1,1}
};

int prevInput = 0;
float curInput = 0.0;

void writeDigit(int userInput) {
  /* write zeroes first 
  for (int i = 0; i < 8; i++) {
    digitalWrite(i, LOW);
  }
  */
  for (int i = 0; i < 8; i++) {
    digitalWrite(i, pinsOutputLevels[userInput][i]);
  }
}


void setup() {
  // have to set digital pins 1-8 to output mode, adc 0 to input mode
  for (int i = 0; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(A0, INPUT);
}

void loop() {
  curInput = round(analogRead(A0) * (15 / 1023));
  //check for change in potentiometer value
  if (prevInput != (int)curInput) {
    //if change then call write digit to value obtained from potentiometer
    writeDigit(curInput);
  }
  prevInput = (int)curInput;
}
