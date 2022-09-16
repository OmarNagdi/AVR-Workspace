/*
 * ADC_porgram.c
 *
 *  Created on: Aug 12, 2022
 *      Author: OmarNagdy
 */



#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include"ADC_Interface.h"
#include"ADC_Prv.h"
#include "ADC_Cfg.h"

void MADC_voidInit(void)
{
	//We will configure here options that don't change during run time


	// 1-Ref. Volt.
#if ADC_REF_VOLT== AVCC
	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);
	//put other possible values here
#endif
	// 2-Data Adjustment Direction
	CLR_BIT(ADMUX,ADLAR);

	// 3-ADC peripheral Enable
	SET_BIT(ADCSRA,ADEN);

	// 4-Auto Trigger Enable
	CLR_BIT(ADCSRA,ADATE);

	// 4-a Select Trigger Source

	// 5-Interrupt Enable
#if ADC_INTERRUPT_ENABLE==DISABLE
	CLR_BIT(ADCSRA,ADIE);
#elif ADC_INTERRUPT_ENABLE==ENABLE
	SET_BIT(ADCSRA,ADIE);
#endif
	// 6- ADC Prescaler
	//Using bit masking instead of using set & clr operations normally
	/*First, we clear three bits of the prescaler without changing the rest of the register and
	 then we force the required mask which is the required value of the prescaler again without
	 changing the rest of the register*/
#if ADC_PRESCALER == ADC_PS_4

	ADCSRA= ( ADCSRA & 0xF8 ) |  (ADC_PRESCALER) ;
//put other possible values here
#endif





}

//func. giving us the int value for the no. of steps
u16 MADC_u16AnalogRead(u8 A_u8ChannelNo)
{
	// 1-Input Validation(can be done by bit masking also)
	if(A_u8ChannelNo<32)
	{
		// 2- Select Channel
		ADMUX= (ADMUX &0xE0) | A_u8ChannelNo;

		// 3-Start Conversion
		SET_BIT(ADCSRA,ADSC);

		// 4-Poll On flag(interrupt disabled)
		while(GET_BIT(ADCSRA,ADIF)   !=1  )
		; // = {}
		// 5-Clear flag by writing 1 to it in case of polling
		SET_BIT(ADCSRA,ADIF);
		// 6-Read ADC Data
		return ADC;

	}


}
