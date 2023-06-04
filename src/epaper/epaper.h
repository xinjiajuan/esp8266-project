//
// Created by moexinjiajuan on 2023/5/25.
//
#include "DEV_Config.h"
#include "EPD.h"
#include "GUI_Paint.h"
#include "stdlib.h"

#ifndef ESP8266_PROJECT_EPAPER_H
#define ESP8266_PROJECT_EPAPER_H


class epaper {
    #define YearTYPE 0
    #define MonthTYPE 1
    #define DayTYPE 2
    UBYTE *BlackImage, *RImage;
    void setRedBG();
    void setBlcakBG();
    int EpochTimetoExactTime(unsigned long epochtime, int getType);
public:
    void init_epaper_device();
    void date_make_show(unsigned long epochtime = 2023);
    void time_make_show(int hour = 24, int min = 24);
    void DHT22_make_show(float tem1, float tem2, float hu, float hi);
    void display();
    void sleep();
    void clear();
};

#endif //ESP8266_PROJECT_EPAPER_H
