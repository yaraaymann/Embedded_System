/*********************************************/
/********** Author: Yara Ayman ***************/
/********** Date: 30/8/2023    ***************/
/*********************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB            0 
#define RCC_APB1           1 
#define RCC_APB2           2

u8 Mcal_Rcc_InitSysClock(void);
u8 Mcal_Rcc_EnablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId);
u8 Mcal_Rcc_DisablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId);
u8 Mcal_Rcc_DivideSystemClock(u8 RCC_SYSCLK_DIVIDE);
u8 Mcal_Rcc_MultiplicationSystemClock(u8 RCC_SYSCLK_PLL_MULTIPLY);

#define RCC_CR_HSION       0
#define RCC_CR_HSIRDY      1
#define RCC_CR_HSITRIM     7
#define RCC_CR_HSICAL      15
#define RCC_CR_HSEON       16
#define RCC_CR_HSERDY      17
#define RCC_CR_HSEBYP      18
#define RCC_CR_CSSON       19
#define RCC_CR_PLLON       24
#define RCC_CR_PLLRDY      25

#define RCC_CFGR_SW        0
#define RCC_CFGR_SWS       2
#define RCC_CFGR_HPRE1     4
#define RCC_CFGR_HPRE2     5
#define RCC_CFGR_HPRE3     6
#define RCC_CFGR_HPRE4     7
#define RCC_CFGR_PPRE1     10
#define RCC_CFGR_PPRE2     13
#define RCC_CFGR_ADCPRE    15
#define RCC_CFGR_PLLSRC    16
#define RCC_CFGR_PLLXTPRE  17
#define RCC_CFGR_PLLMUL1   18
#define RCC_CFGR_PLLMUL2   19
#define RCC_CFGR_PLLMUL3   20
#define RCC_CFGR_PLLMUL4   21
#define RCC_CFGR_USBPRE    22
#define RCC_CFGR_MCO       26

#define RCC_HSI             0   
#define RCC_HSE             1   
#define RCC_PLL             2

#define RCC_CRYSTAL_CLK_    0   
#define RCC_RC_CLK_         1


#endif