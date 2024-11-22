//Library
#include	"../include/STD_TYPES.h"
#include	"../include/BIT_MATH.h"

//lower layer

//self layer

//self files
#include	"../include/RCC_interface.h"
#include	"../include/RCC_private.h"
#include	"../include/RCC_config.h"




//pre-build configuration
void RCC_voidInit(void)
{
	#if	RCC_CLOCK_SOURCE == RCC_CLK_HSI
		SET_BIT(RCC_CR,0);		//enable HSI
		CLR_BIT(RCC_CR,16);		//disable HSE
		CLR_BIT(RCC_CR,24);		//disable PLL
		//polling on the flag until HSI is ready
		while(GET_BIT(RCC_CR,1)==0);	
		//select HSI as input clk source
		CLR_BIT(RCC_CFGR,0);
		CLR_BIT(RCC_CFGR,1);
		
	#elif RCC_CLOCK_SOURCE == RCC_CLK_HSE
		CLR_BIT(RCC_CR,0);		//disable HSI
		SET_BIT(RCC_CR,16);		//enable HSE
		CLR_BIT(RCC_CR,24);		//disable PLL
		//polling on the flag until HSE is ready
		while(GET_BIT(RCC_CR,17)==0);	
		//select HSE as input clk source
		SET_BIT(RCC_CFGR,0);
		CLR_BIT(RCC_CFGR,1);		
		
		
	#elif RCC_CLOCK_SOURCE == RCC_CLK_PLL
		#if	RCC_CLK_PLL_SRC  == RCC_CLK_HSI
			CLR_BIT(RCC_PLLCFGR,22);
		#elif	RCC_CLK_PLL_SRC == RCC_CLK_HSE
			SET_BIT(RCC_PLLCFGR,22);
		#else
			#error	"RCC_CLK_PLL_SRC Configuration Error"
		#endif
		
		CLR_BIT(RCC_CR,0);		//disable HSI
		CLR_BIT(RCC_CR,16);		//disable HSE
		SET_BIT(RCC_CR,24);		//enable PLL

		//polling on the flag until PLL is ready
		while(GET_BIT(RCC_CR,25)==0);	
		//select PLL as input clk source
		CLR_BIT(RCC_CFGR,0);
		SET_BIT(RCC_CFGR,1);		

	#else
		#error	"RCC_CLOCK_SOURCE Configuration Error"
	#endif
	
	//AHB prescaler settings
	RCC_CFGR &= ~(RCC_AHB_PRESCALER_MASK<<4);
	RCC_CFGR |= (RCC_AHB_PRESCALER<<4);	
	//APB1 prescaler settings
	RCC_CFGR &= ~(RCC_APB1_PRESCALER_MASK<<10);
	RCC_CFGR |= (RCC_APB1_PRESCALER<<10);
	//APB2 prescaler settings
	RCC_CFGR &= ~(RCC_APB2_PRESCALER_MASK<<13);
	RCC_CFGR |= (RCC_APB2_PRESCALER<<13);
	
}

//post-build configuration

void RCC_voidEnableClockSource(u8 Copy_u8ClockSource)
{
	if(Copy_u8ClockSource == RCC_HSI)
	{
		SET_BIT(RCC_CR,0);
	}
	else if(Copy_u8ClockSource == RCC_HSE)
	{
		SET_BIT(RCC_CR,16);
	}
	else if(Copy_u8ClockSource == RCC_PLL)
	{
		SET_BIT(RCC_CR,24);
	}
	else
	{
		//Error
		
	}
	
}


void RCC_voidDisableClockSource(u8 Copy_u8ClockSource)
{
	if(Copy_u8ClockSource == RCC_HSI)
	{
		CLR_BIT(RCC_CR,0);
	}
	else if(Copy_u8ClockSource == RCC_HSE)
	{
		CLR_BIT(RCC_CR,16);
	}
	else if(Copy_u8ClockSource == RCC_PLL)
	{
		CLR_BIT(RCC_CR,24);
	}
	else
	{
		//Error
		
	}
	
}


void RCC_voidEnablePeripheralClock(u8 Copy_u8BusName,u8 Copy_u8PeripheralName)
{
	switch (Copy_u8BusName)
	{
		case	RCC_AHB:
			SET_BIT(RCC_AHB1ENR,Copy_u8PeripheralName);
		break;
		
		case	RCC_APB1:
			SET_BIT(RCC_APB1ENR,Copy_u8PeripheralName);
		
		break;
		
		case	RCC_APB2:
			SET_BIT(RCC_APB2ENR,Copy_u8PeripheralName);
		
		break;
		
		default:
			//error
			break;
	}	
	
	
}


void RCC_voidDisablePeripheralClock(u8 Copy_u8BusName,u8 Copy_u8PeripheralName)
{
	switch (Copy_u8BusName)
	{
		case	RCC_AHB:
			CLR_BIT(RCC_AHB1ENR,Copy_u8PeripheralName);
		break;
		
		case	RCC_APB1:
			CLR_BIT(RCC_APB1ENR,Copy_u8PeripheralName);
		
		break;
		
		case	RCC_APB2:
			CLR_BIT(RCC_APB2ENR,Copy_u8PeripheralName);
		
		break;
		
		default:
			//error
			break;
	}	
	
	
}

