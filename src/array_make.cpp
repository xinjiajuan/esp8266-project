//
// Created by moexinjiajuan on 2022/11/2.
//
#include "iostream"
#include "sstream"
#include "cstring"
#include "sys/time.h"
#include "res/res.h"
#include "array_make.h"
#include "e-paper.h"
#include "ESP8266WiFi.h"
using namespace std;
const int time_local[5] = {1283, 1587,2195, 2499};
const int time_Colone_local = 1972;



void Epaper_Wifi_Config(int wifi_status, int E_color, int wifi_local = 3648);
void Creat_Time_Number_Array(int vale, int location);
int Creat_DHT22_Number_Array(int vale, int number);
int Creat_DHT22_DecimalPoint_Array(int start_local);
//wifi show
void Epaper_Wifi_Config(int wifi_status, int E_color, int wifi_local) {
    for (int j = 0; j < sizeof(Wifi_Icon[wifi_status]); ++ ++j) {
        for (int i = 0; i < 2; ++i) {
            switch (E_color) {
                case 0:
                    gImage_BW[wifi_local + i] = Wifi_Icon[wifi_status][j + i];
                    break;
                case 1:
                    gImage_R[wifi_local + i] = Wifi_Icon[wifi_status][j + i];
                    break;
            }
        }
        wifi_local = wifi_local + 16;
    }
    Serial.println("Creat WIFI OK!");
}

void CreatWifi_Epaper_Array_ICON() {
    int wifiRSSI = WiFi.RSSI();
    //Serial.printf("RSSI:%d", wifiRSSI);
    if (wifiRSSI <= 0 && wifiRSSI >= -50) {
        Epaper_Wifi_Config(0, 0);    //满格
    } else if (wifiRSSI < -50 && wifiRSSI >= -70) {
        Epaper_Wifi_Config(3, 0);    //减一格
    } else if (wifiRSSI < -70 && wifiRSSI >= -80) {
        Epaper_Wifi_Config(2, 0);    //减二格
    } else if (wifiRSSI < -80 && wifiRSSI > -100) {
        Epaper_Wifi_Config(1, 1);    //一格
    } else {
        Epaper_Wifi_Config(4, 1);    //无信号
    }
}
//time show
void Epaper_Time_Array_Config(int Hour, int Minute,unsigned long EpochTime) {
    char date[10];
    time_t t;
    struct tm *ttime;
    t= EpochTime;
    ttime= localtime(&t);
    strftime(date,64,"%Y.%m.%d",ttime);
    string date_str(date);
    //
    int local=time_Colone_local;
    int time[4] = {Hour / 10, Hour % 10, Minute / 10, Minute % 10};
    for (int i = 0; i < countof(time); ++i) {
        Creat_Time_Number_Array(time[i], i);
    }
    for (int i = 0; i < sizeof(_Colon_Symbol_); ++++i) {
        for (int j = 0; j < 2; ++j) {
            gImage_BW[local + j] = _Colon_Symbol_[i+j];
        }
        local= local + 16;
    }
    int date_local[3]={259-16*2,133-16,645+16*2};
    int local_ID_date=0;
    for (int i = 0; i < date_str.length(); ++i) {
        if (date_str.substr(i,1)=="."){
            local_ID_date++;
        } else{
            date_local[local_ID_date]= Creat_DHT22_Number_Array(atoi(date_str.substr(i,1).c_str()),date_local[local_ID_date]);
        }
    }
}

void Creat_Time_Number_Array(int vale, int location) {
    int local=time_local[location];
    for (int j = 0; j < sizeof(Front_int_X32[vale]); ++ ++ ++j) {
        for (int k = 0; k < 3; ++k) {
            gImage_R[local + k] = Front_int_X32[vale][j + k];
        }
         local= local + 16;
    }
}

const int DHT_Vale_local[3]={640,2368 ,2949}; //location
//dht22 vale show
void Epaper_DHT22_Vale_Array(float Tem_Origin,float Hum_Origin,float HI){
    string tem_origin_str= to_string(Tem_Origin);
    string hum_origin_str= to_string(Hum_Origin);
    string hi_str= to_string(HI);
    int tem_or_local=DHT_Vale_local[0];
    int hum_or_local=DHT_Vale_local[1];
    int hi_local=DHT_Vale_local[2];
    int tem_DecPoin,hum_DecPoin,hi_DecPoin;
    for (int i = 0; i < tem_origin_str.length(); ++i) {
        if (tem_origin_str.substr(i,1)=="."){
            tem_DecPoin=i;
            tem_or_local= Creat_DHT22_DecimalPoint_Array(tem_or_local);
        } else if(i-tem_DecPoin==3){
            break;
        } else{
            tem_or_local= Creat_DHT22_Number_Array(atoi(tem_origin_str.substr(i,1).c_str()),tem_or_local);
        }
    }

    for (int i = 0; i < hum_origin_str.length(); ++i) {
        if (hum_origin_str.substr(i,1)=="."){
            hum_DecPoin=i;
            hum_or_local= Creat_DHT22_DecimalPoint_Array(hum_or_local);
        } else if (i-hum_DecPoin==3){
            break;
        } else{
            hum_or_local= Creat_DHT22_Number_Array(atoi(hum_origin_str.substr(i,1).c_str()),hum_or_local);
        }
    }
    for (int i = 0; i < hi_str.length(); ++i) {
        if (hi_str.substr(i,1)=="."){
            hi_DecPoin=i;
            hi_local= Creat_DHT22_DecimalPoint_Array(hi_local);
        } else if (i-hi_DecPoin==3){
            break;
        } else{
            hi_local= Creat_DHT22_Number_Array(atoi(hi_str.substr(i,1).c_str()),hi_local);
        }
    }
}
int Creat_DHT22_Number_Array(int vale, int start_local) {
    for (int j = 0; j < sizeof(Front_int_X17[vale]); ++ ++j) {
        for (int k = 0; k < 2; ++k) {
            gImage_R[start_local + k] = Front_int_X17[vale][j + k];
        }
        start_local= start_local + 16;
    }
    return start_local+16*2;
}

int Creat_DHT22_DecimalPoint_Array(int local){
    local=local+1;
    for (int j = 0; j < sizeof(_DecimalPoint_); ++j) {
        gImage_R[local] = _DecimalPoint_[j];
        local= local + 16;
    }
    return local+16*6-1;
}