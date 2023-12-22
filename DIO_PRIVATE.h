/*****************************************************************************************/
/*                 AUTHOR :  REFAAT HASSAN MAHMOUD                                       */
/*                 DATA   :  8/9/2023  v1                                                */
/*                 TITLE  : DIO PRIVATE                                                  */
/*****************************************************************************************/
#ifndef   DIO_PRIVATE_H_
#define   DIO_PRIVATE_H_
#include"TYPES.h"
//DEFINE STRUCT HAS ALL DIO PORTS
typedef struct DIO{
  u8 volatile PIND;          //REGESTER TO READ  IF IT INPUT DATA FROM PORTD
  u8 volatile DDRD;          //REGESTER TO SET DIREECTION TO PORTD
  u8 volatile PORTD;         //REGESTER TO WRITE IF IT OUTPUT PIN DATA FROM PORTD
  u8 volatile PINC;          //REGESTER TO READ IF IT INPUT  DATA FROM PORTC
  u8 volatile DDRC;          //REGESTER TO SET DIREECTION TO PORTC
  u8 volatile PORTC;         //REGESTER TO WRITE IF IT OUTPUT PIN DATA FROM PORTC
  u8 volatile PINB;          //REGESTER TO READ IF IT INPUT  DATA FROM PORTB
  u8 volatile DDRB;          //REGESTER TO SET DIREECTION TO PORTB
  u8 volatile PORTB;         //REGESTER TO WRITE IF IT OUTPUT PIN DATA FROM PORTB 
  u8 volatile PINA;          //REGESTER TO READ IF IT INPUT  DATA FROM PORTA
  u8 volatile DDRA;          //REGESTER TO SET DIREECTION TO PORTA
  u8 volatile PORTA;         //REGESTER TO WRITE IF IT OUTPUT PIN DATA FROM PORTA
}DIO;

#define MDIO     ((volatile DIO *)0X30)   //DECLEAR POINTER TO STRUCT WITH TYPE PF STRUCT HAVE THE REGISTERS
#endif
