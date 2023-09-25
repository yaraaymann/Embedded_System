/****************************************************************/
/******* Author    : Yara Ayman                 *****************/
/******* Date      : 29 Aug 2023                *****************/
/****************************************************************/
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_


#define GPIO_PORTA_BASE_ADDRESS     0x40010800U   
#define GPIO_PORTB_BASE_ADDRESS     0x40010C00U   
#define GPIO_PORTC_BASE_ADDRESS     0x40011000U   


#define GPIOA_CRL            (*((volatile u32 *)(GPIO_PORTA_BASE_ADDRESS + 0x00))) 
#define GPIOA_CRH            (*((volatile u32 *)(GPIO_PORTA_BASE_ADDRESS + 0x04))) 
#define GPIOA_IDR            (*((volatile u32 *)(GPIO_PORTA_BASE_ADDRESS + 0x08))) 
#define GPIOA_ODR            (*((volatile u32 *)(GPIO_PORTA_BASE_ADDRESS + 0x0C))) 
#define GPIOA_BSR            (*((volatile u32 *)(GPIO_PORTA_BASE_ADDRESS + 0x10))) 
#define GPIOA_BRR            (*((volatile u32 *)(GPIO_PORTA_BASE_ADDRESS + 0x14))) 
#define GPIOA_LCK            (*((volatile u32 *)(GPIO_PORTA_BASE_ADDRESS + 0x18))) 


#define GPIOB_CRL            (*((volatile u32 *)(GPIO_PORTB_BASE_ADDRESS + 0x00))) 
#define GPIOB_CRH            (*((volatile u32 *)(GPIO_PORTB_BASE_ADDRESS + 0x04))) 
#define GPIOB_IDR            (*((volatile u32 *)(GPIO_PORTB_BASE_ADDRESS + 0x08))) 
#define GPIOB_ODR            (*((volatile u32 *)(GPIO_PORTB_BASE_ADDRESS + 0x0C))) 
#define GPIOB_BSR            (*((volatile u32 *)(GPIO_PORTB_BASE_ADDRESS + 0x10))) 
#define GPIOB_BRR            (*((volatile u32 *)(GPIO_PORTB_BASE_ADDRESS + 0x14))) 
#define GPIOB_LCK            (*((volatile u32 *)(GPIO_PORTB_BASE_ADDRESS + 0x18))) 


#define GPIOC_CRL            (*((volatile u32 *)(GPIO_PORTC_BASE_ADDRESS + 0x00))) 
#define GPIOC_CRH            (*((volatile u32 *)(GPIO_PORTC_BASE_ADDRESS + 0x04))) 
#define GPIOC_IDR            (*((volatile u32 *)(GPIO_PORTC_BASE_ADDRESS + 0x08))) 
#define GPIOC_ODR            (*((volatile u32 *)(GPIO_PORTC_BASE_ADDRESS + 0x0C))) 
#define GPIOC_BSR            (*((volatile u32 *)(GPIO_PORTC_BASE_ADDRESS + 0x10))) 
#define GPIOC_BRR            (*((volatile u32 *)(GPIO_PORTC_BASE_ADDRESS + 0x14))) 
#define GPIOC_LCK            (*((volatile u32 *)(GPIO_PORTC_BASE_ADDRESS + 0x18))) 




#endif 