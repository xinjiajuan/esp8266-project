//
// Created by moexinjiajuan on 2023/5/25.
//
#include "DEV_Config.h"
#include "EPD.h"
#include "GUI_Paint.h"
#include "stdlib.h"
#ifndef ESP8266_PROJECT_EPAPER_H
#define ESP8266_PROJECT_EPAPER_H
class epaper{
    UBYTE *BlackImage,*RImage;
public:
    void init_epaper_device();
    void date_make_show(int year,int month,int day);


};
#endif //ESP8266_PROJECT_EPAPER_H
