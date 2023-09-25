/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 12 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : NVIC_program.c             *****************/
/****************************************************************/

/*****************************< LIB *****************************/
#include "C:\Users\H&M\Desktop\IEEE_Embedded_Workshop\COTS\STM32F103C8\LIB\STD_TYPES.h"
#include <stdbool.h>
#include "C:\Users\H&M\Desktop\IEEE_Embedded_Workshop\COTS\STM32F103C8\LIB\BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"
/*****************************< Function Implementations *****************************/

/**<  Function to configure SWJ (Serial Wire JTAG) configuration */
Std_ReturnType MCAL_AFIO_SetRemap(u32 Copy_RemapConfig)
{
    /**< Check if the remapConfig is within valid range */ 
    if (Copy_RemapConfig > AFIO_REMAP_CUSTOM)
    {
        return E_NOT_OK;  /**< Invalid configuration */ 
    }

    // Configure the remap settings
    AFIO->MAPR &= ~AFIO_MAPR_SWJ_CFG_Msk;  /**< Clear SWJ_CFG bits */ 

    switch (Copy_RemapConfig) 
    {
        case AFIO_REMAP_NONE:
            /**< No remap, SWJ ON without trace (default) */ 
            break;
        case AFIO_REMAP_FULL:
            /**< Full SWJ (JTAG-DP + SW-DP) but without NJTRST */ 
            AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_001;
            break;
        case AFIO_REMAP_PARTIAL:
            /**< JTAG-DP Disabled and SW-DP Enabled */ 
            AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_010;
            break;
        case AFIO_REMAP_CUSTOM:
            /**< Custom remap (user-defined) */ 
            break;
        default:
            return E_NOT_OK;  /**< Invalid configuration */ 
    }

    return E_OK;  /**<  Configuration successful */
}

/**< Function to configure ADC2_ETRGREG remapping */ 
void AFIO_MAPR_ADC2ETRGREGRemap(bool Copy_Enable) 
{
    u32 regValue = AFIO->MAPR;
    if (Copy_Enable) 
    {
        regValue |= AFIO_MAPR_ADC2_ETRGREG_Msk;
    } 
    else 
    {
        regValue &= ~AFIO_MAPR_ADC2_ETRGREG_Msk;
    }
    AFIO->MAPR = regValue;
}

/**< Function to configure ADC2_ETRGINJ remapping */ 
void AFIO_MAPR_ADC2ETRGINJRemap(bool Copy_Enable) 
{
    u32 regValue = AFIO->MAPR;
    if (Copy_Enable)
    {
        regValue |= AFIO_MAPR_ADC2_ETRGINJ_Msk;
    }
    else 
    {
        regValue &= ~AFIO_MAPR_ADC2_ETRGINJ_Msk;
    }
    AFIO->MAPR = regValue;
}




Std_ReturnType MCAL_AFIO_SetEXTIConfiguration(u8 Copy_Line, u8 Copy_PortMap)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if(Copy_Line > 15 || Copy_PortMap > 2)
    {
        return Local_FunctionStatus;
    }

    u8 Local_RegIdex = Copy_Line / 4; 
    Copy_Line %= 4;

    AFIO->EXTICR[Local_RegIdex] &= ~((0b1111) << (Copy_Line * 4));
    AFIO->EXTICR[Local_RegIdex] |= Copy_PortMap << (Copy_Line * 4);
		AFIO->EVCR = 0x0;

    return Local_FunctionStatus;
}


















/*****************************< End of Function Implementations *****************************/
