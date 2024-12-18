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
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#define		GPIOA_BASE_ADDRESS		0x40020000
#define		GPIOB_BASE_ADDRESS		0x40020400
#define		GPIOC_BASE_ADDRESS		0x40020800 

/************************* GPIOA Registers *************************/
#define		GPIOA_MODER				*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x00))
#define		GPIOA_OTYPER			*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x04))
#define		GPIOA_OSPEEDR			*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x08))
#define		GPIOA_PUPDR				*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x0C))
#define		GPIOA_IDR				*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x10))
#define		GPIOA_ODR				*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x14))
#define		GPIOA_BSRR				*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x18))
#define		GPIOA_LCKR				*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x1C))
#define		GPIOA_AFRL				*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x20))
#define		GPIOA_AFRH				*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x24))

/************************* GPIOB Registers *************************/
#define		GPIOB_MODER				*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x00))
#define		GPIOB_OTYPER			*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x04))
#define		GPIOB_OSPEEDR			*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x08))
#define		GPIOB_PUPDR				*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x0C))
#define		GPIOB_IDR				*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x10))
#define		GPIOB_ODR				*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x14))
#define		GPIOB_BSRR				*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x18))
#define		GPIOB_LCKR				*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x1C))
#define		GPIOB_AFRL				*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x20))
#define		GPIOB_AFRH				*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x24))

/************************* GPIOC Registers *************************/
#define		GPIOC_MODER				*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x00))
#define		GPIOC_OTYPER			*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x04))
#define		GPIOC_OSPEEDR			*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x08))
#define		GPIOC_PUPDR				*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x0C))
#define		GPIOC_IDR				*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x10))
#define		GPIOC_ODR				*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x14))
#define		GPIOC_BSRR				*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x18))
#define		GPIOC_LCKR				*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x1C))
#define		GPIOC_AFRL				*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x20))
#define		GPIOC_AFRH				*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x24))


#define		MODER_MASK				0b11
#define		OSPEEDR_MASK			0b11
#define		OTYPE_MASK				0b1
#define     ITYPE_MASK              0b11
#define     PORT_MASK               0xFFFF
#define     AF_MASK					0b1111
#define		PIN_OFFSET				2
#define     PORT_OFFSET             16
#define     AF_BITS_OFFSET			4
#define     AF_HIGH_BITS_OFFSET		8
#define     PORT_VALUE              0xFFFF




#endif