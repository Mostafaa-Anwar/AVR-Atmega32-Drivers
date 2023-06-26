
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#define F_CPU   8000000UL
#include <util/delay.h>

#include "DIO_interface.h"

#include "STEPPER_interface.h"

int main(void)
{
	u8 Local_u8Counter ;
	/* Stepper Motor Init */
	STEPPER_voidInit();
	while (1)
	{
		/* Rotate clock wise for 5 seconds */
		for (Local_u8Counter=0;Local_u8Counter<250;Local_u8Counter++)
		{
			STEPPER_voidRotateCW();
		}

		/* Rotate anti clock wise for 5 seconds */
		for (Local_u8Counter=0;Local_u8Counter<250;Local_u8Counter++)
		{
			STEPPER_voidRotateACW();
		}


	}

	return 0;
}
