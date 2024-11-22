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

#ifndef STK_CONFIG_H
#define STK_CONFIG_H

/*
options for clock source:
1-STK_AHB_DIV_8
2-STK_AHB
*/
#define     STK_CLK_SRC     STK_AHB_DIV_8

/*
options for interrupt enable
1-STK_DISABLE
2-STK_ENABLE
*/
#define     STK_INT_CTRL    STK_ENABLE

/*
options for STK enable
1-STK_DISABLE
2-STK_ENSABLE
*/
#define     STK_CTRL        STK_DISABLE




#endif
