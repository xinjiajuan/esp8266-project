#include <Arduino.h>
#include "DHT.h"
#include "Adafruit_BMP085.h"
#include "e-paper.h"
#include "res/wifi.h"
#include "avr/pgmspace.h"
#include "array_make.h"

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
        int bw_start=3648;
        //sizeof(wifi_full_g_18x14);
        for (int j = 0; j < sizeof(wifi_full_g_18x14); ++++j){
            for (int i = 0; i < 2;++i) {
                gImage_BW[bw_start + i] = wifi_full_g_18x14[j+i];
            }
            bw_start=bw_start+16;
        }

        EPD_HW_Init(); // Electronic paper initialization
        EPD_WhiteScreen_ALL_Clean();
        //EPD_DeepSleep(); // Enter deep sleep,Sleep instruction is necessary, please do not delete!!!

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