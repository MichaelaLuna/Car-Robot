/*
 * 
 */
 
#define MotorA 7 //A1N1
#define MotorB 8 //B1N1
#define Motor_SpeedA 5 //PWMA
#define Motor_SpeedB 6 //PWMB
#define EnablePin 3




void setup() { // put your setup code here, to run once:
  for(int i=1; i<9; i++){
     pinMode(i, OUTPUT);
  }
  pinMode(EnablePin, OUTPUT);
}

void loop() { // put your main code here, to run repeatedly:
  digitalWrite(EnablePin, HIGH);
  Stop();
  delay(3000); 
}

void Forward (){ //
  digitalWrite(MotorA,1);
  digitalWrite(MotorB,1);
  analogWrite(Motor_SpeedA,255);
  analogWrite(Motor_SpeedB,255);  
}

void Backward (){ //
  digitalWrite(MotorA,0);
  digitalWrite(MotorB,0);
  analogWrite(Motor_SpeedA,255);
  analogWrite(Motor_SpeedB,255);  
}

void Left (){//
  digitalWrite(MotorA,1);
  digitalWrite(MotorB,0);
  analogWrite(Motor_SpeedA,255);
  analogWrite(Motor_SpeedB,255);  
}

void Right (){ //
  digitalWrite(MotorA,0);
  digitalWrite(MotorB,1);
  analogWrite(Motor_SpeedA,255);
  analogWrite(Motor_SpeedB,255);  
}

void LFW () { //
  digitalWrite(MotorA,1);
  digitalWrite(MotorB,1);
  analogWrite(Motor_SpeedA,255);
  analogWrite(Motor_SpeedB,126);  
}

void LBK (){ //
  digitalWrite(MotorA,0);
  digitalWrite(MotorB,0);
  analogWrite(Motor_SpeedA,255);
  analogWrite(Motor_SpeedB,126);  
}

void RFW (){ //
  digitalWrite(MotorA,1);
  digitalWrite(MotorB,1);
  analogWrite(Motor_SpeedA,126);
  analogWrite(Motor_SpeedB,255);  
}

void RBK (){ //
  digitalWrite(MotorA,0);
  digitalWrite(MotorB,0);
  analogWrite(Motor_SpeedA,126);
  analogWrite(Motor_SpeedB,255);  
}

void Stop (){ //
  digitalWrite(MotorA,1);
  digitalWrite(MotorB,1);
  analogWrite(Motor_SpeedA,0);
  analogWrite(Motor_SpeedB,0);  
}
