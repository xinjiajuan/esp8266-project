//
// Created by moexinjiajuan on 2023/1/19.
//

#ifndef ESP8266_PROJECT_DATA_H
#define ESP8266_PROJECT_DATA_H

#include "DHT.h"
#include "Adafruit_BMP085.h"
#include "sys/time.h"
#include "string"

#define DHTType DHT22
#define DHTPin 14

class EnvData{
private:
    Adafruit_BMP085 bmp;
    DHT dht=DHT(DHTPin,DHTType);
    /*
     * 江西赣州市海平面气压
     * 通过获得2022-2019年每年中每月的平均海平面气压，
     * 计算每年趋势线，趋势线为多项式，4阶数，
     * 再获得每年趋势线方程，计算趋势线在每月中具体的值
     * 讲每年相同月份的值计算平均数，得出下面的每月海平面气压趋势值。
     * 可用于参考每月的海平面气压，直接进行海拔高度计算
     * */
    int GanzhouSealevelPressure[12]={
            102354,
            102229,
            101822,
            101312,
            100849,
            100542,
            100461,
            100629,
            101023,
            101567,
            102130,
            102523,
    };
public:
    float tem1;
    float hum;
    float hi;
    float tem2;
    int pre;
    float alt;

    void initDHTSensor();
    bool initBMP180Sensor();
    bool readALLSensorData(int month,bool initSensorObject= true);
};

static const int TimeYear=0;
static const int TimeMonth=1;
static const int TimeDay=2;
static const int TimeHour=3;
static const int TimeMin=4;

class timestamp{
public:
    unsigned long TimeStamp;
    int timestampToYear_OR_Month_OR_Day(unsigned long timestamp,int timeType){
        std::string timeStr;
        time_t  t;
        struct tm *time;
        t=timestamp;
        time= localtime(&t);
        switch (timeType) {
            case 0:
                strftime(timeStr.data(),64,"%Y",time);
                break;
            case 1:
                strftime(timeStr.data(),64,"%m",time);
                break;
            case 2:
                strftime(timeStr.data(),64,"%d",time);
                break;
            case 3:
                strftime(timeStr.data(),64,"%H",time);
                break;
            case 4:
                strftime(timeStr.data(),64,"%M",time);
                break;
        }
        return atoi(timeStr.c_str());
    };
};
#endif //ESP8266_PROJECT_DATA_H
