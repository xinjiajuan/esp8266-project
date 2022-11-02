#include <Arduino.h>
#include "DHT.h"
#include "Adafruit_BMP085.h"
#include "e-paper.h"
#include "res/wifi.h"
#include "avr/pgmspace.h"

#define DHTType DHT22
#define DHTPin 13
DHT dht(DHTPin,DHTType);
Adafruit_BMP085 bmp;


void setup() {
// write your initialization code here

    Serial.begin(115200);
    EPD_HW_InitPion();
    ESP.wdtDisable();
}

void loop() {
    while (1)
    {
        // Clean
        /*
        unsigned char gImage[4000] PROGMEM={};
        for (int i = 0; i < 4000; ++i) {
            gImage[i]=gImage_BW[i];
        }*/
        int bw_start=3648;
        for (int i = 0; i < 19; ++i) {
            for (int j = 0; j < 3; ++j) {
            gImage_BW[bw_start]=wifi_3_18x14[j];
            }
            bw_start=bw_start+16;
        }
        EPD_HW_Init(); // Electronic paper initialization
        EPD_WhiteScreen_ALL_Clean();
        EPD_DeepSleep(); // Enter deep sleep,Sleep instruction is necessary, please do not delete!!!

        // Full screen refresh
        EPD_HW_Init();                            // Electronic paper initialization
        EPD_WhiteScreen_ALL(true,gImage_BW, gImage_R); // Refresh the picture in full screen
        EPD_DeepSleep();                          // Enter deep sleep,Sleep instruction is necessary, please do not delete!!!
        delay(2000);

        // Clean
        /*
        EPD_HW_Init(); // Electronic paper initialization
        EPD_WhiteScreen_ALL_Clean();
        EPD_DeepSleep(); // Enter deep sleep,Sleep instruction is necessary, please do not delete!!!
         */
        while (1)
        {
            Sys_run(); // System run
            LED_run(); // Breathing lamp
        }
    }
}