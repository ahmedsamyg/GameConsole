/*********************************************
 * Author:				Ahmed Samy
 * Creation Data:		28 Mar, 2024
 * Version:				v3.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  28 Mar, 2024		  Ahmed Samy		  	Initial Creation
 * v2.0		  19 Jun, 2024		  Ahmed Samy		  	Add input APIs
 * v3.0		  23 Jun, 2024		  Ahmed Samy		  	Add AF APIs
*********************************************/

//libraies
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

//self layer
#include "../include/GPIO_interface.h"
#include "../include/GPIO_private.h"
#include "../include/GPIO_config.h"



void MGPIO_voidSetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinMode)
{

    switch(Copy_u8PortName)
        {
            case    GPIO_PORTA:
                    GPIOA_MODER &= ~(MODER_MASK<<(Copy_u8PinNumber*PIN_OFFSET));
                    GPIOA_MODER |= (Copy_u8PinMode<< (Copy_u8PinNumber*PIN_OFFSET));
            break;

            case    GPIO_PORTB:
                    GPIOB_MODER &= ~(MODER_MASK<<(Copy_u8PinNumber*PIN_OFFSET));
                    GPIOB_MODER |= (Copy_u8PinMode<< (Copy_u8PinNumber*PIN_OFFSET));
            break;

            case    GPIO_PORTC:
                    GPIOC_MODER &= ~(MODER_MASK<<(Copy_u8PinNumber*PIN_OFFSET));
                    GPIOC_MODER |= (Copy_u8PinMode<< (Copy_u8PinNumber*PIN_OFFSET));
            break;

            default:
                //error
            break;
        }

}




void MGPIO_voidSetPinOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinOutputType)
{
    switch(Copy_u8PortName)
        {
            case    GPIO_PORTA:
                    GPIOA_OTYPER &= ~(OTYPE_MASK<<(Copy_u8PinNumber));
                    GPIOA_OTYPER |= (Copy_u8PinOutputType<< (Copy_u8PinNumber));
            break;

            case    GPIO_PORTB:
                    GPIOB_OTYPER &= ~(OTYPE_MASK<<(Copy_u8PinNumber));
                    GPIOB_OTYPER |= (Copy_u8PinOutputType<< (Copy_u8PinNumber));
            break;

            case    GPIO_PORTC:
                    GPIOC_OTYPER &= ~(OTYPE_MASK<<(Copy_u8PinNumber));
                    GPIOC_OTYPER |= (Copy_u8PinOutputType<< (Copy_u8PinNumber));
            break;

            default:
                //error
            break;
        }
    

}
void MGPIO_voidSetPinOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinSpeed)
{
    switch(Copy_u8PortName)
        {
            case    GPIO_PORTA:
                    GPIOA_OSPEEDR &= ~(OSPEEDR_MASK<<(Copy_u8PinNumber*PIN_OFFSET));
                    GPIOA_OSPEEDR |= (Copy_u8PinSpeed<< (Copy_u8PinNumber*PIN_OFFSET));
            break;

            case    GPIO_PORTB:
                    GPIOB_OSPEEDR &= ~(OSPEEDR_MASK<<(Copy_u8PinNumber*PIN_OFFSET));
                    GPIOB_OSPEEDR |= (Copy_u8PinSpeed<< (Copy_u8PinNumber*PIN_OFFSET));
            break;

            case    GPIO_PORTC:
                    GPIOC_OSPEEDR &= ~(OSPEEDR_MASK<<(Copy_u8PinNumber*PIN_OFFSET));
                    GPIOC_OSPEEDR |= (Copy_u8PinSpeed<< (Copy_u8PinNumber*PIN_OFFSET));
            break;

            default:
                //error
            break;
        }

}
void MGPIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
    switch(Copy_u8PortName)
        {
            case    GPIO_PORTA:
                    if (Copy_u8PinValue==GPIO_PIN_LOW)
                    {
                       // SET_BIT(GPIOA_BSRR,Copy_u8PinNumber+16);
                        GPIOA_BSRR = 1 << (Copy_u8PinNumber+16);
                    }
                    else if(Copy_u8PinValue==GPIO_PIN_HIGH)
                    {
                        //SET_BIT(GPIOA_BSRR,Copy_u8PinNumber);
                        GPIOA_BSRR = 1 << (Copy_u8PinNumber);
                    }
            break;

            case    GPIO_PORTB:
                    if (Copy_u8PinValue==GPIO_PIN_LOW)
                    {
                       // SET_BIT(GPIOA_BSRR,Copy_u8PinNumber+16);
                        GPIOB_BSRR = 1 << (Copy_u8PinNumber+16);
                    }
                    else if(Copy_u8PinValue==GPIO_PIN_HIGH)
                    {
                        //SET_BIT(GPIOA_BSRR,Copy_u8PinNumber);
                        GPIOB_BSRR = 1 << (Copy_u8PinNumber);
                    }
            break;

            case    GPIO_PORTC:
                    if (Copy_u8PinValue==GPIO_PIN_LOW)
                    {
                       // SET_BIT(GPIOA_BSRR,Copy_u8PinNumber+16);
                        GPIOC_BSRR = 1 << (Copy_u8PinNumber+16);
                    }
                    else if(Copy_u8PinValue==GPIO_PIN_HIGH)
                    {
                        //SET_BIT(GPIOA_BSRR,Copy_u8PinNumber);
                        GPIOC_BSRR = 1 << (Copy_u8PinNumber);
                    }
            break;

            default:
                    //error
            break;
        }
    
}



void    MGPIO_voidSetPortMode(u8 Copy_u8PortName,u8 Copy_u8PortMode)
{
    u8  Local_u8Counter=0;
    switch(Copy_u8PortName)
        {
            case    GPIO_PORTA:
                    for(Local_u8Counter=0;Local_u8Counter<=15;Local_u8Counter++)
                    {  
                        GPIOA_MODER &= ~(MODER_MASK<<(Local_u8Counter*PIN_OFFSET));
                        GPIOA_MODER |= (Copy_u8PortMode<< (Local_u8Counter*PIN_OFFSET));
                    }
                    
            break;

            case    GPIO_PORTB:
                    for(Local_u8Counter=0;Local_u8Counter<=15;Local_u8Counter++)
                    {  
                        GPIOB_MODER &= ~(MODER_MASK<<(Local_u8Counter*PIN_OFFSET));
                        GPIOB_MODER |= (Copy_u8PortMode<< (Local_u8Counter*PIN_OFFSET));
                    }
            break;

            case    GPIO_PORTC:
                    for(Local_u8Counter=0;Local_u8Counter<=15;Local_u8Counter++)
                    {  
                        GPIOC_MODER &= ~(MODER_MASK<<(Local_u8Counter*PIN_OFFSET));
                        GPIOC_MODER |= (Copy_u8PortMode<< (Local_u8Counter*PIN_OFFSET));
                    }
            break;

            default:
                //error
            break;
        }
}

void    MGPIO_voidSetPortOutputType(u8 Copy_u8PortName,u8 Copy_u8PortOutputType)
{
    u8  Local_u8Counter=0;
    switch(Copy_u8PortName)
        {
            case    GPIO_PORTA:
                for(Local_u8Counter=0;Local_u8Counter<=15;Local_u8Counter++)
                {
                    GPIOA_OTYPER &= ~(OTYPE_MASK<<(Local_u8Counter));
                    GPIOA_OTYPER |= (Copy_u8PortOutputType<< (Local_u8Counter));
                }
                    
            break;

            case    GPIO_PORTB:
                for(Local_u8Counter=0;Local_u8Counter<=15;Local_u8Counter++)
                {
                    GPIOB_OTYPER &= ~(OTYPE_MASK<<(Local_u8Counter));
                    GPIOB_OTYPER |= (Copy_u8PortOutputType<< (Local_u8Counter));
                }
            break;

            case    GPIO_PORTC:
                for(Local_u8Counter=0;Local_u8Counter<=15;Local_u8Counter++)
                {
                    GPIOC_OTYPER &= ~(OTYPE_MASK<<(Local_u8Counter));
                    GPIOC_OTYPER |= (Copy_u8PortOutputType<< (Local_u8Counter));
                }
            break;

            default:
                //error
            break;
        }

}

void    MGPIO_voidSetPortOutputSpeed(u8 Copy_u8PortName,u8 Copy_u8PortSpeed)
{
    u8  Local_u8Counter=0;
    switch(Copy_u8PortName)
        {
            case    GPIO_PORTA:
                for(Local_u8Counter=0;Local_u8Counter<=15;Local_u8Counter++)
                {
                    GPIOA_OSPEEDR &= ~(OSPEEDR_MASK<<(Local_u8Counter*PIN_OFFSET));
                    GPIOA_OSPEEDR |= (Copy_u8PortSpeed<< (Local_u8Counter*PIN_OFFSET));

                }
                    
            break;

            case    GPIO_PORTB:
                for(Local_u8Counter=0;Local_u8Counter<=15;Local_u8Counter++)
                {
                    GPIOB_OSPEEDR &= ~(OSPEEDR_MASK<<(Local_u8Counter*PIN_OFFSET));
                    GPIOB_OSPEEDR |= (Copy_u8PortSpeed<< (Local_u8Counter*PIN_OFFSET));

                }
            break;

            case    GPIO_PORTC:
                for(Local_u8Counter=0;Local_u8Counter<=15;Local_u8Counter++)
                {
                    GPIOC_OSPEEDR &= ~(OSPEEDR_MASK<<(Local_u8Counter*PIN_OFFSET));
                    GPIOC_OSPEEDR |= (Copy_u8PortSpeed<< (Local_u8Counter*PIN_OFFSET));

                }
            break;

            default:
                //error
            break;
        }
}

void    MGPIO_voidSetPortValue(u8   Copy_u8PortName,u8  Copy_u8PortValue)
{
	u8 Local_u8Counter=0;
	for(Local_u8Counter=0;Local_u8Counter<=15;Local_u8Counter++)
	{
		MGPIO_voidSetPinValue(Copy_u8PortName,Local_u8Counter,Copy_u8PortValue);
	}
//    switch(Copy_u8PortName)
//        {
//            case    GPIO_PORTA:
//                    if (Copy_u8PortValue==GPIO_PORT_LOW)
//                    {
//                        GPIOA_BSRR &= ~(PORT_MASK<<PORT_OFFSET);
//                        GPIOA_BSRR |= (PORT_VALUE);
//                    }
//                    else if(Copy_u8PortValue==GPIO_PORT_HIGH)
//                    {
//                        GPIOA_BSRR &= ~(PORT_MASK);
//                        GPIOA_BSRR |= (PORT_VALUE);
//                    }
//            break;
//
//            case    GPIO_PORTB:
//                    if (Copy_u8PortValue==GPIO_PORT_LOW)
//                    {
//                        GPIOB_BSRR &= ~(PORT_MASK<<PORT_OFFSET);
//                        GPIOB_BSRR |= (PORT_VALUE);
//                    }
//                    else if(Copy_u8PortValue==GPIO_PORT_HIGH)
//                    {
//                        GPIOB_BSRR &= ~(PORT_MASK);
//                        GPIOB_BSRR |= (PORT_VALUE);
//                    }
//            break;
//
//            case    GPIO_PORTC:
//                    if (Copy_u8PortValue==GPIO_PORT_LOW)
//                    {
//                        GPIOC_BSRR &= ~(PORT_MASK<<PORT_OFFSET);
//                        GPIOC_BSRR |= (PORT_VALUE);
//                    }
//                    else if(Copy_u8PortValue==GPIO_PORT_HIGH)
//                    {
//                        GPIOC_BSRR &= ~(PORT_MASK);
//                        GPIOC_BSRR |= (PORT_VALUE);
//                    }
//            break;
//
//            default:
//                    //error
//            break;
//        }

}


void    MGPIO_voidSetPinInputType(u8 Copy_u8PortName,u8 Copy_u8PinNumber,u8 Copy_u8PinIntputType)
{
     switch(Copy_u8PortName)
        {
            case    GPIO_PORTA:
                    GPIOA_PUPDR &= ~(ITYPE_MASK<<(Copy_u8PinNumber*PIN_OFFSET));
                    GPIOA_PUPDR |= (Copy_u8PinIntputType<< (Copy_u8PinNumber*PIN_OFFSET));
            break;

            case    GPIO_PORTB:
                    GPIOB_PUPDR &= ~(ITYPE_MASK<<(Copy_u8PinNumber*PIN_OFFSET));
                    GPIOB_PUPDR |= (Copy_u8PinIntputType<< (Copy_u8PinNumber*PIN_OFFSET));
            break;

            case    GPIO_PORTC:
                    GPIOC_PUPDR &= ~(ITYPE_MASK<<(Copy_u8PinNumber*PIN_OFFSET));
                    GPIOC_PUPDR |= (Copy_u8PinIntputType<< (Copy_u8PinNumber*PIN_OFFSET));
            break;

            default:
                //error
            break;
        }
}

u8      MGPIO_u8GetPinValue(u8 Copy_u8PortName,u8 Copy_u8PinNumber)
{
    u8  Local_u8BitStatus;
    switch(Copy_u8PortName)
    {
        case    GPIO_PORTA:
            Local_u8BitStatus=GET_BIT(GPIOA_IDR,Copy_u8PinNumber);
        break;
        case    GPIO_PORTB:
            Local_u8BitStatus=GET_BIT(GPIOB_IDR,Copy_u8PinNumber);
        break;
        case    GPIO_PORTC:
            Local_u8BitStatus=GET_BIT(GPIOC_IDR,Copy_u8PinNumber);
        break;
    }
    return  Local_u8BitStatus;
}


void    MGPIO_voidSetAF(u8   Copy_u8PortName,u8  Copy_u8PinNumber,u8    Copy_u8AF )
{
    switch (Copy_u8PortName)
    {
    case GPIO_PORTA :
        if((Copy_u8PortName<=GPIO_PIN7)&&(Copy_u8PortName>=GPIO_PIN0)) //low part
        {
            GPIOA_AFRL &=  ~(AF_MASK << (Copy_u8PinNumber* AF_BITS_OFFSET));
            GPIOA_AFRL |= (Copy_u8AF<< (Copy_u8PinNumber *AF_BITS_OFFSET ));

        }
        else if((Copy_u8PortName<=GPIO_PIN15)&&(Copy_u8PortName>=GPIO_PIN8)) //high part
        {
            GPIOA_AFRH &=  ~(AF_MASK << ((Copy_u8PinNumber-AF_HIGH_BITS_OFFSET)* AF_BITS_OFFSET));
            GPIOA_AFRH |= (Copy_u8AF<< ((Copy_u8PinNumber-AF_HIGH_BITS_OFFSET) *AF_BITS_OFFSET ));   
        }
        else
        {
            //error
        }
        break;

    case    GPIO_PORTB :
        if((Copy_u8PortName<=GPIO_PIN7)&&(Copy_u8PortName>=GPIO_PIN0)) //low part
        {
            GPIOB_AFRL &=  ~(AF_MASK << (Copy_u8PinNumber* AF_BITS_OFFSET));
            GPIOB_AFRL |= (Copy_u8AF<< (Copy_u8PinNumber *AF_BITS_OFFSET ));

        }
        else if((Copy_u8PortName<=GPIO_PIN15)&&(Copy_u8PortName>=GPIO_PIN8)) //high part
        {
            GPIOB_AFRH &=  ~(AF_MASK << ((Copy_u8PinNumber-AF_HIGH_BITS_OFFSET)* AF_BITS_OFFSET));
            GPIOB_AFRH |= (Copy_u8AF<< ((Copy_u8PinNumber-AF_HIGH_BITS_OFFSET) *AF_BITS_OFFSET ));   
        }
        else
        {
            //error
        }

        break;

    case    GPIO_PORTC :
        if((Copy_u8PortName<=GPIO_PIN7)&&(Copy_u8PortName>=GPIO_PIN0)) //low part
        {
            GPIOC_AFRL &=  ~(AF_MASK << (Copy_u8PinNumber* AF_BITS_OFFSET));
            GPIOC_AFRL |= (Copy_u8AF<< (Copy_u8PinNumber *AF_BITS_OFFSET ));

        }
        else if((Copy_u8PortName<=GPIO_PIN15)&&(Copy_u8PortName>=GPIO_PIN8)) //high part
        {
            GPIOC_AFRH &=  ~(AF_MASK << ((Copy_u8PinNumber-AF_HIGH_BITS_OFFSET)* AF_BITS_OFFSET));
            GPIOC_AFRH |= (Copy_u8AF<< ((Copy_u8PinNumber-AF_HIGH_BITS_OFFSET) *AF_BITS_OFFSET ));   
        }
        else
        {
            //error
        }

        break;
    default:
        //error
        break;
    }

}

void MGPIO_voidSetAlternativeFunction(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8AlternativeFunction)
{
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			// Check for the pin part
			if(Copy_u8PinNumber <= GPIO_PIN7 && Copy_u8PinNumber >= GPIO_PIN0)
			{
				// Clear the 4 bits associated for that pin (Bit Masking)
				GPIOA_AFRL &= ~(AF_MASK << (Copy_u8PinNumber * AF_BITS_OFFSET));
				// Set the Alternative function number in the bits
				GPIOA_AFRL |= (Copy_u8AlternativeFunction << (Copy_u8PinNumber * AF_BITS_OFFSET));
			}
			else if(Copy_u8PinNumber <= GPIO_PIN15 && Copy_u8PinNumber >= GPIO_PIN8)
			{
				// Clear the 4 bits associated for that pin (Bit Masking)
				GPIOA_AFRH &= ~(AF_MASK << ((Copy_u8PinNumber-AF_HIGH_BITS_OFFSET) * AF_BITS_OFFSET));
				// Set the Alternative function number in the bits
				GPIOA_AFRH |= (Copy_u8AlternativeFunction << ((Copy_u8PinNumber-AF_HIGH_BITS_OFFSET) * AF_BITS_OFFSET));
			}
			else
			{
				// Error
			}
		break;

		case GPIO_PORTB:
		break;

		case GPIO_PORTC:
		break;

		default:
			// Error
		break;
	}
}
