/*
 * ADC_Prv.h
 *
 *  Created on: Sep 2, 2022
 *      Author: OmarNagdy
 */
#ifndef ADC_PRV_H_
#define ADC_PRV_H_

//ADC Reg.
#define ADMUX    *((volatile u8* )(0x27))
#define ADCSRA	 *((volatile u8* )(0x26))
#define ADCL	 *((volatile u8* )(0x24))
#define ADCH	 *((volatile u8* )(0x25))
#define SFIOR	 *((volatile u8* )(0x50))


//Reg ADMUX
#define REFS1	7
#define REFS0	6
#define ADLAR 	5



//Reg. ADCSRA
#define ADEN	7
#define ADATE	5
#define ADIE	3
#define ADSC	6
#define ADIF	4



/*Reg. data of ADC(I used bit manipulation) and there is another
way by casting the ADCL reg. address into a u16 ptr and dereferencing it
bec. our memory is a little endian*/
#define ADC		((u16)ADCL+(ADCH<<8))




//ADC Presc. Possible values :
#define ADC_PS_4	0b010
/**
 * and so on
 */





//ADC Ref. Volt. Possible values :
#define AVCC	1
/**
 * and so on
 */


//ADC working interr. based or polling
#define ENABLE	1
#define DISABLE 0



#endif /* ADC_PRV_H_ */
