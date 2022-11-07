#include <Arduino.h>
#include "DHT.h"
#include "Adafruit_BMP085.h"
#include "e-paper.h"
#include "array_make.h"
#include "ESP8266WiFi.h"
#include "ESP8266WiFiMulti.h"
#include "AddrList.h"


#ifndef STASSID
#define STASSID "serverwlan"
#define STAPSK  "1114807608hzq"
#endif

const char *ssid = STASSID;
const char *password = STAPSK;

#define DHTType DHT22
#define DHTPin 13
DHT dht(DHTPin, DHTType);
Adafruit_BMP085 bmp;

ESP8266WiFiMulti wiFiMulti;

void setup() {
// write your initialization code here

    Serial.begin(115200);
    EPD_HW_InitPion();
    ESP.wdtDisable();
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    for (auto a: addrList) {
        Serial.println(a.toString().c_str());
    }
}

void loop() {
    //clean display
    while (1) {
        EPD_HW_Init(); // Electronic paper initialization
        EPD_WhiteScreen_ALL_Clean();
        EPD_DeepSleep();
        //wifi array
        CreatWifi_Epaper_Array_ICON();

        EPD_HW_Init();                            // Electronic paper initialization
        EPD_WhiteScreen_ALL(false, gImage_BW, gImage_R); // Refresh the picture in full screen
        EPD_DeepSleep();                          // Enter deep sleep,Sleep instruction is necessary, please do not delete!!!
        delay(2000);

        while (true){
            Sys_run(); // System run
            LED_run(); // Breathing lamp
        }
    }
}

