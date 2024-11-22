/*
 * main.c
 *
 *  Created on: Oct 15, 2024
 *      Author: PC
 */
#include "../include/BIT_MATH.h"
#include "../include/STD_TYPES.h"

#include "../include/GPIO_interface.h"
#include "../include/RCC_interface.h"
#include "../include/STK_interface.h"
#include "../include/NVIC_interface.h"
#include "../include/EXTI_interface.h"
#include "../include/USART_interface.h"
#include "../include/Sound_Arrays.h"

#define Sound_port				GPIO_PORTB
#define welcome_Array_length	21504
#define GameOver_Array_length	11712
#define Exit_Array_length 		8064


#define NO_START		0
#define START			1

#define	BUTTON_POWER	0
#define	BUTTON_1		1
#define	BUTTON_2		2
#define	BUTTON_3		6
#define	BUTTON_4		4
#define	BUTTON_5		5
#define	BUTTON_6		7
#define	BUTTON_7		8
#define	BUTTON_8		10
#define	BUTTON_9		11
#define	BUTTON_0		14
#define	BUTTON_UP		21
#define	BUTTON_DOWN		22
#define	BUTTON_RIGHT	23
#define	BUTTON_LEFT		20
#define	BUTTON_OK		18




u8	APP_u8ButtonData=0;
u8	APP_u8StartBitFlag = NO_START;
u8	APP_u8EdgeCounter = 0;
u32	APP_u32ReceivedFrame[100];
volatile u8 soundPlayedFlag = 0;
volatile u8 PowerFlag =0;

void GetFrame(void);
void TakeAction(void);
void APP_voidPlay(void);
void APP_PlaySound(const u8 *copy_pu8SoundArray,const u32 Array_Length);


int main()
{

	RCC_voidInit();
	//enable GPIO clk
	RCC_voidEnablePeripheralClock(RCC_AHB, RCC_AHB_GPIOAEN);
	RCC_voidEnablePeripheralClock(RCC_AHB, RCC_AHB_GPIOBEN);
	//enable UART clk
	RCC_voidEnablePeripheralClock(RCC_APB2, RCC_APB2_USART1EN);
	//enable clk for SYSCFG
	RCC_voidEnablePeripheralClock(RCC_APB2,RCC_APB2_SYSCFGEN);
	//Set PA0 for EXTI0 to be input pull up
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN0, GPIO_INPUT);
	MGPIO_voidSetPinInputType(GPIO_PORTA,GPIO_PIN0,GPIO_INPUT_PU);
	//init PB for DAC
	MGPIO_voidSetPinMode(GPIO_PORTB,GPIO_PIN0,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(GPIO_PORTB,GPIO_PIN1,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(GPIO_PORTB,GPIO_PIN2,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(GPIO_PORTB,GPIO_PIN8,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(GPIO_PORTB,GPIO_PIN9,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(GPIO_PORTB,GPIO_PIN5,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(GPIO_PORTB,GPIO_PIN6,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(GPIO_PORTB,GPIO_PIN7,GPIO_OUTPUT);
	//init STK & NVIC
	MSTK_voidInit();
	MNVIC_voidInit();
	//Set PA0 for EXTI0 to be input pull up
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN0, GPIO_INPUT);
	MGPIO_voidSetPinInputType(GPIO_PORTA,GPIO_PIN0,GPIO_INPUT_PU);
	//set callback for EXTI0 and enable it
	MEXTI_voidInit();	//EXTI0 ,PA0 , falling
	MEXTI_voidSetCallBack(MEXTI_EXTI0, &GetFrame);
	MNVIC_voidPeripheralInterruptControl(MNVIC_EXTI0, MNVIC_INT_ENABLE);


	MUSART1_voidInit();

	u8 ReceivedData=0;


	while(1)
	{

	}

	return 0;
}

void GetFrame(void)
{

	if(APP_u8StartBitFlag== NO_START)
	{
		MSTK_voidSetPreloadValue(1000000);
		MSTK_voidSetSingleIntervel(&TakeAction);
		APP_u8StartBitFlag = START;
	}
	else
	{
		APP_u32ReceivedFrame[APP_u8EdgeCounter] = MSTK_u32GetTimeElapsed();
		MSTK_voidResetTimer();
		MSTK_voidSetPreloadValue(1000000);
		APP_u8EdgeCounter++;
	}


}

void TakeAction(void)
{
	u8	Local_u8Counter=0;
	for(Local_u8Counter=0;Local_u8Counter<8;Local_u8Counter++)
	{
		if((APP_u32ReceivedFrame[17+Local_u8Counter]>= 1000)&&
		(APP_u32ReceivedFrame[17+Local_u8Counter]<= 1500))
		{
			CLR_BIT(APP_u8ButtonData,Local_u8Counter);
		}
		else
		{
			SET_BIT(APP_u8ButtonData,Local_u8Counter);
		}
	}
	APP_u8EdgeCounter=0;
	APP_u8StartBitFlag= NO_START;
	MSTK_voidSTKEnable();
	APP_voidPlay();
}

void APP_voidPlay(void)
{
	switch(APP_u8ButtonData)
		{
		case BUTTON_POWER:

			MUSART1_voidSendDataSynchronous(0);
			if (PowerFlag == 0)
			{
				APP_PlaySound(Exit_Array, (u32)Exit_Array_length);
				PowerFlag = 1; // Set flag to prevent re-entry
			}
			break;
		case BUTTON_1:
			MUSART1_voidSendDataSynchronous(1);
			break;
		case BUTTON_2:
			MUSART1_voidSendDataSynchronous(2);
			break;
		case BUTTON_3:
			MUSART1_voidSendDataSynchronous(3);
			break;
		case BUTTON_4:
			MUSART1_voidSendDataSynchronous(4);
			break;
		case BUTTON_5:
			MUSART1_voidSendDataSynchronous(5);
			break;
		case BUTTON_6:
			MUSART1_voidSendDataSynchronous(6);
			break;
		case BUTTON_7:
			MUSART1_voidSendDataSynchronous(7);
			break;
		case BUTTON_8:
			MUSART1_voidSendDataSynchronous(8);
			if (soundPlayedFlag == 0)
			{
				APP_PlaySound(welcome_Array, (u32)welcome_Array_length);
				soundPlayedFlag = 1; // Set flag to prevent re-entry
			}
			break;
		case BUTTON_9:
			MUSART1_voidSendDataSynchronous(9);
			break;
		case BUTTON_0:
			MUSART1_voidSendDataSynchronous(10);
			break;
		case BUTTON_UP:
			MUSART1_voidSendDataSynchronous(11);
			break;
		case BUTTON_DOWN:
			MUSART1_voidSendDataSynchronous(12);
			break;
		case BUTTON_RIGHT:
			MUSART1_voidSendDataSynchronous(13);
			break;
		case BUTTON_LEFT:
			MUSART1_voidSendDataSynchronous(14);
			break;
		case BUTTON_OK:
			MUSART1_voidSendDataSynchronous(15);


			break;
		default:
			break;
		}
}

void APP_PlaySound(const u8 *copy_pu8SoundArray,const u32 Array_Length)
{
	u32 Local_u32Counter=0;
	for(Local_u32Counter=0;Local_u32Counter<Array_Length;Local_u32Counter++)
	{
		MSTK_voidResetTimer();
		MGPIO_voidSetPinValue(Sound_port,GPIO_PIN0,GET_BIT(copy_pu8SoundArray[Local_u32Counter],0));
		MGPIO_voidSetPinValue(Sound_port,GPIO_PIN1,GET_BIT(copy_pu8SoundArray[Local_u32Counter],1));
		MGPIO_voidSetPinValue(Sound_port,GPIO_PIN2,GET_BIT(copy_pu8SoundArray[Local_u32Counter],2));
		MGPIO_voidSetPinValue(Sound_port,GPIO_PIN8,GET_BIT(copy_pu8SoundArray[Local_u32Counter],3));
		MGPIO_voidSetPinValue(Sound_port,GPIO_PIN9,GET_BIT(copy_pu8SoundArray[Local_u32Counter],4));
		MGPIO_voidSetPinValue(Sound_port,GPIO_PIN5,GET_BIT(copy_pu8SoundArray[Local_u32Counter],5));
		MGPIO_voidSetPinValue(Sound_port,GPIO_PIN6,GET_BIT(copy_pu8SoundArray[Local_u32Counter],6));
		MGPIO_voidSetPinValue(Sound_port,GPIO_PIN7,GET_BIT(copy_pu8SoundArray[Local_u32Counter],7));
		MSTK_voidSetBusyWait(150);
	}
}


