#ifndef requestController
#define requestController

#include "variables.h"
#include "irController.h"
#include "wifiController.h"

namespace requestController{

inline void commandAnalyzer(char cmd[]){
      
      Serial.println(cmd);
      if(isEqual(cmd,"/BULB/ON")){
        Serial.println("red");
      }else if(isEqual(cmd,"/BULB/OFF")){
        Serial.println("blue");
      }
      }else if(isEqual(cmd,"/AC/NEC/ON")){
        irController::sendCommand(1,1);//command have to be replaced
      }
      }else if(isEqual(cmd,"/AC/NEC/OFF")){
        irController::sendCommand(1,0);//command have to be replaced
      }
      }else if(isEqual(cmd,"/AC/SONY/ON")){
        irController::sendCommand(2,1);//command have to be replaced
      }
      }else if(isEqual(cmd,"/AC/SONY/OFF")){
        irController::sendCommand(2,0);//command have to be replaced
      }
      }else if(isEqual(cmd,"/AC/SAMSUNG/ON")){
        irController::sendCommand(3,1);//command have to be replaced
      }
      }else if(isEqual(cmd,"/AC/SAMSUNG/OFF")){
        irController::sendCommand(3,0);//command have to be replaced
      }
      }else if(isEqual(cmd,"/AC/SHARP/ON")){
        irController::sendCommand(4,1);//command have to be replaced
      }
      }else if(isEqual(cmd,"/AC/SHARP/OFF")){
        irController::sendCommand(4,0);//command have to be replaced
      }
      
    }
  
  
    }

#endif

