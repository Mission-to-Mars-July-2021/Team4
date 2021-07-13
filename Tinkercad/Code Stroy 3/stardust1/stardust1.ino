const int FWDRIGHT = 12;
const int REVRIGHT = 11;
const int ENABLERIGHT = 10;
const int ENABLELEFT = 9;
const int FWDLEFT = 8; 
const int REVLEFT = 7;

void setup()
{
  pinMode(FWDRIGHT, OUTPUT);
  pinMode(REVRIGHT, OUTPUT);
  pinMode(ENABLERIGHT, OUTPUT);
  pinMode(ENABLELEFT, OUTPUT);
  pinMode(FWDLEFT, OUTPUT);
  pinMode(REVLEFT, OUTPUT);
}
void loop(){
  
  forwards();			
  delay(5000);
  
  stop();
  delay(1000);
  
  reverse();
  delay(2000);
  
  stop();
}

void forwards(){
  digitalWrite(FWDRIGHT, HIGH);				
  digitalWrite(ENABLERIGHT, HIGH);		
  digitalWrite(ENABLELEFT, HIGH);			
  digitalWrite(FWDLEFT, HIGH);
}

void reverse(){
  digitalWrite(ENABLERIGHT, HIGH);
  digitalWrite(ENABLELEFT, HIGH);			
  digitalWrite(REVRIGHT, HIGH);				
  digitalWrite(REVLEFT, HIGH);	
}

void stop(){
  digitalWrite(FWDRIGHT, LOW);				
  digitalWrite(ENABLERIGHT, LOW);			
  digitalWrite(ENABLELEFT, LOW);			
  digitalWrite(FWDLEFT, LOW);
  digitalWrite(REVRIGHT, LOW);
  digitalWrite(REVLEFT,LOW);
}
