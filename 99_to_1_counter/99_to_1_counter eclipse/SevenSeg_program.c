/*
 * Sevenseg_program.c
 *
 *  Created on: Jul 17, 2022
 *      Author: OmarNagdy
 */


#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_Interface.h"
#include"SevenSeg_Interface.h"




void HSEVENSEG_voidDisplayNumber(u8 A_u8Number)
{

	MDIO_voidSetPortValue(SEVEN_SEG_PORT,A_u8Number);

}


void HSEVENSEG_voidDisplayNumberOnOneSegmentOfAnInputPort(u8 A_u8PortNo,u8 A_u8Number)
{
	if(   (A_u8PortNo<=PORTD)   && (A_u8Number<=9)     )
	{

		MDIO_voidSetPortValue(A_u8PortNo,A_u8Number);

	}





}
