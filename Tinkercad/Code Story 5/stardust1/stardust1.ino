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

void setup()
{
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
  
  doZigzag();
  
}

void LeftMotorISR(){
  leftcounter++;
  Serial.print("Left counter: ");
  Serial.println(leftcounter);
  if(leftcounter == 10){
    Serial.println("Left counter has reached 10!");
  }
  
}						//adds one to the counter on each motor revolution

void RightMotorISR(){ 
  rightcounter++;		//adds one to the counter on each motor revolution
  Serial.print("Right counter: ");
  Serial.println(rightcounter);
  if(rightcounter == 10){
    Serial.println("Right counter has reached 10!");
  }
}

void turnleft(){
  analogWrite(ENABLELEFT, 150);		//Left Angle
  analogWrite(ENABLERIGHT, 0);		//Right Angle
}

void turnright(){
  analogWrite(ENABLELEFT, 0);		//Left Angle
  analogWrite(ENABLERIGHT, 150);	//Right Angle
}

void forwards(){
  digitalWrite(FWDRIGHT, HIGH);				
  analogWrite(ENABLERIGHT, 200);		
  analogWrite(ENABLELEFT, 200);			
  digitalWrite(FWDLEFT, HIGH);  
  digitalWrite(REVRIGHT, LOW);
  digitalWrite(REVLEFT, LOW);
}

void reverse(){
  digitalWrite(ENABLERIGHT, HIGH);
  digitalWrite(ENABLELEFT, 200);			
  digitalWrite(REVRIGHT, 200);				
  digitalWrite(REVLEFT, HIGH);	
  digitalWrite(FWDLEFT, LOW);
  digitalWrite(FWDRIGHT, LOW);
}

void stop(){
  digitalWrite(FWDRIGHT, LOW);				
  analogWrite(ENABLERIGHT, 0);			
  analogWrite(ENABLELEFT, 0);			
  digitalWrite(FWDLEFT, LOW);
  digitalWrite(REVRIGHT, LOW);
  digitalWrite(REVLEFT, LOW);
}

void doZigzag(){
  turnleft();
  delay(1000);
  
  stop();
  delay(1000);
  
  forwards();
  delay(2000);
  
  stop();
  delay(1000);
  
  turnright();
  delay(1000);
  
  stop();
  delay(1000);
  
  forwards();
  delay(2000);
  
  stop();
  delay(2000);
  
  zigzagcounter++;
}
