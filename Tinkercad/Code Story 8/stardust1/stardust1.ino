const int FWDRIGHT = 7;
const int REVRIGHT = 8;
const int ENABLERIGHT = 9;
const int ENABLELEFT = 10;
const int FWDLEFT = 11; 
const int REVLEFT = 12;

const int LEFT_FEEDBACK = 3;
const int RIGHT_FEEDBACK = 2;

volatile int leftcounter = 0;
volatile int rightcounter = 0;

volatile int zigzagcounter = 0;

int boxloop = 0;

void setup(){
  
  pinMode(FWDRIGHT, OUTPUT);
  pinMode(REVRIGHT, OUTPUT);
  pinMode(ENABLERIGHT, OUTPUT);
  pinMode(ENABLELEFT, OUTPUT);
  pinMode(FWDLEFT, OUTPUT);
  pinMode(REVLEFT, OUTPUT);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK), LeftMotorISR, RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK), RightMotorISR, RISING);
  
}

void loop(){
  doBox(3);
  exit(0);
}

void LeftMotorISR(){
  leftcounter++;
  Serial.print("\nLeft counter: ");
  Serial.println(leftcounter);
  if(leftcounter == 10){
    Serial.println("Left counter has reached 10!");
  }
}  

void RightMotorISR(){ 
  rightcounter++;		//adds one to the counter on each motor revolution
  Serial.print("\nRight counter: ");
  Serial.println(rightcounter);
  if(rightcounter == 10){
    Serial.println("Right counter has reached 10!");
  }
}

void forwardsturnleft(){
  analogWrite(ENABLELEFT, 200);		//Left Angle
  analogWrite(ENABLERIGHT, 60);		//Right Angle
  digitalWrite(FWDLEFT, HIGH);
  digitalWrite(FWDRIGHT, HIGH);
  digitalWrite(REVRIGHT, LOW);
  digitalWrite(REVLEFT, LOW);
  
  //This Will Move The Left to 200 analog and 80 on the Right
}
void forwardsturnright(){
  analogWrite(ENABLELEFT, 60);		//Left Angle
  analogWrite(ENABLERIGHT, 200);	//Right Angle
  digitalWrite(FWDLEFT, HIGH);
  digitalWrite(FWDRIGHT, HIGH);
  digitalWrite(REVRIGHT, LOW);
  digitalWrite(REVLEFT, LOW);
}

void forwards(int SPEED){
  analogWrite(ENABLELEFT, SPEED);	
  analogWrite(ENABLERIGHT, SPEED);		
  digitalWrite(FWDLEFT, HIGH);
  digitalWrite(FWDRIGHT, HIGH);
  digitalWrite(REVRIGHT, LOW);
  digitalWrite(REVLEFT, LOW);
}

void reverse(){
  analogWrite(ENABLELEFT, 100);
  analogWrite(ENABLERIGHT, 100);		
  digitalWrite(REVRIGHT, HIGH);				
  digitalWrite(REVLEFT, HIGH);	
  digitalWrite(FWDLEFT, LOW);
  digitalWrite(FWDRIGHT, LOW);
}

void stop(){
  analogWrite(ENABLELEFT, 0);
  analogWrite(ENABLERIGHT, 0);			
  digitalWrite(FWDLEFT, LOW);
  digitalWrite(FWDRIGHT, LOW);
  digitalWrite(REVLEFT, LOW);
  digitalWrite(REVRIGHT, LOW);

}

void turnleft(int SPEED){
  analogWrite(ENABLELEFT, SPEED);	
  analogWrite(ENABLERIGHT, SPEED);		
  digitalWrite(FWDLEFT, LOW);
  digitalWrite(FWDRIGHT, HIGH);
  digitalWrite(REVRIGHT, LOW);
  digitalWrite(REVLEFT, HIGH);
}

void turnright(int SPEED){
  analogWrite(ENABLELEFT, SPEED);	
  analogWrite(ENABLERIGHT, SPEED);		
  digitalWrite(FWDLEFT, HIGH);
  digitalWrite(FWDRIGHT, LOW);
  digitalWrite(REVRIGHT, HIGH);
  digitalWrite(REVLEFT, LOW);
}

void doZigzag(){
  forwardsturnleft();
  delay(2000);
  
  forwards(100);
  delay(3000);
  
  forwardsturnright();
  delay(2000);
  forwards(100);
  delay(3000);
  
  zigzagcounter++;
}

void forwardcheck(int CHECKSPEED){
  if (rightcounter < leftcounter){
    Serial.println("Moving right tyre to balance...");
    analogWrite(ENABLERIGHT, CHECKSPEED + 20);

  } else if (rightcounter > leftcounter){
    Serial.println("Moving left tyre to balance...");
    analogWrite(ENABLELEFT, CHECKSPEED + 20);

  } else if (leftcounter < CHECKSPEED) {
    analogWrite(ENABLELEFT, CHECKSPEED);

  } else if (rightcounter < CHECKSPEED) {
    analogWrite(ENABLERIGHT, CHECKSPEED);

  } else {
    Serial.println("Continuing...");
  }
}

void doBox(int DIRECTION){
  if (DIRECTION == 1){
    while (boxloop != 4){
      forwards(150);				//Movesforward at the speed of 150
      delay(100);
      forwardcheck(150);			//Checks the counters at the speed of 150

      if (leftcounter >= 172){	//Checks the left counter for 172 clicks
        stop();
        delay(1000);

        turnleft(200);			//Angle
        delay(850);

        stop();
        delay(1000);

        leftcounter = 0;
        boxloop++;
      }
    }
    
  } else if (DIRECTION == 2){
    
    while (boxloop != 4){
      forwards(150);				//Movesforward at the speed of 150
      delay(1000);
      forwardcheck(150);			//Checks the counters at the speed of 150

      if (leftcounter >= 172){	//Checks the left counter for 172 clicks
        stop();
        delay(1000);

        turnright(200);			//Angle
        delay(850);

        stop();
        delay(1000);

        leftcounter = 0;
        boxloop++;
      }
    }
  } else if (DIRECTION == 3){
    
    while (boxloop != 4){
      forwards(150);				//Movesforward at the speed of 150
      delay(1000);
      forwardcheck(150);			//Checks the counters at the speed of 150

      if (leftcounter >= 172){	//Checks the left counter for 172 clicks
        stop();
        delay(1000);

        turnleft(200);			//Angle
        delay(850);

        stop();
        delay(1000);

        leftcounter = 0;
        boxloop++;
      }
    }
    
    boxloop = 0;
    
    while (boxloop != 4){
      forwards(150);				//Movesforward at the speed of 150
      delay(1000);
      forwardcheck(150);			//Checks the counters at the speed of 150

      if (rightcounter >= 172){		//Checks the left counter for 172 clicks
        stop();
        delay(1000);

        turnright(200);				//Angle
        delay(950);

        stop();
        delay(1000);

        leftcounter = 0;
        boxloop++;
      }
    }
  }
    
  stop();
  exit(0);
  
}