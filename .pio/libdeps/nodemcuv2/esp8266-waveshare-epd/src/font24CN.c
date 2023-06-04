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

const CH_CN Font24CN_Table[]  = 
{
/*--  文字:  温  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
{"温",
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x1C,0x01,0xC0,
        0x0F,0x1F,0xFF,0xE0,0x07,0x9E,0x01,0xC0,0x03,0x9E,0x01,0xC0,0x03,0x7E,0x01,0xC0,
        0x00,0x7E,0x01,0xC0,0x00,0x7F,0xFF,0xC0,0x70,0xDE,0x01,0xC0,0x38,0xDE,0x01,0xC0,
        0x3C,0xDE,0x01,0xC0,0x1D,0xDE,0x01,0xC0,0x1D,0x9F,0xFF,0xC0,0x01,0x9E,0x01,0xC0,
        0x03,0x9C,0x01,0x80,0x03,0x80,0x00,0x00,0x03,0x70,0x00,0x70,0x07,0x7F,0xFF,0xF8,
        0x07,0x79,0xCE,0x70,0x7F,0x79,0xCE,0x70,0x7E,0x79,0xCE,0x70,0x1E,0x79,0xCE,0x70,
        0x0E,0x79,0xCE,0x70,0x0E,0x79,0xCE,0x70,0x1E,0x79,0xCE,0x70,0x1E,0x79,0xCE,0x70,
        0x1E,0x79,0xCE,0x7C,0x0F,0xFF,0xFF,0xFE,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,},


/*--  文字:  湿  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
{"湿",
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x0C,0x00,0x60,
        0x0F,0x0F,0xFF,0xF0,0x07,0x8E,0x00,0x70,0x07,0x8E,0x00,0x70,0x03,0x6E,0x00,0x70,
        0x00,0x6E,0x00,0x70,0x00,0x6F,0xFF,0xF0,0x70,0xEE,0x00,0x70,0x38,0xCE,0x00,0x70,
        0x3C,0xCE,0x00,0x70,0x1F,0xCE,0x00,0x70,0x0F,0x8F,0xFF,0xF0,0x0F,0x8F,0xCC,0x70,
        0x03,0x8D,0xEF,0x00,0x03,0x01,0xCE,0x18,0x07,0x61,0xCE,0x3C,0x07,0x71,0xCE,0x3C,
        0x0E,0x39,0xCE,0x78,0x7E,0x3D,0xCE,0x70,0x1E,0x1D,0xCE,0xE0,0x1E,0x1F,0xCF,0xC0,
        0x1E,0x0F,0xCF,0x80,0x1E,0x0D,0xCF,0x00,0x1E,0x01,0xCE,0x00,0x1E,0x01,0xCE,0x00,
        0x1E,0x01,0xCE,0x1C,0x1D,0xFF,0xFF,0xFE,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,},

/*--  文字:  度  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
{"度",
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x80,0x00,0x00,0x01,0xE0,0x00,
        0x00,0x01,0xE0,0x10,0x0E,0x00,0xE0,0x38,0x0F,0xFF,0xFF,0xFC,0x0F,0x0E,0x06,0x00,
        0x0F,0x0F,0x07,0x80,0x0F,0x0E,0x07,0x30,0x0F,0x0E,0x07,0x78,0x0F,0xFF,0xFF,0xFC,
        0x0F,0x0E,0x07,0x00,0x0F,0x0E,0x07,0x00,0x0F,0x0E,0x07,0x00,0x0E,0x0E,0x07,0x00,
        0x0E,0x0F,0xFF,0x00,0x0E,0x0E,0x07,0x00,0x0E,0x0C,0x01,0x80,0x0E,0x7F,0xFF,0xC0,
        0x0E,0x2E,0x07,0xC0,0x0E,0x06,0x07,0x00,0x1C,0x03,0x0F,0x00,0x1C,0x03,0x9E,0x00,
        0x1C,0x01,0xFC,0x00,0x18,0x00,0xF8,0x00,0x38,0x01,0xFC,0x00,0x30,0x07,0xFF,0x80,
        0x30,0x1F,0x0F,0xFE,0x60,0xF8,0x03,0xFC,0x67,0xC0,0x00,0x78,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,},

/*--  文字:  热  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
{"热",
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x70,0x00,0x00,0xF0,0x7C,0x00,
        0x00,0xE0,0x78,0x00,0x00,0xE0,0x78,0x00,0x00,0xE0,0x78,0x00,0x00,0xEC,0x79,0xC0,
        0x3F,0xFF,0xFF,0xE0,0x18,0xE1,0xF9,0xC0,0x00,0xE0,0x79,0xC0,0x00,0xE0,0x71,0xC0,
        0x00,0xEE,0x71,0xC0,0x00,0xFF,0xF1,0xC0,0x07,0xE1,0xF1,0xC0,0x7F,0xE0,0xF1,0xCC,
        0x3E,0xE0,0xFD,0xCC,0x38,0xE0,0xFD,0xCC,0x00,0xE1,0xDD,0xFC,0x00,0xE3,0x8E,0xFC,
        0x0F,0xE7,0x0C,0x7C,0x03,0xEE,0x00,0x7C,0x01,0xDC,0x00,0x1E,0x06,0x00,0x61,0xC0,
        0x06,0x38,0x70,0xE0,0x06,0x1C,0x78,0xF0,0x0E,0x1E,0x38,0x78,0x1E,0x1E,0x3C,0x78,
        0x1E,0x1E,0x3C,0x38,0x3C,0x0C,0x18,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00},

/*--  文字:  指  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
{"指",
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x83,0x80,0x00,0x03,0xE3,0xC0,0x00,
        0x03,0xC3,0xC0,0xE0,0x03,0xC3,0xC1,0xF2,0x03,0xC3,0xC7,0xF0,0x03,0xC3,0xDF,0x80,
        0x03,0xDF,0xFC,0x18,0x7F,0xFF,0xE0,0x18,0x33,0xC3,0xC0,0x18,0x03,0xC3,0xC0,0x18,
        0x03,0xC3,0xC0,0x3C,0x03,0xCF,0xFF,0xFC,0x03,0xFD,0xFF,0xFC,0x03,0xF0,0x00,0x00,
        0x03,0xE3,0x80,0x70,0x0F,0xC3,0xFF,0xF8,0x3F,0xC3,0xC0,0x70,0x7F,0xC3,0xC0,0x70,
        0x3B,0xC3,0xC0,0x70,0x03,0xC3,0xC0,0x70,0x03,0xC3,0xFF,0xF0,0x03,0xC3,0xC0,0x70,
        0x03,0xC3,0xC0,0x70,0x03,0xC3,0xC0,0x70,0x03,0xC3,0xC0,0x70,0x03,0xC3,0xFF,0xF0,
        0x3F,0xC3,0xC0,0x70,0x0F,0x83,0xC0,0x70,0x03,0x03,0x80,0x60,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,},

/*--  文字:  黑  --*/
/*--  微软雅黑24;  此字体下对应的点阵为：宽x高=32x41   --*/
{"数",
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x1C,0x00,0x00,0x7B,0x1F,0x00,
        0x0E,0x73,0xDE,0x00,0x0F,0x77,0x9C,0x00,0x07,0x77,0x3C,0x00,0x07,0x7E,0x38,0x00,
        0x02,0x7B,0xB8,0x1C,0x3F,0xFF,0xFF,0xFE,0x19,0xF0,0x70,0xF0,0x01,0xFC,0x78,0xF0,
        0x03,0xFF,0x78,0xF0,0x07,0x7F,0xF8,0xE0,0x0E,0x77,0xD8,0xE0,0x1C,0x71,0xD8,0xE0,
        0x70,0xE1,0x98,0xE0,0x60,0xF0,0x1D,0xE0,0x01,0xE7,0x1D,0xC0,0x7F,0xFF,0x9D,0xC0,
        0x31,0xC7,0x0F,0xC0,0x03,0x8E,0x0F,0xC0,0x03,0x8E,0x0F,0x80,0x07,0xFC,0x07,0x80,
        0x00,0xFE,0x0F,0x80,0x00,0x7F,0x9F,0xC0,0x01,0xF7,0xBD,0xF0,0x03,0xC3,0xF8,0xFC,
        0x0F,0x01,0xE0,0x7E,0x7C,0x03,0xC0,0x38,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,},

/*--  文字:  气  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
{"气",
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xF0,0x00,0x00,
        0x01,0xF0,0x00,0x00,0x01,0xE0,0x00,0x60,0x03,0xC0,0x00,0xF0,0x03,0xFF,0xFF,0xF8,
        0x03,0x80,0x00,0x00,0x07,0x00,0x03,0x80,0x07,0xFF,0xFF,0xC0,0x0E,0x60,0x00,0x00,
        0x1C,0x00,0x00,0x00,0x18,0x00,0x07,0x00,0x3F,0xFF,0xFF,0x80,0x73,0x00,0x07,0x00,
        0x40,0x00,0x07,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x07,0x00,
        0x00,0x00,0x07,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x07,0x0C,
        0x00,0x00,0x07,0x8C,0x00,0x00,0x03,0x9C,0x00,0x00,0x03,0xDC,0x00,0x00,0x01,0xFC,
        0x00,0x00,0x01,0xFC,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x3C,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,},

/*--  文字:  压  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
{"压",
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x06,0x00,0x00,0x78,
        0x07,0xFF,0xFF,0xFC,0x07,0x00,0x00,0x00,0x07,0x00,0xC0,0x00,0x07,0x00,0xF0,0x00,
        0x07,0x00,0xE0,0x00,0x07,0x00,0xE0,0x00,0x07,0x00,0xE0,0x00,0x07,0x00,0xE0,0x00,
        0x07,0x00,0xE0,0x00,0x07,0x00,0xE0,0x40,0x07,0x00,0xE0,0xE0,0x07,0x7F,0xFF,0xF0,
        0x07,0x30,0xE0,0x00,0x07,0x00,0xE0,0x00,0x07,0x00,0xEC,0x00,0x07,0x00,0xEE,0x00,
        0x07,0x00,0xE7,0x80,0x07,0x00,0xE3,0xC0,0x0F,0x00,0xE3,0xE0,0x0E,0x00,0xE1,0xE0,
        0x0E,0x00,0xE1,0xE0,0x1C,0x00,0xE0,0xC0,0x1C,0x00,0xE0,0x18,0x18,0x00,0xE0,0x3C,
        0x3F,0xFF,0xFF,0xFE,0x73,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,},


/*--  文字:  年  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
{"年",
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xF0,0x00,0x00,
        0x01,0xE0,0x00,0x00,0x01,0xE0,0x00,0x30,0x01,0xC0,0x00,0x78,0x03,0xFF,0xFF,0xFC,
        0x07,0x81,0xE0,0x00,0x07,0x01,0xE0,0x00,0x0E,0x01,0xE0,0x00,0x1C,0x01,0xE0,0x00,
        0x1C,0x01,0xE0,0xC0,0x3B,0x81,0xE1,0xE0,0x63,0xFF,0xFF,0xF0,0x03,0xC1,0xE0,0x00,
        0x03,0xC1,0xE0,0x00,0x03,0xC1,0xE0,0x00,0x03,0xC1,0xE0,0x00,0x03,0xC1,0xE0,0x18,
        0x03,0xC1,0xE0,0x3C,0x7F,0xFF,0xFF,0xFE,0x30,0x01,0xE0,0x00,0x00,0x01,0xE0,0x00,
        0x00,0x01,0xE0,0x00,0x00,0x01,0xE0,0x00,0x00,0x01,0xE0,0x00,0x00,0x01,0xE0,0x00,
        0x00,0x01,0xE0,0x00,0x00,0x01,0xE0,0x00,0x00,0x01,0xE0,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,},

/*--  文字:  月  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
{"月",
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x03,0x80,
        0x00,0xFF,0xFF,0xC0,0x00,0xE0,0x03,0x80,0x00,0xE0,0x03,0x80,0x00,0xE0,0x03,0x80,
        0x00,0xE0,0x03,0x80,0x00,0xE0,0x03,0x80,0x00,0xE0,0x03,0x80,0x00,0xFF,0xFF,0x80,
        0x00,0xE0,0x03,0x80,0x00,0xE0,0x03,0x80,0x00,0xE0,0x03,0x80,0x00,0xE0,0x03,0x80,
        0x00,0xE0,0x03,0x80,0x00,0xE0,0x03,0x80,0x00,0xFF,0xFF,0x80,0x00,0xE0,0x03,0x80,
        0x00,0xE0,0x03,0x80,0x01,0xE0,0x03,0x80,0x01,0xE0,0x03,0x80,0x01,0xC0,0x03,0x80,
        0x03,0xC0,0x03,0x80,0x03,0x80,0x03,0x80,0x07,0x00,0x03,0x80,0x07,0x00,0xFF,0x80,
        0x0E,0x00,0x7F,0x80,0x3C,0x00,0x0F,0x00,0x70,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,},

/*--  文字:  日  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
{"日",
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x80,0x01,0xC0,
        0x03,0xFF,0xFF,0xE0,0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,
        0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,
        0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,0x03,0xFF,0xFF,0xC0,0x03,0x80,0x01,0xC0,
        0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,
        0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,
        0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,0x03,0xFF,0xFF,0xC0,0x03,0x80,0x01,0xC0,
        0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,},

/*--  文字:  %  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
{"%",
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x18,0x00,0x00,0x7E,0x38,0x00,0x00,
        0xEE,0x30,0x00,0x00,0xE7,0x30,0x00,0x00,0xE7,0x70,0x00,0x00,0xE7,0x60,0x00,0x00,
        0xE7,0xE0,0x00,0x00,0xE7,0xC0,0x00,0x00,0xE7,0xC0,0x00,0x00,0xEF,0xC0,0x00,0x00,
        0x7F,0xBC,0x00,0x00,0x7F,0xFE,0x00,0x00,0x03,0xE6,0x00,0x00,0x07,0xE7,0x00,0x00,
        0x06,0xE7,0x00,0x00,0x06,0xE7,0x00,0x00,0x0E,0xE7,0x00,0x00,0x0C,0xE7,0x00,0x00,
        0x1C,0xE7,0x00,0x00,0x18,0xE7,0x00,0x00,0x18,0x7E,0x00,0x00,0x38,0x3C,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,},

/*--  文字:  -  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
{"-",
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0xFF,0xFF,0x00,0x00,0x7F,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,},

/*--  文字:  .  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
{".",
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x3C,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x3C,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,},

/*--  文字:  :  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
{":",
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x03,0xC0,0x00,0x00,0x07,0xC0,0x00,0x00,0x07,0xC0,0x00,0x00,
        0x03,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x03,0xC0,0x00,0x00,0x07,0xC0,0x00,0x00,0x07,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
},

/*--  文字:  ℃  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
{"℃",
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x07,0x00,0x00,0x00,0x0F,0xC1,0xFE,0x00,0x1D,0xC7,0xFF,0xA0,0x1D,0xCF,0x01,0xF0,
        0x1D,0xDE,0x00,0xF0,0x0F,0x9C,0x00,0x70,0x02,0x3C,0x00,0x70,0x00,0x38,0x00,0x30,
        0x00,0x78,0x00,0x30,0x00,0x78,0x00,0x30,0x00,0x78,0x00,0x00,0x00,0x78,0x00,0x00,
        0x00,0x78,0x00,0x00,0x00,0x78,0x00,0x00,0x00,0x78,0x00,0x00,0x00,0x78,0x00,0x00,
        0x00,0x78,0x00,0x00,0x00,0x38,0x00,0x00,0x00,0x3C,0x00,0x30,0x00,0x1C,0x00,0x70,
        0x00,0x1E,0x00,0xE0,0x00,0x0F,0x83,0xC0,0x00,0x07,0xFF,0x80,0x00,0x01,0xFE,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,},

/*--  文字:  ：  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
{"：",
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x0F,0x80,0x00,0x00,0x1F,0x80,0x00,0x00,0x1F,0x80,0x00,0x00,
        0x0F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x0F,0x80,0x00,0x00,0x1F,0x80,0x00,0x00,0x1F,0x80,0x00,0x00,
        0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,},


};

cFONT Font24CN = {
  Font24CN_Table,
  sizeof(Font24CN_Table)/sizeof(CH_CN),  /*size of table*/
  24, /* ASCII Width */
  32, /* Width */
  33, /* Height */
};

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
