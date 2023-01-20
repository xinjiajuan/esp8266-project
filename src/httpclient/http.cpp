//
// Created by moexinjiajuan on 2023/1/13.
//

#include "http.h"
#include "ESP8266HTTPClient.h"
#include "ArduinoJson.h"



#define ServerHost "http://127.0.0.1:3660/dht22";
WiFiClient client;
HTTPClient http;

void HttpClient::Data::IncomingDeviceInfo() {
    chipId=ESP.getChipId();
}
void HttpClient::Data::getPOSTJSON(float dht_tem, float dht_hum, float dht_hi,float bmp_tem,int bmp_pre,float bmp_alt){
    IncomingDeviceInfo();
    IncomingDHT22Info(dht_tem,dht_hum,dht_hi);
    IncomingBMP180Info(bmp_tem,bmp_pre,bmp_alt);
    ArduinoJson::DynamicJsonDocument doc(1024);
    ArduinoJson::JsonObject DeviceObject=doc.createNestedObject("Device");
    DeviceObject["chipId"]=chipId;
    ArduinoJson::JsonObject dht22Object=doc.createNestedObject("DHT22");
    dht22Object["tem"]=tem1;
    dht22Object["hum"]=hum;
    dht22Object["hi"]=hi;
    ArduinoJson::JsonObject BMP180Object=doc.createNestedObject("BMP180");
    BMP180Object["tem"]=tem2;
    BMP180Object["pre"]=pre;
    BMP180Object["alt"]=alt;
    std::string jsonStr;
    ArduinoJson::serializeJson(doc,jsonStr);
    Serial.println(jsonStr.c_str());
}