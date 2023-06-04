#include <Arduino.h>
#include "httpclient/http.h"
#include "data/data.h"

#include "ESP8266WiFi.h"
#include "ESP8266WiFiMulti.h"
#include "WiFiUdp.h"
#include "NTPClient.h"
#include "epaper/epaper.h"


#ifndef STASSID
#define STASSID "CMCC-5cSZ"
#define STAPSK  "1114807608hzq"
#endif

const char *ssid = STASSID;
const char *password = STAPSK;

//#define SealevelPressure 101750
ESP8266WiFiMulti wiFiMulti;
//ntp客户端
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ntp.ntsc.ac.cn", 8 * 60 * 60, 1000);



void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    //connect wifi
    Serial.print("Connecting WIFI");
    while (WiFi.status() != WL_CONNECTED) {
        ESP.wdtFeed();
        delay(500);
        Serial.print(".");
    }
    Serial.println("Wifi connect success!");
    //ntpclient
    timeClient.begin();
    while (!timeClient.update()){
        ESP.wdtFeed();
        delay(100);
        Serial.println("updating timeclient");
    }
    epaper display;
    display.init_epaper_device();
    display.date_make_show(timeClient.getEpochTime());
    display.time_make_show(timeClient.getHours(),timeClient.getMinutes());
    display.display();
    display.sleep();
}

void loop() {

}
