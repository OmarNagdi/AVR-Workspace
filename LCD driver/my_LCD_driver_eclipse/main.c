/*
 * main.c
 *
 *  Created on: Jul 30, 2022
 *      Author: OmarNagdy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include <util/delay.h>


void main (void)
{
	//Set the LCD Control & Data ports as o/p
	MDIO_voidSetPortDirection(PORTA,0xFF);
	MDIO_voidSetPortDirection(PORTC,0xFF);


	//LCD Init.
	HLCD_voidInit();


	/*To Print letter 'A'
	HLCD_voidSendData('A');*/

	//To print my name in many steps
	/*HLCD_voidSendData('O');
	HLCD_voidSendData('M');
	HLCD_voidSendData('A');
	HLCD_voidSendData('R');*/

	//To print my name in one line using send string func.
	//HLCD_voidSendString("Omar Nagdi");


	//This will go to the first row,3rd cell assuming index starts from 0 & print Omar Nagdi there
	HLCD_voidGoToPosition(ROW1,2);
	HLCD_voidSendString("Omar Nagdi");




	HLCD_voidGoToPosition(ROW2,3);
	HLCD_voidSendString("Engineer");






	/*
	//MY Personal Info shifted but not working properly

	//name
	HLCD_voidSendString("Omar Nagdi");

	//job
	HLCD_voidGoToPosition(ROW1,13);
	HLCD_voidSendString("Engineer");


	//age
	HLCD_voidGoToPosition(ROW2,0);
	HLCD_voidDisplayNumber(29);
	HLCD_voidSendData(' ');
	HLCD_voidSendString("years");


	//Phone
	HLCD_voidGoToPosition(ROW2,13);
	HLCD_voidDisplayNumber(0100770);
	HLCD_voidDisplayNumber(6045);
	_delay_ms(5000);
	*/



	while(1)
	{




	}



}
