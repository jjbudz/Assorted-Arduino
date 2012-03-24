
#define FIRST 0
#define LAST 13

#define ON HIGH
#define OFF LOW

void setup() {
  
  for (int i=FIRST; i <= LAST; i++) {
    
    pinMode(i, OUTPUT);

  }

}

void off() {

  for (int i=FIRST; i <= LAST; i++) {
    
    digitalWrite(i, OFF);

  }
  
}

void greens() {
  
  digitalWrite(13, ON);
  digitalWrite(10, ON);
  digitalWrite(7, ON);
  digitalWrite(4, ON);
  
  
}

void yellows() {

  digitalWrite(12, ON);
  digitalWrite(9, ON);
  digitalWrite(6, ON);
  digitalWrite(3, ON);
  
}

void reds() {
  
  digitalWrite(11, ON);
  digitalWrite(8, ON);
  digitalWrite(5, ON);
  digitalWrite(2, ON);

}
  
void loop() {
  
  int delayms = 50;
  
  for (int i=FIRST; i <= LAST; i++) {
    
    off();
    digitalWrite(i, ON);
    delay(delayms);

  }
  
}


