/****************************************************************/
/******* Author    : Yara Ayman                 *****************/
/******* Date      : 26 Aug 2023                *****************/
/****************************************************************/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(REG, BIT_NUMBER)  REG |= (1 << BIT_NUMBER)


#define CLR_BIT(REG, BIT_NUMBER)  REG &= ~(1 << BIT_NUMBER)


#define TOG_BIT(REG, BIT_NUMBER)  REG ^= (1 << BIT_NUMBER)


#define GET_BIT(REG, BIT_NUMBER)  ((REG & (1 << BIT_NUMBER)) >> BIT_NUMBER)


#endif 