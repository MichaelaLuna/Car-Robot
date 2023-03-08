/* This program is for the Car Robot to go around a table but with values 
 * base on real life measurements taken from a class.
 */
 
#define MotorA 7 // Initialize motor A1N1 to pin 7 of arduino
#define MotorB 8 // Initialize motor B1N1 to pin 8 of arduino
#define Motor_SpeedA 5 // Initialize motor PWMA to pin 5 of arduino
#define Motor_SpeedB 6 // Initialize motor PWMB to pin 6 of arduino
#define EnablePin 3 // Set pin 3 of arduino as the EnablePin, ("Stby")


void setup() { // Run the code once
  for(int i=1; i<9; i++){ // Setup the pins 
     pinMode(i, OUTPUT); // Set these pins as an output
  }
 pinMode(EnablePin, OUTPUT); // Set the enable pin ("Stby") as an ouput
}

void loop() { // Run the code on loop
  digitalWrite(EnablePin,HIGH); // Set enable pin ("Stby") as 1 to turn on
  Stop(); // Call the function Stop to stop the Car
  delay(3000); // Delay for 3secs
  Forward(); // Call the function Forward to go forward
  delay(5000); // Delay for 5secs
  Stop(); // Call the function Stop to stop the Car
  delay (1000); // Delay for 1sec
  Right(); // Call the function Right to go right
  delay(200); // Delay for 200ms
  Forward(); // Call the function Forward to go forward
  delay(2000); // Delay for 2secs
  Stop(); // Call the function Stop to stop the Car
  delay(1000); // Delay for 1sec
  Right(); // Call the function Right to go right
  delay(250); // Delay for 250ms
  Forward(); // Call the function Forward to go forward
  delay(5500); // Delay for 5secs and 500ms
  Stop(); // Call the function Stop to stop the Car
  delay(1000); // Delay for 1sec
  Right(); // Call the function Right to go right
  delay(250); // Delay for 250ms
  Forward(); // Call the function Forward to go forward
  delay(3500); // Delay for 3secs and 500ms
  Stop(); // Call the function Stop to stop the Car
  delay(1000); // Delay for 1sec
  Right(); // Call the function Right to go right
  delay(300); // Delay for 300ms
  Forward(); // Call the function Forward to go forward
  delay(1000);  // Delay for 1sec

} // End loop

void Forward (){ // Function to go Forward 
  digitalWrite(MotorA,1); // Set motorA to 1 to turn on
  digitalWrite(MotorB,1); // Set motorB as High to turn on
  analogWrite(Motor_SpeedA,170); // Set motorspeedA to 170
  analogWrite(Motor_SpeedB,170); // Set motorspeedB to 170
}

void Backward (){ // Function to go Backward
  digitalWrite(MotorA,0); // Set motorA to 0 to turn off
  digitalWrite(MotorB,0); // Set motorB to 0 to turn off
  analogWrite(Motor_SpeedA,255); // Set motorspeedA to 255
  analogWrite(Motor_SpeedB,255); // Set motorspeedB to 255
}

void Left (){ // Function to go Backward
  digitalWrite(MotorA,1); // Set motorA to 1 to turn on
  digitalWrite(MotorB,0); // Set motorB to 0 to turn off
  analogWrite(Motor_SpeedA,255); // Set motorspeedA to 255
  analogWrite(Motor_SpeedB,255); // Set motorspeedB to 255
}

void Right (){ // Function to go Right
  digitalWrite(MotorA,0); // Set motorA to 0 to turn off
  digitalWrite(MotorB,1); // Set motorB to 1 to turn on
  analogWrite(Motor_SpeedA,170); // Set motorspeedA to 170
  analogWrite(Motor_SpeedB,170); // Set motorspeedB to 170
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
