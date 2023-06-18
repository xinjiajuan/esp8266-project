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
    char str_year[5],str_month[3],str_day[3];
    sprintf(str_year,"%02d",yearNUM);
    sprintf(str_month,"%02d",monthNUM);
    sprintf(str_day,"%02d",dayNUM);
    Paint_DrawLine(0,22,250,22,BLACK,DOT_PIXEL_2X2,LINE_STYLE_SOLID);
    //显示日期文字
    Paint_DrawString_CN(11*4+2,2,"年",&Font12CN,BLACK,WHITE);//年
    Paint_DrawString_CN(11*6+2+16,2,"月",&Font12CN,BLACK,WHITE);//月
    Paint_DrawString_CN(11*8+2+16*2,2,"日",&Font12CN,BLACK,WHITE);//日
    setRedBG();
    Paint_DrawString_EN(2,4,str_year,&Font16,WHITE,BLACK);
    Paint_DrawString_EN(11*4+16+2,4,str_month,&Font16,WHITE,BLACK);
    Paint_DrawString_EN(11*6+16*2+2,4,str_day,&Font16,WHITE,BLACK);
}

void epaper::time_make_show(int hour, int min) {
    char str_hour[3],str_min[3];
    sprintf(str_hour,"%02d",hour);
    sprintf(str_min,"%02d",min);
    setRedBG();
    Paint_DrawString_EN(250-(14*2+2),2,str_min,&Font20,WHITE,BLACK);
    setBlcakBG();
    Paint_DrawString_EN(250-(14*3+2),2,":",&Font20,WHITE,BLACK);
    setRedBG();
    Paint_DrawString_EN(250-(14*5+2),2,str_hour,&Font20,WHITE,BLACK);
}

void epaper::tem_1_make_show(float tem1) {
    int int_part,decimal_part;
    char str_int[3],str_decimal[3];
    split_float(tem1,&int_part,&decimal_part);
    sprintf(str_int,"%02d",int_part);
    sprintf(str_decimal,"%02d",decimal_part);
    setBlcakBG();
    Paint_DrawString_CN(2,26,"温度:",&Font12CN,BLACK,WHITE);
    setRedBG();
    Paint_DrawString_EN(16*3-5,29,str_int,&Font16,WHITE,BLACK);
    Paint_DrawString_EN(16*3+11*2-5,29,".",&Font16,WHITE,BLACK);
    Paint_DrawString_EN(16*3+11*3-5,29,str_decimal,&Font16,WHITE,BLACK);
    setBlcakBG();
    Paint_DrawString_CN(16*3+11*5-5,26,"℃",&Font12CN,BLACK,WHITE);
}

void epaper::hum_make_show(float hum) {
    int int_part,decimal_part;
    char str_int[3],str_decimal[3];
    split_float(hum,&int_part,&decimal_part);
    sprintf(str_int,"%02d",int_part);
    sprintf(str_decimal,"%02d",decimal_part);
    setBlcakBG();
    Paint_DrawString_CN(2,44,"湿度:",&Font12CN,BLACK,WHITE);
    setRedBG();
    Paint_DrawString_EN(16*3-5,47,str_int,&Font16,WHITE,BLACK);
    Paint_DrawString_EN(16*3+11*2-5,47,".",&Font16,WHITE,BLACK);
    Paint_DrawString_EN(16*3+11*3-5,47,str_decimal,&Font16,WHITE,BLACK);
    setBlcakBG();
    Paint_DrawString_CN(16*3+11*5+2,44,"%",&Font12CN,BLACK,WHITE);
}

void epaper::hi_make_show(float hi) {
    int int_part,decimal_part;
    char str_int[3],str_decimal[3];
    split_float(hi,&int_part,&decimal_part);
    sprintf(str_int,"%02d",int_part);
    sprintf(str_decimal,"%02d",decimal_part);
    setBlcakBG();
    Paint_DrawString_CN(2,62,"热指数:",&Font12CN,BLACK,WHITE);
    setRedBG();
    Paint_DrawString_EN(16*4-5,65,str_int,&Font16,WHITE,BLACK);
    Paint_DrawString_EN(16*4+11*2-5,65,".",&Font16,WHITE,BLACK);
    Paint_DrawString_EN(16*4+11*3-5,65,str_decimal,&Font16,WHITE,BLACK);
    setBlcakBG();
    Paint_DrawString_CN(16*4+11*5-5,62,"℃",&Font12CN,BLACK,WHITE);
}

void epaper::tem_2_make_show(float tem2) {
    int int_part,decimal_part;
    char str_int[3],str_decimal[3];
    split_float(tem2,&int_part,&decimal_part);
    sprintf(str_int,"%02d",int_part);
    sprintf(str_decimal,"%02d",decimal_part);
    setBlcakBG();
    Paint_DrawString_CN(250-(16*3+11*6+3),26,"温度:",&Font12CN,BLACK,WHITE);
    setRedBG();
    Paint_DrawString_EN(250-(16+11*5+3),29,str_int,&Font16,WHITE,BLACK);
    Paint_DrawString_EN(250-(16+11*3+3),29,".",&Font16,WHITE,BLACK);
    Paint_DrawString_EN(250-(16+11*2+3),29,str_decimal,&Font16,WHITE,BLACK);
    setBlcakBG();
    Paint_DrawString_CN(250-(16+2),26,"℃",&Font12CN,BLACK,WHITE);
}

void epaper::pre_make_show(int32_t pre) {
    char str_pre[7];
    sprintf(str_pre,"%06d",pre);
    setBlcakBG();
    Paint_DrawString_CN(250-(16*3+11*7),44,"气压:",&Font12CN,BLACK,WHITE);
    setRedBG();
    Paint_DrawString_EN(250-(11*8),47,str_pre,&Font16,WHITE,BLACK);
    setBlcakBG();
    Paint_DrawString_EN(250-(11*2),47,"Pa",&Font16,WHITE,BLACK);
}

void epaper::display() {
    EPD_2IN13B_V4_Display(BlackImage,RImage);
    DEV_Delay_ms(2000);
}
void epaper::sleep() {
    printf("Goto Sleep...\r\n");
    EPD_2IN13B_V4_Sleep();
    free(BlackImage);
    free(RImage);
    BlackImage = NULL;
    RImage = NULL;
}
void epaper::clear() {
    EPD_2IN13B_V4_Clear();
    free(BlackImage);
    free(RImage);
    BlackImage = NULL;
    RImage = NULL;
}

void epaper::split_float(float num, int *int_part, int *decimal_part) {
    *int_part = (int)num;  // 将浮点数转换为整数
    *decimal_part = (int)((num - *int_part) * 100);  // 将小数部分转换为整数
}
