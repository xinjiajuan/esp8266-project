/* Includes ------------------------------------------------------------------*/
#include "DEV_Config.h"
#include "EPD.h"
#include "GUI_Paint.h"
#include "imagedata.h"
#include <stdlib.h>

/* Entry point ----------------------------------------------------------------*/
void setup()
{
  printf("EPD_4IN2B_V2_test Demo\r\n");
  DEV_Module_Init();

  printf("e-Paper Init and Clear...\r\n");
  EPD_4IN2B_V2_Init();
  EPD_4IN2B_V2_Clear();
  DEV_Delay_ms(500);

  //Create a new image cache named IMAGE_BW and fill it with white
  UBYTE *Image; // black \Red or Yellow
  UWORD Imagesize = ((EPD_4IN2B_V2_WIDTH % 8 == 0) ? (EPD_4IN2B_V2_WIDTH / 8 ) : (EPD_4IN2B_V2_WIDTH / 8 + 1)) * EPD_4IN2B_V2_HEIGHT;
  if ((Image = (UBYTE *)malloc(Imagesize / 2)) == NULL) {
    printf("Failed to apply for half memory...\r\n");
    while(1);
  }
  printf("NewImage:BlackImage and RYImage\r\n");
  Paint_NewImage(Image, EPD_4IN2B_V2_WIDTH, EPD_4IN2B_V2_HEIGHT / 2, 0, WHITE);

  //Select Image
  Paint_SelectImage(Image);
  Paint_Clear(WHITE);

#if 1 // show image for array    
  printf("show image for array\r\n");
  EPD_4IN2B_V2_Display(gImage_4in2bc_b, gImage_4in2bc_ry);
  DEV_Delay_ms(2000);
#endif

#if 1   //Not enough memory, sending in four times: black 2times,red 2times
  /*Horizontal screen*/
  //1.Draw black image
  printf("Draw black image\r\n");
  Paint_Clear(WHITE);
  Paint_DrawPoint(10, 80, BLACK, DOT_PIXEL_1X1, DOT_STYLE_DFT);
  Paint_DrawPoint(10, 90, BLACK, DOT_PIXEL_2X2, DOT_STYLE_DFT);
  Paint_DrawPoint(10, 100, BLACK, DOT_PIXEL_3X3, DOT_STYLE_DFT);
  Paint_DrawPoint(10, 110, BLACK, DOT_PIXEL_3X3, DOT_STYLE_DFT);
  Paint_DrawLine(20, 70, 70, 120, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
  Paint_DrawLine(70, 70, 20, 120, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
  Paint_DrawRectangle(20, 70, 70, 120, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
  Paint_DrawRectangle(80, 70, 130, 120, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
  Paint_DrawString_EN(10, 0, "waveshare", &Font16, BLACK, WHITE);
  Paint_DrawString_CN(130, 20, "微雪电子", &Font24CN, WHITE, BLACK);
  Paint_DrawNum(10, 50, 987654321, &Font16, WHITE, BLACK);
  EPD_4IN2B_V2_SendHalfBimage(0, Image);
  EPD_4IN2B_V2_SendHalfBimage(1, Image);
  
  //2.Draw red image
  printf("Draw red image\r\n");
  Paint_Clear(WHITE);
  Paint_DrawCircle(160, 95, 20, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
  Paint_DrawCircle(210, 95, 20, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
  Paint_DrawLine(85, 95, 125, 95, BLACK, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
  Paint_DrawLine(105, 75, 105, 115, BLACK, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
  Paint_DrawString_CN(130, 0, "你好abc", &Font12CN, BLACK, WHITE);
  Paint_DrawString_EN(10, 20, "hello world", &Font12, WHITE, BLACK);
  Paint_DrawNum(10, 33, 123456789, &Font12, BLACK, WHITE);
  EPD_4IN2B_V2_SendHalfRYimage(0, Image);
  EPD_4IN2B_V2_SendHalfRYimage(1, Image);

  printf("EPD_Display\r\n");
  EPD_4IN2B_V2_TurnOnDisplay();
  DEV_Delay_ms(2000);
#endif

  printf("Clear...\r\n");
  EPD_4IN2B_V2_Clear();

  printf("Goto Sleep...\r\n");
  EPD_4IN2B_V2_Sleep();
  free(Image);
  Image = NULL;
}

/* The main loop -------------------------------------------------------------*/
void loop()
{
  //
}
