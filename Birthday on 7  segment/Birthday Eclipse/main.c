

/*******************************************************************************************
* ! Title : 7 segment display Program
* ! File Name : main.c
* ! Description : This file has the implementation code for showing your birthday on a 7 seg. dis.
* ! Version : V1.0
********************************************************************************************/



#include <avr/io.h>
#include <util/delay.h>

void main (void)
{

	DDRC=255;
	DDRD=255;


	while(1)
	{


		//to show 2 on PORT D:
		PORTD=0b01011011;
		//to show 6 on PORT C:
		PORTC=0b01111101;
		//delay 2 & 6   for 1 sec:
		_delay_ms(1000);

		//to show 0 on PORT D:
		PORTD=0b00111111;
		//to show 7 on PORT C:
		PORTC=0b00000111;
		//delay 0 & 7   for 1 sec:
		_delay_ms(1000);










	}















}
