
/* The Car Robot kit has its own ultrasonic sensor that acts as its eyes. It is a navigation tool 
 * that can measure distances using sound waves. By creating this program, I managed to set it 
 * as the eye of my Car Robot that adjusted it to move without getting hit by any obstacle.
 */

 
#include <Servo.h> // Include the library for the servo
Servo myservo; // Set servo as an object to control the servo

int echoPin = 12; // Echo pin of the ultrasonic connected to pin 12 of arduino
int trigPin = 13; // Trig pin of the ultrasonic connected to pin 13 of arduino
int middleD = 0, rightD = 0, leftD = 0; // Set value from middleD, rightD and leftD as an integer

#define MotorA 7 // Initialize motor A1N1 to pin 7 of arduino
#define MotorB 8 // Initialize motor B1N1 to pin 8 of arduino
#define Motor_SpeedA 5 // Initialize motor PWMA to pin 5 of arduino
#define Motor_SpeedB 6 // Initialize motor PWMB to pin 6 of arduino
#define EnablePin 3 // Set pin 3 of arduino as the EnablePin, ("Stby")

void Forward (){ // Function to go Forward 
  digitalWrite(MotorA,1); // Set motorA to 1 to turn on
  digitalWrite(MotorB,1); // Set motorB as High to turn on
  analogWrite(Motor_SpeedA,70); // Set motorspeedA to 70
  analogWrite(Motor_SpeedB,70); // Set motorspeedB to 70
  digitalWrite(EnablePin,HIGH); // Set enable pin ("Stby") as 1 to turn on
}

void Backward (){ // Function to go Backward
  digitalWrite(MotorA,0); // Set motorA to 0 to turn off
  digitalWrite(MotorB,0); // Set motorB to 0 to turn off
  analogWrite(Motor_SpeedA,70); // Set motorspeedA to 70
  analogWrite(Motor_SpeedB,70); // Set motorspeedB to 70 
  digitalWrite(EnablePin,HIGH); // Set enable pin ("Stby") as 1 to turn on
}

void Left (){ // Function to go Left
  digitalWrite(MotorA,1); // Set motorA to 1 to turn on
  digitalWrite(MotorB,0); // Set motorA to 0 to turn off
  analogWrite(Motor_SpeedA,70); // Set motorspeedA to 70
  analogWrite(Motor_SpeedB,70); // Set motorspeedB to 70
  digitalWrite(EnablePin,HIGH); // Set enable pin ("Stby") as 1 to turn on
}

void Right (){ // Function to go Right
  digitalWrite(MotorA,0); // Set motorA to 0 to turn off
  digitalWrite(MotorB,1); // Set motorB to 1 to turn on
  analogWrite(Motor_SpeedA,70); // Set motorspeedA to 70
  analogWrite(Motor_SpeedB,70); // Set motorspeedB to 70
  digitalWrite(EnablePin,HIGH); // Set enable pin ("Stby") as 1 to turn on
}

void LFW () { // Function to go Left Forward
  digitalWrite(MotorA,1); // Set motorA to 1 to turn on
  digitalWrite(MotorB,1); // Set motorB to 1 to turn on
  analogWrite(Motor_SpeedA,255); // Set motorspeedA to 255
  analogWrite(Motor_SpeedB,126); // Set motorspeedB to 126
  digitalWrite(EnablePin,HIGH); // Set enable pin ("Stby") as 1 to turn on
}

void LBK (){ // Function to go Left Backward
  digitalWrite(MotorA,0); // Set motorA to 0 to turn off
  digitalWrite(MotorB,0); // Set motorB to 0 to turn off
  analogWrite(Motor_SpeedA,255); // Set motorspeedA to 255
  analogWrite(Motor_SpeedB,126); // Set motorspeedB to 126
  digitalWrite(EnablePin,HIGH); // Set enable pin ("Stby") as 1 to turn on
}

void RFW (){ // Function to go Right Forward
  digitalWrite(MotorA,1); // Set motorA to 1 to turn on
  digitalWrite(MotorB,1); // Set motorB to 1 to turn on
  analogWrite(Motor_SpeedA,126); // Set motorspeedA to 126
  analogWrite(Motor_SpeedB,255); // Set motorspeedB to 255
  digitalWrite(EnablePin,HIGH); // Set enable pin ("Stby") as 1 to turn on
  
}

  void RBK (){ // Function to go Right Backward
  digitalWrite(MotorA,0); // Set motorA to 0 to turn off
  digitalWrite(MotorB,0); // Set motorB to 0 to turn off
  analogWrite(Motor_SpeedA,126); // Set motorspeedA to 126
  analogWrite(Motor_SpeedB,255); // Set motorspeedB to 255
  digitalWrite(EnablePin,HIGH); // Set enable pin ("Stby") as 1 to turn on
  
}

void Stop (){ // Function to go Stop
  digitalWrite(MotorA,1); // Set motorA to 1 to turn on
  digitalWrite(MotorB,1); // Set motorB to 1 to turn on
  analogWrite(Motor_SpeedA,0); // Set motorspeedA to 0
  analogWrite(Motor_SpeedB,0); // Set motorspeedB to 0
  digitalWrite(EnablePin,HIGH); // Set enable pin ("Stby") as 1 to turn on
  
}

int distanceComputation() { // Computation for the distance
  digitalWrite(trigPin, LOW); // Turn off trigpin
  delayMicroseconds(2); // Delay for 2 microseconds
  digitalWrite(trigPin, HIGH);  
  delayMicroseconds(10); // Delay for 10 microseconds
  digitalWrite(trigPin, LOW); // Turn off trigpin
    
  float distanceMeasurement = pulseIn(echoPin, HIGH); // Set distance measurement equal to the pulseIn echopin turned on
  distanceMeasurement = distanceMeasurement / 58; // Distance measurement equal to distance measurement but divided by 58, in order to get value on cm  
  return (int)distanceMeasurement; // Return to distance measurement
}  

void setup() { // Run the code once
  
  for(int i=1; i<9; i++){ // Setup the pins 
     pinMode(i, OUTPUT); // Set these pins as an output
  }
  
  pinMode(EnablePin, OUTPUT); // Set the enable pin ("Stby") as an ouput
  
  myservo.attach(11); // Signal pin of servo connected to pin 11 of arduino
  
  pinMode(echoPin, INPUT); // Set the echo pin as an input
  pinMode(trigPin, OUTPUT); // Set the trig pin as an output
  
  Stop(); // Tell the Car Robot not to move yet
}

void loop() { //Run code on loop
  
 myservo.write(90);  // Set/Turn servo at 90 Degrees position
    delay(300); // Delay for 300ms
    
    middleD = distanceComputation(); // Set the two to have equal values
 
    if(middleD <= 15) { // If value of middleD is lower than or equal 15:   
      Stop(); // Stop the Car Robot
      delay(300); // Delay for 300ms                   
      myservo.write(10); // Set/Turn servo at 10 Degrees position
      delay(1000); // Delay for one second    
       
      rightD = distanceComputation(); // Set the two to have equal values
      
      delay(300); // Delay for 500ms  
      myservo.write(90);  // Set/Turn servo at 90 Degrees position           
      delay(1000); // Delay for one second                                                      
      myservo.write(180); // Set/Turn servo at 180 Degrees position                
      delay(1000); // Delay for one second    
      
      leftD = distanceComputation(); // Set the two to have equal values
      
      delay(300); // Delay for 300ms  
      myservo.write(90); // Set/Turn servo at 90 Degrees position                  
      delay(1000); // Delay for one second    
      
      if(rightD > leftD) { // If value of right distance is greater than left distance then:
        Right(); // Turn right
        delay(350); // Delay for 300ms 
      }
      else if(rightD < leftD) {
        Left(); // Turn left
        delay(350); // Delay for 300ms 
      }
      else if((rightD <= 15) || (leftD <= 15)) {
        Backward(); // Turn backward
        delay(175); // Delay for 150ms 
      }
      else { // If that's not the case:
        Forward(); // Go forward
      }
        }
      else { // If that's not the case:
        Forward(); // Go forward
       }
} // End of loop
