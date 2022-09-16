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


#define WHOLE_PORT_OUTPUT 0xFF


//Pattern Address
#define EEN_LETTER_BASE_ADDRESS		0	//EEN=3en to avoid error
#define MIM_LETTER_BASE_ADDRESS		1
#define RA2_LETTER_BASE_ADDRESS		2
#define NOON_LETTER_BASE_ADDRESS	3
#define GEEM_LETTER_BASE_ADDRESS	4
#define DAL_LETTER_BASE_ADDRESS		5
#define YA2_LETTER_BASE_ADDRESS		6


//column index for 1st written letter
#define FIRST_LETTER_COL_INDEX	12




void main (void)
{
	//set lcd control & data pins
	MDIO_voidSetPinDirection(PORTA,PIN0,OUTPUT);
	MDIO_voidSetPinDirection(PORTA,PIN1,OUTPUT);
	MDIO_voidSetPinDirection(PORTA,PIN2,OUTPUT);
	MDIO_voidSetPortDirection(PORTC,WHOLE_PORT_OUTPUT);


	//compose my name patterns in arrays
	u8 LR_3enLetter[]=  {0x00, 0x0F, 0x08, 0x08, 0x1F, 0x00, 0x00, 0x00};
	u8 LR_MimLetter[]=  {0x00, 0x0F, 0x09, 0x09, 0x1F, 0x00, 0x00, 0x00};
	u8 LR_Ra2Letter[]=  {0x00, 0x01, 0x01, 0x01, 0x1F, 0x00, 0x00, 0x00};

	u8 LR_NoonLetter[]= {0x00, 0x05, 0x01, 0x01, 0x1F, 0x00, 0x00, 0x00};
	u8 LR_GeemLetter[]= {0x08, 0x04, 0x02, 0x01, 0x1F, 0x00, 0x04, 0x00};
	u8 LR_DalLetter[]=  {0x08, 0x04, 0x02, 0x01, 0x1F, 0x00, 0x00, 0x00};
	u8 LR_Ya2Letter[]=  {0x02, 0x05, 0x08, 0x04, 0x12, 0x0C, 0x00, 0x00};



	// lcd init
	HLCD_voidInit();


	//Write 7letters or patterns to CGRAM
	HLCD_voidWriteOnCGRAM(EEN_LETTER_BASE_ADDRESS,LR_3enLetter);
	HLCD_voidWriteOnCGRAM(MIM_LETTER_BASE_ADDRESS,LR_MimLetter);
	HLCD_voidWriteOnCGRAM(RA2_LETTER_BASE_ADDRESS,LR_Ra2Letter);
	HLCD_voidWriteOnCGRAM(NOON_LETTER_BASE_ADDRESS,LR_NoonLetter);
	HLCD_voidWriteOnCGRAM(GEEM_LETTER_BASE_ADDRESS,LR_GeemLetter);
	HLCD_voidWriteOnCGRAM(DAL_LETTER_BASE_ADDRESS,LR_DalLetter);
	HLCD_voidWriteOnCGRAM(YA2_LETTER_BASE_ADDRESS,LR_Ya2Letter);

	//SET AC To DDRAM and then row 1, col 12 for 1st letter(FIRST_LETTER_COL_INDEX)
	HLCD_voidGoToPosition(ROW1,FIRST_LETTER_COL_INDEX);
	HLCD_voidSendData(EEN_LETTER_BASE_ADDRESS);


	//row 1, col 11 for 2nd letter
	HLCD_voidGoToPosition(ROW1,FIRST_LETTER_COL_INDEX-1);
	HLCD_voidSendData(MIM_LETTER_BASE_ADDRESS);

	//row 1, col 10 for 3rd letter
	HLCD_voidGoToPosition(ROW1,FIRST_LETTER_COL_INDEX-2);
	HLCD_voidSendData(RA2_LETTER_BASE_ADDRESS);


	//row 1, col 9 for 4th letter
	HLCD_voidGoToPosition(ROW1,FIRST_LETTER_COL_INDEX-3);
	HLCD_voidSendData(' ');


	//row 1, col 8 for 5th letter
	HLCD_voidGoToPosition(ROW1,FIRST_LETTER_COL_INDEX-4);
	HLCD_voidSendData(NOON_LETTER_BASE_ADDRESS);



	//row 1, col 7 for 6th letter
	HLCD_voidGoToPosition(ROW1,FIRST_LETTER_COL_INDEX-5);
	HLCD_voidSendData(GEEM_LETTER_BASE_ADDRESS);



	//row 1, col 6 for 7th letter
	HLCD_voidGoToPosition(ROW1,FIRST_LETTER_COL_INDEX-6);
	HLCD_voidSendData(DAL_LETTER_BASE_ADDRESS);

	//row 1, col 5 for 8th letter
	HLCD_voidGoToPosition(ROW1,FIRST_LETTER_COL_INDEX-7);
	HLCD_voidSendData(YA2_LETTER_BASE_ADDRESS);



	while(1)
	{

	}


}

