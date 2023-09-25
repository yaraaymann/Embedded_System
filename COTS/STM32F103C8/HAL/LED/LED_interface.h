/****************************************************************/
/******* Author    : Yara Ayman                 *****************/
/******* Date      : 16 Sep 2023                *****************/
/****************************************************************/
#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


typedef enum {
    LED_PORTA, 
    LED_PORTB, 
    LED_PORTC  
} LED_Port_t;


typedef enum {
    LED_PIN0,   
    LED_PIN1,  
    LED_PIN2,  
    LED_PIN3,  
    LED_PIN4,  
    LED_PIN5,  
    LED_PIN6,  
    LED_PIN7,  
    LED_PIN8,  
    LED_PIN9,  
    LED_PIN10, 
    LED_PIN11, 
    LED_PIN12, 
    LED_PIN13, 
    LED_PIN14, 
    LED_PIN15, 
} LED_Pin_t;


typedef u32 LED_Delay_ms_t;


Std_ReturnType HAL_LED_Init(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId);


Std_ReturnType HAL_LED_On(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId);


Std_ReturnType HAL_LED_Off(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId);


Std_ReturnType HAL_LED_Toggle(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId);


Std_ReturnType HAL_LED_BlinkOnce(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId, LED_Delay_ms_t Copy_BlinkTime);


Std_ReturnType HAL_LED_BlinkTwice(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId, LED_Delay_ms_t Copy_BlinkTime);



#endif 