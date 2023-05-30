//
// Created by moexinjiajuan on 2023/5/25.
//

#include "epaper.h"

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
}

void epaper::date_make_show(int year,int month,int day) {
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);
    Paint_DrawLine(0,22,250,22,BLACK,DOT_PIXEL_2X2,LINE_STYLE_SOLID);

}