//
// Created by moexinjiajuan on 2023/1/13.
//

#ifndef ESP8266_PROJECT_HTTP_H
#define ESP8266_PROJECT_HTTP_H

#include <string>

class HttpClient {
private:
    //static std::string post_json;
public:
    class Data {
    private:
        int chipId;
        float tem1;
        float hum;
        float hi;
        float tem2;
        int pre;
        float alt;

        void IncomingDHT22Info(float dht_tem, float dht_hum, float dht_hi) {
            tem1=dht_tem;
            hum=dht_hum;
            hi=dht_hi;
        }
        void IncomingBMP180Info(float bmp_tem,int bmp_pre,float bmp_alt){
            tem2=bmp_tem;
            pre=bmp_pre;
            alt=bmp_alt;
        }
        void IncomingDeviceInfo();
    public:
        std::string getPOSTJSON(
                float dht_tem,
                float dht_hum,
                float dht_hi,
                float bmp_tem,
                int bmp_pre,
                float bmp_alt
                );

    };
    bool SendPOST(std::string jsonstr);
};

#endif //ESP8266_PROJECT_HTTP_H
