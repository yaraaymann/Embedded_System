/*********************************************/
/********** Author: Yara Ayman ***************/
/********** Date: 30/8/2023    ***************/
/*********************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H


#define RCC_SYSCLK            RCC_HSE


#if RCC_SYSCLK == RCC_HSE

#define RCC_CLK_BYPASS        RCC_CRYSTAL_CLK_
                                
#endif  

#endif