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

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


void    MSTK_voidInit(void);
void    MSTK_voidSetBusyWait(u32 Copy_u32Ticks);
u32     MSTK_u32GetRemainingTime(void);
u32     MSTK_u32GetTimeElapsed(void);
void    MSTK_voidResetTimer(void);
void    MSTK_voidSTKEnable(void);
void    MSTK_voidSTKDisable(void);
void    MSTK_voidSetPreloadValue(u32 Copy_u32PreloadValue);
void    MSTK_voidSetSingleIntervel(void (*CallBackFunction)(void));
void    MSTK_voidSetPeriodIntervel(void (*CallBackFunction)(void));
void    SysTick_Handler(void);

#endif