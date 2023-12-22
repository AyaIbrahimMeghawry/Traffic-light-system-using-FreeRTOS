/*****************************************************************************************/
/*                 AUTHOR :  REFAAT HASSAN MAHMOUD                                       */
/*                 DATA   :  8/9/2023  v1                                                */
/*                 TITLE  : DIO IMPLMENTATION                                            */
/*****************************************************************************************/
#include"BIT_MATH.h"
#include"TYPES.h"
#include"DIO_INTERFACE.h"
#include"DIO_CONFIG.h"
#include"DIO_PRIVATE.h"



//function TO Set DIRECTION OF pin take port name such as PORTA and pin number such as PIN0  and direction such as BIN_INPUT 
void  MDIO_voidSetPinDirect(u8  u8copy_port_id,u8  u8copy_pin_id,u8  u8copy_pin_direct)
{
	switch(u8copy_port_id)   //check port name
	{
		case  DIO_PORTA:         //in case it is porta
		    switch(u8copy_pin_direct)      //check direction 
			{
				case PIN_INPUT:           //in case input 
				     CLR_BIT(MDIO->DDRA,u8copy_pin_id);        //clear bit in  DDRA RESGISTER THAT REPRESENT THIS PIN
					 break;
				case PIN_OUTPUT:          //IN CASE OUTPUT
				     SET_BIT(MDIO->DDRA,u8copy_pin_id);       //SET  bit in  DDRA RESGISTER THAT REPRESENT THIS PIN
					 break;
			}
			break;
		case  DIO_PORTB:                       //in case it is portb
		    switch(u8copy_pin_direct)     //check direction 
			{
				case PIN_INPUT:           //in case input 
				     CLR_BIT(MDIO->DDRB,u8copy_pin_id);             //clear bit in  DDRB RESGISTER THAT REPRESENT THIS PIN
					 break;
				case PIN_OUTPUT:         //IN CASE OUTPUT
				     SET_BIT(MDIO->DDRB,u8copy_pin_id);            //SET  bit in  DDRB RESGISTER THAT REPRESENT THIS PIN
					 break;
			}
			break; 
		case  DIO_PORTC:                        //in case it is portc
		    switch(u8copy_pin_direct)      //check direction 
			{
				case PIN_INPUT:            //in case input 
				     CLR_BIT(MDIO->DDRC,u8copy_pin_id);                   //clear bit in  DDRC RESGISTER THAT REPRESENT THIS PIN
					 break;
				case PIN_OUTPUT:           //IN CASE OUTPUT  
				     SET_BIT(MDIO->DDRC,u8copy_pin_id);                   //SET  bit in  DDRC RESGISTER THAT REPRESENT THIS PIN
					 break;
			}
			break; 
		case  DIO_PORTD:                       //in case it is portd
		    switch(u8copy_pin_direct)     //check direction 
			{
				case PIN_INPUT:            //in case input 
				     CLR_BIT(MDIO->DDRD,u8copy_pin_id);                      //clear bit in  DDRD RESGISTER THAT REPRESENT THIS PIN
					 break;
				case PIN_OUTPUT:           //IN CASE OUTPUT
				     SET_BIT(MDIO->DDRD,u8copy_pin_id);                      //SET  bit in  DDRD RESGISTER THAT REPRESENT THIS PIN
					 break;
			}
			break;
	}
}


//function to set value to pin take port name such as PORTA and pin number such as PIN0  and direction such as BIN_INPUT
void  MDIO_voidSetPinValue(u8  u8copy_port_id,u8  u8copy_pin_id,u8  u8copy_pin_value)
{
	
	switch(u8copy_port_id)       //check port name
	{
		case DIO_PORTA:              //IN CASE PORT A
		    switch(u8copy_pin_value)      //CHECK VALUE OF BIT 
			{
				case PIN_LOW:             //IN CASE LOW 
				     CLR_BIT(MDIO->PORTA,u8copy_pin_id);       //clear bit in  PORT A RESGISTER THAT REPRESENT THIS PIN
					 break;
				case PIN_HIGH:           //IN CASE HIGH
				     SET_BIT(MDIO->PORTA,u8copy_pin_id);     //SET  bit in  PORTA RESGISTER THAT REPRESENT THIS PIN
					 break;
			}
			break;
		case DIO_PORTB:                       //IN CASE PORT B
		    switch(u8copy_pin_value)    //CHECK VALUE OF BIT
			{
				case PIN_LOW:            //IN CASE LOW
				     CLR_BIT(MDIO->PORTB,u8copy_pin_id);    //clear bit in  PORT B RESGISTER THAT REPRESENT THIS PIN
					 break;
				case PIN_HIGH:           //IN CASE HIGH
				     SET_BIT(MDIO->PORTB,u8copy_pin_id);    //SET  bit in  PORTB RESGISTER THAT REPRESENT THIS PIN
					 break;
			}
			break;
		case DIO_PORTC:                       //IN CASE PORT C
		    switch(u8copy_pin_value)     //CHECK VALUE OF BIT
			{
				case PIN_LOW:             //IN CASE LOW
				     CLR_BIT(MDIO->PORTC,u8copy_pin_id);    //clear bit in  PORT C RESGISTER THAT REPRESENT THIS PIN
					 break;
				case PIN_HIGH:            //IN CASE HIGH
				     SET_BIT(MDIO->PORTC,u8copy_pin_id);    //SET  bit in  PORTC RESGISTER THAT REPRESENT THIS PIN
					 break;
			}
			break;
		case DIO_PORTD:                        //IN CASE PORT D
		    switch(u8copy_pin_value)      //CHECK VALUE OF BIT
			{
				case PIN_LOW:              //IN CASE LOW
				     CLR_BIT(MDIO->PORTD,u8copy_pin_id);       //clear bit in  PORT D RESGISTER THAT REPRESENT THIS PIN
					 break;
				case PIN_HIGH:             //IN CASE HIGH
				     SET_BIT(MDIO->PORTD,u8copy_pin_id);     //SET  bit in  PORTD RESGISTER THAT REPRESENT THIS PIN
					 break;
			}
			break;
	}
}

//function  to get value from pin take port name such as PORTA and pin number such as PIN0 
u8  MDIO_u8GetPinValue(u8  u8copy_port_id,u8  u8copy_pin_id)
{   u8  u8copy_pin_value=0;
	switch(u8copy_port_id)        //check port name
	{
		case DIO_PORTA:   // IN CASE PORT A
		    u8copy_pin_value=GET_BIT( MDIO->PINA,u8copy_pin_id);   // READ VALUE FROM  REGISTER PIN A THAT REPRESENT THIS VALUE
			break;
		case DIO_PORTB:    // IN CASE PORT B
		    u8copy_pin_value=GET_BIT( MDIO->PINB,u8copy_pin_id);   // READ VALUE FROM  REGISTER PIN B THAT REPRESENT THIS VALUE
			break;
		case DIO_PORTC:    // IN CASE PORT C
		    u8copy_pin_value=GET_BIT( MDIO->PINC,u8copy_pin_id);  // READ VALUE FROM  REGISTER PIN C THAT REPRESENT THIS VALUE
			break;
		case DIO_PORTD:   // IN CASE PORT D
		    u8copy_pin_value=GET_BIT( MDIO->PIND,u8copy_pin_id);  // READ VALUE FROM  REGISTER PIN D THAT REPRESENT THIS VALUE
			break;
	}	
	return u8copy_pin_value;
}




//function TO Set DIRECTION OF port take port name such as PORTA and direction such as 0xFF
void  MDIO_voidSetPortDirect(u8  u8copy_port_id,u8  u8copy_port_direct)
{
	switch(u8copy_port_id)        //check port name
	{
		case DIO_PORTA:   // IN CASE PORT A
		    MDIO->DDRA=u8copy_port_direct;   // WRITE VALUE IN DDRA THAT CONTROL DIRECTION OF PORT A
			break;
		case DIO_PORTB:    // IN CASE PORT B
		    MDIO->DDRB=u8copy_port_direct;   // WRITE VALUE IN DDRB THAT CONTROL DIRECTION OF PORT B
			break;
		case DIO_PORTC:    // IN CASE PORT C
		    MDIO->DDRC=u8copy_port_direct;   // WRITE VALUE IN DDRC THAT CONTROL DIRECTION OF PORT C
			break;
		case DIO_PORTD:   // IN CASE PORT D
		    MDIO->DDRD=u8copy_port_direct;   // WRITE VALUE IN DDRD THAT CONTROL DIRECTION OF PORT D
			break;
	}	
}

//function to set value to port take port name such as PORTA and direction such as 0X00
void  MDIO_voidSetPortValue(u8  u8copy_port_id,u8  u8copy_port_value)
{
	switch(u8copy_port_id)        //check port name
	{
		case DIO_PORTA:   // IN CASE PORT A
		    MDIO->PORTA=u8copy_port_value;   // WRITE VALUE IN portA THAT has value  OF PORT A
			break;
		case DIO_PORTB:    // IN CASE PORT B
		    MDIO->PORTB=u8copy_port_value;    // WRITE VALUE IN portA THAT has value  OF PORT B
			break;
		case DIO_PORTC:    // IN CASE PORT C
		    MDIO->PORTC=u8copy_port_value;    // WRITE VALUE IN portA THAT has value  OF PORT C
			break;
		case DIO_PORTD:   // IN CASE PORT D
		    MDIO->PORTD=u8copy_port_value;    // WRITE VALUE IN portA THAT has value  OF PORT D
			break;
	}	
}

//function  to get value from port take port name such as PORTA 
u8  MDIO_u8GetPortValue(u8  u8copy_port_id)
{   u8  u8copy_port_value=0;
	switch(u8copy_port_id)        //check port name
	{
		case DIO_PORTA:   // IN CASE PORT A
		    u8copy_port_value=MDIO->PINA; // READ VALUE FROM  REGISTER PIN A THAT REPRESENT THIS VALUE
			break;
		case DIO_PORTB:    // IN CASE PORT B
		    u8copy_port_value=MDIO->PINB;  // READ VALUE FROM  REGISTER PIN B THAT REPRESENT THIS VALUE
			break;
		case DIO_PORTC:    // IN CASE PORT C
		    u8copy_port_value=MDIO->PINC;  // READ VALUE FROM  REGISTER PIN C THAT REPRESENT THIS VALUE
			break;
		case DIO_PORTD:   // IN CASE PORT D
		    u8copy_port_value=MDIO->PIND; // READ VALUE FROM  REGISTER PIN D THAT REPRESENT THIS VALUE
			break;
	}	
	return u8copy_port_value;
}

//function  to toggle  pin take port name such as PORTA and pin number such as PIN0 
void  MDIO_voidTogglePinValue(u8  u8copy_port_id,u8  u8copy_pin_id)
{
	switch(u8copy_port_id)        //check port name
	{
		case DIO_PORTA:   // IN CASE PORT A
		    TOG_BIT( MDIO->PORTA,u8copy_pin_id);   // TOGGLE VALUE FROM  REGISTER PIN A THAT REPRESENT THIS VALUE
			break;
		case DIO_PORTB:    // IN CASE PORT B
		   TOG_BIT( MDIO->PORTB,u8copy_pin_id);   // TOGGLE VALUE FROM  REGISTER PIN B THAT REPRESENT THIS VALUE
			break;
		case DIO_PORTC:    // IN CASE PORT C
		    TOG_BIT( MDIO->PORTC,u8copy_pin_id);  // TOGGLE VALUE FROM  REGISTER PIN C THAT REPRESENT THIS VALUE
			break;
		case DIO_PORTD:   // IN CASE PORT D
		    TOG_BIT( MDIO->PORTD,u8copy_pin_id);  // TOGGLE VALUE FROM  REGISTER PIN D THAT REPRESENT THIS VALUE
			break;
	}	
}
