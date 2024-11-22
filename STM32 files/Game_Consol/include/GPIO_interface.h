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
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


//Port number
#define     GPIO_PORTA       0
#define     GPIO_PORTB       1
#define     GPIO_PORTC       2

//pin number
#define     GPIO_PIN0        0 
#define     GPIO_PIN1        1 
#define     GPIO_PIN2        2 
#define     GPIO_PIN3        3 
#define     GPIO_PIN4        4 
#define     GPIO_PIN5        5 
#define     GPIO_PIN6        6 
#define     GPIO_PIN7        7 
#define     GPIO_PIN8        8 
#define     GPIO_PIN9        9 
#define     GPIO_PIN10       10 
#define     GPIO_PIN11       11 
#define     GPIO_PIN12       12
#define     GPIO_PIN13       13 
#define     GPIO_PIN14       14
#define     GPIO_PIN15       15

//pin mode
#define     GPIO_INPUT     0b00
#define     GPIO_OUTPUT    0b01
#define     GPIO_AF        0b10
#define     GPIO_ANALOG    0b11

//input type
#define     GPIO_INPUT_FLOAT    0b00
#define     GPIO_INPUT_PU       0b01
#define     GPIO_INPUT_PD       0b10

//output type
#define		GPIO_OUTPUT_PP		0b00
#define		GPIO_OUTPUT_OD		0b01

//output speed
#define		GPIO_LOW_SPEED		0b00
#define		GPIO_MED_SPEED		0b01
#define		GPIO_HIGH_SPEED		0b10
#define		GPIO_VHIGH_SPEED	0b11

//output value
#define		GPIO_PIN_LOW		0
#define		GPIO_PIN_HIGH		1
#define     GPIO_PORT_LOW       0
#define     GPIO_PORT_HIGH      1

//AF
#define     GPIO_AF0            0b0000
#define     GPIO_AF1            0b0001
#define     GPIO_AF2            0b0010
#define     GPIO_AF3            0b0011
#define     GPIO_AF4            0b0100
#define     GPIO_AF5            0b0101
#define     GPIO_AF6            0b0110
#define     GPIO_AF7            0b0111
#define     GPIO_AF8            0b1000
#define     GPIO_AF9            0b1001
#define     GPIO_AF10           0b1010
#define     GPIO_AF11           0b1011
#define     GPIO_AF12           0b1100
#define     GPIO_AF13           0b1101
#define     GPIO_AF14           0b1110
#define     GPIO_AF15           0b1111

void    MGPIO_voidSetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinMode);
void    MGPIO_voidSetPinOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinOutputType);
void    MGPIO_voidSetPinOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinSpeed);
void    MGPIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue);
void    MGPIO_voidSetPinInputType(u8 Copy_u8PortName,u8 Copy_u8PinNumber,u8 Copy_u8PinIntputType);
u8      MGPIO_u8GetPinValue(u8 Copy_u8PortName,u8 Copy_u8PinNumber);

void    MGPIO_voidSetPortMode(u8 Copy_u8PortName,u8 Copy_u8PortMode);
void    MGPIO_voidSetPortOutputType(u8 Copy_u8PortName,u8 Copy_u8PortOutputType);
void    MGPIO_voidSetPortOutputSpeed(u8 Copy_u8PortName,u8 Copy_u8PortSpeed);
void    MGPIO_voidSetPortValue(u8   Copy_u8PortName,u8  Copy_u8PortValue);

void    MGPIO_voidSetAF(u8   Copy_u8PortName,u8  Copy_u8PinNumber,u8    Copy_u8AF );
void MGPIO_voidSetAlternativeFunction(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8AlternativeFunction);


#endif
