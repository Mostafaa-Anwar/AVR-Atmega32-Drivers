/**********************************************************************/
/**********************************************************************/
/*****************		Author: Mostafa Anwar   ***********************/
/*****************		Layer:	RTOS  			***********************/
/*****************		SWC:	RTOS            ***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
/**********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_interface.h"
#include "DIO_interface.h"
#include "RTOS_interface.h"

void LED1(void);
void LED2(void);
void LED3(void);


void main(void)
{
	PORT_voidInit();

	RTOS_voidCreateTask(0,1000,&LED1);
	RTOS_voidCreateTask(1,2000,&LED2);
	RTOS_voidCreateTask(2,3000,&LED3);

	RTOS_voidStart();
	while(1)
	{

	}
}

void LED1(void)
{
	static u8 Local_u8LedState=0;
	TOGGLE_BIT(Local_u8LedState,0);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,Local_u8LedState);
}
void LED2(void)
{
	static u8 Local_u8LedState=0;
	TOGGLE_BIT(Local_u8LedState,0);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,Local_u8LedState);
}
void LED3(void)
{
	static u8 Local_u8LedState=0;
	TOGGLE_BIT(Local_u8LedState,0);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,Local_u8LedState);
}
