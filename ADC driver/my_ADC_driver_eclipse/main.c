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
#include "LCD_Interface.h"
#include "GIE_Interface.h"
#include "util/delay.h"


//Project Show ADC no of steps on a LCD screen
int main (void)
{
	// Control Pins for LCD
	MDIO_voidSetPinDirection(LCD_CONTROL_PORT,PIN0,OUTPUT);
	MDIO_voidSetPinDirection(LCD_CONTROL_PORT,PIN1,OUTPUT);
	MDIO_voidSetPinDirection(LCD_CONTROL_PORT,PIN2,OUTPUT);

	//Data pins for LCD
	MDIO_voidSetPortDirection(LCD_DATA_PORT,0xFF);

	MADC_voidInit();
	HLCD_voidInit();

	//Activate GIE
	MGIE_voidGIEEnable();


	HLCD_voidSendString("Hi There!");
	_delay_ms(1000);


	u16 L_u16ADCDigitalValue=0;



	while(1)
	{
		//assign value of ADC reading to a var. to be used
		L_u16ADCDigitalValue=MADC_u16AnalogRead(CHANNEL_0);

		//Clr screen
		HLCD_voidClearDisplay();

		//print ADC value
		HLCD_voidDisplayNumber(L_u16ADCDigitalValue);

		// to slow down the while(1) loop
		_delay_ms(250);

	}








}






