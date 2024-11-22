/*********************************************
 * Author:				Ahmed Samy
 * Creation Data:		1 May, 2024
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  1 May, 2024		  Ahmed Samy		  	Initial Creation
*********************************************/

//LIB
#include    "../include/STD_TYPES.h"
#include    "../include/BIT_MATH.h"

//MCAL
#include    "../include/NVIC_interface.h"
#include    "../include/NVIC_private.h"
#include    "../include/NVIC_config.h"


void    MNVIC_voidInit(void)
{
    #define     SCB_AIRCR   *( (volatile u32*) 0xE000ED00 + 0x0C)
    SCB_AIRCR |= ((AIRCR_PRIVKEY<<16) | (MNVIC_GRP_SUB_DISTRIBUTION<<8) );
}

void    MNVIC_voidPeripheralInterruptControl(u8 Copy_u8PeripheralID, u8 Copy_u8InterruptState)
{
    u8 Local_u8RegisterIndex=0;
    Local_u8RegisterIndex = Copy_u8PeripheralID / 32;

    switch (Copy_u8InterruptState)
    {
    case MNVIC_INT_ENABLE:
        NVIC -> ISER[Local_u8RegisterIndex] |= (1<< (Copy_u8PeripheralID % 32)); 
        break;
    case MNVIC_INT_DISABLE:
        NVIC -> ICER[Local_u8RegisterIndex] |= (1<< (Copy_u8PeripheralID % 32)); 
        break;
    default:
        //error
        break;
    }
}

void    MNVIC_voidSetPendingFlag(u8 Copy_u8PeripheralID)
{
    if(Copy_u8PeripheralID <= 239)
    {
        u8 Local_u8RegisterIndex=0;
        Local_u8RegisterIndex = Copy_u8PeripheralID / 32;
        NVIC -> ISPR[Local_u8RegisterIndex] |= (1<< (Copy_u8PeripheralID % 32)); 
    }
}

void    MNVIC_voidClearPendingFlag(u8 Copy_u8PeripheralID)
{
    if(Copy_u8PeripheralID <= 239)
    {
        u8 Local_u8RegisterIndex=0;
        Local_u8RegisterIndex = Copy_u8PeripheralID / 32;
        NVIC -> ICPR[Local_u8RegisterIndex] |= (1<< (Copy_u8PeripheralID % 32)); 
    }
}

u8      MNVIC_u8GetActiveFlag(u8    Copy_u8PeripheralID)
{
    u8 Local_u8RegisterIndex=0;
    Local_u8RegisterIndex = Copy_u8PeripheralID / 32;
    return ((NVIC -> IABR[Local_u8RegisterIndex]) & 0x01);
}

void    MNVIC_voidSetPeripheralPriority(u8 Copy_u8PeripheralID, u8 Copy_u8Priority)
{
    NVIC -> IP[Copy_u8PeripheralID] = (Copy_u8Priority<<4);
}
