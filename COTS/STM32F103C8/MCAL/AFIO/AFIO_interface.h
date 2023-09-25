/****************************************************************/
/******* Author    : Yara Ayman                 *****************/
/******* Date      : 12 Sep 2023                *****************/
/****************************************************************/
#ifndef AFIO_INTERFACE_H_
#define AFIO_INTERFACE_H_



#define AFIO_PORTA          0
#define AFIO_PORTB          1
#define AFIO_PORTC          2


typedef enum 
{
    AFIO_REMAP_NONE,     
    AFIO_REMAP_FULL,     
    AFIO_REMAP_PARTIAL,  
    AFIO_REMAP_CUSTOM,   
} AFIO_RemapConfig_t;


Std_ReturnType MCAL_AFIO_EnablePeripheral(u32 Copy_PeripheralId, u32 Copy_BusId);


Std_ReturnType MCAL_AFIO_SetEXTIConfiguration(u8 Copy_Line, u8 Copy_PortMap);


Std_ReturnType MCAL_AFIO_SetRemap(u32 Copy_RemapConfig);


Std_ReturnType MCAL_AFIO_SetDebugPort(u32 Copy_DebugConfig);


Std_ReturnType MCAL_AFIO_SetMAPR2(u32 Copy_MAPR2Config);





#endif 
