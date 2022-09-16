/*
 * main.c
 *
 *  Created on: Aug 12, 2022
 *      Author: OmarNagdy
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_Interface.h"
#include "DIO_Interface.h"
#include "LED_Interface.h"
#include "LCD_Interface.h"


#include "util/delay.h"


//Project Show ADC no of steps on LEDS as if it is a battery charge status
int main (void)
{
	//We have a 10 bit ADC of a value  ranging from  0 to 1023 that will be displayed on 8 LEDS
	//thus, every 1024/8=128 step we will operate a LED


	// Control Pins for LCD
		MDIO_voidSetPinDirection(LCD_CONTROL_PORT,PIN0,OUTPUT);
		MDIO_voidSetPinDirection(LCD_CONTROL_PORT,PIN1,OUTPUT);
		MDIO_voidSetPinDirection(LCD_CONTROL_PORT,PIN2,OUTPUT);

		//Data pins for LCD
		MDIO_voidSetPortDirection(LCD_DATA_PORT,0xFF);

		//Set port direction for leds
		MDIO_voidSetPortDirection(PORTD,0xFF);

		//Init. LCD & ADC
		MADC_voidInit();
		HLCD_voidInit();


		//LCD says high
		HLCD_voidSendString("Hi There!");
		_delay_ms(1000);


		u16 L_u16ADCValue=0;



	while(1)
	{
		//assign value of ADC reading to a var. to be used
		L_u16ADCValue=MADC_u16AnalogRead(CHANNEL_0);

		//operate nothing
		if(L_u16ADCValue==0)
		{
			MDIO_voidSetPortValue(PORTD,0b0);
		}
		//operate LED1
		else if(L_u16ADCValue<128)
		{
			MDIO_voidSetPortValue(PORTD,0b1);
		}
		//operate LED2
		else if(L_u16ADCValue<128*2)
		{
			MDIO_voidSetPortValue(PORTD,0b11);
		}
		//operate LED3
		else if(L_u16ADCValue<128*3)
		{
			MDIO_voidSetPortValue(PORTD,0b111);
		}
		//operate LED4
		else if(L_u16ADCValue<128*4)
		{
			MDIO_voidSetPortValue(PORTD,0b1111);
		}
		//operate LEd5
		else if(L_u16ADCValue<128*5)
		{
			MDIO_voidSetPortValue(PORTD,0x1F);
		}
		//operate LED6
		else if(L_u16ADCValue<128*6)
		{
			MDIO_voidSetPortValue(PORTD,0x3F);
		}
		//operate LED7
		else if(L_u16ADCValue<128*7)
		{
			MDIO_voidSetPortValue(PORTD,0x7F);
		}
		//operate LED8
		else if(L_u16ADCValue<128*8)
		{
			MDIO_voidSetPortValue(PORTD,0xFF);
		}




		//Clr screen
		HLCD_voidClearDisplay();

		//print ADC value
		HLCD_voidDisplayNumber(L_u16ADCValue);

		// to slow down the while(1) loop
		_delay_ms(250);

	}












}






