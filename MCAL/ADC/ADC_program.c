/**********************************************************************/
/**********************************************************************/
/*****************		Author: Mostafa Anwar   ***********************/
/*****************		Layer:	MCAL  			***********************/
/*****************		SWC:	ADC          	***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
/**********************************************************************/



#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "ADC_interface.h"
#include "ADC_register.h"

void ADC_voidInit(void)
{

	/* Select the Voltage reference AVCC */
	CLR_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);

	/* Select the right Adjustment */
	CLR_BIT(ADMUX,ADMUX_ADLAR);
	/* Select The Prescaler value => 64 */
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);

	/* Enable ADC peripheral */
	SET_BIT(ADCSRA,ADCSRA_ADEN);

}

u16  ADC_u16GetDigitalValue (u8 Copy_u8ChannelNb)
{
	/* Clear The Channel Number bits */
		ADMUX &= (ADMUX_CHANNEL_NUM_MASK);
		/* Select The Channel Number */
		ADMUX |= Copy_u8ChannelNb;

		/* Start Conversion */
		SET_BIT(ADCSRA,ADCSRA_ADSC);

		/* Polling on the flag */
		while(GET_BIT(ADCSRA,ADCSRA_ADIF) == 0);

		/* Clear Flag */
		SET_BIT(ADCSRA,ADCSRA_ADIF);

		/* Read the ADC value */
		return ADC;
}
