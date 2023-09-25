#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "AFIO_interface.h"
#include "LED_interface.h"

volatile u8 value;
volatile u8 value1;
volatile u8 value2;

int main(void)
{
	
  MCAL_RCC_InitSysClock();
	MCAL_RCC_EnablePeripheral(RCC_APB2,RCC_APB2ENR_IOPAEN);
	MCAL_RCC_EnablePeripheral(RCC_APB2,RCC_APB2ENR_IOPBEN);
	EXTI_Init();
	EXTI_EnableLine(EXTI_LINE0);
	EXTI_SetTrigger(EXTI_LINE0,EXTI_RISING_EDGE);
  MCAL_NVIC_EnableIRQ(NVIC_EXTI0_IRQn);
	/** A CROSSWALK BUTTON **/
	MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_INPUT_PULL_UP_MOD);
	MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_LOW);
	/** FOT TESTING **/
	MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN1,GPIO_OUTPUT_PUSH_PULL_2MHZ);
	/** FOR CARS **/
	HAL_LED_Init(GPIO_PORTA,GPIO_PIN2);
	HAL_LED_Init(GPIO_PORTA,GPIO_PIN3);
	HAL_LED_Init(GPIO_PORTA,GPIO_PIN4);
	//** FOR PEDESTRIAN **/
	HAL_LED_Init(GPIO_PORTB,GPIO_PIN2);
	HAL_LED_Init(GPIO_PORTB,GPIO_PIN3);
	HAL_LED_Init(GPIO_PORTB,GPIO_PIN4);
	MCAL_NVIC_vSetPriority(NVIC_EXTI0_IRQn,0,0);
	
	__enable_irq();
	
	for(;;)
	{
		HAL_LED_Off(GPIO_PORTA,GPIO_PIN4);
		HAL_LED_Off(GPIO_PORTB,GPIO_PIN2);
		HAL_LED_On(GPIO_PORTA,GPIO_PIN3);
		HAL_LED_On(GPIO_PORTB,GPIO_PIN3);
		HAL_LED_Off(GPIO_PORTA,GPIO_PIN2);
		HAL_LED_Off(GPIO_PORTB,GPIO_PIN4);
		for(u32 C=0;C<5000;C++);
		
		HAL_LED_Off(GPIO_PORTA,GPIO_PIN3);
		HAL_LED_Off(GPIO_PORTB,GPIO_PIN3);
		HAL_LED_On(GPIO_PORTA,GPIO_PIN2);
		HAL_LED_On(GPIO_PORTB,GPIO_PIN4);
		HAL_LED_Off(GPIO_PORTA,GPIO_PIN4);
		HAL_LED_Off(GPIO_PORTB,GPIO_PIN2);
		for(u32 n=0;n<5000;n++);
		
		HAL_LED_Off(GPIO_PORTA,GPIO_PIN2);
		HAL_LED_Off(GPIO_PORTB,GPIO_PIN4);
		HAL_LED_On(GPIO_PORTA,GPIO_PIN3);
		HAL_LED_On(GPIO_PORTB,GPIO_PIN3);
		for(u32 p=0;p<5000;p++);	
		
		HAL_LED_Off(GPIO_PORTA,GPIO_PIN3);
		HAL_LED_Off(GPIO_PORTB,GPIO_PIN3);
		HAL_LED_On(GPIO_PORTA,GPIO_PIN4);
		HAL_LED_On(GPIO_PORTB,GPIO_PIN2);
		for(u32 j=0;j<5000;j++);
		
	}	

}

void EXTI0_IRQHandler(void){
	  MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_HIGH);
		
	  for(u32 r=0;r<2000;r++);
	  MCAL_GPIO_GetPinValue(GPIO_PORTA,GPIO_PIN0,&value);
	  MCAL_GPIO_GetPinValue(GPIO_PORTA,GPIO_PIN4,&value1);
	  MCAL_GPIO_GetPinValue(GPIO_PORTA,GPIO_PIN3,&value2);
		if(value == GPIO_LOW)
	    { MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_HIGH);
				if(value1 == GPIO_HIGH)
				{  HAL_LED_Off(GPIO_PORTA,GPIO_PIN4);
	         HAL_LED_Off(GPIO_PORTB,GPIO_PIN2);
					 for(u32 i=0;i<10;i++)
					{
						HAL_LED_Toggle(GPIO_PORTA,GPIO_PIN3);
						HAL_LED_Toggle(GPIO_PORTB,GPIO_PIN3);
						for(u32 v=0;v<500;v++);
					}
					 HAL_LED_Off(GPIO_PORTA,GPIO_PIN3);
	         HAL_LED_Off(GPIO_PORTB,GPIO_PIN3);
					 HAL_LED_On(GPIO_PORTA,GPIO_PIN2);
	         HAL_LED_On(GPIO_PORTB,GPIO_PIN4);
	         for(u32 H=0;H<5000;H++);
					
					 HAL_LED_Off(GPIO_PORTA,GPIO_PIN2);
	         HAL_LED_Off(GPIO_PORTB,GPIO_PIN4);
					 HAL_LED_On(GPIO_PORTA,GPIO_PIN3);
	         HAL_LED_On(GPIO_PORTB,GPIO_PIN3);
					 for(u32 s=0;s<5000;s++);
					
					 HAL_LED_Off(GPIO_PORTA,GPIO_PIN3);
	         HAL_LED_Off(GPIO_PORTB,GPIO_PIN3);
				   HAL_LED_On(GPIO_PORTA,GPIO_PIN4);
	         HAL_LED_On(GPIO_PORTB,GPIO_PIN2);
					 for(u32 g=0;g<5000;g++);
				}
				   
				else if(value2 == GPIO_HIGH)
				{ for(u32 M=0;M<10;M++)
					{
						HAL_LED_Toggle(GPIO_PORTA,GPIO_PIN3);
						HAL_LED_Toggle(GPIO_PORTB,GPIO_PIN3);
						for(u32 b=0;b<500;b++);
					}
					 HAL_LED_Off(GPIO_PORTA,GPIO_PIN3);
	         HAL_LED_Off(GPIO_PORTB,GPIO_PIN3);
	         HAL_LED_On(GPIO_PORTA,GPIO_PIN2);
	         HAL_LED_On(GPIO_PORTB,GPIO_PIN4);
	         for(u32 A=0;A<5000;A++);
				}
				}
		  MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);
			MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI0_IRQn);
		}	
