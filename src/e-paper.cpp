//
// Created by moexinjiajuan on 2022/10/28.
//

#include "e-paper.h"
#include "Arduino.h"
// IO settings
/* def
int BUSY_Pin = 16;
int RES_Pin = 5;
int DC_Pin = 4;
int CS_Pin = 14;
int SCK_Pin = 12;
int SDI_Pin = 13;
*/
int BUSY_Pin = 16;
int RES_Pin = 0;
int DC_Pin = 2;
int CS_Pin = 14;
int SCK_Pin = 12;
int SDI_Pin = 13;
#define EPD_W21_MOSI_0 digitalWrite(SDI_Pin, LOW)
#define EPD_W21_MOSI_1 digitalWrite(SDI_Pin, HIGH)

#define EPD_W21_CLK_0 digitalWrite(SCK_Pin, LOW)
#define EPD_W21_CLK_1 digitalWrite(SCK_Pin, HIGH)

#define EPD_W21_CS_0 digitalWrite(CS_Pin, LOW)
#define EPD_W21_CS_1 digitalWrite(CS_Pin, HIGH)

#define EPD_W21_DC_0 digitalWrite(DC_Pin, LOW)
#define EPD_W21_DC_1 digitalWrite(DC_Pin, HIGH)
#define EPD_W21_RST_0 digitalWrite(RES_Pin, LOW)
#define EPD_W21_RST_1 digitalWrite(RES_Pin, HIGH)
#define isEPD_W21_BUSY digitalRead(BUSY_Pin)
// 400*300///////////////////////////////////////

#define MONOMSB_MODE 1
#define MONOLSB_MODE 2
#define RED_MODE 3

#define MAX_LINE_BYTES 16 //=400/8
#define MAX_COLUMN_BYTES 250

#define ALLSCREEN_GRAGHBYTES 4000

void Sys_run(void)
{
    ESP.wdtFeed(); // Feed dog to prevent system reset
}

void LED_run(void)
{
    digitalWrite(LED_BUILTIN, LOW); // Turn the LED on (Note that LOW is the voltage level
    delay(500);
    digitalWrite(LED_BUILTIN, HIGH); // Turn the LED on (Note that LOW is the voltage level
    delay(500);
}

///////////////////EXTERNAL FUNCTION////////////////////////////////////////////////////////////////////////
/////////////////////delay//////////////////////////////////////
void driver_delay_us(unsigned int xus) // 1us
{
    for (; xus > 1; xus--)
        ;
}
void driver_delay_xms(unsigned long xms) // 1ms
{
    unsigned long i = 0, j = 0;

    for (j = 0; j < xms; j++)
    {
        for (i = 0; i < 256; i++)
            ;
    }
}
void DELAY_S(unsigned int delaytime)
{
    int i, j, k;
    for (i = 0; i < delaytime; i++)
    {
        for (j = 0; j < 4000; j++)
        {
            for (k = 0; k < 222; k++)
                ;
        }
    }
}
//////////////////////SPI///////////////////////////////////
void SPI_Delay(unsigned char xrate)
{
    unsigned char i;
    while (xrate)
    {
        for (i = 0; i < 2; i++)
            ;
        xrate--;
    }
}

void SPI_Write(unsigned char value)
{
    unsigned char i;
    SPI_Delay(1);
    for (i = 0; i < 8; i++)
    {
        EPD_W21_CLK_0;
        SPI_Delay(1);
        if (value & 0x80)
            EPD_W21_MOSI_1;
        else
            EPD_W21_MOSI_0;
        value = (value << 1);
        SPI_Delay(1);
        driver_delay_us(1);
        EPD_W21_CLK_1;
        SPI_Delay(1);
    }
}

void Epaper_Write_Command(unsigned char command)
{
    SPI_Delay(1);
    EPD_W21_CS_0;
    EPD_W21_DC_0; // command write
    SPI_Write(command);
    EPD_W21_CS_1;
}
void Epaper_Write_Data(unsigned char command)
{
    SPI_Delay(1);
    EPD_W21_CS_0;
    EPD_W21_DC_1; // command write
    SPI_Write(command);
    EPD_W21_CS_1;
}

/////////////////EPD settings Functions/////////////////////
void EPD_HW_InitPion(void ){
    pinMode(BUSY_Pin, INPUT);
    pinMode(RES_Pin, OUTPUT);
    pinMode(DC_Pin, OUTPUT);
    pinMode(CS_Pin, OUTPUT);
    pinMode(SCK_Pin, OUTPUT);
    pinMode(SDI_Pin, OUTPUT);
}


void EPD_HW_Init(void)
{
    EPD_W21_RST_0; // Module reset
    delay(10);     // At least 10ms delay
    EPD_W21_RST_1;
    delay(10); // At least 10ms delay

    Epaper_READBUSY();
    Epaper_Write_Command(0x12); // SWRESET
    Epaper_READBUSY();

    Epaper_Write_Command(0x01); // Driver output control
    Epaper_Write_Data(0xF9);
    Epaper_Write_Data(0x00);
    Epaper_Write_Data(0x00);

    Epaper_Write_Command(0x11); // data entry mode
    Epaper_Write_Data(0x01);

    Epaper_Write_Command(0x44); // set Ram-X address start/end position
    Epaper_Write_Data(0x00);
    Epaper_Write_Data(0x0F); // 0x0F-->(15+1)*8=128

    Epaper_Write_Command(0x45); // set Ram-Y address start/end position
    Epaper_Write_Data(0xF9);    // 0xF9-->(249+1)=250
    Epaper_Write_Data(0x00);
    Epaper_Write_Data(0x00);
    Epaper_Write_Data(0x00);

    Epaper_Write_Command(0x3C); // BorderWavefrom
    Epaper_Write_Data(0x05);

    Epaper_Write_Command(0x18); // Read built-in temperature sensor
    Epaper_Write_Data(0x80);

    Epaper_Write_Command(0x21); //  Display update control
    Epaper_Write_Data(0x00);
    Epaper_Write_Data(0x80);

    Epaper_Write_Command(0x4E); // set RAM x address count to 0;
    Epaper_Write_Data(0x00);
    Epaper_Write_Command(0x4F); // set RAM y address count to 0X199;
    Epaper_Write_Data(0xF9);
    Epaper_Write_Data(0x00);
    Epaper_READBUSY();
}
//////////////////////////////All screen update////////////////////////////////////////////
void EPD_WhiteScreen_ALL(bool onlyBW, unsigned char *BW_datas,unsigned char *R_datas)
{
    unsigned int i;
    Epaper_Write_Command(0x24); // write RAM for black(0)/white (1)
    for (i = 0; i < ALLSCREEN_GRAGHBYTES; i++)
    {
        Epaper_Write_Data(pgm_read_byte(&BW_datas[i]));
    }
    if (!onlyBW)
    {
        Epaper_Write_Command(0x26); // write RAM for black(0)/white (1)
        for (i = 0; i < ALLSCREEN_GRAGHBYTES; i++)
        {
            Epaper_Write_Data(~pgm_read_byte(&R_datas[i]));
        }
    }
    EPD_Update();
}

/////////////////////////////////////////////////////////////////////////////////////////
void EPD_Update(void)
{
    Epaper_Write_Command(0x22); // Display Update Control
    Epaper_Write_Data(0xF7);
    Epaper_Write_Command(0x20); // Activate Display Update Sequence
    Epaper_READBUSY();
}

void EPD_DeepSleep(void)
{
    Epaper_Write_Command(0x10); // enter deep sleep
    Epaper_Write_Data(0x01);
    delay(100);
}
void Epaper_READBUSY(void)
{
    while (1)
    { //=1 BUSY
        if (isEPD_W21_BUSY == 0)
            break;
        ESP.wdtFeed(); // Feed dog to prevent system reset
    }
}

void EPD_WhiteScreen_ALL_Clean(void)
{
    unsigned int i;
    Epaper_Write_Command(0x24); // write RAM for black(0)/white (1)
    for (i = 0; i < ALLSCREEN_GRAGHBYTES; i++)
    {
        Epaper_Write_Data(0xff);
    }
    Epaper_Write_Command(0x26); // write RAM for black(0)/white (1)
    for (i = 0; i < ALLSCREEN_GRAGHBYTES; i++)
    {
        Epaper_Write_Data(0x00);
    }
    EPD_Update();
}

//////////////////////////////////END//////////////////////////////////////////////////