/****************************************************************/
/******* Author    : Yara Ayman                 *****************/
/******* Date      : 9 Sep 2023                 *****************/
/****************************************************************/
#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_


EXTI_Configuration_t EXTI_Configurations[EXTI_LINES_COUNT] = {

    
    {
        .LineEnabled   = EXTI_LINE_ENABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },

    
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_FALLING_EDGE,
    },

    
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    
    {
        .LineEnabled   = EXTI_LINE_ENABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    
    {
        .LineEnabled   = EXTI_LINE_ENABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
    
    {
        .LineEnabled   = EXTI_LINE_ENABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
    },
    
};

#endif 