//
// Created by moexinjiajuan on 2022/11/2.
//
#include "res/res.h"
#include "array_make.h"
#include "e-paper.h"
#include "ESP8266WiFi.h"

void Epaper_Wifi_Config(int wifi_status,int E_color,int wifi_local){
    unsigned char wifi[34];
    switch (wifi_status) {
        case 0:
            for (int i = 0; i < sizeof(wifi_full); ++i) {
                wifi[i]=wifi_full[i];
            }
            break;
        case 1:
            for (int i = 0; i < sizeof(wifi_1); ++i) {
                wifi[i]=wifi_1[i];
            }
            break;
        case 2:
            for (int i = 0; i < sizeof(wifi_2); ++i) {
                wifi[i]=wifi_2[i];
            }
            break;
        case 3:
            for (int i = 0; i < sizeof(wifi_3); ++i) {
                wifi[i]=wifi_3[i];
            }
            break;
        case 4:
            for (int i = 0; i < sizeof(no_wifi); ++i) {
                wifi[i]=no_wifi[i];
            }
            break;
        default:
            for (int i = 0; i < sizeof(no_wifi); ++i) {
                wifi[i]=no_wifi[i];
            }
            break;
    }
    for (int j = 0; j < sizeof (wifi); ++++j){
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
    Serial.println("Array Creat OK!");
}

void CreatWifi_Epaper_Array_ICON(){
    int wifiRSSI=WiFi.RSSI();
    Serial.printf("RSSI:%d",wifiRSSI);
    if (wifiRSSI <= 0 && wifiRSSI >= -50){
        Epaper_Wifi_Config(0,0);    //满格
    } else if (wifiRSSI<-50&&wifiRSSI>=-70){
        Epaper_Wifi_Config(3,0);    //减一格
    } else if(wifiRSSI<-70&&wifiRSSI>=-80){
        Epaper_Wifi_Config(2,0);    //减二格
    } else if(wifiRSSI<-80&&wifiRSSI>-100){
        Epaper_Wifi_Config(1,1);    //一格
    } else {
        Epaper_Wifi_Config(4,1);    //无信号
    }
}