/*********************************************
 * Author:				Ahmed Samy
 * Creation Data:		11 Jun, 2024
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  11 Jun, 2024		  Ahmed Samy		  	Initial Creation
*********************************************/

#ifndef  EXTI_PRIVATE_H
#define  EXTI_PRIVATE_H


#define SYSCFG_EXTICR_PA        0b0000
#define SYSCFG_EXTICR_PB        0b0001
#define SYSCFG_EXTICR_PC        0b0010
//#define SYSCFG_EXTICR_PD      0b0011
//#define SYSCFG_EXTICR_PE      0b0100
//#define SYSCFG_EXTICR_PH      0b0111

#define SYSCFG_MASK             0b1111
#define SYSCFG_OFFSET_BY_4      4
#define SYSCFG_OFFSET_BY_8      8
#define SYSCFG_OFFSET_BY_12     12

typedef struct 
{
    volatile u32    IMR;
    volatile u32    EMR;
    volatile u32    RTSR;
    volatile u32    FTSR;
    volatile u32    SWIER;
    volatile u32    PR;
}EXTI_t;

#define EXTI             ((volatile  EXTI_t *)0x40013C00)
#define SYSCFG_EXTICR1  *((volatile u32 *)0x40013800+0x08)
#define SYSCFG_EXTICR2  *((volatile u32 *)0x40013800+0x0C)
#define SYSCFG_EXTICR3  *((volatile u32 *)0x40013800+0x10)
#define SYSCFG_EXTICR4  *((volatile u32 *)0x40013800+0x14)


#endif