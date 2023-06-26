/**********************************************************************/
/**********************************************************************/
/*****************		Author: Mostafa Anwar   ***********************/
/*****************		Layer:	MCAL  			***********************/
/*****************		SWC:	UART          	***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
/**********************************************************************/

#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_

#define UDR_T            *((volatile u8 *)0x2C)
#define UDR_R            *((volatile u8 *)0x2C)
#define UCSRA            *((volatile u8 *)0x2B)
#define UCSRB            *((volatile u8 *)0x2A)
#define UCSRC            *((volatile u8 *)0x40)
#define UBRRL            *((volatile u8 *)0x29)
#define UBRRH            *((volatile u8 *)0x40)

#endif /* UART_REGISTER_H_ */
