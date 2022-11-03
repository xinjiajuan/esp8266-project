//
// Created by moexinjiajuan on 2022/11/2.
//

#include "array_make.h"
#include "e-paper.h"
#include "cstdlib"
/*
unsigned char Combine_gimage_Elements(
        int x_size,int y_size,
        int x_coord,int y_coord,
        unsigned char *MainArrayData,unsigned char *ElementsArrayData)
        {

    for (int i = 0; i < 54;++i) {
        if(i%3!=0){
            for (int j = 0; j < 2; ++j) {
                MainArrayData[bw_start+j]=ElementsArrayData[i+j];
            }
            bw_start=bw_start+16;
        }
    }

    return *MainArrayData;
}
*/

int arrayDistribution(int arraysize,int share){
    return arraysize/share;
}

char hextobin(char *hex)
{
    int i=0;
    char bin[9];
    while(hex[i])
    {
        switch(hex[i])
        {
            case '0':
                strcat(bin,"0000");
                break;
            case '1':
                strcat(bin,"0001");
                break;
            case '2':
                strcat(bin,"0010");
                break;
            case '3':
                strcat(bin,"0011");
                break;
            case '4':
                strcat(bin,"0100");
                break;
            case '5':
                strcat(bin,"0101");
                break;
            case '6':
                strcat(bin,"0110");
                break;
            case '7':
                strcat(bin,"0111");
                break;
            case '8':
                strcat(bin,"1000");
                break;
            case '9':
                strcat(bin,"1000");
                break;
            case 'A':
                strcat(bin,"1010");
                break;
            case 'a':
                strcat(bin,"1010");
                break;
            case 'B':
                strcat(bin,"1011");
                break;
            case 'b':
                strcat(bin,"1011");
                break;
            case 'C':
                strcat(bin,"1100");
                break;
            case 'c':
                strcat(bin,"1100");
                break;
            case 'D':
                strcat(bin,"1101");
                break;
            case 'd':
                strcat(bin,"1101");
                break;
            case 'E':
                strcat(bin,"1110");
                break;
            case 'e':
                strcat(bin,"1110");
                break;
            case 'F':
                strcat(bin,"1111");
                break;
            case 'f':
                strcat(bin,"1111");
                break;
        }
        i++;
    }
    return *bin;
}