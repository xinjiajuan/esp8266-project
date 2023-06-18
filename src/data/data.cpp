//
// Created by moexinjiajuan on 2023/1/19.
//

#include "data.h"
#include "DHT.h"

void EnvData::initDHTSensor() {
    //dht=DHT(DHTPin,DHTType);
    delay(100);
    pinMode(TriodPin,OUTPUT);
    delay(150);
    dht.begin();
    while (isnan(dht.readTemperature()) || isnan(dht.readHumidity()) || isnan(dht.readTemperature(true))) {
        Serial.println(F("Failed to read from DHT sensor!"));
        delay(500);
        ESP.wdtFeed();
    }
}
void EnvData::downDHTSensor() {
    pinMode(TriodPin,INPUT);
}

float EnvData::read_Tem_1_SensorData() {
    return tem1;
}

float EnvData::read_Hu_SensorData() {
    return hu;
}

float EnvData::read_Hi_sensorData() {
    return hi;
}

void EnvData::initBMPSensor() {
    //mywire.begin(BMP_SDA_PIN,BMP_SCL_PIN);
    while (!bmp.begin()){
        delay(500);
        Serial.println("Could not find a valid BMP085 sensor, check wiring!");
        ESP.wdtFeed();
    }
}

void EnvData::initSensorData() {
    tem1=dht.readTemperature();
    tem2=bmp.readTemperature();
    hu=dht.readHumidity();
    hi=dht.computeHeatIndex((tem2+tem1)/2,hu);
    pre=bmp.readPressure();
}

float EnvData::read_Tem_2_SensorData() {
    return tem2;
}

int32_t EnvData::read_Pressure_sensorData() {
    return pre;
}