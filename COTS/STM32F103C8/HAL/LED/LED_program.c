/****************************************************************/
/******* Author    : Yara Ayman                 *****************/
/******* Date      : 16 Sep 2023                *****************/
/****************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

#include "LED_interface.h"


Std_ReturnType HAL_LED_Init(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId)
{
    
    return MCAL_GPIO_SetPinMode(Copy_LedPortId, Copy_LedPinId, GPIO_OUTPUT_PUSH_PULL_2MHZ);
}

Std_ReturnType HAL_LED_On(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId)
{
    return MCAL_GPIO_SetPinValue(Copy_LedPortId, Copy_LedPinId, GPIO_HIGH);
}

Std_ReturnType HAL_LED_Off(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId)
{
    return MCAL_GPIO_SetPinValue(Copy_LedPortId, Copy_LedPinId, GPIO_LOW);
}

Std_ReturnType HAL_LED_Toggle(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId)
{
    u8 Local_PinValue;
    
    
    if (MCAL_GPIO_GetPinValue(Copy_LedPortId, Copy_LedPinId, &Local_PinValue) == E_NOT_OK) 
    {
        return E_NOT_OK;
    }
    
    
    if (Local_PinValue == GPIO_HIGH) 
    {
        
        return MCAL_GPIO_SetPinValue(Copy_LedPortId, Copy_LedPinId, GPIO_LOW);
    } 
    else 
    {
        
        return MCAL_GPIO_SetPinValue(Copy_LedPortId, Copy_LedPinId, GPIO_HIGH);
    }
}

Std_ReturnType HAL_LED_BlinkOnce(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId, LED_Delay_ms_t Copy_BlinkTime)
{
    if(MCAL_GPIO_SetPinValue(Copy_LedPortId, Copy_LedPinId, GPIO_HIGH) == 0)
    {
        return 0;
    }

    if(SYSTICKSetDelay_ms(Copy_BlinkTime) == 0)
    {
        return 0;
    }

    if(MCAL_GPIO_SetPinValue(Copy_LedPortId, Copy_LedPinId, GPIO_LOW) == 0)
    {
        return 0;
    }

    return 1;
}

Std_ReturnType HAL_LED_BlinkTwice(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId, LED_Delay_ms_t Copy_BlinkTime)
{
    if(HAL_LED_BlinkOnce(Copy_LedPortId, Copy_LedPinId, Copy_BlinkTime) == 0)
    {
        return 0;
    }

    SYSTICKSetDelay_ms(Copy_BlinkTime);

    HAL_LED_BlinkOnce(Copy_LedPortId, Copy_LedPinId, Copy_BlinkTime);

    return 1;
}

