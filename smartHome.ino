
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include "irController.h"
#include "variables.h"
#include "wifiController.h"
#include "requestController.h"


int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  wifiController::connect(server,status);
  irController::irsend.begin();
}

void loop() {

  wifiController::wait(server);  

}
