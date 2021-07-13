void setup()
{
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  digitalWrite(12, HIGH);	//Pin 12 High
  digitalWrite(10, HIGH);	//Pin 10 High
  digitalWrite(9, HIGH);	//Pin 9 High
  digitalWrite(8, HIGH);	//Pin 8 High
  delay(5000);				//Delay of 5 secconds
  digitalWrite(12, LOW);	//Pin 12 Low
  digitalWrite(10, LOW);	//Pin 10 Low
  digitalWrite(9, LOW);		//Pin 9 Low
  digitalWrite(8, LOW);		//Pin 8 Low
  delay(1000);				//Delay of 1 seccond
  digitalWrite(10, HIGH);	//Pin 10 High
  digitalWrite(9, HIGH);	//Pin 9 High
  digitalWrite(11, HIGH);	//Pin 11 High
  digitalWrite(7, HIGH);	//Pin 7 High
  delay(2000);				//Delay of secconds
  digitalWrite(10, LOW);	//Pin 10 Low
  digitalWrite(9, LOW);		//Pin 9 Low
  digitalWrite(11, LOW);	//Pin 11 Low
  digitalWrite(7, LOW);		//Pin 7 Low
  delay(2000);				//Delay of 2 secconds
} 



