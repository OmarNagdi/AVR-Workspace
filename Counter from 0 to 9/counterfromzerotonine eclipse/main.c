

/*******************************************************************************************
* ! Title : 7 segment display Program
* ! File Name : main.c
* ! Description : This file has the implementation code for counting from 0 to 9 & staring again
* ! Version : V1.0
********************************************************************************************/


#include <avr/io.h>
#include<util/delay.h>


void main (void)
{

	DDRD=0xFF;



	while(1)
	{


		/*All segmets off at the beginning
		PORTD=0b11111111;
		_delay_ms(1000);*/


		//to show 0
		PORTD=0b11000000;
		_delay_ms(1000);

		//to show 1
		PORTD=0b11111001;
		_delay_ms(1000);

		// to show 2
		PORTD=0b10100100;
		_delay_ms(1000);

		//to show 3
		PORTD=0b10110000;
		_delay_ms(1000);

		//to show 4
		PORTD=0b10011001;
		_delay_ms(1000);

		//to show 5
		PORTD=0b10010010;
		_delay_ms(1000);

		//to show 6
		PORTD=0b10000010;
		_delay_ms(1000);

		//to show 7
		PORTD=0b11111000;
		_delay_ms(1000);

		//to show 8
		PORTD=0b10000000;
		_delay_ms(1000);

		//to show 9
		PORTD=0b10010000;
		_delay_ms(1000);


	}





}
