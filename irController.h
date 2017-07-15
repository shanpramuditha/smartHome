#ifndef IRCTRL
#define IRCTRL
#include <IRsend.h>
#include "variables.h"


namespace irController{

  IRsend irsend(IRLED);
  
  inline void sendCommand(int brand, unsigned long command){

  if(brand == 1){
      irsend.sendNEC(ACCODES[brand][command], 42,3);
      delay(300);
  }else if(brand == 2){
      irsend.sendSony(ACCODES[brand][command],24,3);
      delay(300);
  }else if(brand == 3){
    irsend.sendSAMSUNG(ACCODES[brand][command],12,3);
    delay(300);
  }else if(brand == 4){
    irsend.sendLG(ACCODES[brand][command],32,3);
  }else {
    //do something else
  }
  
  }
}



#endif
