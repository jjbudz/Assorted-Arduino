
#define RED 13
#define YELLOW 12
#define GREEN 11

#define ON HIGH
#define OFF LOW

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  
  int delayms = 200;
  
  digitalWrite(RED, ON);
  digitalWrite(YELLOW, OFF);
  digitalWrite(GREEN, OFF);  

  delay(delayms);

  digitalWrite(RED, OFF);
  digitalWrite(YELLOW, ON);
  digitalWrite(GREEN, OFF);  
  
  delay(delayms);

  digitalWrite(RED, OFF);
  digitalWrite(YELLOW, OFF);
  digitalWrite(GREEN, ON);

  delay(delayms);  
  
}


