/*********************************************/
/********** Author: Yara Ayman ***************/
/********** Date: 30/8/2023    ***************/
/*********************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#define RCC_CR         (*((volatile u8*)0x40021000))
#define RCC_CFGR       (*((volatile u8*)0x40021004))
#define RCC_CIR        (*((volatile u8*)0x40021008))
#define RCC_APB2RSTR   (*((volatile u8*)0x4002100C))
#define RCC_APB1RSTR   (*((volatile u8*)0x40021010))
#define RCC_AHBENR     (*((volatile u8*)0x40021014))
#define RCC_APB2ENR    (*((volatile u8*)0x40021018))
#define RCC_APB1ENR    (*((volatile u8*)0x4002101C))
#define RCC_BDCR       (*((volatile u8*)0x40021020))
#define RCC_CSR        (*((volatile u8*)0x40021024))




#endif
