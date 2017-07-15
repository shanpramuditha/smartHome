#ifndef requestController
#define requestController

#include "variables.h"
#include "irController.h"
#include "bulbController.h"
#include "wifiController.h"

namespace requestController {

inline void commandAnalyzer(char cmd[]) {

  Serial.println(cmd);
  if (isEqual(cmd, "/BULB/ON")==0) {
    bulbController::onRelay();
  }
  else if (isEqual(cmd, "/BULB/OFF")==0) {
    bulbController::offRelay();
    bulbController::beep();
  }
  else if (isEqual(cmd, "/AC/NEC/ONOFF")==0) {
    irController::sendCommand(1, 0); 
  }
  else if (isEqual(cmd, "/AC/NEC/UP")==0) {
    irController::sendCommand(1, 1); 
  }
  else if (isEqual(cmd, "/AC/NEC/DOWN")==0) {
    irController::sendCommand(1, 2); 
  }
  else if (isEqual(cmd, "/AC/SONY/ONOFF")) {
    irController::sendCommand(2, 0); 
  }
  else if (isEqual(cmd, "/AC/SONY/UP")) {
    irController::sendCommand(2, 1); 
  }
  else if (isEqual(cmd, "/AC/SONY/DOWN")) {
    irController::sendCommand(2, 2); 
  }
  else if (isEqual(cmd, "/AC/SAMSUNG/ONOFF")) {
    irController::sendCommand(3, 0); 
  }
  else if (isEqual(cmd, "/AC/SAMSUNG/UP")) {
    irController::sendCommand(3, 1); 
  }
  else if (isEqual(cmd, "/AC/SAMSUNG/DOWN")) {
    irController::sendCommand(3, 2); 
  }
  else if (isEqual(cmd, "/AC/LG/ONOFF")) {
    irController::sendCommand(4, 0); 
  }
  else if (isEqual(cmd, "/AC/LG/UP")) {
    irController::sendCommand(4, 1); 
  }
  else if (isEqual(cmd, "/AC/LG/DOWN")) {
    irController::sendCommand(4, 2); 
  }else {
    Serial.println("other");
    //do something
  }

}


}

#endif

