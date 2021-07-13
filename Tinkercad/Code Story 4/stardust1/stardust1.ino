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


void loop()
{
  forwards();
  
  if (leftcounter >= 870){ 
    stop();
    delay(200000000);
    leftcounter = 0;
  }
  
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

void forwards(){
  digitalWrite(FWDRIGHT, HIGH);				
  digitalWrite(ENABLERIGHT, HIGH);		
  digitalWrite(ENABLELEFT, HIGH);			
  digitalWrite(FWDLEFT, HIGH);
  digitalWrite(REVRIGHT, LOW);
  digitalWrite(REVLEFT, LOW);
}

void reverse(){
  digitalWrite(ENABLERIGHT, HIGH);
  digitalWrite(ENABLELEFT, HIGH);			
  digitalWrite(REVRIGHT, HIGH);				
  digitalWrite(REVLEFT, HIGH);	
  digitalWrite(FWDLEFT, LOW);
  digitalWrite(FWDRIGHT, LOW);
}

void stop(){
  digitalWrite(FWDRIGHT, LOW);				
  digitalWrite(ENABLERIGHT, LOW);			
  digitalWrite(ENABLELEFT, LOW);			
  digitalWrite(FWDLEFT, LOW);
  digitalWrite(REVRIGHT, LOW);
  digitalWrite(REVLEFT, LOW);
}
  
