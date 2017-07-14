#ifndef WIFICONTROLLER
#define WIFICONTROLLER

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include "variables.h"
#include "requestController.h"


namespace wifiController{

inline void successResponse(WiFiClient client) {
  // send a standard http response header
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(
    "Connection: close");  // the connection will be closed after completion of the response
  client.println();
  client.println("<!DOCTYPE HTML><html>");
  client.println("OPTIONS: RED BLUE<br></html>");

}

inline void printStatus(){
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}

  inline void connect(WiFiServer& server, int& status){
    if(WiFi.status() == WL_NO_SHIELD){
      Serial.println("WiFi shield not available");
      while(true);  
    }

    status = WiFi.begin(ssid,pass);
    while(status != WL_CONNECTED){
      status = WiFi.status();
      Serial.print("Connecting to SSID: ");
      Serial.println(ssid); 
      delay(5000);     
    }

    server.begin();

    wifiController::printStatus();
    }

    inline void wait(WiFiServer& server){
      char lineBuffer[255], lineValue[255], *linePtr;
      int lineCount;

      
      WiFiClient wifiClient = server.available();
      if(wifiClient){
        Serial.println("connected !!");
        boolean lineBreak = true;
        linePtr = lineBuffer;
        lineCount = 0;

        while(wifiClient.connected()){
          if(wifiClient.available()){
            char value = wifiClient.read();
            Serial.print(value);

            if(value == '\n' && lineBreak){
              
              requestController::commandAnalyzer(lineValue);
              wifiController::successResponse(wifiClient);
              break;
            }

            if(value == '\n'){
              lineBreak = true;
              if(memcmp(lineBuffer,"GET ",4)==0){
                strcpy(lineValue, &(lineBuffer[4]));
              }

              linePtr = lineBuffer;
              lineCount = 0;
              }else if(value != '\r'){
                lineBreak = false;
                if(lineCount < sizeof(lineBuffer)){
                  *linePtr++ = value;
                  lineCount++;
                }
              }
          }
        }

        delay(1);
        wifiClient.stop();
        Serial.println("clientDisconnected");
      }
    }
}


#endif

