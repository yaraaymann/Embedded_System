/****************************************************************/
/******* Author    : Yara Ayman                 *****************/
/******* Date      : 12 Sep 2023                *****************/
/****************************************************************/

#include "STD_TYPES.h"
#include <stdbool.h>
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"



Std_ReturnType MCAL_AFIO_SetRemap(u32 Copy_RemapConfig)
{
     
    if (Copy_RemapConfig > AFIO_REMAP_CUSTOM)
    {
        return E_NOT_OK;  
    }

    
    AFIO->MAPR &= ~AFIO_MAPR_SWJ_CFG_Msk;  

    switch (Copy_RemapConfig) 
    {
        case AFIO_REMAP_NONE:
             
            break;
        case AFIO_REMAP_FULL:
            
            AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_001;
            break;
        case AFIO_REMAP_PARTIAL:
             
            AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_010;
            break;
        case AFIO_REMAP_CUSTOM:
           
            break;
        default:
            return E_NOT_OK;  
    }

    return E_OK;  
}


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

