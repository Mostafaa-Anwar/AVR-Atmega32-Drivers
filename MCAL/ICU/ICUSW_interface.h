/**********************************************************************/
/**********************************************************************/
/*****************		Author: Mostafa Anwar   ***********************/
/*****************		Layer:	MCAL  			***********************/
/*****************		SWC:	ICU          	***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
/**********************************************************************/

#ifndef ICUSW_INTERFACE_H_
#define ICUSW_INTERFACE_H_

void ICUSW_voidEnableSWICU(void);
void ICUSW_voidDisableSWICU(void);
u8   ICUSW_u8GetOnPeriod(u16 * Copy_pu16OnPeriod);
u8   ICUSW_u8GetTotalPeriod(u32 * Copy_pu32TotalPeriod);
u8   ICUSW_u8GetDutyCycle(u8 * Copy_pu8DutyCycle);

#endif /* ICUSW_INTERFACE_H_ */
