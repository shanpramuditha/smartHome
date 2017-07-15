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
    bulbController::beep();
  }
  else if (isEqual(cmd, "/BULB/OFF")==0) {
    bulbController::offRelay();
    bulbController::beep();
  }
  else if (isEqual(cmd, "/AC/NEC/ONOFF")==0) {
    irController::sendCommand(1, 0);
    bulbController::beep(); 
  }
  else if (isEqual(cmd, "/AC/NEC/UP")==0) {
    irController::sendCommand(1, 1);
    bulbController::beep(); 
  }
  else if (isEqual(cmd, "/AC/NEC/DOWN")==0) {
    irController::sendCommand(1, 2);
    bulbController::beep(); 
  }
  else if (isEqual(cmd, "/AC/SONY/ONOFF")==0) {
    irController::sendCommand(2, 0);
    bulbController::beep(); 
  }
  else if (isEqual(cmd, "/AC/SONY/UP")==0) {
    irController::sendCommand(2, 1);
    bulbController::beep(); 
  }
  else if (isEqual(cmd, "/AC/SONY/DOWN")==0) {
    irController::sendCommand(2, 2); 
    bulbController::beep();
  }
  else if (isEqual(cmd, "/AC/SAMSUNG/ONOFF")==0) {
    irController::sendCommand(3, 0);
    bulbController::beep(); 
  }
  else if (isEqual(cmd, "/AC/SAMSUNG/UP")==0) {
    irController::sendCommand(3, 1); 
    bulbController::beep();
  }
  else if (isEqual(cmd, "/AC/SAMSUNG/DOWN")==0) {
    irController::sendCommand(3, 2); 
    bulbController::beep();
  }
  else if (isEqual(cmd, "/AC/LG/ONOFF")==0) {
    irController::sendCommand(4, 0); 
    bulbController::beep();
  }
  else if (isEqual(cmd, "/AC/LG/UP")==0) {
    irController::sendCommand(4, 1);
    bulbController::beep(); 
  }
  else if (isEqual(cmd, "/AC/LG/DOWN")==0) {
    irController::sendCommand(4, 2);
    bulbController::beep(); 
  }else {
    Serial.println("other");
    //do something
  }

}


}

#endif

