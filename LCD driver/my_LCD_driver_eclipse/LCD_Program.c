/*
 * LCD_program.c
 *
 *  Created on: Jul 29, 2022
 *      Author: OmarNagdy
 */


#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_Interface.h"
#include"LCD_Interface.h"
#include <util/delay.h>




void HLCD_voidSendCommand(u8 A_u8Command)
{
	// Assign values for RS and RW pins 0 & 1 of portA
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,PIN0,LOW);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,PIN1,LOW);


	//Send Command ON Data pins
	MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Command);

	//Send a pulse on enable pin pin 2 of port A
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,PIN2,HIGH);
	_delay_ms(1);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,PIN2,LOW);
	_delay_ms(1);





}



void HLCD_voidSendData(u8 A_u8Data)
{
	// Assign values for RS and RW pins 0 & 1 of portA respectively
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,PIN0,HIGH);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,PIN1,LOW);


	//Send Data ON Data pins
	MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Data);

	//Send a pulse on enable pin pin 2 of port A
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,PIN2,HIGH);
	_delay_ms(1);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,PIN2,LOW);
	_delay_ms(1);





}






// 8bit Init. func.
void HLCD_voidInit(void){

	//wait more than 30 msc
	_delay_ms(31);

	//Function set 0b00111100
	HLCD_voidSendCommand(LCD_FUNCTION_SET);

	//wait more than 39 us
	_delay_us(40);

	//Display ON/OFF Control 0b00001100 with no shown cursor and no blinking
	HLCD_voidSendCommand(DISPLAY_ON_OR_OFF_CONTROL);

	//wait more than 39 us
		_delay_us(40);

	//Display Clear 0b00000001
	HLCD_voidSendCommand(DISPLAY_CLEAR);


	//wait more than 1.53ms
	_delay_ms(2);


	//Entry Mode Set 0b00000110 with no shift and writing from left to right
	HLCD_voidSendCommand(ENTRY_MODE_SET);
}





void HLCD_voidClearDisplay(void)
{


	//Display Clear 0b00000001
	HLCD_voidSendCommand(DISPLAY_CLEAR);


	//wait more than 1.53ms
	_delay_ms(2);


}


void HLCD_voidSendString(u8 *A_PtrtoString)

{

	while(*A_PtrtoString!='\0')
	//or the lab eng. condition since the decimal of '\0\ is 0: while(*A_PtrtoString>0)
	//or while(*A_PtrtoString!=0)
	{

		HLCD_voidSendData(*A_PtrtoString);
		A_PtrtoString++;



	}

}





void HLCD_voidGoToPosition(u8 A_u8RowNumber,u8 A_u8ColumnNumber)
{
	//Here I have assumed that the index of the first row & first column both will be 0
	switch(A_u8RowNumber)
	{

	case ROW1: HLCD_voidSendCommand(ROW1_ADDRESS_START+A_u8ColumnNumber);  break;
	case ROW2: HLCD_voidSendCommand(ROW2_ADDRESS_START+A_u8ColumnNumber);  break;

	}


	//wait for more than 39 usec
	_delay_us(40);


}


void HLCD_voidDisplayNumber(s32 A_s32Number)
{
	u32 L_u32Number=1;

	if (A_s32Number==0)
	{
		HLCD_voidSendData('0');
	}
	else if (A_s32Number<0)
	{
		HLCD_voidSendData('-');
		A_s32Number=A_s32Number*-1;
	}

	while(A_s32Number!=0)
	{
		L_u32Number=L_u32Number*10 +A_s32Number%10;
		A_s32Number/=10;
	}

	while(L_u32Number!=1)
	{
		//we added 48 as '0' has ascii of 48
		HLCD_voidSendData(L_u32Number%10+48);
		L_u32Number/=10;
	}


}





void HLCD_voidWriteOnCGRAM(u8 A_u8PatternIndex,u8 *A_u8PtrToPatternValue)
{
	u8 L_u8LoopIterator;

	/* 1- Set AC to CGRAM  */
	switch(A_u8PatternIndex)
	{

	case 0: HLCD_voidSendCommand(PATTERN1_BASE_ADDRESS); break;
	case 1: HLCD_voidSendCommand(PATTERN2_BASE_ADDRESS); break;
	case 2: HLCD_voidSendCommand(PATTERN3_BASE_ADDRESS); break;
	case 3: HLCD_voidSendCommand(PATTERN4_BASE_ADDRESS); break;
	case 4: HLCD_voidSendCommand(PATTERN5_BASE_ADDRESS); break;
	case 5: HLCD_voidSendCommand(PATTERN6_BASE_ADDRESS); break;
	case 6: HLCD_voidSendCommand(PATTERN7_BASE_ADDRESS); break;
	case 7: HLCD_voidSendCommand(PATTERN8_BASE_ADDRESS); break;
	//default: /* Report Error to ensure func. arguments data validation */			break;

	}

	/* 2- Write to CGRAM  */
	for(L_u8LoopIterator=0; L_u8LoopIterator<8;L_u8LoopIterator++)
	{
		HLCD_voidSendData(A_u8PtrToPatternValue[L_u8LoopIterator]);

	}



}
