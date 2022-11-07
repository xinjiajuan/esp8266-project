//
// Created by moexinjiajuan on 2022/11/6.
//
#include "res/res.h"

unsigned char wifi_full[34] = {
        0XFB,0XFF,0XF0,0XFF,
        0XF0,0X7F,0XE0,0X3F,
        0XE0,0X0F,0XE0,0X07,
        0XC0,0X03,0XC0,0X01,
        0XC0,0X00,0XC0,0X01,
        0XC0,0X03,0XE0,0X07,
        0XE0,0X1F,0XE0,0X3F,
        0XF0,0X7F,0XF1,0XFF,
        0XFB,0XFF,
};
unsigned char wifi_1[34] = {
        0XFB,0XFF,0XF0,0XFF,
        0XF4,0X7F,0XE7,0X3F,
        0XEF,0X8F,0XEF,0XE7,
        0XCF,0XE3,0XCF,0XC0,
        0XCF,0XC0,0XCF,0XC1,
        0XCF,0XE3,0XEF,0XC7,
        0XE7,0X9F,0XE7,0X3F,
        0XF4,0X7F,0XF0,0XFF,
        0XFB,0XFF,
};

unsigned char wifi_2[34] = {
        0XF9,0XFF,0XF0,0XFF,
        0XF4,0X7F,0XE7,0X1F,
        0XEF,0X8F,0XEF,0X07,
        0XEF,0X01,0XCF,0X00,
        0XCF,0X00,0XCF,0X01,
        0XEF,0X03,0XEF,0X07,
        0XEF,0X8F,0XE6,0X3F,
        0XF4,0X7F,0XF8,0XFF,
        0XFB,0XFF,
};

unsigned char wifi_3[34] = {
        0XFB,0XFF,0XF1,0XFF,
        0XF4,0X7F,0XEC,0X3F,
        0XE8,0X1F,0XC8,0X07,
        0XC8,0X03,0XD8,0X01,
        0XD8,0X00,0XD8,0X01,
        0XC8,0X03,0XE8,0X0F,
        0XE8,0X1F,0XE4,0X3F,
        0XF4,0XFF,0XF1,0XFF,
        0XFB,0XFF,
};

unsigned char no_wifi[32] = {
        0XB1,0XFF,0X80,0XFF,
        0XC0,0X7F,0XE0,0X1F,
        0XC0,0X0F,0XC0,0X07,
        0XC0,0X01,0XC0,0X01,
        0XC0,0X01,0XC0,0X03,
        0XC0,0X07,0XE0,0X03,
        0XE0,0X31,0XE0,0X78,
        0XF0,0XFC,0XFB,0XFF,
};

//fonts
unsigned char _1_Front_Int[10]{ //1
        0XFF,0XFF,
        0XDF,0X7F,
        0X80,0X7F,
        0X7F,0XFF,
        0XFF,0XFF,
};

unsigned char _2_Front_Int[10]{ //2
        0XCE,0X7F,
        0XBD,0X7F,
        0XBB,0X7F,
        0XB7,0X7F,
        0XCF,0X7F,
};

unsigned char _3_Front_Int[10]{ //3
        0XDE,0XFF,
        0XBF,0X7F,
        0XB7,0X7F,
        0XB7,0X7F,
        0XC8,0XFF,
};

unsigned char _4_Front_Int[10]{ //4
        0XF9,0XFF,
        0XF5,0XFF,
        0XCD,0X7F,
        0X80,0X7F,
        0XFD,0X7F,
};

unsigned char _5_Front_Int[10]{ //5
        0X82,0XFF,
        0XB7,0X7F,
        0XB7,0X7F,
        0XB7,0X7F,
        0XB8,0XFF,
};

unsigned char _6_Front_Int[10]{ //6
        0XE0,0XFF,
        0XDB,0X7F,
        0XB7,0X7F,
        0XB7,0X7F,
        0XD8,0XFF,
};

unsigned char _7_Front_Int[10]{ //7
        0XBF,0XFF,
        0XB8,0X7F,
        0XA7,0XFF,
        0X9F,0XFF,
        0XFF,0XFF,
};

unsigned char _8_Front_Int[10]{ //8
        0XC8,0XFF,
        0XB7,0X7F,
        0XB7,0X7F,
        0XB7,0X7F,
        0XC8,0XFF,
};

unsigned char _9_Front_Int[10]{ //9
        0XC6,0XFF,
        0XBB,0X7F,
        0XBB,0X7F,
        0XB6,0XFF,
        0XC1,0XFF,
};

unsigned char _0_Front_Int[10]{ //0
        0XC0,0XFF,
        0XBF,0X7F,
        0XBF,0X7F,
        0XBF,0X7F,
        0XC0,0XFF,
};

//alphabet

unsigned char _A_Front[12]{
        0XFF,0XFD,
        0XFF,0XC1,
        0XFE,0X37,
        0XFF,0X87,
        0XFF,0XF1,
        0XFF,0XFD,
};
