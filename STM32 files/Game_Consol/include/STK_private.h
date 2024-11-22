/*********************************************
 * Author:				Ahmed Samy
 * Creation Data:		6 Apr, 2024
 * Version:				v2.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  6 Apr, 2024		  Ahmed Samy		  	Initial Creation
 * v2.0       14 Jun,2024         Ahmed Samy            Adding new APIs
*********************************************/

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

//macros for configuration
#define STK_AHB         0
#define STK_AHB_DIV_8   1
#define STK_ENABLE      0
#define STK_DISABLE     1


//macros for bits in registers
#define STK_CTRL_ENABLE     0
#define STK_CTRL_TICK_INT   1
#define STK_CTRL_CLK_SRC    2
#define STK_CTRL_COUNT_FLAG 16
#define SINGLE_INTERVAL     0
#define PERIODIC_INTERVAL   1

typedef struct
{
    volatile    u32  CTRL;
    volatile    u32  LOAD;
    volatile    u32  VAL;
    volatile    u32  CALIB;
}STK_t;

#define    STK      ((volatile STK_t *)0xE000E010) //no * before the address because when using STK->CTRL its = *(STK).CTRL



#endif