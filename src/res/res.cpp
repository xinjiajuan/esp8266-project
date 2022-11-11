//
// Created by moexinjiajuan on 2022/11/6.
//

#include "res/res.h"

//wifi icon
unsigned char Wifi_Icon[5][34] = {
        {//full
                0XFB, 0XFF, 0XF0, 0XFF,
                0XF0, 0X7F, 0XE0, 0X3F,
                0XE0, 0X0F, 0XE0, 0X07,
                0XC0, 0X03, 0XC0, 0X01,
                0XC0, 0X00, 0XC0, 0X01,
                0XC0, 0X03, 0XE0, 0X07,
                0XE0, 0X1F, 0XE0, 0X3F,
                0XF0, 0X7F, 0XF1, 0XFF,
                0XFB, 0XFF,
        },
        {//wifi1
                0XFB, 0XFF, 0XF0, 0XFF,
                0XF4, 0X7F, 0XE7, 0X3F,
                0XEF, 0X8F, 0XEF, 0XE7,
                0XCF, 0XE3, 0XCF, 0XC0,
                0XCF, 0XC0, 0XCF, 0XC1,
                0XCF, 0XE3, 0XEF, 0XC7,
                0XE7, 0X9F, 0XE7, 0X3F,
                0XF4, 0X7F, 0XF0, 0XFF,
                0XFB, 0XFF,
        },
        {//wifi2
                0XF9, 0XFF, 0XF0, 0XFF,
                0XF4, 0X7F, 0XE7, 0X1F,
                0XEF, 0X8F, 0XEF, 0X07,
                0XEF, 0X01, 0XCF, 0X00,
                0XCF, 0X00, 0XCF, 0X01,
                0XEF, 0X03, 0XEF, 0X07,
                0XEF, 0X8F, 0XE6, 0X3F,
                0XF4, 0X7F, 0XF8, 0XFF,
                0XFB, 0XFF,
        },
        {//wifi3
                0XFB, 0XFF, 0XF1, 0XFF,
                0XF4, 0X7F, 0XEC, 0X3F,
                0XE8, 0X1F, 0XC8, 0X07,
                0XC8, 0X03, 0XD8, 0X01,
                0XD8, 0X00, 0XD8, 0X01,
                0XC8, 0X03, 0XE8, 0X0F,
                0XE8, 0X1F, 0XE4, 0X3F,
                0XF4, 0XFF, 0XF1, 0XFF,
                0XFB, 0XFF,
        },
        {//nowifi
                0XB1, 0XFF, 0X80, 0XFF,
                0XC0, 0X7F, 0XE0, 0X1F,
                0XC0, 0X0F, 0XC0, 0X07,
                0XC0, 0X01, 0XC0, 0X01,
                0XC0, 0X01, 0XC0, 0X03,
                0XC0, 0X07, 0XE0, 0X03,
                0XE0, 0X31, 0XE0, 0X78,
                0XF0, 0XFC, 0XFB, 0XFF,
        }
};

//fonts number


unsigned char Front_int_X17[10][14]{
        { //0
                0XF8, 0X1F,
                0XE7, 0XE7,
                0XDF, 0XFB,
                0XDF, 0XFB,
                0XDF, 0XFB,
                0XE7, 0XE7,
                0XF8, 0X1F,
        },{ //1
                0xFF, 0xFF,
                0XEF, 0XFB,
                0XEF, 0XFB,
                0XC0, 0X03,
                0XFF, 0XFB,
                0XFF, 0XFB,
                0xFF, 0xFF,
        },{ //2
                0XF3, 0XF3,
                0XEF, 0XEB,
                0XDF, 0XDB,
                0XDF, 0XBB,
                0XDF, 0X7B,
                0XEE, 0XFB,
                0XF1, 0XE3,
        },{ //3
                0XE7, 0XE7,
                0XDF, 0XFB,
                0XDE, 0XFB,
                0XDE, 0XFB,
                0XDE, 0XFB,
                0XED, 0X77,
                0XF3, 0X8F,
        },{ //4
                0XFF, 0X9F,
                0XFE, 0X5F,
                0XF9, 0XDB,
                0XF7, 0XDB,
                0XC0, 0X03,
                0XFF, 0XDB,
                0XFF, 0XDB,
        },{ //5
                0XFF, 0XC7,
                0XC0, 0XFB,
                0XDD, 0XFB,
                0XDD, 0XFB,
                0XDD, 0XFB,
                0XDE, 0XF7,
                0XDF, 0X0F,
        },{ //6
                0XF8, 0X0F,
                0XE6, 0XF7,
                0XDD, 0XFB,
                0XDD, 0XFB,
                0XDD, 0XFB,
                0XEE, 0XF7,
                0XFF, 0X0F,
        },{ //7
                0XC7, 0XFF,
                0XDF, 0XFF,
                0XDF, 0X83,
                0XDE, 0X7F,
                0XD9, 0XFF,
                0XC7, 0XFF,
                0XDF, 0XFF,
        },{ //8
                0XF3, 0X8F,
                0XED, 0X77,
                0XDE, 0XFB,
                0XDE, 0XFB,
                0XDE, 0XFB,
                0XED, 0X77,
                0XF3, 0X8F,
        },{ //9
                0XF0, 0XFF,
                0XEF, 0X77,
                0XDF, 0XBB,
                0XDF, 0XBB,
                0XDF, 0XBB,
                0XEF, 0X67,
                0XF0, 0X1F,
        }
};

//front number big
unsigned char Front_int_X32[10][42]{
        { //0
                0xFF, 0xFF, 0xFF,
                0XFF, 0XC1, 0XFF,
                0XFC, 0X00, 0X1F,
                0XF0, 0X00, 0X07,
                0XE3, 0XFF, 0XC3,
                0XCF, 0XFF, 0XF9,
                0XDF, 0XFF, 0XFD,
                0XBF, 0XFF, 0XFD,
                0XBF, 0XFF, 0XFD,
                0XDF, 0XFF, 0XFD,
                0XCF, 0XFF, 0XF3,
                0XE1, 0XFF, 0X83,
                0XF0, 0X00, 0X0F,
                0XFE, 0X00, 0X3F,
        },
        { //1
                0xFF, 0xFF, 0xFF,
                0xFF, 0xFF, 0xFF,
                0XEF, 0XFF, 0XFD,
                0XEF, 0XFF, 0XFD,
                0XEF, 0XFF, 0XFD,
                0XEF, 0XFF, 0XFD,
                0XC0, 0X00, 0X01,
                0X80, 0X00, 0X01,
                0XFF, 0XFF, 0XFD,
                0XFF, 0XFF, 0XFD,
                0XFF, 0XFF, 0XFD,
                0XFF, 0XFF, 0XFD,
                0xFF, 0xFF, 0xFF,
                0xFF, 0xFF, 0xFF,
        },
        { //2
                0xFF, 0xFF, 0xFF,
                0XFF, 0XFF, 0XF9,
                0XF0, 0XFF, 0XF1,
                0XE0, 0X7F, 0XE9,
                0XDE, 0XFF, 0X99,
                0XDF, 0XFF, 0X39,
                0XBF, 0XFE, 0X79,
                0XBF, 0XFC, 0XF9,
                0XBF, 0XF9, 0XF9,
                0XDF, 0XF3, 0XF9,
                0XDF, 0XC7, 0XF9,
                0XC0, 0X0F, 0XF9,
                0XE0, 0X3F, 0XF1,
                0XF8, 0XFF, 0XCF,
        },
        { //3
                0xFF, 0xFF, 0xFF,
                0XF1, 0XFF, 0XC7,
                0XE1, 0XFF, 0X83,
                0XDD, 0XFF, 0XC9,
                0XDF, 0XFF, 0XFD,
                0XBF, 0XEF, 0XFD,
                0XBF, 0XEF, 0XFD,
                0XBF, 0XEF, 0XFD,
                0XDF, 0XD7, 0XFD,
                0XC7, 0X97, 0XF9,
                0XE0, 0X38, 0XE3,
                0XF0, 0X78, 0X07,
                0XFF, 0XFE, 0X1F,
                0xFF, 0xFF, 0xFF,
        },
        { //4
                0XFF, 0XFE, 0X7F,
                0XFF, 0XF9, 0X7F,
                0XFF, 0XF3, 0X7F,
                0XFF, 0XCF, 0X7F,
                0XFF, 0XBF, 0X7F,
                0XFE, 0X7F, 0X7D,
                0XFD, 0XFF, 0X7D,
                0XF3, 0XFF, 0X7D,
                0XC0, 0X00, 0X01,
                0X80, 0X00, 0X01,
                0XFF, 0XFF, 0X79,
                0XFF, 0XFF, 0X7D,
                0XFF, 0XFF, 0X7D,
                0XFF, 0XFF, 0X7F,
        },
        { //5
                0xFF, 0xFF, 0xFF,
                0XFF, 0XFF, 0X87,
                0XC0, 0X07, 0X83,
                0XCF, 0XEF, 0XDD,
                0XCF, 0XDF, 0XFD,
                0XCF, 0XDF, 0XFD,
                0XCF, 0X9F, 0XFD,
                0XCF, 0X9F, 0XFD,
                0XCF, 0X9F, 0XFD,
                0XCF, 0XCF, 0XF9,
                0XCF, 0XC3, 0XE3,
                0XCF, 0XE0, 0X07,
                0XFF, 0XF8, 0X1F,
                0xFF, 0xFF, 0xFF,
        },
        { //6
                0xFF, 0xFF, 0xFF,
                0XFF, 0XE0, 0XFF,
                0XFC, 0X00, 0X0F,
                0XF0, 0X00, 0X07,
                0XE3, 0XE7, 0XE3,
                0XCF, 0XCF, 0XF9,
                0XDF, 0XDF, 0XFD,
                0XDF, 0X9F, 0XFD,
                0XBF, 0X9F, 0XFD,
                0XBF, 0X9F, 0XFD,
                0XDF, 0XDF, 0XFD,
                0XC3, 0XC7, 0XF3,
                0XE7, 0XE0, 0X07,
                0XFF, 0XF0, 0X0F,
        },
        { //7
                0xFF, 0xFF, 0xFF,
                0XE1, 0XFF, 0XFF,
                0XC7, 0XFF, 0XFF,
                0XCF, 0XFF, 0XFF,
                0XCF, 0XFF, 0XFF,
                0XCF, 0XFF, 0X01,
                0XCF, 0XF8, 0X01,
                0XCF, 0XE1, 0XFF,
                0XCF, 0X8F, 0XFF,
                0XCE, 0X7F, 0XFF,
                0XC9, 0XFF, 0XFF,
                0XC7, 0XFF, 0XFF,
                0XDF, 0XFF, 0XFF,
                0xFF, 0xFF, 0xFF,
        },
        { //8
                0xFF, 0xFF, 0xFF,
                0XFF, 0XFF, 0X1F,
                0XF0, 0X7C, 0X07,
                0XE0, 0X39, 0XF3,
                0XCF, 0X13, 0XF9,
                0XDF, 0X87, 0XFD,
                0XBF, 0XCF, 0XFD,
                0XBF, 0XC7, 0XFD,
                0XBF, 0XE7, 0XFD,
                0XDF, 0XE3, 0XFD,
                0XDF, 0XD1, 0XFD,
                0XCF, 0X98, 0XFB,
                0XE0, 0X3C, 0X07,
                0XF8, 0XFE, 0X0F,
        },
        { //9
                0xFF, 0xFF, 0xFF,
                0XFC, 0X1F, 0XFF,
                0XF0, 0X07, 0XF7,
                0XE1, 0XC3, 0XE3,
                0XCF, 0XF9, 0XE1,
                0XDF, 0XF9, 0XFD,
                0XBF, 0XFD, 0XFD,
                0XBF, 0XFD, 0XFD,
                0XBF, 0XFD, 0XFD,
                0XDF, 0XFB, 0XFB,
                0XCF, 0XF7, 0XE3,
                0XE3, 0XCE, 0X07,
                0XF0, 0X00, 0X1F,
                0XFC, 0X00, 0XFF,
        }
};


//front symbol
unsigned char _Celsius_Symbol_C[28]{
        0XE3, 0XFF,
        0XDD, 0XFF,
        0XDD, 0XFF,
        0XE3, 0XFF,
        0XFF, 0XFF,
        0XFC, 0X1F,
        0XF0, 0X07,
        0XF3, 0XE7,
        0XEF, 0XF3,
        0XEF, 0XFB,
        0XEF, 0XFB,
        0XEF, 0XF3,
        0XF3, 0XE7,
        0XF3, 0XE7,
};
unsigned char _Colon_Symbol_[8]{
        0X9F, 0XF3,
        0X0F, 0XE1,
        0X0F, 0XE1,
        0X9F, 0XF3,
};
unsigned char _DecimalPoint_[2]{
        0xF3,
        0xF3,
};

unsigned char _Percent_Symbol[14]{
        0XE1, 0XFF,
        0XDE, 0XE7,
        0XE1, 0X9F,
        0XFC, 0X7F,
        0XF3, 0X0F,
        0XCE, 0XF7,
        0XFF, 0X0F,
};

//alphabet
unsigned char _A_Front[16]{
        0XFF, 0XF7,
        0XFF, 0X87,
        0XF8, 0X77,
        0XC7, 0X7F,
        0XF1, 0X7F,
        0XFE, 0X37,
        0XFF, 0XC7,
        0XFF, 0XF7,
};
unsigned char _B_Front[14]{
        0XDF, 0XF7,
        0XC0, 0X07,
        0XDD, 0XF7,
        0XDD, 0XF7,
        0XDD, 0XF7,
        0XE2, 0XEF,
        0XFF, 0X1F,
};
unsigned char _C_Front[14]{
        0XF8, 0X3F,
        0XE7, 0XCF,
        0XDF, 0XF7,
        0XDF, 0XF7,
        0XDF, 0XF7,
        0XDF, 0XEF,
        0XC7, 0XDF,
};
unsigned char _D_Front[14]{
        0XDF, 0XF7,
        0XC0, 0X07,
        0XDF, 0XF7,
        0XDF, 0XF7,
        0XDF, 0XF7,
        0XEF, 0XEF,
        0XF0, 0X1F,
};
unsigned char _E_Front[14]{
        0XDF, 0XF7,
        0XC0, 0X07,
        0XDD, 0XF7,
        0XDD, 0XF7,
        0XD0, 0X77,
        0XDF, 0XF7,
        0XEF, 0XCF,
};
unsigned char _F_Front[14]{
        0XDF, 0XF7,
        0XC0, 0X07,
        0XDD, 0XF7,
        0XDD, 0XFF,
        0XD0, 0X7F,
        0XDF, 0XFF,
        0XEF, 0XFF,
};
unsigned char _G_Front[14]{
        0XF8, 0X3F,
        0XE7, 0XCF,
        0XDF, 0XF7,
        0XDF, 0XF7,
        0XDF, 0X77,
        0XC7, 0X0F,
        0XFF, 0X7F,
};
unsigned char _H_Front[16]{
        0XDF, 0XF7,
        0XC0, 0X07,
        0XDE, 0XF7,
        0XFE, 0XFF,
        0XFE, 0XFF,
        0XDE, 0XF7,
        0XC0, 0X07,
        0XDF, 0XF7,
};
unsigned char _I_Front[10]{
        0XDF, 0XF7,
        0XDF, 0XF7,
        0XC0, 0X07,
        0XDF, 0XF7,
        0XDF, 0XF7,
};
unsigned char _J_Front[14]{
        0XFF, 0XF9,
        0XFF, 0XFD,
        0XDF, 0XFD,
        0XDF, 0XFD,
        0XC0, 0X03,
        0XDF, 0XFF,
        0XDF, 0XFF,
};
unsigned char _K_Front[14]{
        0XDF, 0XF7,
        0XC0, 0X07,
        0XDD, 0XF7,
        0XF8, 0XFF,
        0XD7, 0X37,
        0XCF, 0XC7,
        0XDF, 0XF7,
};
unsigned char _L_Front[14]{
        0XDF, 0XF7,
        0XC0, 0X07,
        0XDF, 0XF7,
        0XFF, 0XF7,
        0XFF, 0XF7,
        0XFF, 0XF7,
        0XFF, 0XE7,
};
unsigned char _M_Front[14]{
        0XDF, 0XF7,
        0XC0, 0X07,
        0XC0, 0XFF,
        0XFF, 0X07,
        0XC0, 0XFF,
        0XC0, 0X07,
        0XDF, 0XF7,
};
unsigned char _N_Front[16]{
        0XDF, 0XF7,
        0XC0, 0X07,
        0XE7, 0XF7,
        0XF9, 0XFF,
        0XFE, 0X3F,
        0XDF, 0XCF,
        0XC0, 0X07,
        0XDF, 0XFF,
};
unsigned char _O_Front[14]{
        0XF0, 0X1F,
        0XEF, 0XEF,
        0XDF, 0XF7,
        0XDF, 0XF7,
        0XDF, 0XF7,
        0XEF, 0XEF,
        0XF0, 0X1F,
};
unsigned char _P_Front[14]{
        0XDF, 0XF7,
        0XC0, 0X07,
        0XDE, 0XF7,
        0XDE, 0XFF,
        0XDE, 0XFF,
        0XDE, 0XFF,
        0XE1, 0XFF,
};
unsigned char _Q_Front[14]{
        0XF0, 0X1F,
        0XEF, 0XEF,
        0XDF, 0XD7,
        0XDF, 0XD7,
        0XDF, 0XE7,
        0XEF, 0XEB,
        0XF0, 0X1B,
};
unsigned char _R_Front[16]{
        0XDF, 0XF7,
        0XC0, 0X07,
        0XDD, 0XF7,
        0XDD, 0XFF,
        0XDC, 0X7F,
        0XDD, 0X9F,
        0XE3, 0XE7,
        0XFF, 0XF7,
};
unsigned char _S_Front[12]{
        0XE3, 0XC7,
        0XDD, 0XF7,
        0XDE, 0XF7,
        0XDE, 0XF7,
        0XDF, 0X77,
        0XC7, 0X8F,
};
unsigned char _T_Front[14]{
        0XCF, 0XFF,
        0XDF, 0XFF,
        0XDF, 0XF7,
        0XC0, 0X07,
        0XDF, 0XF7,
        0XDF, 0XFF,
        0XCF, 0XFF,
};
unsigned char _U_Front[16]{
        0XDF, 0XFF,
        0XC0, 0X0F,
        0XDF, 0XF7,
        0XFF, 0XF7,
        0XFF, 0XF7,
        0XDF, 0XF7,
        0XC0, 0X0F,
        0XDF, 0XFF,
};
unsigned char _V_Front[16]{
        0XDF, 0XFF,
        0XC3, 0XFF,
        0XDC, 0X3F,
        0XFF, 0XC7,
        0XFF, 0X1F,
        0XD8, 0XFF,
        0XC7, 0XFF,
        0XDF, 0XFF,
};
unsigned char _W_Front[14]{
        0XDF, 0XFF,
        0XC0, 0X7F,
        0XFF, 0X07,
        0XC0, 0XFF,
        0XFF, 0X07,
        0XC0, 0X7F,
        0XDF, 0XFF,
};
unsigned char _X_Front[16]{
        0XDF, 0XF7,
        0XCF, 0XE7,
        0XD3, 0X97,
        0XFC, 0X7F,
        0XFC, 0X7F,
        0XD3, 0X97,
        0XCF, 0XE7,
        0XDF, 0XF7,
};
unsigned char _Y_Front[14]{
        0XDF, 0XFF,
        0XC7, 0XFF,
        0XD9, 0XF7,
        0XFE, 0X07,
        0XD9, 0XF7,
        0XC7, 0XFF,
        0XDF, 0XFF,
};
unsigned char _Z_Front[14]{
        0XEF, 0XF7,
        0XDF, 0XC7,
        0XDF, 0X37,
        0XDE, 0XF7,
        0XD9, 0XF7,
        0XC7, 0XF7,
        0XDF, 0XCF,
};


//front lower case
unsigned char _a_Front[12]{
        0XFD, 0X9F,
        0XFB, 0X6F,
        0XFB, 0X6F,
        0XFA, 0XDF,
        0XFC, 0X0F,
        0XFF, 0XEF,
};
unsigned char _b_Front[14]{
        0XDF, 0XFF,
        0XC0, 0X0F,
        0XFD, 0XDF,
        0XFB, 0XEF,
        0XFB, 0XEF,
        0XFD, 0XDF,
        0XFE, 0X3F,
};
unsigned char _c_Front[12]{
        0XFE, 0X3F,
        0XFD, 0XDF,
        0XFB, 0XEF,
        0XFB, 0XEF,
        0XFB, 0XEF,
        0XFD, 0XDF,
};
unsigned char _d_Front[14]{
        0XFC, 0X1F,
        0XFB, 0XEF,
        0XFB, 0XEF,
        0XFB, 0XEF,
        0XDB, 0XDF,
        0XC0, 0X0F,
        0XFF, 0XEF,
};
unsigned char _e_Front[12]{
        0XFC, 0X1F,
        0XFB, 0X6F,
        0XFB, 0X6F,
        0XFB, 0X6F,
        0XFB, 0X6F,
        0XFC, 0X5F,
};
unsigned char _f_Front[12]{
        0XFB, 0XEF,
        0XFB, 0XEF,
        0XE0, 0X0F,
        0XDB, 0XEF,
        0XDB, 0XEF,
        0XEF, 0XFF,
};
unsigned char _g_Front[12]{
        0XFC, 0XA7,
        0XFB, 0X5B,
        0XFB, 0X5B,
        0XFB, 0X5B,
        0XF8, 0XDB,
        0XFB, 0XE7,
};
unsigned char _h_Front[16]{
        0XDF, 0XEF,
        0XC0, 0X0F,
        0XFD, 0XEF,
        0XFB, 0XFF,
        0XFB, 0XFF,
        0XFB, 0XEF,
        0XFC, 0X0F,
        0XFF, 0XEF,
};
unsigned char _i_Front[10]{
        0XFB, 0XEF,
        0X9B, 0XEF,
        0X98, 0X0F,
        0XFF, 0XEF,
        0XFF, 0XEF,
};
unsigned char _j_Front[10]{
        0XFF, 0XF3,
        0XFF, 0XFB,
        0XFB, 0XFB,
        0X9B, 0XFB,
        0X98, 0X07,
};
unsigned char _k_Front[14]{
        0XDF, 0XEF,
        0XC0, 0X0F,
        0XFF, 0X6F,
        0XFE, 0X7F,
        0XF9, 0XAF,
        0XFB, 0XCF,
        0XFB, 0XEF,
};
unsigned char _l_Front[10]{
        0XDF, 0XEF,
        0XDF, 0XEF,
        0X80, 0X0F,
        0XFF, 0XEF,
        0XFF, 0XEF,
};
unsigned char _m_Front[18]{
        0XFB, 0XEF,
        0XF8, 0X0F,
        0XFB, 0XEF,
        0XFB, 0XFF,
        0XF8, 0X0F,
        0XFB, 0XEF,
        0XFB, 0XFF,
        0XFC, 0X0F,
        0XFF, 0XEF,
};
unsigned char _n_Front[16]{
        0XFB, 0XEF,
        0XF8, 0X0F,
        0XFD, 0XEF,
        0XFB, 0XFF,
        0XFB, 0XFF,
        0XFB, 0XEF,
        0XFC, 0X0F,
        0XFF, 0XEF,
};
unsigned char _o_Front[12]{
        0XFC, 0X1F,
        0XFB, 0XEF,
        0XFB, 0XEF,
        0XFB, 0XEF,
        0XFB, 0XEF,
        0XFC, 0X1F,
};
unsigned char _p_Front[14]{
        0XFB, 0XFB,
        0XF8, 0X03,
        0XFD, 0XDB,
        0XFB, 0XEF,
        0XFB, 0XEF,
        0XFD, 0XDF,
        0XFE, 0X3F,
};
unsigned char _q_Front[14]{
        0XFE, 0X3F,
        0XFD, 0XDF,
        0XFB, 0XEF,
        0XFB, 0XEF,
        0XFD, 0XDB,
        0XF8, 0X03,
        0XFF, 0XFB,
};
unsigned char _r_Front[14]{
        0XFB, 0XEF,
        0XFB, 0XEF,
        0XF8, 0X0F,
        0XFD, 0XEF,
        0XFB, 0XEF,
        0XFB, 0XFF,
        0XF9, 0XFF,
};
unsigned char _s_Front[12]{
        0XFC, 0XCF,
        0XFB, 0X6F,
        0XFB, 0X6F,
        0XFB, 0X6F,
        0XFB, 0X6F,
        0XF9, 0X9F,
};
unsigned char _t_Front[12]{
        0XFB, 0XFF,
        0XFB, 0XFF,
        0XE0, 0X1F,
        0XFB, 0XEF,
        0XFB, 0XEF,
        0XFF, 0XDF,
};
unsigned char _u_Front[16]{
        0XFB, 0XFF,
        0XF8, 0X1F,
        0XFF, 0XEF,
        0XFF, 0XEF,
        0XFF, 0XEF,
        0XFB, 0XDF,
        0XF8, 0X0F,
        0XFF, 0XEF,
};
unsigned char _v_Front[14]{
        0XFB, 0XFF,
        0XF8, 0XFF,
        0XFB, 0X3F,
        0XFF, 0XCF,
        0XFB, 0X3F,
        0XF8, 0XFF,
        0XFB, 0XFF,
};
unsigned char _w_Front[16]{
        0XF9, 0XFF,
        0XFA, 0X3F,
        0XFF, 0XCF,
        0XFB, 0X3F,
        0XF8, 0X7F,
        0XFF, 0X8F,
        0XFA, 0X7F,
        0XF9, 0XFF,
};
unsigned char _x_Front[12]{
        0XFB, 0XEF,
        0XF9, 0XCF,
        0XFA, 0X3F,
        0XFE, 0X2F,
        0XF9, 0XCF,
        0XFB, 0XEF,
};
unsigned char _y_Front[16]{
        0XFB, 0XFF,
        0XF9, 0XFB,
        0XFA, 0X7B,
        0XFF, 0X87,
        0XFF, 0X9F,
        0XFA, 0X7F,
        0XF9, 0XFF,
        0XFB, 0XFF,
};
unsigned char _z_Front[12]{
        0XF9, 0XEF,
        0XFB, 0XCF,
        0XFB, 0X2F,
        0XFA, 0XEF,
        0XF9, 0XEF,
        0XFB, 0XCF,
};
