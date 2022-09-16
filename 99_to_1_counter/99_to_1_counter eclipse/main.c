/*
 * main.c
 *
 *  Created on: Jul 17, 2022
 *      Author: OmarNagdy
 */


#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_Interface.h"
#include"SevenSeg_Interface.h"
#include<util/delay.h>




void main (void)
{
//R in the array name for ARRAY in the used naming convention
 u8 R_u8DisplayedNumbers[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
 MDIO_voidSetPortDirection(SEVEN_SEGMENT_PORT1,0XFF);
 MDIO_voidSetPortDirection(SEVEN_SEGMENT_PORT2,0XFF);


 //For the high common anode of the 7seg.
 /*MDIO_voidSetPinDirection(PORTA,PIN0,OUTPUT);
 MDIO_voidSetPinDirection(PORTA,PIN1,OUTPUT);

 MDIO_voidSetPinValue(PORTA,PIN0,HIGH);
 MDIO_voidSetPinValue(PORTA,PIN1,HIGH);*/



 while(1)
 {

	 for (s8 i=9; i>=0 ; i--)
	 {
		 MDIO_voidSetPortValue(SEVEN_SEGMENT_PORT2,R_u8DisplayedNumbers[i]);
		 for(s8 j=9; j>=0; j--)
		 {
			 MDIO_voidSetPortValue(SEVEN_SEGMENT_PORT1,R_u8DisplayedNumbers[j]);
			 _delay_ms(1000);
		 }

	 }

 }










}
