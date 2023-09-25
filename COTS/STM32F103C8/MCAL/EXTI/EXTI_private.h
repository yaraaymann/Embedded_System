/****************************************************************/
/******* Author    : Yara Ayman                 *****************/
/******* Date      : 9 Sep 2023                 *****************/
/****************************************************************/
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_


#define EXTI_BASE_ADDRESS    0x40010400U


typedef struct 
{
    volatile u32 IMR;  
    volatile u32 EMR;  
    volatile u32 RTSR; 
    volatile u32 FTSR; 
    volatile u32 SWIER;
    volatile u32 PR;   
} EXTI_RegDef_t;


#define EXTI   ((EXTI_RegDef_t *)EXTI_BASE_ADDRESS)


#define EXTI_LINES_COUNT        16


#define EXTI_LINE_ENABLED       1


#define EXTI_LINE_DISABLED      0


typedef struct 
{
    void (*LineCallback)(void); 
    u8 LineEnabled: 1;          
    u8 TriggerType: 2;          
    u8 : 5;                     
} EXTI_Configuration_t;


extern EXTI_Configuration_t EXTI_Configurations[EXTI_LINES_COUNT];

#endif 
