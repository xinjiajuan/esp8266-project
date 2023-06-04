//
// Created by moexinjiajuan on 2023/1/19.
//
/*
#include "data.h"
#include "DHT.h"
#include "Adafruit_BMP085.h"


bool EnvData::readALLSensorData(int month,bool initSensorObject) {
    if(initSensorObject){
        initDHTSensor();
        if(!initBMP180Sensor()){
            Serial.println("Failed init for bmp SensorObject ");
            return false;
        }
    }
    Serial.println("init bmp SensorObject OK!");
    int i=0;
    //dht22
    //test working
    while (isnan(dht.readHumidity()) || isnan(dht.readTemperature()) || isnan(dht.readTemperature(true))) {
        delay(500);
        Serial.println(F("Failed to read from DHT sensor!"));
        if(i==20){
            return false;
        }
        i++;
        ESP.wdtFeed();
    }
    Serial.println("init DHT22 SensorObject OK!");
    //record the value at the moment
    tem1=dht.readTemperature();
    hum=dht.readHumidity();
    hi=dht.computeHeatIndex(tem1,hum, false);
    //bmp180
    tem2=bmp.readTemperature();
    pre=bmp.readPressure();
    alt=bmp.readAltitude(GanzhouSealevelPressure[month]);
    return true;
}

void EnvData::initDHTSensor() {
    //dht=DHT(DHTPin,DHTType);
    dht.begin();
}

bool EnvData::initBMP180Sensor() {
    if (!bmp.begin()) {
        Serial.println("Could not find a valid BMP085 sensor, check wiring!");
        return false;
    } else{
        return true;
    }
}
*/