/*********************************************/
/********** Author: Yara Ayman ***************/
/********** Date: 30/8/2023    ***************/
/*********************************************/

#include "c:\Users\H&M\Desktop\New folder\STD_TYPES.h"
#include "c:\Users\H&M\Desktop\New folder\STD_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

u8 Mcal_Rcc_InitSysClock(void)
{
  u8 status = 0;
  #if RCC_SYSCLK == RCC_HSE
    
        #if RCC_CLK_BYPASS == RCC_RC_CLK_ 
         SET_BIT(RCC_CR,RCC_CR_HSEBYP);
        #elif RCC_CLK_BYPASS == RCC_CRYSTAL_CLK_
         CLR_BIT(RCC_CR,RCC_CR_HSEBYP);
        #else
         #error "ERROR!"
        #endif
        SET_BIT(RCC_CR, RCC_CR_HSEON);
        while(!GET_BIT(RCC_CR, RCC_CR_HSERDY));
        RCC_CFGR = 0x00000001;
        status = 1;
  #elif RCC_SYSCLK == RCC_HSI
        
        SET_BIT(RCC_CR, RCC_CR_HSION);
        while(!GET_BIT(RCC_CR, RCC_CR_HSIRDY));
        RCC_CFGR = 0x00000000;
        status = 1;

 #elif RCC_SYSCLK == RCC_PLL    
        SET_BIT(RCC_CR,RCC_CR_PLLON)
        while (!GET_BIT(RCC_CR,RCC_CR_PLLRDY));
        RCC_CFGR = 0x00000010;
        status = 1;
 #else
        #error "ERROR!"

  #endif
  return status;
}
u8 Mcal_Rcc_EnablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId)
{
      u8 status = 0;

    switch(Copy_BusId)
    {
        case RCC_AHB:
            SET_BIT(RCC_AHBENR, Copy_PeripheralId);
            status = 1;
            break;

        case RCC_APB1:
            SET_BIT(RCC_APB1ENR, Copy_PeripheralId);
            status = 1;
            break;

        case RCC_APB2:
            SET_BIT(RCC_APB2ENR, Copy_PeripheralId);
            status = 1;
            break;

        default:
            status = 0;
            break;
    }

    return status;
}
u8 Mcal_Rcc_DisablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId)
{
      u8 status = 0;

    switch(Copy_BusId)
    {
        case RCC_AHB:
            CLR_BIT(RCC_AHBENR, Copy_PeripheralId);
            status = 1;
            break;

        case RCC_APB1:
            CLR_BIT(RCC_APB1ENR, Copy_PeripheralId);
            status = 1;
            break;

        case RCC_APB2:
            CLR_BIT(RCC_APB2ENR, Copy_PeripheralId);
            status = 1;
            break;

        default:
            status = 0;
            break;
    }

    return status;
}
u8 Mcal_Rcc_DivideSystemClock(u8 RCC_SYSCLK_DIVIDE)
{ u8 Status = 0;
  #if RCC_SYSCLK_DIVIDE == 0
      CLR_BIT(RCC_CFGR,RCC_CFGR_HPRE4);
      Status = 1;
  #else 
      SET_BIT(RCC_CFGR,RCC_CFGR_HPRE4);
      #if RCC_SYSCLK_DIVIDE == 2
        CLR_BIT(RCC_CFGR,RCC_CFGR_HPRE1);
        CLR_BIT(RCC_CFGR,RCC_CFGR_HPRE2);
        CLR_BIT(RCC_CFGR,RCC_CFGR_HPRE3);
        Status = 1;
      #elif RCC_SYSCLK_DIVIDE == 4
        SET_BIT(RCC_CFGR,RCC_CFGR_HPRE1);
        CLR_BIT(RCC_CFGR,RCC_CFGR_HPRE2);
        CLR_BIT(RCC_CFGR,RCC_CFGR_HPRE3);
        Status = 1;
      #elif RCC_SYSCLK_DIVIDE == 8
        CLR_BIT(RCC_CFGR,RCC_CFGR_HPRE1);
        SET_BIT(RCC_CFGR,RCC_CFGR_HPRE2);
        CLR_BIT(RCC_CFGR,RCC_CFGR_HPRE3);
        Status = 1;
      #elif RCC_SYSCLK_DIVIDE == 16
        SET_BIT(RCC_CFGR,RCC_CFGR_HPRE1);
        SET_BIT(RCC_CFGR,RCC_CFGR_HPRE2);
        CLR_BIT(RCC_CFGR,RCC_CFGR_HPRE3);
        Status = 1;
      #elif RCC_SYSCLK_DIVIDE == 64
        CLR_BIT(RCC_CFGR,RCC_CFGR_HPRE1);
        CLR_BIT(RCC_CFGR,RCC_CFGR_HPRE2);
        SET_BIT(RCC_CFGR,RCC_CFGR_HPRE3);
        Status = 1;
      #elif RCC_SYSCLK_DIVIDE == 128
        SET_BIT(RCC_CFGR,RCC_CFGR_HPRE1);
        CLR_BIT(RCC_CFGR,RCC_CFGR_HPRE2);
        SET_BIT(RCC_CFGR,RCC_CFGR_HPRE3);
        Status = 1;
      #elif RCC_SYSCLK_DIVIDE == 256
        CLR_BIT(RCC_CFGR,RCC_CFGR_HPRE1);
        SET_BIT(RCC_CFGR,RCC_CFGR_HPRE2);
        SET_BIT(RCC_CFGR,RCC_CFGR_HPRE3);
        Status = 1;
      #elif RCC_SYSCLK_DIVIDE == 512
        SET_BIT(RCC_CFGR,RCC_CFGR_HPRE1);
        SET_BIT(RCC_CFGR,RCC_CFGR_HPRE2);
        SET_BIT(RCC_CFGR,RCC_CFGR_HPRE3);
        Status = 1;
      #else
        #error 'ERROE!'
      #endif  
  #endif
  return Status;
}
u8 Mcal_Rcc_MultiplicationSystemClock(u8 RCC_SYSCLK_PLL_MULTIPLY)
{ 
u8 Status = 0;
u8 RCC_PLLON = (GET_BIT(RCC_CR,RCC_CR_PLLON));
u8 RCC_PLLReady = (GET_BIT(RCC_CR,RCC_CR_PLLRDY));
#if (RCC_PLLON && ! RCC_PLLReady)
  CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
  CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
  CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
  CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL4);
  #if RCC_SYSCLK_PLL_MULTIPLY == 2
      Status = 1;
  #elif RCC_SYSCLK_PLL_MULTIPLY == 3
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
      Status = 1;
  #elif RCC_SYSCLK_PLL_MULTIPLY == 4
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
      Status = 1;
  #elif RCC_SYSCLK_PLL_MULTIPLY == 5
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
      Status = 1;
  #elif RCC_SYSCLK_PLL_MULTIPLY == 6
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
      Status = 1;
  #elif RCC_SYSCLK_PLL_MULTIPLY == 7
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
      Status = 1;
  #elif RCC_SYSCLK_PLL_MULTIPLY == 8
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
      Status = 1;
  #elif RCC_SYSCLK_PLL_MULTIPLY == 9
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
      Status = 1;
  #elif RCC_SYSCLK_PLL_MULTIPLY == 10
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL4);
      Status = 1;
  #elif RCC_SYSCLK_PLL_MULTIPLY == 11
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL4);
      Status = 1;
  #elif RCC_SYSCLK_PLL_MULTIPLY == 12
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL4);
      Status = 1;
  #elif RCC_SYSCLK_PLL_MULTIPLY == 13
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL4);
      Status = 1;
  #elif RCC_SYSCLK_PLL_MULTIPLY == 14
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL4);
      Status = 1;
  #elif RCC_SYSCLK_PLL_MULTIPLY == 15
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL4);
      Status = 1;  
  #elif RCC_SYSCLK_PLL_MULTIPLY == 16
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL4);
      Status = 1;
  #elif RCC_SYSCLK_PLL_MULTIPLY == 17
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
      SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL4);
      Status = 1;
  #else
      #error 'ERROE!'
  #endif
#endif 
return Status;
}