/*****************************************************************************************/
/*                 AUTHOR :  REFAAT HASSAN MAHMOUD                                       */
/*                 DATA   :  8/9/2023        v1                                          */
/*                 TITLE  : DIO INTERFACE                                                */
/*****************************************************************************************/
#include"TYPES.h"

#ifndef   DIO_INTERFACE_H_
#define   DIO_INTERFACE_H_


//PORTS ID TO USE IN SET PORT DIRECTION OR SET PORT VALUE 
#define    DIO_PORTA             (u8)(0x00)         //WRITE IT IF YOU WANT TO USE PORT A AS INPUT OR OUTPUT
#define    DIO_PORTB             (u8)(0x01)         //WRITE IT IF YOU WANT TO USE PORT B AS INPUT OR OUTPUT
#define    DIO_PORTC             (u8)(0x02)         //WRITE IT IF YOU WANT TO USE PORT C AS INPUT OR OUTPUT
#define    DIO_PORTD             (u8)(0x03)         //WRITE IT IF YOU WANT TO USE PORT D AS INPUT OR OUTPUT


//PIN ID TO SET VALUE OR READ IT 
#define    PIN0               (u8)(0x00)    		// USE IT IF YOU WANT TO USE PIN 0
#define    PIN1               (u8)(0x01)    		// USE IT IF YOU WANT TO USE PIN 1
#define    PIN2               (u8)(0x02)			// USE IT IF YOU WANT TO USE PIN 2
#define    PIN3               (u8)(0x03)            // USE IT IF YOU WANT TO USE PIN 3
#define    PIN4               (u8)(0x04)            // USE IT IF YOU WANT TO USE PIN 4
#define    PIN5               (u8)(0x05)            // USE IT IF YOU WANT TO USE PIN 5
#define    PIN6               (u8)(0x06)            // USE IT IF YOU WANT TO USE PIN 6
#define    PIN7               (u8)(0x07)            // USE IT IF YOU WANT TO USE PIN 7


//ID TO WRITE HIGH OR LOW  IN PIN 
#define    PIN_LOW            (u8)(0x00)    // IT WILL OUT LOW IN PIN 
#define    PIN_HIGH           (u8)(0x01)    // IT WILL OUT HIGH IN PIN 


//ID TO WRITE DIRECTION OF BIT 
#define    PIN_INPUT            (u8)(0x00)   //SET PIN AS INPUT
#define    PIN_OUTPUT           (u8)(0x01)   //SET PIN AS OUTPUT

//function TO Set DIRECTION OF pin take port name such as PORTA and pin number such as PIN0  and direction such as BIN_INPUT 
void  MDIO_voidSetPinDirect(u8  u8copy_port_id,u8  u8copy_pin_id,u8 u8copy_pin_direct);

//function to set value to pin take port name such as PORTA and pin number such as PIN0  and direction such as BIN_INPUT
void  MDIO_voidSetPinValue(u8  u8copy_port_id,u8  u8copy_pin_id,u8  u8copy_pin_value);

//function  to get value from pin take port name such as PORTA and pin number such as PIN0 
u8  MDIO_u8GetPinValue(u8  u8copy_port_id,u8  u8copy_pin_id);


//function TO Set DIRECTION OF port take port name such as PORTA and direction such as 0xFF
void  MDIO_voidSetPortDirect(u8  u8copy_port_id,u8  u8copy_port_direct);

//function to set value to port take port name such as PORTA and direction such as 0X00
void  MDIO_voidSetPortValue(u8  u8copy_port_id,u8  u8copy_port_value);

//function  to get value from port take port name such as PORTA 
u8  MDIO_u8GetPortValue(u8  u8copy_port_id);

void  MDIO_voidTogglePinValue(u8  u8copy_port_id,u8  u8copy_pin_id);

#endif
