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

//Library
#include	"../include/STD_TYPES.h"
#include	"../include/BIT_MATH.h"

//lower layer

//self layer

//self files
#include	"../include/STK_interface.h"
#include	"../include/STK_private.h"
#include	"../include/STK_config.h"

static  void    (*pNotificationFunction)(void)=NULLPTR;
static  u8      u8IntervalTypeFlag = SINGLE_INTERVAL;


void    MSTK_voidInit(void)
{
    //choose the clock source for STK
    #if STK_CLK_SRC == STK_AHB
        SET_BIT(STK->CTRL,STK_CTRL_CLK_SRC);
    #elif   STK_CLK_SRC == STK_AHB_DIV_8
        CLR_BIT(STK->CTRL,STK_CTRL_CLK_SRC);
    #else
        #error"STK clock source configuration error"
    #endif
    //enable the interrupt
    #if STK_INT_CTRL == STK_ENABLE
        SET_BIT(STK->CTRL,STK_CTRL_TICK_INT);
    #elif STK_INT_CTRL == STK_DISABLE
        CLR_BIT(STK->CTRL,STK_CTRL_TICK_INT);
    #else   
        #error "STK interrupt error"
    #endif
    //enable the STK
    #if STK_CTRL == STK_ENABLE
        SET_BIT(STK->CTRL,STK_CTRL_ENABLE);
    #elif STK_CTRL == STK_DISABLE
        CLR_BIT(STK->CTRL,STK_CTRL_ENABLE);
    #else
        #error "STK enable error"
    #endif
}

void    MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
    //load the ticks value into LOAD register
    STK->LOAD = Copy_u32Ticks;
    //polling on interrupt flag
    while( GET_BIT(STK->CTRL,STK_CTRL_COUNT_FLAG)==0 );
    //flag clearance by writing on VAL register
    STK->VAL = 0;

}

u32     MSTK_u32GetRemainingTime(void)
{
    u32 Local_u32RemainingTime;
    Local_u32RemainingTime = STK->VAL;
    return  Local_u32RemainingTime;
}

u32     MSTK_u32GetTimeElapsed(void)
{
    u32 Local_u32TimeElapsed;
    Local_u32TimeElapsed = (STK->LOAD) - (STK->VAL);
    return  Local_u32TimeElapsed;
}

void    MSTK_voidResetTimer(void)
{
    STK->VAL = 0;
}

void    MSTK_voidSTKEnable(void)
{
	SET_BIT(STK->CTRL,0);
}

void    MSTK_voidSTKDisable(void)
{
	CLR_BIT(STK->CTRL,0);
}

void    MSTK_voidSetPreloadValue(u32 Copy_u32PreloadValue)
{
    STK->LOAD = Copy_u32PreloadValue;
}

void    MSTK_voidSetSingleIntervel(void (*CallBackFunction)(void))
{
    pNotificationFunction = CallBackFunction;
    u8IntervalTypeFlag = SINGLE_INTERVAL;
    SET_BIT(STK->CTRL,STK_CTRL_ENABLE);
}

void    MSTK_voidSetPeriodIntervel(void (*CallBackFunction)(void))
{
    pNotificationFunction = CallBackFunction;
    u8IntervalTypeFlag = PERIODIC_INTERVAL;
}

void    SysTick_Handler(void)
{
    u8  Local_u8Temp=0;
    if ( u8IntervalTypeFlag == SINGLE_INTERVAL)
    {
        //disable timer
        STK -> LOAD = 0;
        STK -> VAL  = 0;
        CLR_BIT(STK -> CTRL , 0);
    }
    if(    pNotificationFunction != NULLPTR)
    {
        pNotificationFunction();
    }
    //clear flag
    Local_u8Temp = GET_BIT(STK -> CTRL,STK_CTRL_COUNT_FLAG);
}




