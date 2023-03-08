#include <IRremote.h> // Include the library for the IRremote
#include <Servo.h> // Include the library for the servo

#define MotorA 7 // Initialize motor A1N1 to pin 7 of arduino
#define MotorB 8 // Initialize motor B1N1 to pin 8 of arduino
#define Motor_SpeedA 5 // Initialize motor PWMA to pin 5 of arduino
#define Motor_SpeedB 6 // Initialize motor PWMB to pin 6 of arduino
#define EnablePin 3 // Set pin 3 of arduino as the EnablePin, ("Stby")

int LatchPin = 19;  // defines pin for the latch
int ShiftPin = 18;  // defines pin for shift 
int DataInput = 10; // defines pin for data input 
int digPins[4] = {A0,A1,12,13}; // has four dedicated common pins to control each digit separately */

int receiver = 9; // Set pin 9 as the receiver 

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


Servo myservo; // Set servo as an object to control the servo
IRrecv irrecv(receiver); // Create the receiver object; I chose 'irrecv'
decode_results results; // Decode Xresults from the IRremote; 


void setup() { // Run the code once
  
  pinMode (LatchPin ,OUTPUT);
  pinMode (ShiftPin, OUTPUT);
  pinMode (DataInput, OUTPUT);
  pinMode (A0, OUTPUT);
  pinMode (A1, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (13, OUTPUT); 
  
  irrecv.enableIRIn(); // Start the receiver
  
  for(int i=1; i<9; i++){ // Setup the pins 
     pinMode(i, OUTPUT); // Set these pins as an output
  }
  pinMode(EnablePin, OUTPUT); // Set the enable pin ("Stby") as an ouput
  myservo.attach(11); // Signal pin of servo connected to pin 11 of arduino
}


void loop() { // Run the code on loop
  
  // Start of First Dig
  digitalWrite (13, LOW);
  digitalWrite (12, HIGH);
  digitalWrite (A1, HIGH);
  digitalWrite (A0, HIGH);
  digitalWrite (LatchPin, LOW);
  shiftOut(DataInput, ShiftPin, MSBFIRST,digits[7] );
  digitalWrite (LatchPin, HIGH); 
  delay(5);
 
  // Start of Second Dig
  digitalWrite (13, HIGH);
  digitalWrite (12, LOW);
  digitalWrite (A1, HIGH);
  digitalWrite (A0, HIGH);
  digitalWrite (LatchPin, LOW);
  shiftOut(DataInput, ShiftPin, MSBFIRST, digits[3] );
  digitalWrite (LatchPin, HIGH);
  delay(5);
  
  // Start of Third Dig
  digitalWrite (13, HIGH);
  digitalWrite (12, HIGH);
  digitalWrite (A1, LOW);
  digitalWrite (A0, HIGH);
  digitalWrite (LatchPin, LOW);
  shiftOut(DataInput, ShiftPin, MSBFIRST,digits[9]);
  digitalWrite (LatchPin, HIGH); 
  delay(5);

  // Start of Fourth Dig
  digitalWrite (13, HIGH);
  digitalWrite (12, HIGH);
  digitalWrite (A1, HIGH);
  digitalWrite (A0, LOW);
  digitalWrite (LatchPin, LOW);
  shiftOut(DataInput, ShiftPin, MSBFIRST, digits[6]);
  digitalWrite (LatchPin, HIGH);
  delay(5);
  
  myservo.write(90);  // Set/Turn servo at 90 Degrees position
  delay(300); // Delay for 300ms
  
  digitalWrite(EnablePin, HIGH); // Set the enable pin High in order for it to turn on

  if (irrecv.decode(&results)) // First case: Have we received an IR signal?
  {
    switch(results.value) // If yes, go to cases:
    {
     case 0xFF906F: // case 1: Up button pressed, code of Up button is FF906F
                      Forward(); // Call Function
                      break; // Tell Arduino to go on
     case 0xFFE01F: // case 2: Down button pressed, code of Down button is FFE01F
                      Backward(); // Call Function 
                      break; // Tell Arduino to go on
     case 0xFFC23D: // case 3: Right button pressed, code of Right button is FFC23D
                      myservo.write(90);  // Set/Turn servo at 90 Degrees position           
                      delay(1000); // Delay for one second                                                      
                      myservo.write(180); // Set/Turn servo at 180 Degrees position                
                      delay(1000); // Delay for one second 
                      Right(); // Call Function 
                      delay(1000);
                      Forward();
                      break; // Tell Arduino to go on
     case 0xFF22DD: // case 4: Left button pressed, code of Left button is FF22DD
                      myservo.write(90);  // Set/Turn servo at 90 Degrees position           
                      delay(1000); // Delay for one second                                                      
                      myservo.write(180); // Set/Turn servo at 180 Degrees position                
                      delay(1000); // Delay for one second 
                      Left(); // Call Function 
                      delay(1000);
                      Forward(); 
                      break; // Tell Arduino to go on
     case 0xFF02FD: // case 4: Stop button pressed, code of Stop button is FF02FD                               
                      myservo.write(10); // Set/Turn servo at 10 Degrees position
                      delay(100); // Delay for one second  
                      Stop(); // Call Function 
                      break; // Tell Arduino to go on
      
    } // End of cases
    
      irrecv.resume(); // Receive the next value
      
  } // End of "if"
 
  
} // End of loop

void Forward (){ // Function to go Forward 
  digitalWrite(MotorA,1); // Set motorA to 1 to turn on
  digitalWrite(MotorB,1); // Set motorB as High to turn on
  analogWrite(Motor_SpeedA,100); // Set motorspeedA to 100
  analogWrite(Motor_SpeedB,100); // Set motorspeedB to 100
}

void Backward (){ // Function to go Backward
  digitalWrite(MotorA,0); // Set motorA to 0 to turn off
  digitalWrite(MotorB,0); // Set motorA to 0 to turn off
  analogWrite(Motor_SpeedA,100); // Set motorspeedA to 100
  analogWrite(Motor_SpeedB,100); // Set motorspeedB to 100 
}

void Left (){ // Function to go Left
  digitalWrite(MotorA,1); // Set motorA to 1 to turn on
  digitalWrite(MotorB,0); // Set motorA to 0 to turn off
  analogWrite(Motor_SpeedA,100); // Set motorspeedA to 100
  analogWrite(Motor_SpeedB,100); // Set motorspeedB to 100
}

void Right (){ // Function to go Right
  digitalWrite(MotorA,0); // Set motorA to 0 to turn off
  digitalWrite(MotorB,1); // Set motorB to 1 to turn on
  analogWrite(Motor_SpeedA,100); // Set motorspeedA to 100
  analogWrite(Motor_SpeedB,100); // Set motorspeedB to 100
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
