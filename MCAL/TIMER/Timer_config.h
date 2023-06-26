/**********************************************************************/
/**********************************************************************/
/*****************		Author: Mostafa Anwar   ***********************/
/*****************		Layer:	MCAL  			***********************/
/*****************		SWC:	TIMER          	***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
/**********************************************************************/


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

#define TIMER0_u8_PRELOAD_VALUE             64
#define TIMER0_u32_NUMBER_OF_OVF            3907
#define TIMER_u8_OCR0_INIT_VALUE            127
#define TIMER1_u16_ICR1_VALUE               19999



/* Config for Timer Driver */

/* Timers Enable options
 * options : TIMER_u8_INIT_STATE_ENABLE
             TIMER_u8_INIT_STATE_DISABLE         */

#define TIMER0_INIT_STATE              TIMER_u8_INIT_STATE_DISABLE
#define TIMER1_INIT_STATE              TIMER_u8_INIT_STATE_ENABLE



/* Timer 0 Mode Config */
/* Options = TIMER0_NORMAL_MODE
             TIMER0_PHASE_CORRECT_PWM
             TIMER0_CTC_MODE
             TIMER0_FAST_PWM          */

#define TIMER0_MODE              TIMER0_NORMAL_MODE

/* Timer 1 Mode Config */
/* Options = TIMER1_NORMAL_MODE
			 TIMER1_FAST_PWM_ICR1_TOP */
#define TIMER1_MODE             TIMER1_FAST_PWM_ICR1_TOP

/* Timer 0 Interrupt Enable */
/* options = TIMER_INTERRUPT_ENABLE
             TIMER_INTERRUPT_DISABLE */
#define TIMER0_OVF_INTERRUPT_INIT    TIMER_INTERRUPT_ENABLE
#define TIMER0_CTC_INTERRUPT_INIT    TIMER_INTERRUPT_DISABLE

/* Timer 1 Interrupt Enable */
/* options = TIMER_INTERRUPT_ENABLE
             TIMER_INTERRUPT_DISABLE */
#define TIMER1_OVF_INTERRUPT_INIT              TIMER_INTERRUPT_DISABLE
#define TIMER1_CTC_CHANNEL_A_INTERRUPT_INIT    TIMER_INTERRUPT_DISABLE
#define TIMER1_CTC_CHANNEL_B_INTERRUPT_INIT    TIMER_INTERRUPT_DISABLE

/* Timer  Prescaler values */
/* options = TIMER_CLOCK_NO_CLOCK
             TIMER_CLOCK_NO_PRESCHALER
             TIMER_CLOCK_8_PRESCHALER
             TIMER_CLOCK_64_PRESCHALER
             TIMER_CLOCK_256_PRESCHALER
             TIMER_CLOCK_1024_PRESCHALER
             TIMER_CLOCK_EXTERNAL_FALLING_EDGE
             TIMER_CLOCK_EXTERNAL_RISING_EDGE	 */
#define TIMER0_CLOCK_SOURCE          TIMER_CLOCK_8_PRESCHALER
#define TIMER1_CLOCK_SOURCE          TIMER_CLOCK_8_PRESCHALER

/* OCX pin Config Macros */
/* Options :TIMER_u8_OCX_DISCONNECTED
            TIMER_u8_OCX_TOGGELE
            TIMER_u8_OCX_SET
            TIMER_u8_OCX_CLEAR        */
#define TIMER_u8_OC0_PIN_MODE        TIMER_u8_OCX_CLEAR
#define TIMER_u8_OC1A_PIN_MODE       TIMER_u8_OCX_CLEAR
#define TIMER_u8_OC1B_PIN_MODE       TIMER_u8_OCX_CLEAR



#define TIMER_u8_ICP_INIT_STATE      TIMER_u8_ICP_RAISING_EDGE
 #endif /* TIMER_CONFIG_H_ */
