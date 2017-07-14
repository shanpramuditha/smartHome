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
  else if (isEqual(cmd, "/AC/NEC/ON")==0) {
    irController::sendCommand(1, 1, 1); //value have to be replaced
  }
  else if (isEqual(cmd, "/AC/NEC/OFF")==0) {
    irController::sendCommand(1, 0, 0); //value have to be replaced
  }
  else if (isEqual(cmd, "/AC/SONY/ON")) {
    irController::sendCommand(2, 1, 1); //value have to be replaced
  }
  else if (isEqual(cmd, "/AC/SONY/OFF")) {
    irController::sendCommand(2, 0, 0); //value have to be replaced
  }
  else if (isEqual(cmd, "/AC/SAMSUNG/ON")) {
    irController::sendCommand(3, 1, 1); //value have to be replaced
  }
  else if (isEqual(cmd, "/AC/SAMSUNG/OFF")) {
    irController::sendCommand(3, 0, 0); //value have to be replaced
  }
  else if (isEqual(cmd, "/AC/SHARP/ON")) {
    irController::sendCommand(4, 1, 1); //value have to be replaced
  }
  else if (isEqual(cmd, "/AC/SHARP/OFF")) {
    irController::sendCommand(4, 0, 0); //value have to be replaced
  } else {
    Serial.println("other");
    //do something
  }

}


}

#endif

