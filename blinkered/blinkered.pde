
#define FIRST 5
#define LAST 13

#define ON HIGH
#define OFF LOW

void setup() {
  pinMode(STOP, OUTPUT);
  pinMode(CAUTION, OUTPUT);
  pinMode(GO, OUTPUT);
}

void randomWrite(int min, int max, int delayms) {

  int led = random(min,max+1);
  
  for (int i=min; i <= max; i++) {
    
    digitalWrite(i, (i==led) ? ON : OFF);

  }
  
  delay(delayms);

}
  
void loop() {
  
  randomWrite(FIRST, LAST, 50);
    
}


