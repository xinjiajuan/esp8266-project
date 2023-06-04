/**
  ******************************************************************************
  * @file    Font12.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    18-February-2014
  * @brief   This file provides text Font12 for STM32xx-EVAL's LCD driver. 
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2014 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "fonts.h"

// 
//  Font data for Courier New 12pt
// 

const CH_CN Font12CN_Table[] = 
{
/*--  文字:  温  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
{"温",
        0x00,0x00,0x23,0xF8,0x12,0x08,0x12,0x08,0x83,0xF8,0x42,0x08,0x42,0x08,0x13,0xF8,
        0x10,0x00,0x27,0xFC,0xE4,0xA4,0x24,0xA4,0x24,0xA4,0x24,0xA4,0x2F,0xFE,0x00,0x00,},

/*--  文字:  湿  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
{"湿",
        0x00,0x00,0x27,0xF8,0x14,0x08,0x14,0x08,0x87,0xF8,0x44,0x08,0x44,0x08,0x17,0xF8,
        0x11,0x20,0x21,0x20,0xE9,0x24,0x25,0x28,0x23,0x30,0x21,0x20,0x2F,0xFE,0x00,0x00,},

/*--  文字:  度  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
{"度",
        0x01,0x00,0x00,0x80,0x3F,0xFE,0x22,0x20,0x22,0x20,0x3F,0xFC,0x22,0x20,0x22,0x20,
        0x23,0xE0,0x20,0x00,0x2F,0xF0,0x24,0x10,0x42,0x20,0x41,0xC0,0x86,0x30,0x38,0x0E,},

/*--  文字:  热  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
{"热",
        0x10,0x40,0x10,0x40,0x10,0x40,0xFD,0xF8,0x10,0x48,0x10,0x48,0x1C,0xC8,0x30,0x48,
        0xD0,0xAA,0x10,0xAA,0x51,0x06,0x22,0x02,0x00,0x00,0x48,0x88,0x44,0x44,0x84,0x44,},

/*--  文字:  指  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
{"指",
        0x11,0x00,0x11,0x04,0x11,0x38,0x11,0xC0,0xFD,0x02,0x11,0x02,0x10,0xFE,0x14,0x00,
        0x19,0xFC,0x31,0x04,0xD1,0x04,0x11,0xFC,0x11,0x04,0x11,0x04,0x51,0xFC,0x21,0x04,},

/*--  文字:  数  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
{"数",
        0x08,0x20,0x49,0x20,0x2A,0x20,0x08,0x3E,0xFF,0x44,0x2A,0x44,0x49,0x44,0x88,0xA4,
        0x10,0x28,0xFE,0x28,0x22,0x10,0x42,0x10,0x64,0x28,0x18,0x28,0x34,0x44,0xC2,0x82,},

/*--  文字:  气  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
{"气",
        0x10,0x00,0x10,0x00,0x3F,0xFC,0x20,0x00,0x4F,0xF0,0x80,0x00,0x3F,0xF0,0x00,0x10,
        0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x0A,0x00,0x0A,0x00,0x06,0x00,0x02,},

/*--  文字:  压  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
{"压",
        0x00,0x00,0x3F,0xFE,0x20,0x00,0x20,0x80,0x20,0x80,0x20,0x80,0x20,0x80,0x2F,0xFC,
        0x20,0x80,0x20,0x80,0x20,0x90,0x20,0x88,0x20,0x88,0x40,0x80,0x5F,0xFE,0x80,0x00,},

/*--  文字:  年  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
{"年",
        0x10,0x00,0x10,0x00,0x1F,0xFC,0x20,0x80,0x20,0x80,0x40,0x80,0x1F,0xF8,0x10,0x80,
        0x10,0x80,0x10,0x80,0xFF,0xFE,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,},
/*--  文字:  月  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
{"月",
        0x00,0x00,0x1F,0xF8,0x10,0x08,0x10,0x08,0x10,0x08,0x1F,0xF8,0x10,0x08,0x10,0x08,
        0x10,0x08,0x1F,0xF8,0x10,0x08,0x10,0x08,0x20,0x08,0x20,0x08,0x40,0x28,0x80,0x10,},
/*--  文字:  日  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
{"日",
        0x00,0x00,0x1F,0xF0,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1F,0xF0,
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1F,0xF0,0x10,0x10,},
/*--  文字:  %  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
{"%",
        0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0xA4,0x00,0xA8,0x00,0xA8,0x00,0xB0,0x00,
        0x54,0x00,0x1A,0x00,0x2A,0x00,0x2A,0x00,0x4A,0x00,0x44,0x00,0x00,0x00,0x00,0x00,},
/*--  文字:  ：  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
{"：",
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x30,0x00,0x30,0x00,0x00,0x00,0x30,0x00,0x30,0x00,0x00,0x00,0x00,0x00,},

/*--  文字:  .  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
{".",
        0x10,0x00,0x10,0x00,0x1F,0xFC,0x20,0x80,0x20,0x80,0x40,0x80,0x1F,0xF8,0x10,0x80,
        0x10,0x80,0x10,0x80,0xFF,0xFE,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,},
/*--  文字:  :  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
{":",
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x18,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x18,0x00,0x00,0x00,0x00,0x00,},
/*--  文字:  ℃  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
{"℃",
        0x60,0x00,0x91,0xF4,0x96,0x0C,0x6C,0x04,0x08,0x04,0x18,0x00,0x18,0x00,0x18,0x00,
        0x18,0x00,0x18,0x00,0x18,0x00,0x08,0x00,0x0C,0x04,0x06,0x08,0x01,0xF0,0x00,0x00,},
};

cFONT Font12CN = {
  Font12CN_Table,
  sizeof(Font12CN_Table)/sizeof(CH_CN),  /*size of table*/
  13, /* ASCII Width */
  16, /* Width */
  16, /* Height */
};

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/