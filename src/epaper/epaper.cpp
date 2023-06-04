//
// Created by moexinjiajuan on 2023/5/25.
//

#include "epaper.h"
#include "DEV_Config.h"
#include "EPD.h"
#include "GUI_Paint.h"
#include "stdlib.h"
#include "string"
void epaper::init_epaper_device() {
    DEV_Module_Init();
    EPD_2IN13B_V4_Init();
    EPD_2IN13B_V4_Clear();
    DEV_Delay_ms(500);
    UWORD Imagesize = ((EPD_2IN13B_V4_WIDTH % 8 == 0) ? (EPD_2IN13B_V4_WIDTH / 8 ) : (EPD_2IN13B_V4_WIDTH / 8 + 1)) * EPD_2IN13B_V4_HEIGHT;
    if ((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
        while (1);
    }
    if ((RImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for red memory...\r\n");
        while (1);
    }
    printf("NewImage:BlackImage and RYImage\r\n");
    Paint_NewImage(BlackImage, EPD_2IN13B_V4_WIDTH, EPD_2IN13B_V4_HEIGHT, 270, WHITE);
    Paint_NewImage(RImage, EPD_2IN13B_V4_WIDTH, EPD_2IN13B_V4_HEIGHT, 270, WHITE);
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);
    Paint_SelectImage(RImage);
    Paint_Clear(WHITE);
}
void epaper::setBlcakBG() {
    Paint_SelectImage(BlackImage);
}
void epaper::setRedBG() {
    Paint_SelectImage(RImage);
}
int epaper::EpochTimetoExactTime(unsigned long epochtime,int getType) {
    std::string timeStr;
    time_t  t;
    struct tm *time;
    t=epochtime;
    time= localtime(&t);
    switch (getType) {
        case 0:
            strftime(timeStr.data(),64,"%Y",time);
            break;
        case 1:
            strftime(timeStr.data(),64,"%m",time);
            break;
        case 2:
            strftime(timeStr.data(),64,"%d",time);
            break;
    }
    return atoi(timeStr.c_str());
}

void epaper::date_make_show(unsigned long epochtime) {
    setBlcakBG();
    //显示时间栏分割线
    int yearNUM,monthNUM,dayNUM;
    yearNUM= EpochTimetoExactTime(epochtime,YearTYPE);
    monthNUM= EpochTimetoExactTime(epochtime,MonthTYPE);
    dayNUM= EpochTimetoExactTime(epochtime,DayTYPE);
    int YueCN_X,DayCN_X,DayNUM_X;
    if(monthNUM>=10){
        YueCN_X=11*6+2+16;
        DayNUM_X=11*6+16*2+2;
        if(dayNUM>=10){
            DayCN_X=11*8+2+16*2;
        } else{
            DayCN_X=11*7+16*2+2;
        }
    } else{
        YueCN_X=11*5+2+16;
        DayNUM_X=11*5+16*2+2;
        if(dayNUM>=10){
            DayCN_X=11*7+2+16*2;
        } else{
            DayCN_X=11*6+2+16*2;
        }
    }
    Paint_DrawLine(0,22,250,22,BLACK,DOT_PIXEL_2X2,LINE_STYLE_SOLID);
    //显示日期文字
    Paint_DrawString_CN(11*4+2,2,"年",&Font12CN,BLACK,WHITE);//年
    Paint_DrawString_CN(YueCN_X,2,"月",&Font12CN,BLACK,WHITE);//月
    Paint_DrawString_CN(DayCN_X,2,"日",&Font12CN,BLACK,WHITE);//日
    setRedBG();
    Paint_DrawNum(2,4,yearNUM,&Font16,BLACK,WHITE);
    Paint_DrawNum(11*4+16+2,4,monthNUM,&Font16,BLACK,WHITE);
    Paint_DrawNum(DayNUM_X,4,dayNUM,&Font16,BLACK,WHITE);
}
void epaper::time_make_show(int hour, int min) {
    setRedBG();
    Paint_DrawNum(250-(14*2+2),2,min,&Font20,BLACK,WHITE);
    setBlcakBG();
    Paint_DrawString_EN(250-(14*3+2),2,":",&Font20,WHITE,BLACK);
    setRedBG();
    Paint_DrawNum(250-(14*5+2),2,hour,&Font20,BLACK,WHITE);
}
void epaper::DHT22_make_show(float tem1, float tem2, float hu, float hi) {
    
}
void epaper::display() {
    EPD_2IN13B_V4_Display(BlackImage,RImage);
    DEV_Delay_ms(2000);
}
void epaper::sleep() {
    printf("Goto Sleep...\r\n");
    EPD_2IN13B_V4_Sleep();
}
void epaper::clear() {
    EPD_2IN13B_V4_Clear();
    free(BlackImage);
    free(RImage);
    BlackImage = NULL;
    RImage = NULL;
}