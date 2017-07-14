#ifndef IRCTRL
#define IRCTRL
#include <IRsend.h>
#include "variables.h"


namespace irController{

  IRsend irsend(IRLED);
  
  inline void sendCommand(int brand, unsigned long data, int bits){

  if(brand == 1){
      irsend.sendNEC(data, bits);
      delay(300);
  }else if(brand == 2){
      irsend.sendSony(data,bits,2);
      delay(300);
  }else if(brand == 3){
    irsend.sendSAMSUNG(data,bits);
    delay(300);
  }else if(brand == 4){
    irsend.sendSharp(data,bits);
  }else {
    //do something else
  }
  
  }
}



#endif
