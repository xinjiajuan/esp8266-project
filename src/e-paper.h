//
// Created by moexinjiajuan on 2022/10/28.
//

#ifndef ESP8266_PROJECT_E_PAPER_H
#define ESP8266_PROJECT_E_PAPER_H
#include "avr/pgmspace.h"

void driver_delay_us(unsigned int xus);
void driver_delay_xms(unsigned long xms);
void DELAY_S(unsigned int delaytime);
void SPI_Delay(unsigned char xrate);
void SPI_Write(unsigned char value);
void Epaper_Write_Command(unsigned char command);
void Epaper_Write_Data(unsigned char command);
// EPD
void Epaper_READBUSY(void);
void Epaper_Spi_WriteByte(unsigned char TxData);
void Epaper_Write_Command(unsigned char cmd);
void Epaper_Write_Data(unsigned char data);

void EPD_HW_Init(void); // Electronic paper initialization
void EPD_Update(void);
void EPD_DeepSleep(void);
// Display
void EPD_WhiteScreen_ALL(bool onlyBW, unsigned char *BW_datas,unsigned char *R_datas);
void EPD_WhiteScreen_ALL_Clean(void);
void Sys_run(void );
void LED_run(void);
void EPD_HW_InitPion(void );

extern const unsigned char gImage_BW[4000];
extern const unsigned char gImage_R[4000];
/*
extern int Epaper_size_x=250;
extern  int  Epaper_size_y=122;
*/
#endif //ESP8266_PROJECT_E_PAPER_H
