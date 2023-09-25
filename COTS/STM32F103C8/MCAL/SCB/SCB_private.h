/****************************************************************/
/******* Author    : Yara Ayman                 *****************/
/******* Date      : 7 Sep 2023                 *****************/
/****************************************************************/
#ifndef SCB_PRIVATE_H_
#define SCB_PRIVATE_H_

#define SCB_BASE_ADDRESS    0xE000ED00U

#define SCB_AIRCR           (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x00C))) 
#define SCB_SHCSR           (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x024))) 
#define SCB_SHPR1           (*((volatile u32 *)(SCB_BASE_ADDRESS + 0xD18))) 
#define SCB_SHPR2           (*((volatile u32 *)(SCB_BASE_ADDRESS + 0xD1C))) 
#define SCB_SHPR3           (*((volatile u32 *)(SCB_BASE_ADDRESS + 0xD20))) 


#define SCB_SHCSR_MEMFAULTENA_POS    16  
#define SCB_SHCSR_BUSFAULTENA_POS    17  
#define SCB_SHCSR_USGFAULTENA_POS    18  


#define SCB_AIRCR_PRIGROUP_POS      8          
#define SCB_AIRCR_PRIGROUP_MASK     0x00000700 


#define SCB_16GROUP_0SUB   0x05FA0300U 
#define SCB_8GROUP_2SUB    0x05FA0400U 
#define SCB_4GROUP_4SUB    0x05FA0500U 
#define SCB_2GROUP_8SUB    0x05FA0600U 
#define SCB_0GROUP_16SUB   0x05FA0700U 


#endif 