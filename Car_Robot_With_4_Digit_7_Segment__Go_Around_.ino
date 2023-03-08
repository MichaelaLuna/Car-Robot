/* This program is used to control the Car Robot to go forward.
 * It has been possible by learning how to set the pins correctly 
 * and learning how to call the function that has been created.
 */
 
#define MotorA 7 // Initialize motor A1N1 to pin 7 of arduino
#define MotorB 8 // Initialize motor B1N1 to pin 8 of arduino
#define Motor_SpeedA 5 // Initialize motor PWMA to pin 5 of arduino
#define Motor_SpeedB 6 // Initialize motor PWMB to pin 6 of arduino
#define EnablePin 3 // Set pin 3 of arduino as the EnablePin, ("Stby")

int LatchPin = 19;  // defines pin for the latch
int ShiftPin = 18;  // defines pin for shift 
int DataInput = 10; // defines pin for data input 
int digPins[4] = {A0,A1,12,13}; // has four dedicated common pins to control each digit separately */

const byte digits[10] = {  
  // defines an array of bytes that represent the pattern to light up each segment of a digit.
  B11101111,  // 0 afbgc-de
  B00101100,  // 1
  B10110111,  // 2
  B10111110,  // 3
  B01111100,  // 4
  B11011110,  // 5
  B11011111,  // 6
  B10101100,  // 7
  B11111111,  // 8
  B11111110,  // 9
};


void setup() { // Run the code once
  for(int i=1; i<9; i++){ // Setup the pins 
     pinMode(i, OUTPUT); // Set these pins as an output
  }
 pinMode(EnablePin, OUTPUT); // Set the enable pin ("Stby") as an ouput

  pinMode (LatchPin ,OUTPUT);
  pinMode (ShiftPin, OUTPUT);
  pinMode (DataInput, OUTPUT);
  pinMode (A0, OUTPUT);
  pinMode (A1, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (13, OUTPUT); 
  
}

void loop() { // Run code on loop

  Display1();
  delay(500);
  Display2();
  delay(500);
  Display3();
  delay(500);
  Display4();
  delay(5);
  
  digitalWrite(EnablePin,HIGH); // Set enable pin ("Stby") as 1 to turn on
  /*Forward(); // Call the function Forward to go forward
  delay (2000); // Delay for 2secs
  Backward();
  delay (2000);
  Left();
  delay (2000);
  Right();
  delay (2000); */
  Stop(); // Call the function Stop to stop the Car
  delay (2000); // Delay for 2secs
   
} // End of loop

void Display1(){
 
  digitalWrite (13, LOW);
  digitalWrite (12, HIGH);
  digitalWrite (A1, HIGH);
  digitalWrite (A0, HIGH);
  digitalWrite (LatchPin, LOW);
  shiftOut(DataInput, ShiftPin, MSBFIRST,digits[2] );
  digitalWrite (LatchPin, HIGH); 
}

void Display2(){
  
  digitalWrite (13, HIGH);
  digitalWrite (12, LOW);
  digitalWrite (A1, HIGH);
  digitalWrite (A0, HIGH);
  digitalWrite (LatchPin, LOW);
  shiftOut(DataInput, ShiftPin, MSBFIRST, digits[4] );
  digitalWrite (LatchPin, HIGH);
}

void Display3(){
  
  digitalWrite (13, HIGH);
  digitalWrite (12, HIGH);
  digitalWrite (A1, LOW);
  digitalWrite (A0, HIGH);
  digitalWrite (LatchPin, LOW);
  shiftOut(DataInput, ShiftPin, MSBFIRST,digits[6]);
  digitalWrite (LatchPin, HIGH); 
}

void Display4(){
  
  digitalWrite (13, HIGH);
  digitalWrite (12, HIGH);
  digitalWrite (A1, HIGH);
  digitalWrite (A0, LOW);
  digitalWrite (LatchPin, LOW);
  shiftOut(DataInput, ShiftPin, MSBFIRST, digits[8]);
  digitalWrite (LatchPin, HIGH);
}
  
void Forward (){ // Function to go Forward 
  digitalWrite(MotorA,1); // Set motorA to 1 to turn on
  digitalWrite(MotorB,1); // Set motorB as High to turn on
  analogWrite(Motor_SpeedA,100); // Set motorspeedA to 100
  analogWrite(Motor_SpeedB,100); // Set motorspeedB to 100
}

void Backward (){ // Function to go Backward
  digitalWrite(MotorA,0); // Set motorA to 0 to turn off
  digitalWrite(MotorB,0); // Set motorB to 0 to turn off
  analogWrite(Motor_SpeedA,100); // Set motorspeedA to 255
  analogWrite(Motor_SpeedB,100); // Set motorspeedB to 255
}

void Left (){ // Function to go Backward
  digitalWrite(MotorA,1); // Set motorA to 1 to turn on
  digitalWrite(MotorB,0); // Set motorB to 0 to turn off
  analogWrite(Motor_SpeedA,100); // Set motorspeedA to 255
  analogWrite(Motor_SpeedB,100); // Set motorspeedB to 255
}

void Right (){ // Function to go Right
  digitalWrite(MotorA,0); // Set motorA to 0 to turn off
  digitalWrite(MotorB,1); // Set motorB to 1 to turn on
  analogWrite(Motor_SpeedA,100); // Set motorspeedA to 170
  analogWrite(Motor_SpeedB,100); // Set motorspeedB to 170
}

void LFW () { // Function to go Left Forward
  digitalWrite(MotorA,1); // Set motorA to 1 to turn on
  digitalWrite(MotorB,1); // Set motorB to 1 to turn on
  analogWrite(Motor_SpeedA,255); // Set motorspeedA to 255
  analogWrite(Motor_SpeedB,126); // Set motorspeedB to 126
}

void LBK (){ // Function to go Left Backward
  digitalWrite(MotorA,0); // Set motorA to 0 to turn off
  digitalWrite(MotorB,0); // Set motorB to 0 to turn off
  analogWrite(Motor_SpeedA,255); // Set motorspeedA to 255
  analogWrite(Motor_SpeedB,126); // Set motorspeedB to 126
}

void RFW (){ // Function to go Right Forward
  digitalWrite(MotorA,1); // Set motorA to 1 to turn on
  digitalWrite(MotorB,1); // Set motorB to 1 to turn on
  analogWrite(Motor_SpeedA,126); // Set motorspeedA to 126
  analogWrite(Motor_SpeedB,255); // Set motorspeedB to 255
}

void RBK (){ // Function to go Right Backward
  digitalWrite(MotorA,0); // Set motorA to 0 to turn off
  digitalWrite(MotorB,0); // Set motorB to 0 to turn off
  analogWrite(Motor_SpeedA,126); // Set motorspeedA to 126
  analogWrite(Motor_SpeedB,255); // Set motorspeedB to 255
}

void Stop (){ // Function to go Stop
  digitalWrite(MotorA,1); // Set motorA to 1 to turn on
  digitalWrite(MotorB,1); // Set motorB to 1 to turn on
  analogWrite(Motor_SpeedA,0); // Set motorspeedA to 0
  analogWrite(Motor_SpeedB,0); // Set motorspeedB to 0
}

 
