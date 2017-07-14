#ifndef BULBCTRL
#define BULBCTRL
#include "variables.h"

namespace bulbController{

inline void toggleRelay() {
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, !digitalRead(RELAY));
}

inline void onRelay() {
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, 1);
}

inline void offRelay() {
  Serial.println(digitalRead(RELAY));
  
  Serial.println(!digitalRead(RELAY));
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, 0);
  
  Serial.println(digitalRead(RELAY));
}

  inline void setRelay(bool b){
    pinMode(RELAY, OUTPUT);
    digitalWrite(RELAY,b);
  }

   inline void beep(){
    pinMode(BUZZ, OUTPUT);
    digitalWrite(BUZZ, HIGH);
    delay(1000);
    digitalWrite(BUZZ,LOW);
   }
}

#endif

