/******************************************/
/********** NAME: YARA AYMAN **************/
/********** DATE: 1/9/2023   **************/
/******************************************/

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#define GPIO_PORTA   (*((volatile u8*)0x40010800))
#define GPIO_PORTB   (*((volatile u8*)0x40010C00))
#define GPIO_PORTC   (*((volatile u8*)0x40011000))
#define GPIO_PORTD   (*((volatile u8*)0x40011400))
#define GPIO_PORTE   (*((volatile u8*)0x40011800))
#define GPIO_PORTF   (*((volatile u8*)0x40011C00))
#define GPIO_PORTG   (*((volatile u8*)0x40012000))

#define GPIOA_CRL    (*((volatile u8*)(0x40010800 + 0x00)))
#define GPIOB_CRL    (*((volatile u8*)(0x40010C00 + 0x00)))
#define GPIOC_CRL    (*((volatile u8*)(0x40011000 + 0x00)))
#define GPIOD_CRL    (*((volatile u8*)(0x40011400 + 0x00)))
#define GPIOE_CRL    (*((volatile u8*)(0x40011800 + 0x00)))
#define GPIOF_CRL    (*((volatile u8*)(0x40011C00 + 0x00)))
#define GPIOG_CRL    (*((volatile u8*)(0x40012000 + 0x00)))

#define GPIOA_CRH    (*((volatile u8*)(0x40010800 + 0x04)))
#define GPIOB_CRH    (*((volatile u8*)(0x40010C00 + 0x04)))
#define GPIOC_CRH    (*((volatile u8*)(0x40011000 + 0x04)))
#define GPIOD_CRH    (*((volatile u8*)(0x40011400 + 0x04)))
#define GPIOE_CRH    (*((volatile u8*)(0x40011800 + 0x04)))
#define GPIOF_CRH    (*((volatile u8*)(0x40011C00 + 0x04)))
#define GPIOG_CRH    (*((volatile u8*)(0x40012000 + 0x04)))

#define GPIOA_IDR    (*((volatile u8*)(0x40010800 + 0x08)))
#define GPIOB_IDR    (*((volatile u8*)(0x40010C00 + 0x08)))
#define GPIOC_IDR    (*((volatile u8*)(0x40011000 + 0x08)))
#define GPIOD_IDR    (*((volatile u8*)(0x40011400 + 0x08)))
#define GPIOE_IDR    (*((volatile u8*)(0x40011800 + 0x08)))
#define GPIOF_IDR    (*((volatile u8*)(0x40011C00 + 0x08)))
#define GPIOG_IDR    (*((volatile u8*)(0x40012000 + 0x08)))

#define GPIOA_ODR    (*((volatile u8*)(0x40010800 + 0x0C)))
#define GPIOB_ODR    (*((volatile u8*)(0x40010C00 + 0x0C)))
#define GPIOC_ODR    (*((volatile u8*)(0x40011000 + 0x0C)))
#define GPIOD_ODR    (*((volatile u8*)(0x40011400 + 0x0C)))
#define GPIOE_ODR    (*((volatile u8*)(0x40011800 + 0x0C)))
#define GPIOF_ODR    (*((volatile u8*)(0x40011C00 + 0x0C)))
#define GPIOG_ODR    (*((volatile u8*)(0x40012000 + 0x0C)))

#define GPIOB_BSRR    (*((volatile u8*)(0x40010C00 + 0x10)))
#define GPIOA_BSRR    (*((volatile u8*)(0x40010800 + 0x10)))
#define GPIOC_BSRR    (*((volatile u8*)(0x40011000 + 0x10)))
#define GPIOD_BSRR    (*((volatile u8*)(0x40011400 + 0x10)))
#define GPIOE_BSRR    (*((volatile u8*)(0x40011800 + 0x10)))
#define GPIOF_BSRR    (*((volatile u8*)(0x40011C00 + 0x10)))
#define GPIOG_BSRR    (*((volatile u8*)(0x40012000 + 0x10)))

#endif
