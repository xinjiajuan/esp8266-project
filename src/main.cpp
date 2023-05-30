#include <Arduino.h>

#include "httpclient/http.h"
#include "data/data.h"

#include "ESP8266WiFi.h"
#include "ESP8266WiFiMulti.h"
#include "AddrList.h"
#include "WiFiUdp.h"
#include "NTPClient.h"


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
    // write your initialization code here
    Serial.begin(115200);
    //init dht 3.3v power
    delay(500);
    pinMode(9,OUTPUT);
    delay(500);
    //init epaper
    ESP.wdtFeed();
    //init wifi
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    //connect wifi
    Serial.print("Connecting WIFI");
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
    /*
     * start work
     * */
    //clean display屏幕初始化

    while (!timeClient.update()) {
        delay(500);
        Serial.println(F("Failed to read from NTP Time!"));
        ESP.wdtFeed();//喂狗
    }
    timestamp stamp;
    EnvData data;
    stamp.TimeStamp=timeClient.getEpochTime();
    Serial.println("getTimeStamp OK!");
    data.readALLSensorData(stamp.timestampToYear_OR_Month_OR_Day(stamp.TimeStamp,TimeMonth));
    //off dht power
    pinMode(9,INPUT);
    delay(500);
    HttpClient::Data client;
    HttpClient httpPost;
    std::string dataJson=client.getPOSTJSON(data.tem1,data.hum,data.hi,data.tem2,data.pre,data.alt);
    httpPost.SendPOST(dataJson);
    //deepsleep esp
    ESP.deepSleep(120e6);
}

void loop() {

}
