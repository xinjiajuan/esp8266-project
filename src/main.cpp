#include <Arduino.h>

#include "e-paper.h"
#include "array_make.h"
#include "httpclient/http.h"
#include "data/data.h"

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

//#define SealevelPressure 101750
ESP8266WiFiMulti wiFiMulti;
//ntp客户端
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ntp.ntsc.ac.cn", 8 * 60 * 60, 1000);

EpaperArray paper;

void setup() {
    // write your initialization code here
    Serial.begin(115200);
    //init dht 3.3v power
    delay(500);
    pinMode(9,OUTPUT);
    delay(500);
    //init epaper
    EPD_HW_InitPion();
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
    //clean display
    EPD_HW_Init(); // Electronic paper initialization
    EPD_WhiteScreen_ALL_Clean();
    paper.Epaper_Array_init();
    paper.CreatWifi_Epaper_Array_ICON();
    Serial.println("Creat WIFI OK!");
    Sys_run();
//    while (isnan(dht.readHumidity()) || isnan(dht.readTemperature()) || isnan(dht.readTemperature(true))) {
//        delay(500);
//        Serial.println(F("Failed to read from DHT sensor!"));
//        Sys_run();
//    }
    while (!timeClient.update()) {
        delay(500);
        Serial.println(F("Failed to read from NTP Time!"));
        Sys_run();
    }
    timestamp stamp;
    EnvData data;
    stamp.TimeStamp=timeClient.getEpochTime();
    Serial.println("getTimeStamp OK!");
    paper.Epaper_Time_Array_Config(stamp.TimeStamp);
    data.readALLSensorData(stamp.timestampToYear_OR_Month_OR_Day(stamp.TimeStamp,TimeMonth));
    paper.Epaper_DHT22_Vale_Array(data.tem1,data.hum,data.hi);
    paper.Epaper_BMP180_Vale_Array(data.pre,data.tem2,data.alt);
//    paper.Epaper_DHT22_Vale_Array(
//            dht.readTemperature(),
//            dht.readHumidity(),
//            dht.computeHeatIndex(dht.readTemperature(), dht.readHumidity(), false)
//    );
//    paper.Epaper_BMP180_Vale_Array(bmp.readPressure(),bmp.readTemperature(), Calculate_Pressure_Altitude(bmp.readPressure(),dht.readTemperature()));
    EPD_HW_Init();                            // Electronic paper initialization
    EPD_WhiteScreen_ALL(false, paper.Return_gImage_BW(), paper.Return_gImage_R()); // Refresh the picture in full screen
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
