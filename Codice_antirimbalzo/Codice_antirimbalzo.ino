
#define DEBOUNCE_TIME  20   //mSec

#define INPUT_PIN   2
#define OUT_PIN     6

#define DEBOUNCE



void setup() 
{
  pinMode(INPUT_PIN,INPUT);
  pinMode(OUT_PIN, OUTPUT);
  Serial.begin(9600);
  
}

void loop() 
{
  uint8_t inp_val = 0;

#ifndef DEBOUNCE
  inp_val = digitalRead(INPUT_PIN);
 #endif

 #ifdef DEBOUNCE 
  inp_val = read_pin(INPUT_PIN);
 #endif 
  
  digitalWrite(OUT_PIN, inp_val);
    
}


uint8_t read_pin(uint8_t pin)
{
   uint8_t val = 0;
   unsigned long time = 0;
   uint8_t switch_flag = 0;
   
  if(digitalRead(pin) == 1)
  {
    time = millis();
    while((millis() - time) < DEBOUNCE_TIME);
    val = digitalRead(pin);
  }
  else
    val = 0; 
 
 return val;   
}



