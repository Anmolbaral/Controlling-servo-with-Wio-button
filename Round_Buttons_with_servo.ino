#include "Servo.h"
Servo myservo1;


int pos = 0;
void setup() {
  Serial.begin(115200);
  myservo1.attach(D1);
  pinMode(WIO_5S_UP, INPUT);
  pinMode(WIO_5S_DOWN,INPUT);
  pinMode(WIO_5S_LEFT,INPUT);
  pinMode(WIO_5S_RIGHT,INPUT);
  pinMode(WIO_5S_PRESS, INPUT);
  pinMode(WIO_KEY_A, INPUT);
  pinMode(WIO_KEY_B, INPUT);
  pinMode(WIO_KEY_C, INPUT);
}

void loop() {
  if(digitalRead(WIO_5S_LEFT) == LOW) {
    pos = pos-1 ;
    myservo1.write(pos);
    
    delay(100);
    pos = max(0, min(pos,180));
    Serial.println(pos);
  }
   else if(digitalRead(WIO_5S_RIGHT) == LOW) {
     pos=pos+1 ;
     myservo1.write(pos);
     
     delay(100);
     pos = max(0, min(pos,180));
     Serial.println(pos);
  }
 
}

