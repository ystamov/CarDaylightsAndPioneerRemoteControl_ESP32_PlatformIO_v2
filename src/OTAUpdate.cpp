#include <OTAUpdate.h>
#include <Arduino.h>
#include <GlobalVariables.h>
#include <ESPmDNS.h>          // OTA libraries
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

/* OTA Wi-Fi parameters */
const char* ssid     = "LearningRoom";
const char* password = "c#sharp#";
// const char* ssid = "DellHotspot_YSS";
// const char* password = "DellHotspotEsp32";
//TODO: make try to connect to first Wifi, if fails, try to connect to the second.

void OTAUpdate()
{
    Serial.println("Booting");
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.waitForConnectResult() != WL_CONNECTED) 
    {
      //Serial.println("Connection Failed! Rebooting...");            // TODO: to think how to exit from this situation elegant
      Serial.println("Connection Failed! Please try again...");            // TODO: to think how to exit from this situation elegant
      vTaskDelay(1000 / portTICK_PERIOD_MS);
      break;
      //vTaskDelay(5000);
      //ESP.restart();
    }

  /*
    Port defaults to 3232
    ArduinoOTA.setPort(3232);

    Hostname defaults to esp3232-[MAC]
    ArduinoOTA.setHostname("myesp32");

    No authentication by default
    ArduinoOTA.setPassword("admin");

    Password can be set with it's md5 value as well
    MD5(admin) = 21232f297a57a5a743894a0e4a801fc3
    ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");
  */

  ArduinoOTA
    .onStart([]() 
      {
        String type;
        if (ArduinoOTA.getCommand() == U_FLASH)
        {
          type = "sketch";
        }
        else // U_SPIFFS
        {
          type = "filesystem";
        }

        Serial.println("Start updating " + type);  // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
      })
    .onEnd([]() 
      {
        Serial.println("\nEnd");
      })
    .onProgress([](unsigned int progress, unsigned int total) 
      {
        Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
      })
    .onError([](ota_error_t error) 
      {
        Serial.printf("Error[%u]: ", error);

        if (error == OTA_AUTH_ERROR) 
        {
          Serial.println("Auth Failed");
        }
        else if (error == OTA_BEGIN_ERROR) 
        {
          Serial.println("Begin Failed");
        }
        else if (error == OTA_CONNECT_ERROR) 
        {
          Serial.println("Connect Failed");
        }
        else if (error == OTA_RECEIVE_ERROR) 
        {
          Serial.println("Receive Failed");
        }
        else if (error == OTA_END_ERROR) 
        {
          Serial.println("End Failed");
        }
      });

    ArduinoOTA.begin();
    Serial.println("Ready");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}