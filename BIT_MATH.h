/*****************************************************************************************/
/*                 AUTHOR :  REFAAT HASSAN MAHMOUD                                       */
/*                 DATA   :  3/9/2023 v2                                                   */
/*                 TITLE  :  OPERATION LIBRARY                                  */
/*****************************************************************************************/
#ifndef   BIT_MATH_H_
#define   BIT_MATH_H_
//to set bit
#define  SET_BIT(reg,bit)     (reg|=(1<<bit))
//to clear bit
#define  CLR_BIT(reg,bit)     (reg&=(~(1<<bit)))
//to get value from  bit
#define  GET_BIT(reg,bit)     (1&(reg>>bit))
//to toggle
#define  TOG_BIT(reg,bit)     (reg^=(1<<bit))
//SET PORT
#define  WRITE_REG(reg,val)     (reg=val)
#endif
