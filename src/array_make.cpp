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
#include "data/data.h"
using namespace std;
const int time_local[5] = {1283, 1587,2195, 2499};
const int time_Colone_local = 1972;
const int wifi_local= 3648;
//unsigned char gImage_BW_USE[4000];
//unsigned char gImage_R_USE[4000];

void Epaper_Wifi_Config(int wifi_status, int wifi_local);
//void Creat_Time_Number_Array(int vale, int location);
//int Creat_Number_Array(int vale, int number);
//int Creat_DecimalPoint_Array(int start_local);
//void Creat_BMP180_Unit_array(int type,int startlocal);
//int GetLettersID(int ascii);
//int CreatLettersArray(int vale,int local);

void EpaperArray::Epaper_Array_init(){
    for (int i = 0; i < countof(gImage_EA_BW); ++i) {
        gImage_EA_BW[i]=gImage_BW[i];
    }
    for (int i = 0; i < countof(gImage_EA_R); ++i) {
        gImage_EA_R[i]=gImage_R[i];
    }
}

//wifi show
void EpaperArray::Epaper_Wifi_Config(int wifi_status) {
    int local=wifi_local;
    for (int j = 0; j < countof(Wifi_Icon[wifi_status]); ++ ++j) {
        for (int i = 0; i < 2; ++i) {
            gImage_EA_BW[local + i] = Wifi_Icon[wifi_status][j + i];
        }
        local = local + 16;
    }
}

void EpaperArray::CreatWifi_Epaper_Array_ICON() {
    int wifiRSSI = WiFi.RSSI();
    //Serial.printf("RSSI:%d", wifiRSSI);
    if (wifiRSSI <= 0 && wifiRSSI >= -50) {
        Epaper_Wifi_Config(0);    //满格
    } else if (wifiRSSI < -50 && wifiRSSI >= -70) {
        Epaper_Wifi_Config(3);    //减一格
    } else if (wifiRSSI < -70 && wifiRSSI >= -80) {
        Epaper_Wifi_Config(2);    //减二格
    } else if (wifiRSSI < -80 && wifiRSSI > -100) {
        Epaper_Wifi_Config(1);    //一格
    } else {
        Epaper_Wifi_Config(4);    //无信号
    }
}
//time show
void EpaperArray::Epaper_Time_Array_Config(unsigned long EpochTime) {
    timestamp stamp;
    string date_str=to_string(stamp.timestampToYear_OR_Month_OR_Day(EpochTime,TimeYear))
            +"."+to_string(stamp.timestampToYear_OR_Month_OR_Day(EpochTime,TimeMonth))
            +"."+to_string(stamp.timestampToYear_OR_Month_OR_Day(EpochTime,TimeDay));

    int Hour=stamp.timestampToYear_OR_Month_OR_Day(EpochTime,TimeHour);
    int Minute=stamp.timestampToYear_OR_Month_OR_Day(EpochTime,TimeMin);

//    char date[10];
//    time_t t;
//    struct tm *ttime;
//    t= EpochTime;
//    ttime= localtime(&t);
//    strftime(date,64,"%Y.%m.%d",ttime);
//    string date_str(date);
    //
    int local=time_Colone_local;
    int time[4] = {Hour / 10, Hour % 10, Minute / 10, Minute % 10};
    for (int i = 0; i < countof(time); ++i) {
        Creat_Time_Number_Array(time[i], i);
    }
    for (int i = 0; i < sizeof(_Colon_Symbol_); ++++i) {
        for (int j = 0; j < 2; ++j) {
            gImage_EA_BW[local + j] = _Colon_Symbol_[i+j];
        }
        local= local + 16;
    }
    int date_local[3]={259-16*3,133-16*2,645+16*2};
    int local_ID_date=0;
    for (int i = 0; i < date_str.length(); ++i) {
        if (date_str[i]==46){
            local_ID_date++;
        } else{
            date_local[local_ID_date]= Creat_Number_Array(atoi(date_str.substr(i,1).c_str()),date_local[local_ID_date]);
        }
    }
    Serial.println("Show Time in the Display is OK!");
}

void EpaperArray::Creat_Time_Number_Array(int vale, int location) {
    int local=time_local[location];
    for (int j = 0; j < sizeof(Front_int_X32[vale]); ++ ++ ++j) {
        for (int k = 0; k < 3; ++k) {
            gImage_EA_R[local + k] = Front_int_X32[vale][j + k];
        }
         local= local + 16;
    }
}

const int DHT_Vale_local[3]={640,2368 ,2949}; //location
//dht22 vale show
void EpaperArray::Epaper_DHT22_Vale_Array(float Tem_Origin,float Hum_Origin,float HI){
    string tem_origin_str= to_string(Tem_Origin);
    string hum_origin_str= to_string(Hum_Origin);
    string hi_str= to_string(HI);
    int tem_or_local=DHT_Vale_local[0];
    int hum_or_local=DHT_Vale_local[1];
    int hi_local=DHT_Vale_local[2];
    int tem_DecPoin,hum_DecPoin,hi_DecPoin;
    for (int i = 0; i < tem_origin_str.length(); ++i) {
        if (tem_origin_str[i]==46){
            tem_DecPoin=i;
            tem_or_local= Creat_DecimalPoint_Array(tem_or_local);
        } else if(i-tem_DecPoin==3){
            break;
        } else{
            tem_or_local= Creat_Number_Array(atoi(tem_origin_str.substr(i,1).c_str()),tem_or_local);
        }
    }

    for (int i = 0; i < hum_origin_str.length(); ++i) {
        if (hum_origin_str[i]==46){
            hum_DecPoin=i;
            hum_or_local= Creat_DecimalPoint_Array(hum_or_local);
        } else if (i-hum_DecPoin==3){
            break;
        } else{
            hum_or_local= Creat_Number_Array(atoi(hum_origin_str.substr(i,1).c_str()),hum_or_local);
        }
    }
    for (int i = 0; i < hi_str.length(); ++i) {
        if (hi_str[i]==46){
            hi_DecPoin=i;
            hi_local= Creat_DecimalPoint_Array(hi_local);
        } else if (i-hi_DecPoin==3){
            break;
        } else{
            hi_local= Creat_Number_Array(atoi(hi_str.substr(i,1).c_str()),hi_local);
        }
    }
}
int EpaperArray::Creat_Number_Array(int vale, int start_local) {
    for (int j = 0; j < sizeof(Front_int_X17[vale]); ++ ++j) {
        for (int k = 0; k < 2; ++k) {
            gImage_EA_R[start_local + k] = Front_int_X17[vale][j + k];
        }
        start_local= start_local + 16;
    }
    return start_local+16*2;
}

int EpaperArray::Creat_DecimalPoint_Array(int local){
    local=local+1;
    for (int j = 0; j < sizeof(_DecimalPoint_); ++j) {
        gImage_EA_R[local] = _DecimalPoint_[j];
        local= local + 16;
    }
    return local+16*6-1;
}

void EpaperArray::Epaper_BMP180_Vale_Array(int pressure,float temp,float altitude){
    int bmp_local[3]={16*4*8+7,16*4*8+9,16*4*8+11};
    string vale_str[3]= {to_string(pressure),to_string(temp),to_string(altitude)};
    int Decpion;
    for (int i = 0; i < countof(vale_str); ++i) {
        for (int j = 0; j < vale_str[i].length(); ++j) {
            if (vale_str[i][j]==46){
                Decpion=j;
                bmp_local[i]= Creat_DecimalPoint_Array(bmp_local[i]);
            } else if (j-Decpion==3){
                break;
            } else{
                bmp_local[i]= Creat_Number_Array(atoi(vale_str[i].substr(j,1).c_str()),bmp_local[i]);
            }
        }
        Creat_BMP180_Unit_array(i,bmp_local[i]);
    }
}
void EpaperArray::Creat_BMP180_Unit_array(int type,int startlocal){
    string unit[]={"Pa","m"};
    switch (type) {
        case 0:
            for (int i = 0; i < unit[0].length(); ++i) {
                startlocal=CreatLettersArray(GetLettersID(unit[0][i]),startlocal);
            }
            break;
        case 2:
            for (int i = 0; i < unit[1].length(); ++i) {
                startlocal=CreatLettersArray(GetLettersID(unit[1][i]),startlocal);
            }
            break;
        default:
            return;
    }
}
int EpaperArray::GetLettersID(int ascii){
    if(ascii<=90 && ascii>=65){
        return ascii-65;
    } else if(ascii>=97 && ascii<=122){
        return ascii-71;
    }
    return 0;
}
int EpaperArray::CreatLettersArray(int vale,int local){
    for (int i = 0; i < countof(Letters_Front[vale]); ++++i) {
        for (int k = 0; k < 2; ++k) {
            gImage_EA_BW[local + k] = Letters_Front[vale][i + k];
        }
        local= local + 16;
    }
    return local;
}

unsigned char * EpaperArray::Return_gImage_BW(){
    return gImage_EA_BW;
}

unsigned char * EpaperArray::Return_gImage_R() {
    return gImage_EA_R;
}