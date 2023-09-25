/****************************************************************/
/******* Author    : Yara Ayman                 *****************/
/******* Date      : 7 Sep 2023                 *****************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SCB_interface.h"
#include "SCB_private.h"
#include "SCB_config.h"

void SCB_SetPriorityGrouping(u32 Copy_PriorityGrouping)
{
    SCB_AIRCR = Copy_PriorityGrouping;
}

void DisableGlobalInterrupts(void) 
{
    __asm volatile ("cpsid i");
}

void EnableGlobalInterrupts(void) 
{
    __asm volatile ("cpsie i");
}

void SCB_EnableMemFault(void)
{
    SCB_SHCSR |= (1 << SCB_SHCSR_MEMFAULTENA_POS);
}

void SCB_EnableBusFault(void)
{
    SCB_SHCSR |= (1 << SCB_SHCSR_BUSFAULTENA_POS);
}

void SCB_EnableUsageFault(void)
{
    SCB_SHCSR |= (1 << SCB_SHCSR_USGFAULTENA_POS);
}

void SCB_ClearMemFault(void)
{
    SCB_SHCSR &= ~(1 << SCB_SHCSR_MEMFAULTENA_POS);
}

void SCB_ClearBusFault(void)
{
    SCB_SHCSR &= ~(1 << SCB_SHCSR_BUSFAULTENA_POS);
}

void SCB_ClearUsageFault(void)
{
    SCB_SHCSR &= ~(1 << SCB_SHCSR_USGFAULTENA_POS);
}

