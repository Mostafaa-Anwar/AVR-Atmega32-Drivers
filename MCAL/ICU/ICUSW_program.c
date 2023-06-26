/**********************************************************************/
/**********************************************************************/
/*****************		Author: Mostafa Anwar   ***********************/
/*****************		Layer:	MCAL  			***********************/
/*****************		SWC:	ICU          	***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
/**********************************************************************/

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "EXTINT_interface.h"
#include "TIMER_interface.h"

#include "ICUSW_interface.h"
#include "ICUSW_private.h"
#include "ICUSW_config.h"

volatile static u16 ICUSW_u16OnPeriod,ICUSW_u16OffPeriod;

void ICUSW_voidEnableSWICU(void)
{
	EXTINT_voidSetCallBack(&EXT_INTCallBackfunction,EXTINT_INT0);
#if(ICUSW_TRIG_SOURCE_INIT == ICUSW_EDGE_SOURCE_RAISING_EDGE)
	EXTINT_voidEnable(EXTINT_INT0,EXTINT_RAISING_EDGE);
#elif(ICUSW_TRIG_SOURCE_INIT == ICUSW_EDGE_SOURCE_FALLING_EDGE)
	EXTINT_voidEnable(EXTINT_INT0,EXTINT_FALLING_EDGE);

#endif
}
void ICUSW_voidDisableSWICU(void)
{
	EXTINT_voidDisable(EXTINT_INT0);
}
u8   ICUSW_u8GetOnPeriod(u16 * Copy_pu16OnPeriod)
{
	u8 Local_u8ReturnState = 1;

		*Copy_pu16OnPeriod = ICUSW_u16OnPeriod;


	return Local_u8ReturnState;
}
u8   ICUSW_u8GetTotalPeriod(u32 * Copy_pu32TotalPeriod)
{
	u8 Local_u8ReturnState = 1;
//	if(Copy_pu32TotalPeriod != NULL)
	{
		*Copy_pu32TotalPeriod = (u32)(ICUSW_u16OnPeriod + ICUSW_u16OffPeriod);
//		Local_u8ReturnState = STD_TYPES_u8_ERROR_OK;
	}
	return Local_u8ReturnState;

}
u8   ICUSW_u8GetDutyCycle(u8 * Copy_pu8DutyCycle)
{
	u8 Local_u8ReturnState = 1;
//	if(Copy_pu8DutyCycle != NULL)
	{
		*Copy_pu8DutyCycle = (u8)(((u32)ICUSW_u16OnPeriod * 100) / (ICUSW_u16OnPeriod + ICUSW_u16OffPeriod));
//		Local_u8ReturnState = STD_TYPES_u8_ERROR_OK;
	}
	return Local_u8ReturnState;

}
static void EXT_INTCallBackfunction(void)
{
	static u16 Local_u16CounterValue = 0;
	static u16 Local_u16OldValue     = 0;
	static u8  Local_u8Flag          = ICUSW_TRIG_SOURCE_INIT;
	Timer_voidGetTimer1CounterValue(&Local_u16CounterValue);
	if(Local_u8Flag == ICUSW_EDGE_SOURCE_RAISING_EDGE)/* Raising Edge */
	{
		/* Measure Off Period */
		ICUSW_u16OffPeriod = Local_u16CounterValue - Local_u16OldValue;
		/* Trig source int Falling edge */
		EXTINT_voidEnable(EXTINT_INT0,EXTINT_FALLING_EDGE);

		Local_u8Flag = ICUSW_EDGE_SOURCE_FALLING_EDGE;

	}
	else if(Local_u8Flag == ICUSW_EDGE_SOURCE_FALLING_EDGE)
	{
		/* Measure On Period */
		ICUSW_u16OnPeriod = Local_u16CounterValue - Local_u16OldValue;
		/* Trig source int Raising edge */
		EXTINT_voidEnable(EXTINT_INT0,EXTINT_RAISING_EDGE);

		Local_u8Flag = ICUSW_EDGE_SOURCE_RAISING_EDGE;

	}
	Local_u16OldValue = Local_u16CounterValue;
}
