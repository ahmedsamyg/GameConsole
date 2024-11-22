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

//lib

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

//MCAL
#include "../include/EXTI_interface.h"
#include "../include/EXTI_private.h"
#include "../include/EXTI_config.h"

static  void    (*EXTI_pNotificationFunction[16])(void) = {NULLPTR};

void    MEXTI_voidInit(void)
{
    //Enable EXTI & choose its port & set sensitivity
    if(MEXTI_EXTI0_ENABLE == EXTI_ENABLE)
    {
        //enable EXTI
        SET_BIT(EXTI -> IMR,MEXTI_EXTI0);
        //Choose port
        SYSCFG_EXTICR1 &= ~(SYSCFG_MASK);
        SYSCFG_EXTICR1 |=  MEXTI_EXTI0_PORT;
        //set sensitivity
        MEXTI_voidChangeSenseMode(MEXTI_EXTI0,MEXTI_EXTI0_SENS);
    }
    if(MEXTI_EXTI1_ENABLE == EXTI_ENABLE)
    {
        SET_BIT(EXTI -> IMR,MEXTI_EXTI1);
        SYSCFG_EXTICR1 &= ~(SYSCFG_MASK<<SYSCFG_OFFSET_BY_4);
        SYSCFG_EXTICR1 |=  (MEXTI_EXTI1_PORT<<SYSCFG_OFFSET_BY_4);
        MEXTI_voidChangeSenseMode(MEXTI_EXTI1,MEXTI_EXTI1_SENS);
    }
    if(MEXTI_EXTI2_ENABLE == EXTI_ENABLE)
    {
        SET_BIT(EXTI -> IMR,MEXTI_EXTI2);
        SYSCFG_EXTICR1 &= ~(SYSCFG_MASK<<SYSCFG_OFFSET_BY_8);
        SYSCFG_EXTICR1 |=  (MEXTI_EXTI2_PORT<<SYSCFG_OFFSET_BY_8);
        MEXTI_voidChangeSenseMode(MEXTI_EXTI2,MEXTI_EXTI2_SENS);

    }
    if(MEXTI_EXTI3_ENABLE == EXTI_ENABLE)
    {
        SET_BIT(EXTI -> IMR,MEXTI_EXTI3);
        SYSCFG_EXTICR1 &= ~(SYSCFG_MASK<<SYSCFG_OFFSET_BY_12);
        SYSCFG_EXTICR1 |=  (MEXTI_EXTI3_PORT<<SYSCFG_OFFSET_BY_12);
        MEXTI_voidChangeSenseMode(MEXTI_EXTI3,MEXTI_EXTI3_SENS);
    }
    if(MEXTI_EXTI4_ENABLE == EXTI_ENABLE)
    {
        SET_BIT(EXTI -> IMR,MEXTI_EXTI4);
        SYSCFG_EXTICR2 &= ~(SYSCFG_MASK);
        SYSCFG_EXTICR2 |=  (MEXTI_EXTI4_PORT);
        MEXTI_voidChangeSenseMode(MEXTI_EXTI4,MEXTI_EXTI4_SENS);
    }
    if(MEXTI_EXTI5_ENABLE == EXTI_ENABLE)
    {
        SET_BIT(EXTI -> IMR,MEXTI_EXTI5);
        SYSCFG_EXTICR2 &= ~(SYSCFG_MASK<<SYSCFG_OFFSET_BY_4);
        SYSCFG_EXTICR2 |=  (MEXTI_EXTI5_PORT<<SYSCFG_OFFSET_BY_4);
        MEXTI_voidChangeSenseMode(MEXTI_EXTI5,MEXTI_EXTI5_SENS);
    }
    if(MEXTI_EXTI6_ENABLE == EXTI_ENABLE)
    {
        SET_BIT(EXTI -> IMR,MEXTI_EXTI6);
        SYSCFG_EXTICR2 &= ~(SYSCFG_MASK<<SYSCFG_OFFSET_BY_8);
        SYSCFG_EXTICR2 |=  (MEXTI_EXTI6_PORT<<SYSCFG_OFFSET_BY_8);
        MEXTI_voidChangeSenseMode(MEXTI_EXTI6,MEXTI_EXTI6_SENS);
    }
    if(MEXTI_EXTI7_ENABLE == EXTI_ENABLE)
    {
        SET_BIT(EXTI -> IMR,MEXTI_EXTI7);
        SYSCFG_EXTICR2 &= ~(SYSCFG_MASK<<SYSCFG_OFFSET_BY_12);
        SYSCFG_EXTICR2 |=  (MEXTI_EXTI7_PORT<<SYSCFG_OFFSET_BY_12);
        MEXTI_voidChangeSenseMode(MEXTI_EXTI7,MEXTI_EXTI7_SENS);
    }
    if(MEXTI_EXTI8_ENABLE == EXTI_ENABLE)
    {
        SET_BIT(EXTI -> IMR,MEXTI_EXTI8);
        SYSCFG_EXTICR3 &= ~(SYSCFG_MASK);
        SYSCFG_EXTICR3 |=  (MEXTI_EXTI8_PORT);
        MEXTI_voidChangeSenseMode(MEXTI_EXTI8,MEXTI_EXTI8_SENS);
    }
    if(MEXTI_EXTI9_ENABLE == EXTI_ENABLE)
    {
        SET_BIT(EXTI -> IMR,MEXTI_EXTI9);
        SYSCFG_EXTICR3 &= ~(SYSCFG_MASK<<SYSCFG_OFFSET_BY_4);
        SYSCFG_EXTICR3 |=  (MEXTI_EXTI9_PORT<<SYSCFG_OFFSET_BY_4);
        MEXTI_voidChangeSenseMode(MEXTI_EXTI9,MEXTI_EXTI9_SENS);
    }
    if(MEXTI_EXTI10_ENABLE == EXTI_ENABLE)
    {
        SET_BIT(EXTI -> IMR,MEXTI_EXTI10);
        SYSCFG_EXTICR3 &= ~(SYSCFG_MASK<<SYSCFG_OFFSET_BY_8);
        SYSCFG_EXTICR3 |=  (MEXTI_EXTI10_PORT<<SYSCFG_OFFSET_BY_8);
        MEXTI_voidChangeSenseMode(MEXTI_EXTI10,MEXTI_EXTI10_SENS);
    }
    if(MEXTI_EXTI11_ENABLE == EXTI_ENABLE)
    {
        SET_BIT(EXTI -> IMR,MEXTI_EXTI11);
        SYSCFG_EXTICR3 &= ~(SYSCFG_MASK<<SYSCFG_OFFSET_BY_12);
        SYSCFG_EXTICR3 |=  (MEXTI_EXTI11_PORT<<SYSCFG_OFFSET_BY_12); 
        MEXTI_voidChangeSenseMode(MEXTI_EXTI11,MEXTI_EXTI11_SENS);       
    }
    if(MEXTI_EXTI12_ENABLE == EXTI_ENABLE)
    {
        SET_BIT(EXTI -> IMR,MEXTI_EXTI12);
        SYSCFG_EXTICR4 &= ~(SYSCFG_MASK);
        SYSCFG_EXTICR4 |=  (MEXTI_EXTI12_PORT);
        MEXTI_voidChangeSenseMode(MEXTI_EXTI12,MEXTI_EXTI12_SENS);
    }
    if(MEXTI_EXTI13_ENABLE == EXTI_ENABLE)
    {
        SET_BIT(EXTI -> IMR,MEXTI_EXTI13);
        SYSCFG_EXTICR4 &= ~(SYSCFG_MASK<<SYSCFG_OFFSET_BY_4);
        SYSCFG_EXTICR4 |=  (MEXTI_EXTI13_PORT<<SYSCFG_OFFSET_BY_4);
        MEXTI_voidChangeSenseMode(MEXTI_EXTI13,MEXTI_EXTI13_SENS);
    }
    if(MEXTI_EXTI14_ENABLE == EXTI_ENABLE)
    {
        SET_BIT(EXTI -> IMR,MEXTI_EXTI14);
        SYSCFG_EXTICR4 &= ~(SYSCFG_MASK<<SYSCFG_OFFSET_BY_8);
        SYSCFG_EXTICR4 |=  (MEXTI_EXTI14_PORT<<SYSCFG_OFFSET_BY_8);
        MEXTI_voidChangeSenseMode(MEXTI_EXTI14,MEXTI_EXTI14_SENS);
    }
    if(MEXTI_EXTI15_ENABLE == EXTI_ENABLE)
    {
        SET_BIT(EXTI -> IMR,MEXTI_EXTI15);
        SYSCFG_EXTICR4 &= ~(SYSCFG_MASK<<SYSCFG_OFFSET_BY_12);
        SYSCFG_EXTICR4 |=  (MEXTI_EXTI15_PORT<<SYSCFG_OFFSET_BY_12);
        MEXTI_voidChangeSenseMode(MEXTI_EXTI15,MEXTI_EXTI15_SENS);
    }
    else
    {
        //error
    }
}

void    MEXTI_voidEnableInterrupt(MEXTI_INTERRUPT_LITE_t Copy_tInterruptLine)
{
    SET_BIT(EXTI -> IMR,Copy_tInterruptLine);
}

void    MEXTI_voidDisableInterrupt(MEXTI_INTERRUPT_LITE_t Copy_tInterruptLine)
{
    CLR_BIT(EXTI -> IMR,Copy_tInterruptLine);
}


void    MEXTI_voidChangeSenseMode(MEXTI_INTERRUPT_LITE_t Copy_tInterruptLine ,MEXTI_INTERRUPT_SENSE_SIGNAL_t    Copy_tSenseSignal)
{
    switch (Copy_tSenseSignal)
    {  
        case   MEXTI_RISING:
            SET_BIT(EXTI ->RTSR,Copy_tInterruptLine);
            CLR_BIT(EXTI ->FTSR,Copy_tInterruptLine);
        break;
        case    MEXTI_FALLING:
            CLR_BIT(EXTI ->RTSR,Copy_tInterruptLine);
            SET_BIT(EXTI ->FTSR,Copy_tInterruptLine);
        break;
        case    MEXTI_ONCHANGE:
            SET_BIT(EXTI ->RTSR,Copy_tInterruptLine);
            SET_BIT(EXTI ->FTSR,Copy_tInterruptLine);
        break;
        default:
        //error
        break;
    }
}

void    MEXTI_voidSetCallBack(MEXTI_INTERRUPT_LITE_t Copy_tInterruptLine, void  (*pCallBackFunction)(void))
{
    switch(Copy_tInterruptLine)
    {
        case    MEXTI_EXTI0:
            EXTI_pNotificationFunction[Copy_tInterruptLine] = pCallBackFunction;
        break;
        case    MEXTI_EXTI1:
            EXTI_pNotificationFunction[Copy_tInterruptLine] = pCallBackFunction;
        break;
        case    MEXTI_EXTI2:
            EXTI_pNotificationFunction[Copy_tInterruptLine] = pCallBackFunction;
        break;
        case    MEXTI_EXTI3:
            EXTI_pNotificationFunction[Copy_tInterruptLine] = pCallBackFunction;
        break;
        case    MEXTI_EXTI4:
            EXTI_pNotificationFunction[Copy_tInterruptLine] = pCallBackFunction;
        break;
        case    MEXTI_EXTI5:
            EXTI_pNotificationFunction[Copy_tInterruptLine] = pCallBackFunction;
        break;
        case    MEXTI_EXTI6:
            EXTI_pNotificationFunction[Copy_tInterruptLine] = pCallBackFunction;
        break;
        case    MEXTI_EXTI7:
            EXTI_pNotificationFunction[Copy_tInterruptLine] = pCallBackFunction;
        break;
        case    MEXTI_EXTI8:
            EXTI_pNotificationFunction[Copy_tInterruptLine] = pCallBackFunction;
        break;
        case    MEXTI_EXTI9:
            EXTI_pNotificationFunction[Copy_tInterruptLine] = pCallBackFunction;
        break;
        case    MEXTI_EXTI10:
            EXTI_pNotificationFunction[Copy_tInterruptLine] = pCallBackFunction;
        break;
        case    MEXTI_EXTI11:
            EXTI_pNotificationFunction[Copy_tInterruptLine] = pCallBackFunction;
        break;
        case    MEXTI_EXTI12:
            EXTI_pNotificationFunction[Copy_tInterruptLine] = pCallBackFunction;
        break;
        case    MEXTI_EXTI13:
            EXTI_pNotificationFunction[Copy_tInterruptLine] = pCallBackFunction;
        break;
        case    MEXTI_EXTI14:
            EXTI_pNotificationFunction[Copy_tInterruptLine] = pCallBackFunction;
        break;
        case    MEXTI_EXTI15:
            EXTI_pNotificationFunction[Copy_tInterruptLine] = pCallBackFunction;
        break;

        default:
        //error
        break;

    }
}


void    MEXTI_voidChanePin(MEXTI_INTERRUPT_LITE_t Copy_tInterruptLine, u8 Copy_u8NewPort)
{

   if(Copy_tInterruptLine == MEXTI_EXTI0)
   {
        SYSCFG_EXTICR1 &= ~(SYSCFG_MASK);
        SYSCFG_EXTICR1 |=  Copy_u8NewPort;
   }
   else if(Copy_tInterruptLine == MEXTI_EXTI1)
   {
        SYSCFG_EXTICR1 &= ~(SYSCFG_MASK<<SYSCFG_OFFSET_BY_4);
        SYSCFG_EXTICR1 |=  (Copy_u8NewPort<<SYSCFG_OFFSET_BY_4);
   }
      else if(Copy_tInterruptLine == MEXTI_EXTI2)
   {
        SYSCFG_EXTICR1 &= ~(SYSCFG_MASK<<SYSCFG_OFFSET_BY_8);
        SYSCFG_EXTICR1 |=  (Copy_u8NewPort<<SYSCFG_OFFSET_BY_8);
   }
      else if(Copy_tInterruptLine == MEXTI_EXTI3)
   {
        SYSCFG_EXTICR1 &= ~(SYSCFG_MASK<<SYSCFG_OFFSET_BY_12);
        SYSCFG_EXTICR1 |=  (Copy_u8NewPort<<SYSCFG_OFFSET_BY_12);
   }
      else if(Copy_tInterruptLine == MEXTI_EXTI4)
   {
        SYSCFG_EXTICR2 &= ~(SYSCFG_MASK);
        SYSCFG_EXTICR2 |=  (Copy_u8NewPort);
   }
      else if(Copy_tInterruptLine == MEXTI_EXTI5)
   {
        SYSCFG_EXTICR2 &= ~(SYSCFG_MASK<<SYSCFG_OFFSET_BY_4);
        SYSCFG_EXTICR2 |=  (Copy_u8NewPort<<SYSCFG_OFFSET_BY_4);
   }
      else if(Copy_tInterruptLine == MEXTI_EXTI6)
   {
        SYSCFG_EXTICR2 &= ~(SYSCFG_MASK<<SYSCFG_OFFSET_BY_8);
        SYSCFG_EXTICR2 |=  (Copy_u8NewPort<<SYSCFG_OFFSET_BY_8);
   }
      else if(Copy_tInterruptLine == MEXTI_EXTI7)
   {
        SYSCFG_EXTICR2 &= ~(SYSCFG_MASK<<SYSCFG_OFFSET_BY_12);
        SYSCFG_EXTICR2 |=  (Copy_u8NewPort<<SYSCFG_OFFSET_BY_12);
   }
      else if(Copy_tInterruptLine == MEXTI_EXTI8)
   {
        SYSCFG_EXTICR3 &= ~(SYSCFG_MASK);
        SYSCFG_EXTICR3 |=  (Copy_u8NewPort);
   }
      else if(Copy_tInterruptLine == MEXTI_EXTI9)
   {
        SYSCFG_EXTICR3 &= ~(SYSCFG_MASK<<SYSCFG_OFFSET_BY_4);
        SYSCFG_EXTICR3 |=  (Copy_u8NewPort<<SYSCFG_OFFSET_BY_4);
   }
      else if(Copy_tInterruptLine == MEXTI_EXTI10)
   {
        SYSCFG_EXTICR3 &= ~(SYSCFG_MASK<<SYSCFG_OFFSET_BY_8);
        SYSCFG_EXTICR3 |=  (Copy_u8NewPort<<SYSCFG_OFFSET_BY_8);
   }
      else if(Copy_tInterruptLine == MEXTI_EXTI11)
   {
        SYSCFG_EXTICR3 &= ~(SYSCFG_MASK<<SYSCFG_OFFSET_BY_12);
        SYSCFG_EXTICR3 |=  (Copy_u8NewPort<<SYSCFG_OFFSET_BY_12);
   }
      else if(Copy_tInterruptLine == MEXTI_EXTI12)
   {
        SYSCFG_EXTICR4 &= ~(SYSCFG_MASK);
        SYSCFG_EXTICR4 |=  (Copy_u8NewPort);
   }
      else if(Copy_tInterruptLine == MEXTI_EXTI13)
   {
        SYSCFG_EXTICR4 &= ~(SYSCFG_MASK<<SYSCFG_OFFSET_BY_4);
        SYSCFG_EXTICR4 |=  (Copy_u8NewPort<<SYSCFG_OFFSET_BY_4);
   }
      else if(Copy_tInterruptLine == MEXTI_EXTI14)
   {
        SYSCFG_EXTICR4 &= ~(SYSCFG_MASK<<SYSCFG_OFFSET_BY_8);
        SYSCFG_EXTICR4 |=  (Copy_u8NewPort<<SYSCFG_OFFSET_BY_8);
   }
      else if(Copy_tInterruptLine == MEXTI_EXTI15)
   {
        SYSCFG_EXTICR4 &= ~(SYSCFG_MASK<<SYSCFG_OFFSET_BY_12);
        SYSCFG_EXTICR4 |=  (Copy_u8NewPort<<SYSCFG_OFFSET_BY_12);
   }
   else
   {
        //error
   }

}

void    EXTI0_IRQHandler(void)
{
    if(EXTI_pNotificationFunction[0]!= NULLPTR)
    {
        //set the bit to clear the flag after completing the ISR
        SET_BIT(EXTI -> PR,0);
        EXTI_pNotificationFunction[0]();
    }

}

void    EXTI1_IRQHandler(void)
{
    if(EXTI_pNotificationFunction[1]!= NULLPTR)
    {
        EXTI_pNotificationFunction[1]();
    }
    SET_BIT(EXTI -> PR,1);

}
void    EXTI2_IRQHandler(void)
{
    if(EXTI_pNotificationFunction[2]!= NULLPTR)
    {
        EXTI_pNotificationFunction[2]();
    }
    SET_BIT(EXTI -> PR,2);

}
void    EXTI3_IRQHandler(void)
{
    if(EXTI_pNotificationFunction[3]!= NULLPTR)
    {
        EXTI_pNotificationFunction[3]();
    }
    SET_BIT(EXTI -> PR,3);

}
void    EXTI4_IRQHandler(void)
{
    if(EXTI_pNotificationFunction[4]!= NULLPTR)
    {
        EXTI_pNotificationFunction[4]();
    }
    SET_BIT(EXTI -> PR,4);

}
void    EXTI9_5_IRQHandler(void)
{
    if(EXTI_pNotificationFunction[5]!= NULLPTR)
    {
        EXTI_pNotificationFunction[5]();
    }
    SET_BIT(EXTI -> PR,5);
    if(EXTI_pNotificationFunction[6]!= NULLPTR)
    {
        EXTI_pNotificationFunction[6]();
    }
    SET_BIT(EXTI -> PR,6);
    if(EXTI_pNotificationFunction[7]!= NULLPTR)
    {
        EXTI_pNotificationFunction[7]();
    }
    SET_BIT(EXTI -> PR,7);
    if(EXTI_pNotificationFunction[8]!= NULLPTR)
    {
        EXTI_pNotificationFunction[8]();
    }
    SET_BIT(EXTI -> PR,8);
    if(EXTI_pNotificationFunction[9]!= NULLPTR)
    {
        EXTI_pNotificationFunction[9]();
    }
    SET_BIT(EXTI -> PR,9);
}
void    EXTI15_10_IRQHandler(void)
{
    if(EXTI_pNotificationFunction[10]!= NULLPTR)
    {
        EXTI_pNotificationFunction[10]();
    }
    SET_BIT(EXTI -> PR,10);
    if(EXTI_pNotificationFunction[11]!= NULLPTR)
    {
        EXTI_pNotificationFunction[11]();
    }
    SET_BIT(EXTI -> PR,11);
    if(EXTI_pNotificationFunction[12]!= NULLPTR)
    {
        EXTI_pNotificationFunction[12]();
    }
    SET_BIT(EXTI -> PR,12);
    if(EXTI_pNotificationFunction[13]!= NULLPTR)
    {
        EXTI_pNotificationFunction[13]();
    }
    SET_BIT(EXTI -> PR,13);
    if(EXTI_pNotificationFunction[14]!= NULLPTR)
    {
        EXTI_pNotificationFunction[14]();
    }
    SET_BIT(EXTI -> PR,14);
    if(EXTI_pNotificationFunction[15]!= NULLPTR)
    {
        EXTI_pNotificationFunction[15]();
    }
    SET_BIT(EXTI -> PR,15);
}




