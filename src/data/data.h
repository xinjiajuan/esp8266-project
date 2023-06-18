//
// Created by moexinjiajuan on 2023/1/19.
//

#ifndef ESP8266_PROJECT_DATA_H
#define ESP8266_PROJECT_DATA_H

#include "DHT.h"
#include "sys/time.h"
#include "string"
#include "Adafruit_BMP085.h"

//dht pin
#define DHTPin 12
#define TriodPin 9


#define DHTType DHT22

class EnvData{
private:
    DHT dht=DHT(DHTPin,DHTType);
    //TwoWire mywire;
    Adafruit_BMP085 bmp;
    float tem1,hu,hi,tem2;
    int32_t pre;
public:
    void initDHTSensor();
    void downDHTSensor();
    void initSensorData();
    float read_Tem_1_SensorData();
    float read_Hu_SensorData();
    float read_Hi_sensorData();
    void initBMPSensor();
    float read_Tem_2_SensorData();
    int32_t read_Pressure_sensorData();
};

#endif //ESP8266_PROJECT_DATA_H
