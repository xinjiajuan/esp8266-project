//
// Created by moexinjiajuan on 2022/11/2.
//
#include "res/wifi.h"
#include "array_make.h"
#include "e-paper.h"
#include "ESP8266WiFi.h"

void Epaper_Wifi_Config(int wifi_status,int E_color,int wifi_local){
    int arraysize;
    unsigned char *wifi;
    switch (wifi_status) {
        case 0:
            arraysize= sizeof(wifi_full);
            wifi=wifi_full;
            break;
        case 1:
            arraysize= sizeof(wifi_1);
            wifi=wifi_1;
            break;
        case 2:
            arraysize= sizeof(wifi_2);
            wifi=wifi_2;
            break;
        case 3:
            arraysize= sizeof(wifi_3);
            wifi=wifi_3;
            break;
        case 4:
            arraysize= sizeof(no_wifi);
            wifi=no_wifi;
            break;
        default:
            arraysize= sizeof(no_wifi);
            wifi=no_wifi;
            break;
    }
    for (int j = 0; j < arraysize; ++++j){
        for (int i = 0; i < 2;++i) {
            switch (E_color) {
                case 0:
                    gImage_BW[wifi_local + i] = wifi[j+i];
                    break;
                case 1:
                    gImage_R[wifi_local + i] = wifi[j+i];
                    break;
            }
        }
        wifi_local=wifi_local+16;
    }
}

void CreatWifi_Epaper_Array_ICON(){
    int wifiRSSI=WiFi.RSSI();
    if (wifiRSSI <= 0 && wifiRSSI >= -50){
        Epaper_Wifi_Config(0,1);
    } else if (wifiRSSI<-50&&wifiRSSI>=-70){
        Epaper_Wifi_Config(1,1);
    } else if(wifiRSSI<-70&&wifiRSSI>=-80){
        Epaper_Wifi_Config(2,1);
    } else if(wifiRSSI<-80&&wifiRSSI>-100){
        Epaper_Wifi_Config(3,1);
    } else {
        Epaper_Wifi_Config(4,1);
    }
}