/* The Car Robot from ELEGOO kit has its own remote on the kit already programmed by the
 * creators of it. By this program I created, I was able to use the Infrared remote to control
 * the Car Robot using specifically the buttons that I want and made these respond the way I 
 * programmed it to. 
*/

#include <IRremote.h> // Include the library for the IRremote

int receiver = 9; // Set pin 9 as the receiver 

#define MotorA 7 // Initialize motor A1N1 to pin 7 of arduino
#define MotorB 8 // Initialize motor B1N1 to pin 8 of arduino
#define Motor_SpeedA 5 // Initialize motor PWMA to pin 5 of arduino
#define Motor_SpeedB 6 // Initialize motor PWMB to pin 6 of arduino
#define EnablePin 3 // Set pin 3 of arduino as the EnablePin, ("Stby")


IRrecv irrecv(receiver); // Create the receiver object; I chose 'irrecv'
decode_results results; // Decode Xresults from the IRremote; 


void setup() { // Run the code once
  
  irrecv.enableIRIn(); // Start the receiver
  
  for(int i=1; i<9; i++){ // Setup the pins 
     pinMode(i, OUTPUT); // Set these pins as an output
  }
  pinMode(EnablePin, OUTPUT); // Set the enable pin ("Stby") as an ouput
}


void loop() { // Run the code on loop
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
                      Right(); // Call Function 
                      delay(1000);
                      Forward();
                      break; // Tell Arduino to go on
     case 0xFF22DD: // case 4: Left button pressed, code of Left button is FF22DD
                      Left(); // Call Function 
                      delay(1000);
                      Forward(); 
                      break; // Tell Arduino to go on
     case 0xFF02FD: // case 4: Stop button pressed, code of Stop button is FF02FD
                      Stop(); // Call Function 
                      break; // Tell Arduino to go on
      
    }
    
      irrecv.resume(); // Receive the next value
  }
 
  
} // End of loop

void Forward (){ // Function to go Forward 
  digitalWrite(MotorA,1); // Set motorA to 1 to turn on
  digitalWrite(MotorB,1); // Set motorB as High to turn on
  analogWrite(Motor_SpeedA,100); // Set motorspeedA to 100
  analogWrite(Motor_SpeedB,100); // Set motorspeedB to 100
}

void Backward (){ // Function to go Backward
  digitalWrite(MotorA,0); // Set motorA to 0 to turn off
  digitalWrite(MotorB,0); // Set motorB to 0 to turn off
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
