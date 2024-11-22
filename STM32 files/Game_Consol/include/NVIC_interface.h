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

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

#define     MNVIC_INT_DISABLE       0
#define     MNVIC_INT_ENABLE        1


#define     MNVIC_WWDG              0
#define     MNVIC_EXTI16            1
#define     MNVIC_EXTI21            2
#define     MNVIC_EXTI22            3
#define     MNVIC_FLASH             4
#define     MNVIC_RCC               5
#define     MNVIC_EXTI0             6
#define     MNVIC_EXTI1             7
#define     MNVIC_EXTI2             8
#define     MNVIC_EXTI3             9
#define     MNVIC_EXTI4             10
#define     MNVIC_DMA1_Stream0      11
#define     MNVIC_DMA1_Stream1      12
#define     MNVIC_DMA1_Stream2      13
#define     MNVIC_DMA1_Stream3      14
#define     MNVIC_DMA1_Stream4      15
#define     MNVIC_DMA1_Stream5      16
#define     MNVIC_DMA1_Stream6      17
#define     MNVIC_ADC               18
#define     MNVIC_EXTI9_5           23
#define     MNVIC_TIM1_BRK_TIM9     24
#define     MNVIC_TIM1_BRK_TIM10    25
#define     MNVIC_TIM1_BRK_TIM11    26
#define     MNVIC_TIM1_CC           27
#define     MNVIC_TIM2              28
#define     MNVIC_TIM3              29
#define     MNVIC_TIM4              30
#define     MNVIC_I2C1_EV           31
#define     MNVIC_I2C1_ER           32
#define     MNVIC_I2C2_EV           33
#define     MNVIC_I2C2_ER           34
#define     MNVIC_SPI1              35
#define     MNVIC_SPI2              36
#define     MNVIC_USART1            37
#define     MNVIC_USART2            38
#define     MNVIC_EXTI15_10         40
#define     MNVIC_EXTI17            41
#define     MNVIC_EXTI18            42
#define     MNVIC_DMA1_Stream7      47
#define     MNVIC_SDIO              49
#define     MNVIC_TIM5              50
#define     MNVIC_SPI3              51
#define     MNVIC_DMA2_Stream0      56
#define     MNVIC_DMA2_Stream1      57
#define     MNVIC_DMA2_Stream2      58
#define     MNVIC_DMA2_Stream3      59
#define     MNVIC_DMA2_Stream4      60
#define     MNVIC_OTG_FS            67
#define     MNVIC_DMA2_Stream5      68
#define     MNVIC_DMA2_Stream6      69
#define     MNVIC_DMA2_Stream7      70
#define     MNVIC_USART7            71
#define     MNVIC_I2C3_EV           72
#define     MNVIC_I2C3_ER           73
#define     MNVIC_FPU               81
#define     MNVIC_SPI4              84



void    MNVIC_voidInit(void);
void    MNVIC_voidPeripheralInterruptControl(u8 Copy_u8PeripheralID, u8 Copy_u8InterruptState);
void    MNVIC_voidSetPendingFlag(u8 Copy_u8PeripheralID);
void    MNVIC_voidClearPendingFlag(u8 Copy_u8PeripheralID);
u8      MNVIC_u8GetActiveFlag(u8    Copy_u8PeripheralID);
void    MNVIC_voidSetPeripheralPriority(u8 Copy_u8PeripheralID, u8 Copy_u8Priority);


#endif
