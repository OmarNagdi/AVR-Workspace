/*
 * LED_Program.c
 *
 *  Created on: Jul 17, 2022
 *      Author: OmarNagdy
 */


#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_Interface.h"
#include"LED_Interface.h"















void HLED_voidSetLEDValue(u8 A_u8PortNo, u8 A_u8PinNo, u8 A_u8LEDValue)
{
	if (   (A_u8PortNo<=PORTD) && (A_u8PinNo<=PIN7) && (A_u8LEDValue<=HIGH))
	{
		MDIO_voidSetPinValue(A_u8PortNo,A_u8PinNo,A_u8LEDValue);

	}

}



void HLED_voidSetLEDON(u8 A_u8PortNo, u8 A_u8PinNo)
{
	if (   (A_u8PortNo<=PORTD) && (A_u8PinNo<=PIN7) )
	{

		MDIO_voidSetPinValue(A_u8PortNo,A_u8PinNo,HIGH);

	}

}
void HLED_voidSetLEDOFF(u8 A_u8PortNo, u8 A_u8PinNo)
{
	if (   (A_u8PortNo<=PORTD) && (A_u8PinNo<=PIN7) )
	{

		MDIO_voidSetPinValue(A_u8PortNo,A_u8PinNo,LOW);

	}

}
