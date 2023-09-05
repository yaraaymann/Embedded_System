/******************************************/
/********** NAME: YARA AYMAN **************/
/********** DATE: 1/9/2023   **************/
/******************************************/


#include "STD_TYPES.h"
#include "STD_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

u8 McalSetPinMode (u8 GPIOPort,u8 GPIOPin,u8 GPIOMode)
{
    u8 Status = 0;
    switch (GPIOPort)
    {
    case PORTA:
       Status = 1;
       #if GPIOPin < GPIO_PIN8
         GPIOA_CRL &= ~(0b1111)<<(GPIOPin *4);
         GPIOA_CRL |= (GPIOMode)<<(GPIOPin *4);
        #elif GPIOPin <= GPIO_PIN15
         GPIOA_CRH &= ~(0b1111)<<(GPIOPin *4);
         GPIOA_CRH |= (GPIOMode)<<(GPIOPin *4);          
        #endif
        break;

    case PORTB:
       Status = 1;  
       #if GPIOPin < GPIO_PIN8
         GPIOB_CRL &= ~(0b1111)<<(GPIOPin *4);
         GPIOB_CRL |= (GPIOMode)<<(GPIOPin *4);
        #elif GPIOPin <= GPIO_PIN15
         GPIOB_CRH &= ~(0b1111)<<(GPIOPin *4);
         GPIOB_CRH |= (GPIOMode)<<(GPIOPin *4);          
        #endif
        break;    
    
    case PORTC:
       Status = 1;
       #if GPIOPin < GPIO_PIN8
         GPIOC_CRL &= ~(0b1111)<<(GPIOPin *4);
         GPIOC_CRL |= (GPIOMode)<<(GPIOPin *4);
        #elif GPIOPin <= GPIO_PIN15
         GPIOC_CRH &= ~(0b1111)<<(GPIOPin *4);
         GPIOC_CRH |= (GPIOMode)<<(GPIOPin *4);          
        #endif
        break;    
    
    case PORTD:
       Status = 1;
       #if GPIOPin < GPIO_PIN8
         GPIOD_CRL &= ~(0b1111)<<(GPIOPin *4);
         GPIOD_CRL |= (GPIOMode)<<(GPIOPin *4);
        #elif GPIOPin < GPIO_PIN15
         GPIOD_CRH &= ~(0b1111)<<(GPIOPin *4);
         GPIOD_CRH |= (GPIOMode)<<(GPIOPin *4);          
        #endif
        break;    
    }
    return Status;
}

u8 McalSetPortPinValue (u8 GPIOPort,u8 GPIOPin,u8 GPIOPinValue)
{
  u8 Status = 0;
  switch (GPIOPort)
  {
  case PORTA:
    switch (GPIOPinValue)
    {
    case GPIO_INPUT:
      CLR_BIT(GPIOA_ODR,GPIOPin);
      Status =1;
    break;  
    case GPIO_OUTPUT:
      SET_BIT(GPIOA_ODR,GPIOPin);
      Status =1;
    break;
    }
  case PORTB:
    switch (GPIOPinValue)
    {
    case GPIO_INPUT:
      CLR_BIT(GPIOB_ODR,GPIOPin);
      Status =1;
    break;  
    case GPIO_OUTPUT:
      SET_BIT(GPIOB_ODR,GPIOPin);
      Status =1;
    break;
    }  
  case PORTC:
    switch (GPIOPinValue)
    {
    case GPIO_INPUT:
      CLR_BIT(GPIOC_ODR,GPIOPin);
      Status =1;
    break;  
    case GPIO_OUTPUT:
      SET_BIT(GPIOC_ODR,GPIOPin);
      Status =1;
    break;
    }  
    break;
  }
  return Status;
}
u8 McalGetPinValue (u8 GPIOPort,u8 GPIOPin,u8 *GPIOPinValue)
{
  u8 Status = 0;
  switch (GPIOPort)
  {
  case PORTA:
       *GPIOPinValue = GET_BIT(GPIOA_IDR,GPIOPin);
       Status =1;
    break;   
  case PORTB:
      *GPIOPinValue = GET_BIT(GPIOB_IDR,GPIOPin);
      Status =1;
    break;  
  case PORTC:
      *GPIOPinValue = GET_BIT(GPIOB_IDR,GPIOPin);
      Status =1;
    break;
  }
  return Status;
}
