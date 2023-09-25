/****************************************************************/
/******* Author    : Yara Ayman                 *****************/
/******* Date      : 12 Sep 2023                *****************/
/****************************************************************/
#ifndef AFIO_PRIVATE_H_
#define AFIO_PRIVATE_H_


#define AFIO_BASE_ADDRESS       0x40010000 


typedef struct 
{
    volatile u32 EVCR;        
    volatile u32 MAPR;        
    volatile u32 EXTICR[4];   
    volatile u32 MAPR2;       
} AFIO_RegDef_t;


#define AFIO    ((AFIO_RegDef_t *)AFIO_BASE_ADDRESS)



#define AFIO_MAPR_SWJ_CFG_Pos        24 
#define AFIO_MAPR_SWJ_CFG_Msk        (0x7 << AFIO_MAPR_SWJ_CFG_Pos) 

#define AFIO_MAPR_SWJ_CFG_001        (0x1 << AFIO_MAPR_SWJ_CFG_Pos) 
#define AFIO_MAPR_SWJ_CFG_010        (0x2 << AFIO_MAPR_SWJ_CFG_Pos) 

#define AFIO_MAPR_ADC2_ETRGREG_Pos   20 
#define AFIO_MAPR_ADC2_ETRGREG_Msk   (0x1 << AFIO_MAPR_ADC2_ETRGREG_Pos) 

#define AFIO_MAPR_ADC2_ETRGINJ_Pos   19 
#define AFIO_MAPR_ADC2_ETRGINJ_Msk   (0x1 << AFIO_MAPR_ADC2_ETRGINJ_Pos) 

#define AFIO_MAPR_ADC1_ETRGREG_Pos   18 
#define AFIO_MAPR_ADC1_ETRGREG_Msk   (0x1 << AFIO_MAPR_ADC1_ETRGREG_Pos) 

#define AFIO_MAPR_ADC1_ETRGINJ_Pos   17 
#define AFIO_MAPR_ADC1_ETRGINJ_Msk   (0x1 << AFIO_MAPR_ADC1_ETRGINJ_Pos) 

#define AFIO_MAPR_TIM5CH4_Pos        16 
#define AFIO_MAPR_TIM5CH4_Msk        (0x1 << AFIO_MAPR_TIM5CH4_Pos) 

#define AFIO_MAPR_PD01_Pos           15 
#define AFIO_MAPR_PD01_Msk           (0x1 << AFIO_MAPR_PD01_Pos) 

#define AFIO_MAPR_CAN_REMAP_Pos      13 
#define AFIO_MAPR_CAN_REMAP_Msk      (0x3 << AFIO_MAPR_CAN_REMAP_Pos) 

#define AFIO_MAPR_TIM4_REMAP_Pos     12 
#define AFIO_MAPR_TIM4_REMAP_Msk     (0x1 << AFIO_MAPR_TIM4_REMAP_Pos) 

#define AFIO_MAPR_TIM3_REMAP_Pos     10 
#define AFIO_MAPR_TIM3_REMAP_Msk     (0x3 << AFIO_MAPR_TIM3_REMAP_Pos) 

#define AFIO_MAPR_TIM2_REMAP_Pos      8 
#define AFIO_MAPR_TIM2_REMAP_Msk     (0x3 << AFIO_MAPR_TIM2_REMAP_Pos) 

#define AFIO_MAPR_TIM1_REMAP_Pos      6 
#define AFIO_MAPR_TIM1_REMAP_Msk     (0x3 << AFIO_MAPR_TIM1_REMAP_Pos) 

#define AFIO_MAPR_USART3_REMAP_Pos    4 
#define AFIO_MAPR_USART3_REMAP_Msk   (0x3 << AFIO_MAPR_USART3_REMAP_Pos) 

#define AFIO_MAPR_USART2_REMAP_Pos    3 
#define AFIO_MAPR_USART2_REMAP_Msk   (0x1 << AFIO_MAPR_USART2_REMAP_Pos) 

#define AFIO_MAPR_USART1_REMAP_Pos    2 
#define AFIO_MAPR_USART1_REMAP_Msk   (0x1 << AFIO_MAPR_USART1_REMAP_Pos) 

#define AFIO_MAPR_I2C1_REMAP_Pos      1 
#define AFIO_MAPR_I2C1_REMAP_Msk     (0x1 << AFIO_MAPR_I2C1_REMAP_Pos) 

#define AFIO_MAPR_SPI1_REMAP_Pos      0
#define AFIO_MAPR_SPI1_REMAP_Msk     (0x1 << AFIO_MAPR_SPI1_REMAP_Pos) 



#endif 
