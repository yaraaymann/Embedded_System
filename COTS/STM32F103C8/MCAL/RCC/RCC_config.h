/****************************************************************/
/******* Author    : Yara Ayman                 *****************/
/******* Date      : 26 Aug 2023                *****************/
/****************************************************************/
#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


#define RCC_SYSCLK            RCC_HSE

#if RCC_SYSCLK == RCC_HSE

#define RCC_CLK_BYPASS        RCC_CRYSTAL_CLK_
                                
#endif 

#if RCC_SYSCLK == RCC_PLL


#endif 

                                
#endif 