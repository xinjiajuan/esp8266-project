#include <Arduino.h>
#include "DHT.h"
#include "Adafruit_BMP085.h"
#include "e-paper.h"
#include "array_make.h"
#include "ESP8266WiFi.h"
#include "ESP8266WiFiMulti.h"
#include "AddrList.h"
#include "WiFiUdp.h"
#include "NTPClient.h"


#ifndef STASSID
#define STASSID "serverwlan"
#define STAPSK  "1114807608hzq"
#endif

const char *ssid = STASSID;
const char *password = STAPSK;
//dht22 init
#define DHTType DHT22
#define DHTPin 14
DHT dht(DHTPin, DHTType);

Adafruit_BMP085 bmp;

ESP8266WiFiMulti wiFiMulti;
//ntp客户端
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ntp.ntsc.ac.cn", 8*60*60, 60000);
void setup() {
// write your initialization code here

    Serial.begin(115200);
    //init dht22
    dht.begin();
    //init epaper
    EPD_HW_InitPion();
    ESP.wdtDisable();
    //init bmp180
    if (!bmp.begin()) {
        Serial.println("Could not find a valid BMP085 sensor, check wiring!");
        return;
    }
    //init wifi
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    //connect wifi
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Wifi connect success!");
    Serial.println("IP address: ");
    for (auto a: addrList) {
        Serial.println(a.toString().c_str());
    }
    //ntpclient
    timeClient.begin();
    timeClient.update();
    //clean display
    EPD_HW_Init(); // Electronic paper initialization
    EPD_WhiteScreen_ALL_Clean();
    EPD_DeepSleep();
}

void loop() {
    while (1) {
        Sys_run();
        Serial.println(bmp.readTemperature());
        Serial.println(bmp.readPressure());
        CreatWifi_Epaper_Array_ICON();
        Serial.println(timeClient.getFormattedTime());
        timeClient.update();
        delay(1000);
        Epaper_Time_Array_Config(timeClient.getHours(),timeClient.getMinutes(),timeClient.getEpochTime());
        delay(1000);
        while (isnan(dht.readHumidity()) || isnan(dht.readTemperature()) || isnan(dht.readTemperature(true))) {
            Serial.println(F("Failed to read from DHT sensor!"));
            Sys_run();
        }
        Serial.println(dht.readTemperature());
        Serial.println(dht.readHumidity());
        Epaper_DHT22_Vale_Array(
                dht.readTemperature(),
                dht.readHumidity(),
                dht.computeHeatIndex(dht.readTemperature(),dht.readHumidity(),false)
                );
        Serial.println("DHT Array OK!");
        EPD_HW_Init();                            // Electronic paper initialization
        EPD_WhiteScreen_ALL(false, gImage_BW, gImage_R); // Refresh the picture in full screen
        EPD_DeepSleep();                          // Enter deep sleep,Sleep instruction is necessary, please do not delete!!!
        //delay(120000);
        while (true){
            //wifi array
            Sys_run(); // System run
            LED_run(); // Breathing lamp
        }
    }
}

