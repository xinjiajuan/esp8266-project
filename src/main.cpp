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
NTPClient timeClient(ntpUDP, "ntp.ntsc.ac.cn", 8 * 60 * 60, 60000);



void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    //connect wifi
    Serial.print("Connecting WIFI");
    while (WiFi.status() != WL_CONNECTED) {
        ESP.wdtFeed();
        delay(500);
        Serial.print(".");
    }
    Serial.println("Wifi connect success!");
    delay(500);
    //ntpclient
    timeClient.begin();
    while (!timeClient.update()){
        ESP.wdtFeed();
        delay(500);
        Serial.println("updating timeclient");
    }
    EnvData sensordata;
    sensordata.initDHTSensor();
    sensordata.initBMPSensor();
    sensordata.initSensorData();
    epaper display;
    Serial.println("init display");
    display.init_epaper_device();
    Serial.println("show date");
    display.date_make_show(timeClient.getEpochTime());
    Serial.println("show time");
    display.time_make_show(timeClient.getHours(),timeClient.getMinutes());
    Serial.println("show tem1");
    display.tem_1_make_show(sensordata.read_Tem_1_SensorData());
    Serial.println("show hum");
    display.hum_make_show(sensordata.read_Hu_SensorData());
    Serial.println("show hi");
    display.hi_make_show(sensordata.read_Hi_sensorData());
    Serial.println("show tem2");
    display.tem_2_make_show(sensordata.read_Tem_2_SensorData());
    Serial.println("show pres");
    display.pre_make_show(sensordata.read_Pressure_sensorData());
    sensordata.downDHTSensor();
    display.display();
    display.sleep();
    ESP.deepSleep(600e6);
}

void loop() {

}
