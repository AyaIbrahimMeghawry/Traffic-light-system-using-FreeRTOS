#include "TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "Sevev_Seg_Interface.h"
#include "Sevev_Seg_Config.h"

void Sev_Seg_Intialize(void)
{
	// pins of seven segment on the kit
	MDIO_voidSetPinDirect(DIO_PORTC, PIN0, PIN_OUTPUT);
	MDIO_voidSetPinDirect(DIO_PORTC, PIN1, PIN_OUTPUT);
	MDIO_voidSetPinDirect(DIO_PORTC, PIN2, PIN_OUTPUT);
	MDIO_voidSetPinDirect(DIO_PORTC, PIN3, PIN_OUTPUT);
	MDIO_voidSetPinDirect(DIO_PORTC, PIN4, PIN_OUTPUT);
	MDIO_voidSetPinDirect(DIO_PORTC, PIN5, PIN_OUTPUT);
	MDIO_voidSetPinDirect(DIO_PORTC, PIN6, PIN_OUTPUT);
	MDIO_voidSetPinDirect(DIO_PORTC, PIN7, PIN_OUTPUT);

}
void Sev_Seg_Enable(void)
{

}
void Sev_Seg_Disable(void){

}
void Sev_Seg1_WriteNumber(u8 Number)
{
	if (Number<10)
	{
		MDIO_voidSetPinValue(DIO_PORTC ,PIN0 ,GET_BIT(Number,0));
		MDIO_voidSetPinValue(DIO_PORTC ,PIN1 ,GET_BIT(Number,1));
		MDIO_voidSetPinValue(DIO_PORTC ,PIN2 ,GET_BIT(Number,2));
		MDIO_voidSetPinValue(DIO_PORTC ,PIN3 ,GET_BIT(Number,3));
	}

}
void Sev_Seg2_WriteNumber(u8 Number)
{
	if (Number<10)
	{
		MDIO_voidSetPinValue(DIO_PORTC ,PIN4 ,GET_BIT(Number,0));
		MDIO_voidSetPinValue(DIO_PORTC ,PIN5 ,GET_BIT(Number,1));
		MDIO_voidSetPinValue(DIO_PORTC ,PIN6 ,GET_BIT(Number,2));
		MDIO_voidSetPinValue(DIO_PORTC ,PIN7 ,GET_BIT(Number,3));
	}

}
