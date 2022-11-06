#include <Arduino.h>
#include "DHT.h"
#include "Adafruit_BMP085.h"
#include "e-paper.h"
#include "avr/pgmspace.h"
#include "array_make.h"
#include "ESP8266WiFi.h"
#include "ESP8266WiFiMulti.h"

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
    //clean display
    EPD_HW_Init(); // Electronic paper initialization
    EPD_WhiteScreen_ALL_Clean();
    WiFi.mode(WIFI_STA);
    wiFiMulti.addAP("serverwlan", "1114807608hzq");
    if (wiFiMulti.run()!=WL_CONNECTED){
        Serial.println("WL_CONECTED ERR");
        Sys_run(); // System run
        return;
    }
}

void loop() {
    CreatWifi_Epaper_Array_ICON();
    EPD_HW_Init();                            // Electronic paper initialization
    EPD_WhiteScreen_ALL(true, gImage_BW, gImage_R); // Refresh the picture in full screen
    EPD_DeepSleep();                          // Enter deep sleep,Sleep instruction is necessary, please do not delete!!!
    delay(2000);

    // Clean
    /*
    EPD_HW_Init(); // Electronic paper initialization
    EPD_WhiteScreen_ALL_Clean();
    EPD_DeepSleep(); // Enter deep sleep,Sleep instruction is necessary, please do not delete!!!
     */
    while (1) {
        Sys_run(); // System run
        LED_run(); // Breathing lamp
    }
}